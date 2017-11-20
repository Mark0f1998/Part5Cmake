cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE MatrixDirection)
set(COMPONENT general)
project(${NAMESPACE}-${COMPONENT})

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

find_package(MatrixDirection-realization)
target_link_libraries(${PROJECT_NAME} PRIVATE MatrixDirection::realization)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)