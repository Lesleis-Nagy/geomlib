cmake_minimum_required(VERSION 3.22)
project(geomlib)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(GEOMLIB_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(GEOMLIB_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(GEOMLIB_THIRD_PARTY_DIR "${CMAKE_SOURCE_DIR}/third-party")
set(GEOMLIB_TEST_SRC_DIR "${CMAKE_SOURCE_DIR}/test-src")

include_directories(${GEOMLIB_INCLUDE_DIR})

if (${MULTIPRECISION})

    message(STATUS "Building a multiprecision version of merrill2.")
    set(MULTIPRECISION On)

    # Try to load the multiprecision library.
    find_package(MPFR REQUIRED)

    # Print some messages.
    message(STATUS "Found MPFR, details follow ...")
    message(STATUS "MPFR_INCLUDES: ${MPFR_INCLUDES}")
    message(STATUS "MPFR_LIBRARIES: ${MPFR_LIBRARIES}")
    message(STATUS "MPFR_VERSION: ${MPFR_VERSION}")

    # Add mpreal.
    set(MPREAL_INCLUDE_DIR "${GEOMLIB_THIRD_PARTY_DIR}/mpfrcpp-v3.6.9/include")
    message(STATUS "MPREAL_INCLUDE_DIR: ${MPREAL_INCLUDE_DIR}")

    include_directories(${MPFR_INCLUDES})
    include_directories(${MPREAL_INCLUDE_DIR})

    add_compile_definitions(WITH_MULTIPRECISION=1)

endif()

if (${DEBUG_MESSAGES})

    message(STATUS "Building with debug messages enabled.")
    add_compile_definitions(DEBUG_MESSAGES=1)

endif()

if (${TESTS})

    message(STATUS "Building tests.")

    enable_testing()

    set(GEOMLIB_TEST_SRC_DIR "${CMAKE_SOURCE_DIR}/test-src")
    set(GEOMLIB_TEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR/test-include}")
    set(CATCH_INCLUDE_DIR "${GEOMLIB_THIRD_PARTY_DIR}/catch2-v2.13.9/include")

    include_directories(${CATCH_INCLUDE_DIR})

    add_subdirectory(${GEOMLIB_TEST_SRC_DIR})

endif()

if (${DOCUMENTATION})

    message(STATUS "Building documentation.")

    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/doc/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

        add_custom_target(doc_doxygen ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen."
                VERBATIM)
    else()
        message("Doxygen not found.")
    endif()

endif()
