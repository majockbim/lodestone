cmake_minimum_required(VERSION 3.10)
project(lodestone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(lodestone 
    main.cpp
)

target_include_directories(lodestone PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)
