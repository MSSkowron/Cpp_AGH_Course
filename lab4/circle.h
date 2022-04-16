//
// Created by mateuszskowron on 4/16/22.
//

#ifndef ZAD4SHAPEDRAWING_CIRCLE_H
#define ZAD4SHAPEDRAWING_CIRCLE_H
#include "shape.h"
namespace Shapes{

    class Circle:public Shapes::Shape {
    private:
        Shapes::Point center;
        int radius;
    public:
        Circle(int xCenter, int yCenter, int r): center{xCenter,yCenter}, radius{r} {}
        int x() const{
            return center.x_;
        }
        int y() const {
            return center.y_;
        }
        int getRadius() const{
            return radius;
        }
        virtual bool isIn(int x, int y) const;
    };
}
#endif //ZAD4SHAPEDRAWING_CIRCLE_H
