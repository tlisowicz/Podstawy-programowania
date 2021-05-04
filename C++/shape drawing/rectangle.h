#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
    // TODO:
    int xFrom;
    int xTo;
    int yFrom;
    int yTo;
public:
    Rectangle(int xF, int yF, int xT, int yT) : xFrom(xF), yFrom(yF), xTo(xT), yTo(yT) {};
    int getX()const { return xFrom; }
    int getY()const { return yFrom; }
    int getXTo()const { return xTo; }
    int getYTo()const { return yTo; }

    bool isIn(int x, int y) const override 
     {
        if ((this->getX() <= x) && (x<= this->getXTo()) && (this->getY() <= y) && (y<= this->getYTo())) return true;
        return false;
     }

};
} // namespace Shapes

#endif // RECTANGLE_H
