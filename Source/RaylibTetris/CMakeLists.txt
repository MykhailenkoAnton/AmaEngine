set(PROJECT_NAME RaylibTetris)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)