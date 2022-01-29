file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES false *.h *.cpp)

include(../cmake/filters.cmake)

add_library(${projectLib} STATIC ${SOURCE_FILES})