//
// Created by basti on 04.05.2021.
//

#include "Vector3D.h"

namespace hfu {
    hfu::Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    float Vector3D::getX() const {
        return x;
    }

    float Vector3D::getY() const {
        return y;
    }

    float Vector3D::getZ() const {
        return z;
    }


}

