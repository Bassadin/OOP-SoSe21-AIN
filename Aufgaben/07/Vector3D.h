//
// Created by basti on 04.05.2021.
//

#ifndef OOP_VECTOR3D_H
#define OOP_VECTOR3D_H

namespace hfu {
    class Vector3D {
    private:
        const float x, y, z;
    public:
        Vector3D(float x, float y, float z);

        float getX() const;

        float getY() const;

        float getZ() const;


    };


}

#endif //OOP_VECTOR3D_H
