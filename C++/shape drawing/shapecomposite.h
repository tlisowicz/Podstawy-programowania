#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>

#include "shape.h"

namespace Shapes
{
enum class ShapeOperation
{
    INTERSECTION,
    SUM,
    DIFFERENCE
};

class ShapeComposite : public Shape
{
    std::shared_ptr<Shape> shape1, shape2;
    ShapeOperation operation;

public:
    
    ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation)
    {
        this->shape1 = shape1;
        this->shape2 = shape2;
        this->operation = operation;
    }

    bool isIn(int x, int y) const override
    {
        switch (this->operation) 
        {
            case ShapeOperation::INTERSECTION:
                return this->shape1->isIn(x, y) && this->shape2->isIn(x, y);
            
            case ShapeOperation::SUM:
                return this->shape1->isIn(x, y) || this->shape2->isIn(x, y);
            
            case ShapeOperation::DIFFERENCE:
                return this->shape1->isIn(x, y) && !(this->shape2->isIn(x, y));
        }
        
        
    }
};
} // namespace Shapes

#endif // SHAPECOMPOSITE_H
