cmake_minimum_required(VERSION 3.0.0)
#include(GenerateExportHeader)

project(DH)



set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
find_package( Qt5Widgets )

include_directories(
   src
   ${Qt5Core_INCLUDE_DIRS}
)
add_subdirectory(src/vendor)

add_definitions(${Qt5Core_DEFINITIONS})


file(GLOB ROBOT src/robot/*.cpp src/extras/*.cpp)
#add_definitions(${Qt5Core_DEFINITIONS})
add_executable(dh src/DH.cc ${ROBOT})
target_link_libraries( dh  ${Qt5Widgets_LIBRARIES})
target_link_libraries(dh tinyxml)