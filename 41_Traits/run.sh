#!/bin/bash

TARGET="41_Traits"

# Build executable and exit if error occurs
cmake --build build/ --target $TARGET
retValue=$?
if [ $retValue -ne 0 ];  then
	exit 1;
fi

# Update compile commands (cmake command: -DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
compdb -p build/ list > compile_commands.json

# Run
build/$TARGET
