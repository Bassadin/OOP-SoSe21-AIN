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

    std::ostream &operator<<(std::ostream &outStream, const Vector3D &d) {
        outStream << "(x: " << d.getX() << " y: " << d.getY() << " z: " << d.getZ() << ")";
        return outStream;
    }

    Vector3D Vector3D::operator+(const Vector3D &other) {
        return Vector3D(getX() + other.getX(), getY() + other.getY(), getZ() + other.getZ());
    }

    //Unäres Minus implementieren! #TODO
    Vector3D Vector3D::operator-(const Vector3D &other) {
        return Vector3D(getX() - other.getX(), getY() - other.getY(), getZ() - other.getZ());
    }

    Vector3D Vector3D::operator*(const float factor) const {
        return Vector3D(getX() * factor, getY() * factor, getZ() * factor);
    }

    float Vector3D::operator*(const Vector3D &other) {
        return (other.getX() * getX()) + (other.getY() * getY()) + (other.getZ() * getZ());
    }

    bool Vector3D::operator==(const Vector3D &other) const {
        //Hier vllt nach jeder Expression seperat returnen?
        return x == other.x &&
               y == other.y &&
               z == other.z;
    }

    bool Vector3D::operator!=(const Vector3D &other) const {
        return !(other == *this);
    }

    //Outside class Vector3D
    Vector3D operator*(float factor, const Vector3D &other) {
        return other * factor;
    }
}

