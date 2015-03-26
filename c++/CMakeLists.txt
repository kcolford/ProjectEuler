cmake_minimum_required(VERSION 3.0.0)
project(ProjectEuler)

set(BUILD_SHARED_LIBS ON)

set(INFILE_DIRECTORY "${CMAKE_SOURCE_DIR}/../")

find_package(OpenMP)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OpenMP_CXX_FLAGS}")

add_executable(generate_primes generate_primes.cc)
add_custom_command(OUTPUT primes.c
  COMMAND generate_primes ${CMAKE_CURRENT_BINARY_DIR}/primes.c
  DEPENDS generate_primes
  )

add_library(util SHARED
  attributes.h
  digit_breakdown.cc
  digit_breakdown.hh
  digit_iterator.hh
  error_check.hh
  factoring.cc
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
  add_custom_target(symlink ALL
    COMMAND ln -sf libutil.so libutil_link.so
    DEPENDS util
    WORKING_DIRECTORY .
    )
  set(LIBUTIL -L. -Wl,-rpath,. util_link)
endif()

foreach(src ${PROBLEMS})
  string(REGEX MATCH "^[^.]+" bin ${src})
  add_executable(${bin} ${src})
  add_dependencies(${bin} symlink)
  target_include_directories(${bin}
    PUBLIC ${INFILE_DIRECTORY}
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )
  target_link_libraries(${bin}
    ${LIBUTIL}
    gmpxx
    gmp
    m
    )
endforeach()

configure_file(config.h.in config.h)

