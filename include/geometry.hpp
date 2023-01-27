//
// Created by Lesleis Nagy on 24/01/2023.
//

#pragma once

#include <vector3d.hpp>

namespace org::lesleisnagy::geomlib {

    /**
     * Return the edge_length between two vector endpoints.
     * @param lhs vector representing the start point of the edge.
     * @param rhs vector representing the end point of the edge.
     * @return the length of the edge.
     */
    template <typename Real>
    Real edge_length(const Vector3D<Real> &lhs, const Vector3D<Real> &rhs) {

        return norm(lhs - rhs);

    }

    /**
     * Return the edge center between two vector endpoints - mpreal specific version.
     * @param r1 vector representing the start point of the edge.
     * @param r2 vector representing the end point of the edge.
     * @return the vector representing the center point of the edge.
     */
    template <typename Real>
    Vector3D<Real> edge_center(const Vector3D<Real> &r1, const Vector3D<Real> &r2) {

        return (r1 + r2) / Real(2);

    }

    /**
     * Return the orientation vector between two vector end points; this is the unit vector pointing from \f$r_1\f$ to
     * \f$r_2\f$.
     * @param r1 vector representing the start point of the edge.
     * @param r2 vector representing the end point of the edge.
     * @return the unit vector pointing from \f$r_1\f$ to \f$r_2\f$.
     */
    template <typename Real>
    Vector3D<Real> edge_orientation(const Vector3D<Real> &r1, const Vector3D<Real> &r2) {

        return normalised(r2 - r1);

    }

    /**
     * Return the triangle normal vector assuming vertex clockwise winding \f$ r_1 \rightarrow r_2 \f$,
     * \f$ r_2 \rightarrow r_3 \f$ and \f$ r_3 \rightarrow r_1 \f$.
     * @param r1 vector representing a point on the triangle.
     * @param r2 vector representing a point on the triangle.
     * @param r3 vector representing a point on the triangle.
     * @return the triangle normal vector.
     */
    template <typename Real>
    Vector3D<Real> triangle_normal(const Vector3D<Real> &r1, const Vector3D<Real> &r2, const Vector3D<Real> &r3) {

        return normalised(cross(r2 - r1, r3 - r1));

    }

    /**
     * Return a triangle's center vector.
     * @param r1 vector representing a point on the triangle.
     * @param r2 vector representing a point on the triangle.
     * @param r3 vector representing a point on the triangle.
     * @return the triangle center vector.
     */
    template <typename Real>
    Vector3D<Real> triangle_center(const Vector3D<Real> &r1, const Vector3D<Real> &r2, const Vector3D<Real> &r3) {

        Vector3D sum = (r1 + r2) + r3;

        return sum / Real(3);

    }

    /**
     * Return a triangle's area.
     * @param r1 vector representing a point on the triangle.
     * @param r2 vector representing a point on the triangle.
     * @param r3 vector representing a point on the triangle.
     * @return the triangle area.
     */
    template <typename Real>
    Real triangle_area(const Vector3D<Real> &r1, const Vector3D<Real> &r2, const Vector3D<Real> &r3) {

        return norm(cross(r2 - r1, r3 - r1)) / Real(2);

    }

    /**
     * Return the tetrahedron center vector.
     * @param r1 vector representing a point on the tetrahedron.
     * @param r2 vector representing a point on the tetrahedron.
     * @param r3 vector representing a point on the tetrahedron.
     * @param r4 vector representing a point on the tetrahedron.
     * @return the tetrahedron center vector.
     */
    template <typename Real>
    Vector3D<Real> tetrahedron_center(const Vector3D<Real> &r1, const Vector3D<Real> &r2,
                                      const Vector3D<Real> &r3, const Vector3D<Real> &r4) {

        Vector3D sum = ((r1 + r2) + r3) + r4;

        return sum / Real(4);

    }

    /**
     * Return the volume of a tetrahedron defined by four vertices.
     * @param r1 vector representing a point on the tetrahedron.
     * @param r2 vector representing a point on the tetrahedron.
     * @param r3 vector representing a point on the tetrahedron.
     * @param r4 vector representing a point on the tetrahedron.
     * @return the tetrahedron volume.
     */
    template <typename Real>
    Real tetrahedron_volume(const Vector3D<Real> &r1, const Vector3D<Real> &r2,
                            const Vector3D<Real> &r3, const Vector3D<Real> &r4) {

        Real det = r1.y() * r2.z() * r3.x() - r1.z() * r2.y() * r3.x() +
                   r1.z() * r2.x() * r3.y() - r1.x() * r2.z() * r3.y() -
                   r1.y() * r2.x() * r3.z() + r1.x() * r2.y() * r3.z() +
                   r1.z() * r2.y() * r4.x() - r1.y() * r2.z() * r4.x() -
                   r1.z() * r3.y() * r4.x() + r2.z() * r3.y() * r4.x() +
                   r1.y() * r3.z() * r4.x() - r2.y() * r3.z() * r4.x() -
                   r1.z() * r2.x() * r4.y() + r1.x() * r2.z() * r4.y() +
                   r1.z() * r3.x() * r4.y() - r2.z() * r3.x() * r4.y() -
                   r1.x() * r3.z() * r4.y() + r2.x() * r3.z() * r4.y() +
                   r1.y() * r2.x() * r4.z() - r1.x() * r2.y() * r4.z() -
                   r1.y() * r3.x() * r4.z() + r2.y() * r3.x() * r4.z() +
                   r1.x() * r3.y() * r4.z() - r2.x() * r3.y() * r4.z();

        return det / Real(6);

    }

} // namespace org::nagy::geomlib
