//
// Created by Lesleis Nagy on 26/07/2022.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <iostream>

#include "vector3d.hpp"

TEST_CASE("Test vector addition for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(5.0, 7.0, 9.0);

    double eps = 1E-14;
    Vec3D actual = u + v;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       Vector addition (double)                            |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE(fabs(actual.x() - expected.x()) < eps );
    REQUIRE(fabs(actual.y() - expected.y()) < eps );
    REQUIRE(fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test vector subtraction for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(3.0, 3.0, 3.0);

    double eps = 1E-14;
    Vec3D actual = v - u;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       Vector subtraction (double)                         |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test vector-scalar multiplication for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    double scalar = 2.0;

    Vec3D expected(2.0, 4.0, 6.0);

    double eps = 1E-14;
    Vec3D actual = u * scalar;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                      vector-scalar product (double)                       |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test scalar-vector multiplication for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    double scalar = 2.0;

    Vec3D expected(2.0, 4.0, 6.0);

    double eps = 1E-14;
    Vec3D actual = scalar * u;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                        scalar-vector product (double)                     |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test vector-scalar division for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    double scalar = 2.0;

    Vec3D expected(0.5, 1.0, 1.5);

    double eps = 1E-14;
    Vec3D actual = u / scalar;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       vector-scalar division (double)                     |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(53, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(53, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(53, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(53, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test vector dot product for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    double expected = 32.0;

    double eps = 1E-14;
    double actual = dot(u, v);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                           dot product (double)                            |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual          | " << actual                      << string(54, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual - expected) < eps );

}

TEST_CASE("Test vector cross product for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(-3.0, 6.0, -3.0);

    double eps = 1E-14;
    Vec3D actual = cross(u, v);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                         cross product (double)                            |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(54, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(55, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(55, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(54, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}

TEST_CASE("Test regularized norm for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    // The double should fail for regularization-epsilon values (i.e. the values used in
    // regularizing the vector norm) if the test-eps is too high. Whenever the
    // regularization epsilon is set to 1E-8 or smaller the regularization basically
    // never happens because the value is so small it doesn't affect the norm.
    Vec3D::set_eps(1E-7);
    Vec3D v(1.0, 2.0, 3.0);

    // Note: because the regularization-norm is 1E-7 (see above), 1E-14 is an acceptable
    // choice for the test-eps, however 1E-15 is too small and the test will fail.
    double eps = 1E-14;
    double expected = sqrt(14.0);
    double actual = norm(v);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                          norm (multiprecision)                            |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string( 5, ' ') << "|" << std::endl;
    std::cout << "| actual          | " << actual                      << string( 5, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(norm(v) - expected) < eps );

}

TEST_CASE("Test norm-squared for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D v(1.0, 2.0, 3.0);

    double eps = 1E-14;
    double expected = 14.0;
    double actual = norm_squared(v);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                          norm-squared (double)                            |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual          | " << actual                      << string(54, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual - expected) < eps );

}

TEST_CASE("Test normalised() function for 'double' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D v(1.0, 2.0, 3.0);

    double eps = 1E-14;
    Vec3D expected(1.0 / sqrt(14.0), 2.0 / sqrt(14.0), 3.0 / sqrt(14.0) );
    Vec3D actual = normalised(v);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       normalised function (double)                        |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(actual.x() - expected.x()) < eps );
    REQUIRE( fabs(actual.y() - expected.y()) < eps );
    REQUIRE( fabs(actual.z() - expected.z()) < eps );

}
