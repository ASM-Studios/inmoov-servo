#!/bin/bash

BUILD_FOLDER=cmake-build-debug
PRESET=$1

if [ -z $PRESET ]; then
    PRESET=rp2040
fi
if [ ! -d $BUILD_FOLDER ]; then
    mkdir $BUILD_FOLDER
fi

cd $BUILD_FOLDER || exit
cmake --preset=$PRESET ..
cmake --build .
