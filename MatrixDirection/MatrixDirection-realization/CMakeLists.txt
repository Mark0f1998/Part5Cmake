cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE MatrixDirection)
set(COMPONENT realization)
project(${NAMESPACE}-${COMPONENT})

add_library(${PROJECT_NAME} src/displacement.cpp)
add_library(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)