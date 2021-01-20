cmake_minimum_required(VERSION 3.17)
project(CopenGL)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_package(OpenGL REQUIRED)
#find_package(Threads)
#find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} $ENV{CMAKE_PREFIX_PATH}/mingw32/include)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(CopenGL main.cpp ${SOURCE_FILES})

target_link_libraries(CopenGL ${OPENGL_LIBRARIES} -lOpenGL32 -lfreeGLUT)