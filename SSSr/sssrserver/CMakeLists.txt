cmake_minimum_required(VERSION 3.2)

set(BUILD_VER 1)
set(BUILD_SUBVER 0)
set(BUILD_PATCH 0)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set (BUILD_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(ServerApp VERSION ${BUILD_VER}.${BUILD_SUBVER}.${BUILD_PATCH})

set(SERVERAPP_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(other/sssr)
message(" PROJECT VERSION ===> ${PROJECT_VERSION}")
configure_file(version.h.in include/version.h)

add_subdirectory(src)
# add_subdirectory(test)

# enable_testing()
# add_test(testfull "test/testall")