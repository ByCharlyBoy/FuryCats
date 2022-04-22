#pragma once
#include "Matrix.h"
#define RAD2DEG 57.297469361769855164730224415088f

namespace RotografosEngine /*MTChurritos*/ {
    template <int x>
    class Vector :
        public Matrix<x, 1>
    {
    public:
        Vector(std::vector<float> vector) : Matrix<x, 1>(vector) {

        }

        float PointProduct(Vector rhs);
        float AngleBetweenVec(Vector rhs);
        float Magnitude();
    };

    //cpp

    template<int x>
    inline float Vector<x>::Magnitude()
    {
        return sqrtf(PointProduct(Vector<x>(this->_vectorContent)));
    }

    template<int x>
    inline float Vector<x>::AngleBetweenVec(Vector rhs)
    {
        return acosf((PointProduct(rhs))/(this->Magnitude()*rhs.Magnitude()))*RAD2DEG;
    }

    template <int x>
    float Vector<x>::PointProduct(Vector rhs) {
        if (rhs.GetSizeX() != x)
            return 0;
        float res = 0;
        for (int i = 0; i < this->GetSizeX(); ++i)
            res += this->GetComponent(i, 0) * rhs.GetComponent(i, 0);
        return res;
    }
}