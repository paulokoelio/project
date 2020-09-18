cmake_minimum_required(VERSION 3.2)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)

add_library(SSSr 
                sssr_version.cpp                    
                sssr.cpp 
                ssserver.cpp
                    
            )

set_target_properties(SSSr PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)
message(" CMAKE_CXX_FLAGS ===> ${CMAKE_CXX_COMPILER} / ${CMAKE_CXX_FLAGS} / ${COMPILE_FLAGS}")

target_include_directories(SSSr PUBLIC ${PROJECT_SOURCE_DIR}/headers
                                        "${CMAKE_BINARY_DIR}/headers"
                                        "/usr/include/c++/8/"
                                        ${PROJECT_SOURCE_DIR}/solver
                                PRIVATE ${Boost_INCLUDE_DIRS}        
                            )

target_link_libraries( SSSr PRIVATE stdc++fs solver_lib 
                        Boost::system 
                        )

message(" CMAKE_CXX_FLAGS ===> ${CMAKE_CXX_COMPILER} / ${CMAKE_CXX_FLAGS} / ${COMPILE_FLAGS}")


if (MSVC)
    target_compile_options(SSSr PRIVATE
        /W4
    )
else ()
    target_compile_options(SSSr PRIVATE
        -Wall -Wextra -pedantic -Werror 
        # -std=c++17
    )
endif()

