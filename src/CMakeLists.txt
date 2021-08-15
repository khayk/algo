file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES false *.h *.cpp)

add_library(${projectLib} STATIC ${SOURCE_FILES})