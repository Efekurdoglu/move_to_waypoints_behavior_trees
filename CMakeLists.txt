cmake_minimum_required(VERSION 3.5)
project(move_to_waypoints VERSION 1.0.0)
project(move_to_waypoints LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp_v3)

set(NAME "Efe Kurdoglu")
message("This project has been created by ${NAME}.")

add_library(libraries
            src/at_waypoint.cpp
            src/move_waypoint.cpp
            src/system_status.cpp
            src/Behaivor_Engine.cpp
            src/file.cpp)

add_executable(main
            src/main.cpp)
            
target_include_directories(libraries PUBLIC include)
target_link_libraries(main PUBLIC libraries -ljsoncpp)
target_link_libraries(libraries PUBLIC BT::behaviortree_cpp_v3)
