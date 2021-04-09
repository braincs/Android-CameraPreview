#!/bin/bash
mkdir -p build
cd build
cmake -B . -GNinja -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK_HOME}/build/cmake/android.toolchain.cmake \
	-DANDROID_NDK=${ANDROID_NDK_HOME} \
	-DANDROID_ABI=arm64-v8a \
	-DANDROID_TOOLCHAIN=clang \
	-DANDROID_PLATFORM=android-26 \
	-DANDROID_STL=c++_static\
	-DCMAKE_BUILD_TYPE=Release\
	-D__ARM_NEON__=1\
	-DANDROID_ARM_NEON=1\
	..

ninja -d explain

cd ..
cp build/libcamerapreview.a ../../jniLibs/arm64-v8a/