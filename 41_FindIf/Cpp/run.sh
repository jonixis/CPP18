#!/bin/bash

TARGET="42_FindIf"

# To setup run the following commands once:
# mkdir build
# cd build
# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
# cd ..

# Build executable and exit if error occurs
# cmake --build build/ --target $TARGET
make -C build/
retValue=$?
if [ $retValue -ne 0 ];  then
	exit 1;
fi

# Update compile commands (install compdb: pip install compdb)
compdb -p build/ list > compile_commands.json

# Run
cd build
./$TARGET
