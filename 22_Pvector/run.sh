#!/bin/bash

TARGET="22_Pvector"

# To setup run once:
# mkdir build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

# Build executable and exit if error occurs
cmake --build build/ --target $TARGET
retValue=$?
if [ $retValue -ne 0 ];  then
	exit 1;
fi

# Update compile commands (install compdb: pip install compdb)
compdb -p build/ list > compile_commands.json

# Run
build/$TARGET