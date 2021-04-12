cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(jnilibs "${CMAKE_SOURCE_DIR}/../jniLibs")
message(${jnilibs})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${jnilibs}/${ANDROID_ABI})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -pthread -DMGULK_LOG_STDERR=1 -Wall -Wextra -Wnon-virtual-dtor -Wno-unused-command-line-argument -Wl")

include_directories(${CMAKE_SOURCE_DIR}/libcommon)
include_directories(${CMAKE_SOURCE_DIR}/camera_preview)

#ADD_SUBDIRECTORY(libcommon)
#ADD_SUBDIRECTORY(camera_preview)

include_directories(${CMAKE_SOURCE_DIR}/)


add_library(songstudio
            SHARED
            ChangbaRecordingPreviewScheduler.cpp)

add_library(ccommon STATIC IMPORTED )
set_target_properties(ccommon PROPERTIES
        IMPORTED_LOCATION "${jnilibs}/${ANDROID_ABI}/libcommontool.a")

add_library(cpreview STATIC IMPORTED )
set_target_properties(cpreview PROPERTIES
    IMPORTED_LOCATION "${jnilibs}/${ANDROID_ABI}/libcamerapreview.a")



find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries(songstudio
        -Wl,--start-group
        android
        log
        z
        EGL
        GLESv2
#        cpreview
#        ccommon
        ccommon
        cpreview
        -Wl,--end-group
        )