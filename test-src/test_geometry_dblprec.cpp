//
// Created by Lesleis Nagy on 26/07/2022.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <iostream>

#include "vector3d.hpp"
#include "geometry.hpp"

TEST_CASE("Test edge_length() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D u(1.0, 2.0, 3.0);
    Vec3D v(4.0, 5.0, 6.0);

    double eps = 1E-14;
    double expected = sqrt(27.0);
    double actual_d1 = edge_length(u, v);
    double actual_d2 = edge_length(v, u);

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                            edge length (double)                           |" << std::endl;
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "| variable        | value                                                   |" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
    std::cout << "| expected        | " << expected                    << string(11, ' ') << "|" << std::endl;
    std::cout << "| actual d1       | " << actual_d1                   << string( 5, ' ') << "|" << std::endl;
    std::cout << "| actual d2       | " << actual_d2                   << string( 5, ' ') << "|" << std::endl;
    std::cout << "| reg-eps         | " << Vec3D::eps()                << string( 1, ' ') << "|" << std::endl;
    std::cout << "| reg-eps squared | " << Vec3D::eps_squared()        << string( 1, ' ') << "|" << std::endl;
    std::cout << "+-----------------+---------------------------------------------------------+" << std::endl;
#endif // DEBUG_MESSAGES

    REQUIRE(fabs(actual_d1 - expected) < eps );
    REQUIRE(fabs(actual_d2 - expected) < eps );

}

TEST_CASE("Test edge_center() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D r1(1.0, 2.0, 3.0);
    Vec3D r2(4.0, 5.0, 6.0);

    Vec3D expected(5.0/2.0, 7.0/2.0, 9.0/2.0);
    Vec3D actual = edge_center(r1, r2);

    double eps = 1E-14;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                            edge center (double)                           |" << std::endl;
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
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(expected.x() - actual.x()) < eps );
    REQUIRE( fabs(expected.y() - actual.y()) < eps );
    REQUIRE( fabs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test edge_orientation() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D r1(1.0, 2.0, 3.0);
    Vec3D r2(4.0, 5.0, 6.0);

    Vec3D expected(3.0/sqrt(27.0), 3.0/sqrt(27.0), 3.0/sqrt(27.0));
    Vec3D actual = edge_orientation(r1, r2);

    double eps = 1E-14;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                         edge orientation (double)                         |" << std::endl;
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
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(expected.x() - actual.x()) < eps );
    REQUIRE( fabs(expected.y() - actual.y()) < eps );
    REQUIRE( fabs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_normal() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D r1(1.0, 0.0, 0.0);
    Vec3D r2(0.0, 1.0, 0.0);
    Vec3D r3(0.0, 0.0, 1.0);

    Vec3D expected(1.0/sqrt(3), 1.0/sqrt(3.0), 1.0/sqrt(3.0));
    Vec3D actual = triangle_normal(r1, r2, r3);

    double eps = 1E-14;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                         triangle normal (double)                          |" << std::endl;
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
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(expected.x() - actual.x()) < eps );
    REQUIRE( fabs(expected.y() - actual.y()) < eps );
    REQUIRE( fabs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_center() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D r1(1.0, 0.0, 0.0);
    Vec3D r2(0.0, 1.0, 0.0);
    Vec3D r3(0.0, 0.0, 1.0);

    Vec3D expected(1.0/3.0, 1.0/3.0, 1.0/3.0);
    Vec3D actual = triangle_center(r1, r2, r3);

    double eps = 1E-14;

#ifdef DEBUG_MESSAGES
    std::cout.precision(50);
    std::cout << "+---------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                         triangle center (double)                          |" << std::endl;
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
#endif // DEBUG_MESSAGES

    REQUIRE( fabs(expected.x() - actual.x()) < eps );
    REQUIRE( fabs(expected.y() - actual.y()) < eps );
    REQUIRE( fabs(expected.z() - actual.z()) < eps );

}

TEST_CASE("Test triangle_area() function for 'double' type.", "Vector3D geometry") {

    using namespace org::lesleisnagy::geomlib;

    using std::string;
    using Vec3D = Vector3D<double>;

    Vec3D::set_eps(1E-7);
    Vec3D r1(0.0, 0.0, 0.0);
    Vec3D r2(1.0, 0.0, 0.0);
    Vec3D r3(0.0, 1.0, 0.0);

    double expected = 0.5;
    double actual = triangle_area(r1, r2, r3);

    double eps = 1E-14;

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