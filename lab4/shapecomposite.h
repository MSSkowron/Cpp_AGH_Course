#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#include "shape.h"
#include <memory>

namespace Shapes {
    enum class ShapeOperation{INTERSECTION, SUM, DIFFERENCE};
    class ShapeComposite : public Shapes::Shape {
    public:
        ShapeComposite(std::shared_ptr<Shape> s1,std::shared_ptr<Shape> s2, ShapeOperation shapeOperation){}
        virtual bool isIn(int x, int y) const;
    };
}
#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
