# Example test.

#####################################################################################################################
# Double precision tests.                                                                                           #
#####################################################################################################################

add_executable(test_vector3d_dblprec test_vector3d_dblprec.cpp)
target_include_directories(test_vector3d_dblprec
        PRIVATE ${LIBFABBRI_INCLUDE_DIR}
                ${CATCH_INCLUDE_DIR})
add_test(NAME test_vector3d_dblprec COMMAND test_vector3d_dblprec)


add_executable(test_geometry_dblprec test_geometry_dblprec.cpp)
target_include_directories(test_geometry_dblprec
        PRIVATE ${LIBFABBRI_INCLUDE_DIR}
                ${CATCH_INCLUDE_DIR})
add_test(NAME test_geometry_dblprec COMMAND test_geometry_dblprec)

#####################################################################################################################
# Multiprecision precision tests.                                                                                   #
#####################################################################################################################
if (MULTIPRECISION)

    add_executable(test_vector3d_multiprec test_vector3d_multiprec.cpp)
    target_include_directories(test_vector3d_multiprec
            PRIVATE ${LIBFABBRI_INCLUDE_DIR}
                    ${MPFR_INCLUDES}
                    ${CATCH_INCLUDE_DIR}
                    ${MPREAL_INCLUDE_DIR})
    target_link_libraries(test_vector3d_multiprec
            ${MPFR_LIBRARIES})
    add_test(NAME test_vector3d_multiprec COMMAND test_vector3d_multiprec )

    add_executable(test_geometry_multiprec test_geometry_multiprec.cpp)
    target_include_directories(test_geometry_multiprec
            PRIVATE ${LIBFABBRI_INCLUDE_DIR}
            ${MPFR_INCLUDES}
            ${CATCH_INCLUDE_DIR}
            ${MPREAL_INCLUDE_DIR})
    target_link_libraries(test_geometry_multiprec
            ${MPFR_LIBRARIES})
    add_test(NAME test_geometry_multiprec COMMAND test_geometry_multiprec)

endif()
