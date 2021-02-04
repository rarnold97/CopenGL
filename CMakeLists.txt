cmake_minimum_required(VERSION 3.17)
project(CopenGL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_package(Threads REQUIRED)


#find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(Threads)
#find_package(GLUT REQUIRED)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(CMAKE_PREFIX_PATH "C:/tools/glew-2.2.0")
set(CMAKE_LIBRARY_PATH "C:/tools/glew-2.2.0/lib/Release/x64")

add_subdirectory(glfw-3.3.2)
find_package(GLEW REQUIRED)


set(CMAKE_PREFIX_PATH "C:/tools/qt5/5.12.10/winrt_x64_msvc2017/bin")
set(QT_QPA_PLATFORM_PLUGIN_PATH "C:/tools/qt5/5.12.10/winrt_x64_msvc2017/plugins/platforms")
set(QT_PLUGIN_PATH "C:/tools/qt5/5.12.10/winrt_x64_msvc2017/plugins")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_VERSION 5)

#set(CMAKE_LIBRARY_PATH "freeglut")
#add_subdirectory(freeglut)

#using glad instead now
add_library(GLAD "glad/src/glad.c")

include_directories(${OPENGL_INCLUDE_DIR} C:/tools/mingw32/include helper_files glad/include)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

# to design qt uis in app designer
# set(FORMS <ui files>)
# set(GUI_HEADERS <headers with qt ui shit in them>)
# QT5_WRAP_CPP(QT_HEADERS ${GUI_HEADERS})
# QT5_WRAP_UI(FORMS_HEADERS ${FORMS})
# add_library(qtlib ${QT_HEADERS} ${FORMS_HEADERS})
set(LIBS glfw opengl32 GLAD)

add_executable(CopenGL main.cpp ${SOURCE_FILES} helper_files/common_drawing.h helper_files/common_drawing.cpp helper_files/LoadShaders.h common/MeGlWindow.h common/MeGlWindow.cpp)

target_link_libraries(CopenGL Threads::Threads Qt5::WinMain Qt5::Widgets Qt5::Core Qt5::Gui ${LIBS} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})