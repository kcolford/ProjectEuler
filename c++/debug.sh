#!/bin/bash

debugging_flags="-ggdb3"
cmake_command="cmake "
cmake_command+="-DCMAKE_BUILD_TYPE=Debug "
cmake_command+="-DCMAKE_C_FLAGS_DEBUG=$debugging_flags "
cmake_command+="-DCMAKE_CXX_FLAGS_DEBUG=$debugging_flags "

if [ -d Debug ]; then
    rm -rf Debug
fi
mkdir Debug
cd Debug
$cmake_command ..
