cmake_minimum_required(VERSION 3.4.1)
set(jnilibs "${CMAKE_SOURCE_DIR}/../../jniLibs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${jnilibs}/${ANDROID_ABI})

aux_source_directory(${CMAKE_SOURCE_DIR}/message_queue MESSAGE_QUEUE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/egl_core EGL_CORE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/opensl_media OPENSL_ES_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/opengl_media OPENGL_ES_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/opengl_media/texture OPENGL_ES_FILES_TEXTURE)
aux_source_directory(${CMAKE_SOURCE_DIR}/opengl_media/texture_copier OPENGL_ES_FILES_TEXTURE_COPIER)
aux_source_directory(${CMAKE_SOURCE_DIR}/opengl_media/render OPENGL_ES_FILES_RENDER)

include_directories(${CMAKE_SOURCE_DIR}/)
include_directories(${CMAKE_SOURCE_DIR}/egl_core/)
include_directories(${CMAKE_SOURCE_DIR}/message_queue/)
include_directories(${CMAKE_SOURCE_DIR}/opengl_media/)
include_directories(${CMAKE_SOURCE_DIR}/opensl_media/)
include_directories(${CMAKE_SOURCE_DIR}/opengl_media/texture)
include_directories(${CMAKE_SOURCE_DIR}/opengl_media/texture_copier)
include_directories(${CMAKE_SOURCE_DIR}/opengl_media/render)


add_library(commontool
             STATIC
             matrix.cpp
             thread.cpp
             ${MESSAGE_QUEUE_FILES}
             ${EGL_CORE_FILES}
             ${OPENSL_ES_FILES}
             ${OPENGL_ES_FILES}
             ${OPENGL_ES_FILES_TEXTURE}
             ${OPENGL_ES_FILES_TEXTURE_COPIER}
             ${OPENGL_ES_FILES_RENDER}
             )

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )


target_link_libraries(commontool
        log
        GLESv2
        z
        OpenSLES
        android
        EGL)



