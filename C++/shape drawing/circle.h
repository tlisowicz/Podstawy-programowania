#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
    // TODO:
    int xCenter;
    int yCenter;
    int radius;
public:
    int getX()const { return xCenter; }
    int getY()const { return yCenter; }
    int getRadius()const { return radius; }
    Circle(int xC, int yC, int r) : xCenter(xC), yCenter(yC), radius(r) {};
    bool isIn(int x, int y) const override
    {

        if (((x - this->getX()) * (x - this->getX()) + (y - this->getY()) * (y - this->getY())) <= this->getRadius() * this->getRadius()) return true;
            return false;
    }
};
} // namespace Shapes

#endif // CIRCLE_H
