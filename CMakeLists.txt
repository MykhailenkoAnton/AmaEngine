#general info
cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME FightClubGame)
project(${PROJECT_NAME} VERSION 1.0.0)
message("-------------------------- PROJECT FILES GENERATION for ${PROJECT_NAME} ----------------------------")

#common options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SUPPRESS_REGENERATION ON)

#cpp options
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")

# sources
set(SOURCES 
    Source/main.cpp )

# static 
set(MATH_SOURCES 
    Source/Utils/Math.cpp )
set(MATH_INCLUDES 
    Source/Utils/Math.h )

# dll
set(DLL_GAME_SOURCES     
    Source/Game/Weapon.cpp
    Source/Game/Character.cpp )

    set(DLL_GAME_INCLUDES
    Source/Game/Weapon.h 
    Source/Game/Character.h )

source_group("Source files/Game" FILES "Source/Game/Weapon.cpp" "Source/Game/Character.cpp")
source_group("Header files/Game" FILES "Source/Game/Weapon.h" "Source/Game/Character.h")

# targets
add_executable(${PROJECT_NAME} ${SOURCES})
add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
add_library(${PROJECT_NAME}Lib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})
add_executable(${PROJECT_NAME}TestRunner Source/Tests/main.cpp)

target_compile_definitions(${PROJECT_NAME}Lib PRIVATE _EXPORTING)
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)

option(SKIP_GAME_OPT "Skip game" OFF)
if(SKIP_GAME_OPT)
    target_compile_definitions(${PROJECT_NAME} PUBLIC SKIP_GAME)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib)
target_link_libraries(${PROJECT_NAME}Lib PRIVATE MathLib)
# tests
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE ${PROJECT_NAME}Lib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib)

# includes
set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}TestRunner ${PROJECT_NAME}Lib)
foreach(target IN LISTS TARGETS)    
    target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
    #message("CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} path....")
endforeach()


message("Using ${CMAKE_CXX_COMPILER_ID} compiler")

if(${WIN32})
    message("Rinning on Windows...")
elseif(LINUX)
    message("Rinning on Linux...")
endif()

if(MSVC)
    message("MSVC version: ${MSVC_VERSION}")
    message("MSVC toolset version: ${MSVC_TOOLSET_VERSION}")
    target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
endif()

message("Compiler flags: ${CMAKE_CXX_FLAGS}")
message("Compiler debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message("Compiler release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message("Configuration types: ${CMAKE_CONFIGURATION_TYPES}")
