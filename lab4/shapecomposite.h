#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#include "shape.h"
class ShapeComposite:public Shapes::Shape {
public:
    virtual bool isIn(int x, int y) const;
};
#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
