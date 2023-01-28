//
// Created by Lesleis Nagy on 26/07/2022.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <iostream>

#include "mpreal.h"

#include "vector3d.hpp"
#include "geometry.hpp"

TEST_CASE("Test edge_length() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    mpreal eps = 1E-40;
    mpreal expected = mpfr::sqrt(27.0);
    mpreal actual_d1 = edge_length(u, v);
    mpreal actual_d2 = edge_length(v, u);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                        edge length (multiprecision)                       |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string( 5, ' ') << "|" << std::endl;
    std::cout << "| actual d1       | " << actual_d1                   << string( 5, ' ') << "|" << std::endl;
    std::cout << "| actual d2       | " << actual_d2                   << string( 5, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE(abs(actual_d1 - expected) < eps );
    REQUIRE(abs(actual_d2 - expected) < eps );

}

TEST_CASE("Test edge_center() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(1.0, 2.0, 3.0);
    Vec3D r2(4.0, 5.0, 6.0);

    Vec3D expected(mpreal(5.0)/mpreal(2.0), mpreal(7.0)/mpreal(2.0), mpreal(9.0)/mpreal(2.0));
    Vec3D actual = edge_center(r1, r2);

    mpreal eps = 1E-40;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                       edge center (multiprecision)                        |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string(53, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string(53, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string(53, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string(53, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string(53, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string(53, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(expected.x() - actual.x()) < eps );
    REQUIRE( abs(expected.y() - actual.y()) < eps );
    REQUIRE( abs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test edge_orientation() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(1.0, 2.0, 3.0);
    Vec3D r2(4.0, 5.0, 6.0);

    Vec3D expected(3.0/mpfr::sqrt(27.0), 3.0/mpfr::sqrt(27.0), 3.0/mpfr::sqrt(27.0));
    Vec3D actual = edge_orientation(r1, r2);

    mpreal eps = 1E-40;

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                    edge orientation (multiprecision)                      |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(expected.x() - actual.x()) < eps );
    REQUIRE( abs(expected.y() - actual.y()) < eps );
    REQUIRE( abs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_normal() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(1.0, 0.0, 0.0);
    Vec3D r2(0.0, 1.0, 0.0);
    Vec3D r3(0.0, 0.0, 1.0);

    mpreal eps = 1E-40;
    Vec3D expected(1.0/mpfr::sqrt(3.0), 1.0/mpfr::sqrt(3.0), 1.0/mpfr::sqrt(3.0));
    Vec3D actual = triangle_normal(r1, r2, r3);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                     triangle normal (multiprecision)                      |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(expected.x() - actual.x()) < eps );
    REQUIRE( abs(expected.y() - actual.y()) < eps );
    REQUIRE( abs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_center() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(1.0, 0.0, 0.0);
    Vec3D r2(0.0, 1.0, 0.0);
    Vec3D r3(0.0, 0.0, 1.0);

    mpreal eps = 1E-40;
    Vec3D expected(mpreal(1.0)/mpreal(3.0), mpreal(1.0)/mpreal(3.0), mpreal(1.0)/mpreal(3.0));
    Vec3D actual = triangle_center(r1, r2, r3);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                     triangle center (multiprecision)                      |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(expected.x() - actual.x()) < eps );
    REQUIRE( abs(expected.y() - actual.y()) < eps );
    REQUIRE( abs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_area() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(0.0, 0.0, 0.0);
    Vec3D r2(1.0, 0.0, 0.0);
    Vec3D r3(0.0, 1.0, 0.0);

    mpreal expected = 0.5;
    mpreal actual = triangle_area(r1, r2, r3);

    mpreal eps = 1E-20;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                          triangle area (double)                           |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected area   | " << expected                    << string(11, ' ') << "|" << std::endl;
    std::cout << "| actual area     | " << actual                      << string( 5, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(expected - actual) < eps );

}

TEST_CASE("Test tetrahedron_center() function for 'multiprecision' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using mpfr::mpreal;

    using Vec3D = Vector3D<mpreal>;
    const int digits = 50;
    mpreal::set_default_prec(mpfr::digits2bits(digits));

    Vec3D::set_eps(1E-20);
    Vec3D r1(1.0, 0.0, 0.0);
    Vec3D r2(0.0, 1.0, 0.0);
    Vec3D r3(0.0, 0.0, 1.0);
    Vec3D r4(1.0, 1.0, 1.0);

    mpreal eps = 1E-40;
    Vec3D expected(mpreal(1.0)/mpreal(2.0), mpreal(1.0)/mpreal(2.0), mpreal(1.0)/mpreal(2.0));
    Vec3D actual = tetrahedron_center(r1, r2, r3, r4);

#ifdef TEST_DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                  tetrahedron center (multiprecision)                      |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected x      | " << expected.x()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual x        | " << actual.x()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected y      | " << expected.y()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual y        | " << actual.y()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "| expected z      | " << expected.z()                << string( 4, ' ') << "|" << std::endl;
    std::cout << "| actual z        | " << actual.z()                  << string( 4, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // TEST_DEBUG_MESSAGES

    REQUIRE( abs(expected.x() - actual.x()) < eps );
    REQUIRE( abs(expected.y() - actual.y()) < eps );
    REQUIRE( abs(expected.z() - actual.z()) < eps );

}
