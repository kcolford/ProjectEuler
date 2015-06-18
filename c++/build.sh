#!/bin/bash

set -e

for dir in Debug Release; do
    if [ ! -d $dir ]; then
        mkdir $dir
    fi
    pushd $dir
    rm -rf *
    cmake -DCMAKE_BUILD_TYPE=$dir ..
    popd
done
