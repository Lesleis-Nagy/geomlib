//
// Created by Lesleis Nagy on 26/07/2022.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <iostream>

#include "mpreal.h"

#include "vector3d.hpp"

TEST_CASE("Test vector addition for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(5.0, 7.0, 9.0);

    mpreal eps = 1E-14;
    Vec3D actual = u + v;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       Vector addition (multiprecision)                    |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test vector subtraction for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(3.0, 3.0, 3.0);

    mpreal eps = 1E-14;
    Vec3D actual = v - u;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                    Vector addition (multiprecision)                       |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test vector-scalar multiplication for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    mpreal scalar = 2.0;

    Vec3D expected(2.0, 4.0, 6.0);

    mpreal eps = 1E-14;
    Vec3D actual = u * scalar;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                   vector-scalar product (multiprecision)                  |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test scalar-vector multiplication for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    mpreal scalar = 2.0;

    Vec3D expected(2.0, 4.0, 6.0);

    mpreal eps = 1E-14;
    Vec3D actual = scalar * u;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                    scalar-vector product (multiprecision)                 |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test vector-scalar division for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    mpreal scalar = 2.0;

    Vec3D expected(0.5, 1.0, 1.5);

    mpreal eps = 1E-14;
    Vec3D actual = u / scalar;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                   vector-scalar division (multiprecision)                 |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test vector dot product for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    mpreal expected = 32.0;

    mpreal eps = 1E-14;
    mpreal actual = dot(u, v);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       dot product (multiprecision)                        |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual          | " << actual                      << string(54, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual - expected) < eps );

}


TEST_CASE("Test vector cross product for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    Vec3D expected(-3.0, 6.0, -3.0);

    mpreal eps = 1E-14;
    Vec3D actual = cross(u, v);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       cross product (multiprecision)                      |" << std::endl;
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( mpfr::abs(actual.x() - expected.x()) < eps );
    REQUIRE( mpfr::abs(actual.y() - expected.y()) < eps );
    REQUIRE( mpfr::abs(actual.z() - expected.z()) < eps );

}


TEST_CASE("Test regularized norm for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    // In this test we crank up the precision using MPFR.
    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    // We now use a very high precision for the regularization-eps.
    Vec3D::set_eps(1E-20);
    Vec3D v(1.0, 2.0, 3.0);

    // We expect the test-eps to work down to regularization-eps raised to the 2nd power,
    // in this case 1E-40 == (1E-20)^2 - any smaller value (say 1E-41) should fail.
    mpreal eps = 1E-40;
    mpreal expected = mpfr::sqrt(14.0);
    mpreal actual = norm(v);

#ifdef TEST_DEBUG_MESSAGES
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
#endif // TEST_DEBUG_MESSAGES

    REQUIRE (mpfr::abs(actual - expected) < eps);

}


TEST_CASE("Test norm-squared for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D v(1.0, 2.0, 3.0);

    mpreal eps = 1E-40;
    mpreal expected = 14.0;
    mpreal actual = norm_squared(v);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(digits);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                      norm-squared (multiprecision)                        |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string(54, ' ') << "|" << std::endl;
    std::cout << "| actual          | " << actual                      << string(54, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE (mpfr::abs(actual - expected) < eps);

}

TEST_CASE("Test normalised() function for 'multiprecision' type.", "Vector3D") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D v(1.0, 2.0, 3.0);

    mpreal eps = 1E-40;
    Vec3D expected(1.0 / mpfr::sqrt(14.0), 2.0 / mpfr::sqrt(14.0), 3.0 / mpfr::sqrt(14.0) );
    Vec3D actual = normalised(v);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                 normalised function (multiprecision)                      |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 5, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 5, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 5, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(actual.x() - expected.x()) < eps );
    REQUIRE( abs(actual.y() - expected.y()) < eps );
    REQUIRE( abs(actual.z() - expected.z()) < eps );

}
