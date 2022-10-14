#!/bin/bash
if [ -z "$1" ]
then
      echo "Error: no file path as arg run like $0 your_cpp_file.cpp" 1>&2;
      exit 1
fi

if [[ ! -f "$1" ]]
then
    echo "Error:'$1' file is not found in your system"
    exit 2
fi

if [ "$1" == "*.cpp" ]
then
    echo "Error:'$1' file is not a cpp file type"
    exit 3
fi

tmp=$1
FILE=${tmp##*/}
BUILD_PATH=`echo "./bin/${FILE%.*}.out"`

g++ ./data_structure/test/s1/test.cpp -L/usr/lib/ -lgtest -lgtest_main -pthread -o $BUILD_PATH && $BUILD_PATH
