#ifndef STAGE_H
#define STAGE_H

#include <iosfwd>

namespace Shapes
{
class Shape;
}

class Stage
{
    int width, height;

    constexpr static char emptySymbol{' '};
    constexpr static char shapeSymbol{'*'};

public:
    Stage(int width, int height) : width(width), height(height)
    {}

    void drawShape2Stream(const Shapes::Shape* shape, std::ostream& stream) const {
        for (int y=height; y > 0; --y) 
        {
            for (int x = 0; x < width; ++x)
            {
                if (shape->isIn(this->width, this->height)) stream << shapeSymbol;
                stream <<  emptySymbol;
            }
        }
    }
};

#endif // STAGE_H
