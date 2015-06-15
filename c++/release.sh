#!/bin/bash

build_name="Release"
cmake_command="cmake "
cmake_command+="-DCMAKE_BUILD_TYPE=$build_name "

if [ -d $build_name ]; then
    rm -rf $build_name
fi
mkdir $build_name
cd $build_name
$cmake_command ..
