#ifndef SHAPE_H
#define SHAPE_H

namespace Shapes
{
    struct Point
    {
        int x_, y_;
    };

    class Shape
    {
    public:
        virtual bool isIn(int x, int y) const = 0;
    };
}

#endif // SHAPE_H
