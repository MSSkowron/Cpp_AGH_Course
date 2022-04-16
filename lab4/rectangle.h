#ifndef ZAD4SHAPEDRAWING_RECTANGLE_H
#define ZAD4SHAPEDRAWING_RECTANGLE_H
#include "shape.h"
namespace Shapes{
    class Rectangle: public Shapes::Shape {
    private:
        Shapes::Point from;
        Shapes::Point to;
    public:
        Rectangle(int xFrom,int yFrom,int xTo, int yTo): from{xFrom,yFrom},to{xTo,yTo} {}
        int x() const {
            return from.x_;
        }
        int y() const {
            return from.y_;
        }
        int xTo() const {
            return to.x_;
        }
        int yTo() const {
            return to.y_;
        }
        virtual bool isIn(int x, int y) const;
    };
}
#endif //ZAD4SHAPEDRAWING_RECTANGLE_H
