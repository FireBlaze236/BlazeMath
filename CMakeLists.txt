# CMakeList.txt: CMake project for BlazeMath, include source and define
# project specific logic here.
cmake_minimum_required (VERSION 3.8)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://codeload.github.com/google/googletest/tar.gz/refs/tags/v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

include_directories("include")

# Define the project name
set(PROJECT_NAME "BlazeMath")
project(${PROJECT_NAME} VERSION 0.1 DESCRIPTION "Blaze math library")

# Define sources and headers
set(SOURCES 
    "mat.cpp"
    "vec.cpp"
)

set(HEADERS
    "constants.h"
    "mat.h"
    "vec.h"
)

# Add a CMake option to build shared libraries
option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)

# Create the library (either shared or static based on the BUILD_SHARED_LIBS option)
if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()


# Set the library name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Install the library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

##TESTS

enable_testing()

add_executable(
  math_tests
  tests/vec2D_tests.cc
  tests/vec3D_tests.cc
  tests/vec4D_tests.cc
  tests/mat4_tests.cc
)

target_include_directories(
    math_tests
    PRIVATE
    "include"
    )
target_link_libraries(
  math_tests
  GTest::gtest_main
  ${PROJECT_NAME}
)

include(GoogleTest)
gtest_discover_tests(math_tests)
