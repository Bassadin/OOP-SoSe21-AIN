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

    std::ostream &operator<<(std::ostream &os, const Vector3D &d) {
        os << "(x: " << d.getX() << " y: " << d.getY() << " z: " << d.getZ() << ")";
        return os;
    }

    Vector3D Vector3D::operator+(const Vector3D &other) {
        return Vector3D(getX() + other.getX(), getY() + other.getY(), getZ() + other.getZ());
    }

    Vector3D Vector3D::operator-(const Vector3D &other) {
        return Vector3D(getX() - other.getX(), getY() - other.getY(), getZ() - other.getZ());
    }

    Vector3D Vector3D::operator*(const float &factor) {
        return Vector3D(getX() * factor, getY() * factor, getZ() * factor);
    }

    float Vector3D::operator*(const Vector3D &other) {
        return (other.getX() * getX()) + (other.getY() * getY()) + (other.getZ() * getZ());
    }

    Vector3D operator*(float factor, const Vector3D &other) {
        return Vector3D(other.getX() * factor, other.getY() * factor, other.getZ() * factor);
    }

    bool Vector3D::operator==(const Vector3D &other) const {
        return x == other.x &&
               y == other.y &&
               z == other.z;
    }

    bool Vector3D::operator!=(const Vector3D &rhs) const {
        return !(rhs == *this);
    }
}

