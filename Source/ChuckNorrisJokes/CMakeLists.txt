set(PROJECT_NAME ChuckNorrisJokes)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
#target_link_libraries(${PROJECT_NAME} #[===[cpr::cpr]===])
target_link_libraries(${PROJECT_NAME} raylib)