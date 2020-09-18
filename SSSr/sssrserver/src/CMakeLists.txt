cmake_minimum_required(VERSION 3.2)

add_executable(ssserver 
                main.cpp 
                version.cpp 
                serverapp.cpp
                )

set_target_properties(ssserver PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ssserver PRIVATE 
                            ${PROJECT_SOURCE_DIR}/include
                            "${CMAKE_BINARY_DIR}/include"
                            "/usr/include/c++/8/"
                            ${SSSr_LIB_DIR}
)

target_link_libraries( ssserver PRIVATE stdc++fs SSSr)

if (MSVC)
    target_compile_options(ssserver PRIVATE
        /W4
    )
else ()
    target_compile_options(ssserver PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS ssserver RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT solverdce@gmail.com)

include(CPack)

