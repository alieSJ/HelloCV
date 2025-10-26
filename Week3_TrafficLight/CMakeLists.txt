cmake_minimum_required(VERSION 4.1.2)
project(TrafficLight CXX)
add_executable(TrafficLight practice_week3.cpp)
set(CMAKE_CXX_STANDARD 11)
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/opencvtest)
set(OUTPUT_DIR "$<TARGET_FILE_DIR:TrafficLight>/resources")

add_custom_command(TARGET TrafficLight POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:TrafficLight>/resources"
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            "${RESOURCE_DIR}"
            "$<TARGET_FILE_DIR:TrafficLight>/resources"
    COMMENT "Copying resources -> $<TARGET_FILE_DIR:TrafficLight>/resources"
)

find_package(OpenCV REQUIRED)
target_include_directories(TrafficLight PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(TrafficLight ${OpenCV_LIBS})
