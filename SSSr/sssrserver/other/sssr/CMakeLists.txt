cmake_minimum_required(VERSION 3.2)

set(SSSR_BUILD_VER 0)
set(SSSR_BUILD_SUBVER 0)
set(SSSR_BUILD_PATCH 1)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set (SSSR_BUILD_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(SSSr VERSION ${SSSR_BUILD_VER}.${SSSR_BUILD_SUBVER}.${SSSR_BUILD_PATCH})
set(SSSR_PROJECT_VERSION ${PROJECT_VERSION})

set(SSSr_LIB_DIR   
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                ${CMAKE_CURRENT_SOURCE_DIR}/headers
    )
message(" SSSr_LIB_DIR ===> ${SSSr_LIB_DIR}")
add_subdirectory(solver)
message(" PROJECT VERSION ===> ${PROJECT_VERSION}")
configure_file(sssr_version.h.in ${CMAKE_BINARY_DIR}/headers/sssr_version.h)

add_subdirectory(src)

