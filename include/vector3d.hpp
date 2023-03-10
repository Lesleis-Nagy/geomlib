//
// Created by Lesleis Nagy on 24/01/2023.
//

#pragma once

#include <ostream>

namespace org::lesleisnagy::geomlib {

    /**
     * An implementation of a three dimensional cartesian vector.
     * @tparam T the underlying data type for the calculation - usually ‘double’ or ‘mpreal’.
     */
    template<typename T>
    class Vector3D {

    public:

        /**
         * Set the regularisation-epsilon value for **all** Vector3D objects of this type.
         * @param new_eps the new regularisation-epsilon.
         */
        static void set_eps(T new_eps) {

            _eps = new_eps;
            _eps_squared = new_eps * new_eps;

        }

        /**
         * Retrieve the regularisation-epsilon.
         * @return the regularisation-epsilon.
         */
        static T eps() {

            return _eps;

        }

        /**
         * Retrieve the regularisation-epsilon squared.
         * @return the regularisation-epsilon squared.
         */
        static T eps_squared() {

            return _eps_squared;

        }

        /**
         * Create a three dimensional zero-vector object.
         */
        Vector3D() : _x(0), _y(0), _z(0) {}

        /**
         * Create a three dimensional vector object with the given x, y & z components along
         * with a regularisation-epsilon value.
         * @param x the vector x component.
         * @param y the vector y component.
         * @param z the vector z component.
         * @param eps the regularization-epsilon value.
         */
        Vector3D(T x, T y, T z) : _x(std::move(x)), _y(std::move(y)), _z(std::move(z)) {}

        /**
         * Retrieve the vector's x-component.
         * @return the vector's x-component.
         */
        [[nodiscard]] inline T x() const { return _x; }

        /**
         * Retrieve the vector's y-component.
         * @return the vector's y-component.
         */
        [[nodiscard]] inline T y() const { return _y; }

        /**
         * Retrieve the vector's z-component.
         * @return the vector's z-component.
         */
        [[nodiscard]] inline T z() const { return _z; }

    private:

        T _x;
        T _y;
        T _z;

        [[maybe_unused]] static T _eps;
        [[maybe_unused]] static T _eps_squared;

    };

    // Initialize static eps & eps_squared values to defaults for double precision arithmetic.
    template<typename T> T Vector3D<T>::_eps = 1E-7;

    template<typename T> T Vector3D<T>::_eps_squared = 1E-14;

    /**
     * Redirection operator to display the vector.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param out the output stream.
     * @param v the vector to display.
     * @return the output stream with a representation of the input vector.
     */
    template<typename T>
    std::ostream &operator<<(std::ostream &out, const Vector3D<T> v) {

        out << "<" << v.x() << ", " << v.y() << ", " << v.z() << ">";
        return out;

    }

    /**
     * Vector addition operator.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param u the vector on the left hand side of the sum.
     * @param v the vector on the right hand side of the sum.
     * @return the sum of the two input vectors.
     */
    template<typename T>
    Vector3D<T> operator+(const Vector3D<T> &u, const Vector3D<T> &v) {

        return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};

    }

    /**
     * Vector subtraction operator.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param u the vector on the left hand side of the operator.
     * @param v the vector on the right hand side of the operator.
     * @return the difference of two input vectors.
     */
    template<typename T>
    Vector3D<T> operator-(const Vector3D<T> &u, const Vector3D<T> &v) {

        return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};

    }

    /**
     * Vector-scalar product operator.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param v the vector on the left hand side of the product.
     * @param lambda the scalar on the right hand side of the product.
     * @return the vector-scalar product.
     */
    template<typename T>
    Vector3D<T> operator*(const Vector3D<T> &v, T lambda) {

        return {lambda * v.x(), lambda * v.y(), lambda * v.z()};

    }

    /**
     * Scalar-vector product operator.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param lambda the scalar on the left hand side of the product.
     * @param v the vector on the right hand side of the product.
     * @return the scalar-vector product.
     */
    template<typename T>
    Vector3D<T> operator*(T lambda, const Vector3D<T> &v) {

        return {lambda * v.x(), lambda * v.y(), lambda * v.z()};

    }

    /**
     * Vector-scalar division.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param v the vector on the left hand side of the division.
     * @param lambda the scalar on the right hand side of the division.
     * @return the vector-scalar division.
     */
    template<typename T>
    Vector3D<T> operator/(const Vector3D<T> &v, T lambda) {

        return {v.x() / lambda, v.y() / lambda, v.z() / lambda};

    }

    /**
     * Vector dot product.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param u the vector on the left hand side of the dot product.
     * @param v the scalar on the right hand side of the dot product.
     * @return the vector dot product.
     */
    template<typename T>
    T dot(const Vector3D<T> &u, const Vector3D<T> &v) {

        return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();

    }

    /**
     * Vector cross product.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param u the vector on the left hand side of the cross product.
     * @param v the scalar on the right hand side of the cross product.
     * @return the vector cross product.
     */
    template<typename T>
    Vector3D<T> cross(const Vector3D<T> &u, const Vector3D<T> &v) {

        return {u.y() * v.z() - u.z() * v.y(), -u.x() * v.z() + u.z() * v.x(), u.x() * v.y() - u.y() * v.x()};

    }

    /**
     * The norm of a vector
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param v the vector for which we seek the norm.
     * @return the norm of the input vector.
     */
    template<typename T>
    T norm(const Vector3D<T> &v) {

        return sqrt(dot(v, v) + Vector3D<T>::eps_squared());

    }

    /**
     * The norm squared of a vector.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param v the vector for which we seek the norm-squared.
     * @return the norm-squared of the input vector.
     */
    template<typename T>
    T norm_squared(const Vector3D<T> &v) {

        return dot(v, v);

    }

    /**
     * Produce a normalised version of the input vector.
     * @tparam T the underlying data type for the calculation - usually 'double' or 'mpreal'.
     * @param v the vector that we seek to normalise.
     * @return the normalised input vector.
     */
    template<typename T>
    Vector3D<T> normalised(const Vector3D<T> &v) {

        T l = norm(v);
        return v / l;

    }

} // namespace org::lesleisnagy::geomlib