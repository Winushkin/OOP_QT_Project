cmake_minimum_required(VERSION 3.29)
project(OOP_QT_Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/kirillbelaev/Qt/6.8.0/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OOP_QT_Project main.cpp
        array.cpp
        application.cpp
        complex.h
        complex.cpp
        polynom.h
        polynom.cpp
        interface.cpp
)

target_link_libraries(OOP_QT_Project
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

