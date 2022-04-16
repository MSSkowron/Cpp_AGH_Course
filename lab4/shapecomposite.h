#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#include "shape.h"
#include <memory>
#include <utility>

namespace Shapes {
    enum class ShapeOperation{INTERSECTION, SUM, DIFFERENCE};
    class ShapeComposite : public Shapes::Shape {
    private:
        std::shared_ptr<Shape> shape1;
        std::shared_ptr<Shape> shape2;
        ShapeOperation shapeOperation;
    public:
        ShapeComposite(std::shared_ptr<Shape> s1,std::shared_ptr<Shape> s2, ShapeOperation sOperation):shape1{std::move(s1)}, shape2{std::move(s2)},shapeOperation{sOperation}{}
        virtual bool isIn(int x, int y) const;
    };
}
#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
