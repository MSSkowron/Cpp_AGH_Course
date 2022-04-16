//
// Created by mateuszskowron on 4/16/22.
//

#include "circle.h"
#include <cmath>

bool Shapes::Circle::isIn(int x, int y) const {
    return sqrt(pow((x-center.x_),2) + pow((y-center.y_),2)) <= double(radius);
}

