cmake_minimum_required(VERSION 3.2.1)
project(ProjectEuler)

# Set some variables
set(CMAKE_MODULE_PATH)
set(LIBRARIES)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(BUILD_SHARED_LIBS ON)

# Enable profiling in the debug build.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg")

# Use cotire to improve build time.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cotire/CMake)
include(cotire)

# We need to record where the .in files are for the programs to use
# them.
set(INFILE_DIRECTORY "${CMAKE_SOURCE_DIR}/../")
include_directories(${INFILE_DIRECTORY})

# Additional warnings...
add_compile_options(
  -Wall
  -Wextra
  -Wno-sign-compare
  )

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the options for OpenMP so that it can be used if desired.
find_package(OpenMP)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OpenMP_CXX_FLAGS}")

# Load in Boost.
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Add in the GMP and GMPXX libraries.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/findgmp/cmake)
find_package(GMP REQUIRED)
include_directories(${GMP_INCLUDE_DIR} ${GMPXX_INCLUDE_DIR})
list(APPEND LIBRARIES ${GMP_LIBRARIES} ${GMPXX_LIBRARIES})

# Setup the C++ JSON library (libjsoncpp.so)
find_package(PythonInterp REQUIRED)
if(PYTHONINTERP_FOUND)
  add_custom_command(OUTPUT jsoncpp.cpp
    COMMAND ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/jsoncpp/amalgamate.py
    -s jsoncpp.cpp 
    -t ${CMAKE_SOURCE_DIR}/jsoncpp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
  add_library(jsoncpp jsoncpp.cpp)
  list(APPEND LIBRARIES jsoncpp)
endif(PYTHONINTERP_FOUND)

# Setup the primes module (a static array of prime numbers).
add_executable(generate_primes generate_primes.cc vector.hh)
add_custom_command(OUTPUT primes.c
  COMMAND generate_primes ${CMAKE_BINARY_DIR}/primes.c
  DEPENDS generate_primes
  )

# The util library.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
include(util)
target_link_libraries(util PUBLIC ${LIBRARIES})
target_compile_options(util PUBLIC
  -Wsuggest-attribute=pure
  -Wsuggest-attribute=const
  -Wsuggest-attribute=noreturn
  )
set_property(TARGET util PROPERTY SOVERSION 1)
set_property(TARGET util PROPERTY VERSION 1)
#cotire(util)

# The util testing harness
include(testing)
add_library(boost_test boost_test.cc)
if(BUILD_SHARED_LIBS)
  target_compile_definitions(boost_test 
    PUBLIC -DBOOST_TEST_DYN_LINK -DTESTING=1
    )
endif()
target_link_libraries(test_util PUBLIC util boost_test)

# Add a ``make check`` command
add_custom_target(check 
  COMMAND test_util
  DEPENDS test_util
  )

# The list of problem source files.
include(problems)

foreach(src ${PROBLEMS})
  string(REGEX MATCH "^[^.]+" bin ${src})
  add_executable(${bin} ${src})
  target_link_libraries(${bin} PUBLIC util)
endforeach()

# Build time grows way too much whith full optimizations on this
# problem.
target_compile_options(22 PRIVATE -O0)

# Set up a configuration file.
configure_file(config.h config.h)
