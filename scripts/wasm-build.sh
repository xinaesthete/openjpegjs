#!/bin/sh
# rm -rf build
mkdir -p build
#(cd build && emconfigure cmake -DCMAKE_BUILD_TYPE=Debug ..) &&
# enabling simd has no effort as of Oct 9, 2021. 
# very marginal difference, but seems slightly faster July 30, 2025
# these flags are set in the CMakeLists.txt file now
#(cd build && emcmake cmake -DCMAKE_C_FLAGS="-msimd128"  ..) &&
(cd build && emcmake cmake ..) &&
(cd build && emmake make VERBOSE=1 -j) &&
cp ./build/extern/openjpeg/bin/openjpegjs.js ./dist &&
cp ./build/extern/openjpeg/bin/openjpegjs.wasm ./dist &&
cp ./build/extern/openjpeg/bin/openjpegjs.d.ts ./dist &&
(cd test/node; npm run test)
