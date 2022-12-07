project(RpiSerial)
cmake_minimum_required(VERSION 3.16)

add_executable(RpiSerial ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_include_directories(RpiSerial PRIVATE ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(RpiSerial glog pigpio)

install(TARGETS RpiSerial
        DESTINATION bin)
