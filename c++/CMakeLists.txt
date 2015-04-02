cmake_minimum_required(VERSION 3.0.0)
project(ProjectEuler)

set(CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/cotire/CMake
  ${CMAKE_SOURCE_DIR}/findgmp/cmake
  )

include(cotire)

set(BUILD_SHARED_LIBS ON)

set(INFILE_DIRECTORY "${CMAKE_SOURCE_DIR}/../")

add_compile_options(
  -Wall
  -Wextra
  -Wsuggest-attribute=pure
  -Wsuggest-attribute=const
  -Wsuggest-attribute=noreturn
  -Wno-sign-compare
  )

find_package(OpenMP)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OpenMP_CXX_FLAGS}")

find_package(Boost REQUIRED)

message(${CMAKE_MODULE_PATH})
find_package(GMP REQUIRED)

find_package(PythonInterp REQUIRED)
if(PYTHONINTERP_FOUND)
  set(JSONCPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/dist)
  add_custom_command(OUTPUT jsoncpp.cpp
    COMMAND ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/amalgamate.py
    -s jsoncpp.cpp
    -t ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
  set(JSON_LIB jsoncpp)
  add_library(${JSON_LIB} jsoncpp.cpp)
  target_include_directories(jsoncpp PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
endif(PYTHONINTERP_FOUND)

add_executable(generate_primes generate_primes.cc vector.hh)
add_custom_command(OUTPUT primes.c
  COMMAND generate_primes ${CMAKE_CURRENT_BINARY_DIR}/primes.c
  DEPENDS generate_primes
  )

add_library(util SHARED
  attributes.h
  cast.hh
  digit_breakdown.cc
  digit_breakdown.hh
  digit_iterator.hh
  error_check.hh
  factoring.cc
  has_member.hh
  iterator_compare.hh
  len.h
  limiter.cc
  limiter.hh
  palindrome.hh
  primes.c
  primes.h
  primes.hh
  product.hh
  radixsort.cc
  radixsort.hh
  sum.hh
  util.cc
  util.hh
  vector.hh
  )
target_include_directories(util
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PUBLIC ${Boost_INCLUDE_DIRS}
  )
target_link_libraries(util
  PUBLIC ${GMP} ${JSON_LIB} ${Boost_LIBRARIES}
  )

set(PROBLEMS
  1.cc
  2.cc
  3.cc
  4.cc
  5.cc 
  6.cc
  7.cc 
  8.cc 
  9.cc 
  10.cc
  11.cc
  12.cc 
  13.cc 
  14.cc 
  15.cc 
  16.cc 
  17.cc 
  42.cc
  44.cc
  45.cc
  47.cc
  49.cc
  50.cc
  54.cc
  55.cc
  56.cc
  57.cc
  59.cc
  81.cc
  )

set(LIBUTIL util)
if(CMAKE_HOST_UNIX)
  set(LINKED_UTIL ON)
  add_custom_target(symlink ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink libutil.so libutil_link.so
    DEPENDS util
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
  set(LIBUTIL -L. -Wl,-rpath,. util_link)
endif()

foreach(src ${PROBLEMS})
  string(REGEX MATCH "^[^.]+" bin ${src})
  add_executable(${bin} ${src})
  if(LINKED_UTIL)
    add_dependencies(${bin} symlink)
  endif(LINKED_UTIL)
  target_include_directories(${bin}
    PUBLIC ${INFILE_DIRECTORY}
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${GMP_INCLUDE_DIR} ${GMPXX_INCLUDE_DIR}
    )
  target_link_libraries(${bin}
    ${LIBUTIL}
    ${GMP_LIBRARIES} ${GMPXX_LIBRARIES}
    m
    )
endforeach()

target_link_libraries(17 ${JSON_LIB})

configure_file(config.h config.h)

