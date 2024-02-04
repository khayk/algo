cmake_minimum_required(VERSION 3.15)

project(algo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

if(MSVC)
   add_compile_options(/W4 /WX /MP)
   add_compile_definitions(_WIN32_WINNT=0x0A00)
else()
   add_compile_options(-Wall -Wextra -Wpedantic -Wno-undefined-var-template)
endif()

# Diagnostic information
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(src)

set(projectLib ${CMAKE_PROJECT_NAME}-lib)
set(projectTest ${CMAKE_PROJECT_NAME}-test)

add_subdirectory(src bin)
add_subdirectory(test)
