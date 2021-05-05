//
// Created by basti on 04.05.2021.
//

#ifndef OOP_VECTOR3D_H
#define OOP_VECTOR3D_H

#include <ostream>

namespace hfu {
    class Vector3D {
    private:
        const float x, y, z;
    public:
        Vector3D(float x, float y, float z);

        float getX() const;

        float getY() const;

        float getZ() const;

        Vector3D operator+(const Vector3D& other);

        Vector3D operator-(const Vector3D &other);

        Vector3D operator*(const float factor) const;

        float operator*(const Vector3D& other);

        bool operator==(const Vector3D &other) const;

        bool operator!=(const Vector3D &other) const;

        friend std::ostream &operator<<(std::ostream &os, const Vector3D &d);
    };

    Vector3D operator*(float factor, const Vector3D &other);
}

#endif //OOP_VECTOR3D_H
