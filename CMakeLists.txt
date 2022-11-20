cmake_minimum_required(VERSION 3.14.0)
project(Graduation_Project_GUI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_PREFIX_PATH ~/Qt5.12.12/5.12.12/gcc_64/lib/cmake)
#set(CMAKE_PREFIX_PATH C:/Qt/Qt5.12.12/5.12.12/mingw73_64/lib/cmake)

find_package(Qt5 REQUIRED COMPONENTS Widgets VirtualKeyboard Sql)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB QT_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
set (UI_FILE
    mainwindow.ui
    door.ui
    floor1.ui
    fire_alarm.ui
    password_panel.ui
    add_account.ui
)


file(GLOB THEME_QRC ${CMAKE_CURRENT_SOURCE_DIR}/third_parties/QDarkStyleSheet/qdarkstyle/dark/darkstyle.qrc)

file(GLOB IMAGE_QRC ${CMAKE_CURRENT_SOURCE_DIR}/images.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${THEME_QRC} ${IMAGE_QRC} ${UI_FILE} ${QT_HEADER} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBqRARIES} pthread Qt5::Widgets Qt5::VirtualKeyboard Qt5::Sql mosquitto)



