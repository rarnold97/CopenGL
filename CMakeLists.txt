# STANDARD CMAKE DIRECTIVES
cmake_minimum_required(VERSION 3.17)
project(CopenGL)
add_definitions(-D__STDC_LIMIT_MACROS)
add_definitions(-D__STDC_CONSTANT_MACROS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#FIND SYSTEM PACKAGES
find_package(Threads REQUIRED)
#find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

#FIND GLEW
#set(CMAKE_PREFIX_PATH "C:/tools/glew-2.2.0/lib/Release/x64")
set(CMAKE_PREFIX_PATH "middleware/glew-2.2.0/lib/Release/x64")
find_library(GLEW_LIB glew32.lib REQUIRED)
#set(GLEW_INCLUDE "C:/tools/glew-2.2.0/include/")
set(GLEW_INCLUDE "middleware/glew-2.2.0/include/")


add_subdirectory(middleware/glfw-3.3.2)

# FIND QT LIBRARIES
find_package(Qt5 COMPONENTS Widgets Core Gui OpenGL REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_VERSION 5)


# GLAD LIBRARIES
add_library(GLAD "middleware/glad/src/glad.c")

#INCLUDE DIRECTORIES
#mingw build
#include_directories(${OPENGL_INCLUDE_DIR} C:/tools/mingw32/include helper_files glad/include)
#VS build
include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLEW_INCLUDE}
        helper_files
        middleware/glad/include )

#AUTO INCLUDE SCRIPTS
file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

#APP DESIGNER STUFF
# to design qt uis in app designer
# set(FORMS <ui files>)
# set(GUI_HEADERS <headers with qt ui shit in them>)
# QT5_WRAP_CPP(QT_HEADERS ${GUI_HEADERS})
# QT5_WRAP_UI(FORMS_HEADERS ${FORMS})
# add_library(qtlib ${QT_HEADERS} ${FORMS_HEADERS})

#CUSTOM LIBS AND SYSTEM LIBS
set(LIBS glfw opengl32 GLAD)

# COMPILE
add_executable(CopenGL
        main.cpp
        ${SOURCE_FILES}
        helper_files/common_drawing.h
        helper_files/common_drawing.cpp
        helper_files/LoadShaders.h
        common/MeGlWindow.h
        common/MeGlWindow.cpp)

qt5_use_modules(CopenGL Widgets OpenGL Gui Core)
# LINK BABY AND ALSO FUCK YOURSELF WHILE YOU ARE AT IT THESE ARE THE WORST ERRORS ON PLANET EARTH
target_link_libraries(CopenGL
        ${GLEW_LIB}
        Threads::Threads
        Qt5::WinMain Qt5::Widgets Qt5::Core Qt5::Gui
        ${LIBS}
        ${OPENGL_LIBRARIES}
        ${GLFW_LIBRARIES} )