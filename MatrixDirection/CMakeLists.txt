cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(MatrixDirection)

set(SUBPROJECTS
    ${PROJECT_NAME}-realization
    ${PROJECT_NAME}-general
    ${PROJECT_NAME}-test
   )

macro(find_package)
    if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
        _find_package(${ARGV})
    endif()
endmacro()

foreach(subproj IN LISTS SUBPROJECTS)
    add_subdirectory(${subproj})
endforeach()