#include <string> // string, to_string()

#include <gtest/gtest.h>

#include "vector.h"


namespace
{
using namespace std;
using namespace ::testing;
}

//static string vector2String(VectorImpl *v);
//static string array2String(const T* const array, size_t elements);

//void initialArayWithSmallRandomNumbers(Fraction array[], size_t elements);

class VectorTest : public ::testing::Test
{
};

TEST_F(VectorTest, constructor)
{
    {
        Vector v;
        const size_t expectedCapacity = 0;

        ASSERT_EQ(expectedCapacity, v.Size());
        ASSERT_EQ(expectedCapacity, v.Capacity());
    }

    {
        const size_t expectedSize = 0;
        const size_t expectedCapacity = 10;

        Vector v(expectedCapacity);

        ASSERT_EQ(expectedSize, v.Size());
        ASSERT_EQ(expectedCapacity, v.Capacity());
    }
}

TEST_F(VectorTest, destructOfNotEmptyVector)
{
    constexpr decltype(MyOwnMemoryManagement::deletions) expectedReallocations = 1;
    MyOwnMemoryManagement::deletions = 0;
    {
        const size_t expectedCapacity = 10;

        Vector v(expectedCapacity);
        ASSERT_EQ(expectedCapacity, v.Capacity());
    }
    ASSERT_EQ(expectedReallocations, MyOwnMemoryManagement::deletions);
}

TEST_F(VectorTest, addingMultipleElementsWithoutReallocation)
{
    const Fraction fractions[] = { Fraction{1, 2}, Fraction{3, 4}, Fraction{5, 6} };
    constexpr size_t fractionCount = sizeof(fractions) / sizeof(fractions[0]);

    Vector v(fractionCount);
    for (size_t i=0; i<fractionCount; ++i)
    {
        v.push_back(fractions[i]);
        EXPECT_EQ(i+1, v.Size());
        EXPECT_EQ(fractionCount, v.Capacity());
    }
}

TEST_F(VectorTest, accessingWithIndexOperator)
{
    const Fraction fractions[] = { Fraction{1, 2}, Fraction{3, 4}, Fraction{5, 6} };
    constexpr size_t fractionCount = sizeof(fractions) / sizeof(fractions[0]);

    Vector v(fractionCount);
    for (size_t i=0; i<fractionCount; ++i)
    {
        v.push_back(fractions[i]);

        EXPECT_EQ(fractions[i].getNumerator(),   v[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), v[i].getDenominator());
    }
}
/*
TEST_F(VectorTest, copyAndMoveConstructor)
{
    const Fraction fractions[] = { Fraction{1, 2}, Fraction{3, 4}, Fraction{5, 6} };
    constexpr size_t fractionCount = sizeof(fractions) / sizeof(fractions[0]);

    Vector v(fractionCount);
    for (size_t i=0; i<fractionCount; ++i)
    {
        v.push_back(fractions[i]);
    }


    const Vector vCopied = v;
    ASSERT_EQ(fractionCount, vCopied.Size());
    ASSERT_EQ(fractionCount, vCopied.Capacity());
    for (size_t i=0; i<fractionCount; ++i)
    {
        EXPECT_EQ(fractions[i].getNumerator(),   vCopied[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), vCopied[i].getDenominator());

        EXPECT_EQ(fractions[i].getNumerator(),   v[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), v[i].getDenominator());
    }


    const Vector vMoved = std::move(v);
    constexpr size_t expectedCapacityAfterMoving = 0;
    EXPECT_EQ(expectedCapacityAfterMoving, v.Size());
    EXPECT_EQ(expectedCapacityAfterMoving, v.Capacity());
    ASSERT_EQ(fractionCount, vMoved.Size());
    ASSERT_EQ(fractionCount, vMoved.Capacity());

    for (size_t i=0; i<fractionCount; ++i)
    {
        EXPECT_EQ(fractions[i].getNumerator(),   vMoved[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), vMoved[i].getDenominator());
    }
}
TEST_F(VectorTest, assignmentOperatorCopyingAndMoving)
{
    const Fraction fractions[] = { Fraction{1, 2}, Fraction{3, 4}, Fraction{5, 6} };
    constexpr size_t fractionCount = sizeof(fractions) / sizeof(fractions[0]);

    Vector v(fractionCount), v2, v3;
    for (size_t i=0; i<fractionCount; ++i)
    {
        v.push_back(fractions[i]);
    }


    v2 = v;
    ASSERT_EQ(fractionCount, v2.size());
    ASSERT_EQ(fractionCount, v2.capacity());
    for (size_t i=0; i<fractionCount; ++i)
    {
        EXPECT_EQ(fractions[i].getNumerator(),   v2[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), v2[i].getDenominator());

        EXPECT_EQ(fractions[i].getNumerator(),   v[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), v[i].getDenominator());
    }


    v3 = std::move(v);
    constexpr size_t expectedCapacityAfterMoving = 0;
    EXPECT_EQ(expectedCapacityAfterMoving, v.Size());
    EXPECT_EQ(expectedCapacityAfterMoving, v.Capacity());
    ASSERT_EQ(fractionCount, v3.Size());
    ASSERT_EQ(fractionCount, v3.Capacity());

    for (size_t i=0; i<fractionCount; ++i)
    {
        EXPECT_EQ(fractions[i].getNumerator(),   v3[i].getNumerator());
        EXPECT_EQ(fractions[i].getDenominator(), v3[i].getDenominator());
    }
}*/

TEST_F(VectorTest, accessingWithIndexOperatorOutOfRange)
{
    Vector v;
    ASSERT_THROW(v[v.Size()], std::out_of_range);

    constexpr size_t expectedCapacity = 10;
    const Fraction fraction{1, 2};

    Vector v2(expectedCapacity);
    for (size_t i=0; i<expectedCapacity; ++i)
    {
        v2.push_back(fraction);

        ASSERT_NO_THROW(v2[i]);
    }
    ASSERT_THROW(v2[expectedCapacity+1], std::out_of_range);
}

TEST_F(VectorTest, addingElementsWithReallocationNecessairy)
{
    const Fraction fractions[] = { Fraction{1, 2}, Fraction{3, 4}, Fraction{5, 6} };
    constexpr size_t fractionCount = sizeof(fractions) / sizeof(fractions[0]);

    Vector v;
    for (size_t i=0; i<fractionCount; ++i)
    {
        v.push_back(fractions[i]);
        ASSERT_EQ(i+1, v.Size());
        ASSERT_EQ(v.Size(), v.Capacity());
    }
}

//////////////////////////////////////////////////////////////////////////////////// function definitions:
//static string array2String(const T* const array, size_t elements)
//{
//    string s = "array(" + to_string(elements) + ") = {";
//    if (array)
//    {
//        s += to_string(array[0]);
//        for (size_t i=1; i<elements; ++i)
//        {
//            s += ", " + to_string(array[i]);
//        }
//    }
//    s += "}";

//    return s;
//}

//static string vector2String(VectorImpl* v)
//{
//    if (v)
//    {
//        string s = "Vector(" + to_string(size(v)) + ") = {";
//        if (!empty(v))
//        {
//            s += to_string(*at(v, 0));
//            for (size_t i=1; i<size(v); ++i)
//            {
//                s += ", " + to_string(*at(v, i));
//            }
//        }
//        s += "}";

//        return s;
//    }
//    else
//    {
//        return "{}";
//    }
//}

//void initialArayWithSmallRandomNumbers(T array[], size_t elements)
//{
//    for (size_t i=0; i<elements; ++i)
//    {
//        array[i] = rand()%10;
//    }
//}
