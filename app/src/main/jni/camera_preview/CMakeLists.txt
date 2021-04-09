cmake_minimum_required(VERSION 3.4)

include_directories(${CMAKE_SOURCE_DIR}/../libcommon/)
include_directories(${CMAKE_SOURCE_DIR}/)

message("${jnilibs}/${ANDROID_ABI}/libcommontool.a")
add_library(common STATIC IMPORTED )
set_target_properties(common PROPERTIES
    IMPORTED_LOCATION "${jnilibs}/${ANDROID_ABI}/libcommontool.a")

find_library(log-lib log )


add_library(camerapreview
            STATIC
            recording_preview_renderer.cpp
            mv_recording_preview_controller.cpp )


target_link_libraries(camerapreview log common)


