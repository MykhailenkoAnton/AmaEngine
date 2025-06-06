macro(system_info)
    message("============ SYSTEM INFO ============")
    message("Using ${CMAKE_CXX_COMPILER_ID} compiler")

    if(${WIN32})
        message("Rinning on Windows...")
    elseif(LINUX)
        message("Rinning on Linux...")
    endif()

    if(MSVC)
        message("MSVC version: ${MSVC_VERSION}")
        message("MSVC toolset version: ${MSVC_TOOLSET_VERSION}")
    endif()

    message("Compiler flags: ${CMAKE_CXX_FLAGS}")
    message("Compiler debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
    message("Compiler release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
    message("Configuration types: ${CMAKE_CONFIGURATION_TYPES}")
    message("======================================")
endmacro()

function(setup_precompiled_headers TARGET PCH_SOURCE PCH_HEADER SOURCE_FILES)
if(MSVC)
    target_sources(${TARGET}Lib PRIVATE ${PCH_HEADER} ${PCH_SOURCE})
    set_source_files_properties(${PCH_SOURCE} PROPERTIES COMPILE_FLAGS "/Yc${PCH_HEADER}")
    foreach(SOURCE_FILE ${SOURCE_FILES})
        if(${SOURCE_FILE} MATCHES "\\.cpp$")
            set_source_files_properties(${SOURCE_FILE} PROPERTIES COMPILE_FLAGS "/Yu${PCH_HEADER}")
        endif()
    endforeach()

    target_compile_options(${TARGET}Lib PRIVATE "/FI${PCH_HEADER}")
endif()
endfunction()

macro(setup_conan HOST_PROFILE BUILD_PROFILE)
    set(CMAKE_CONAN_PATH "${CMAKE_BINARY_DIR}/conan_provider.cmake")
    if(NOT EXISTS ${CMAKE_CONAN_PATH})
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/refs/heads/develop2/conan_provider.cmake" ${CMAKE_CONAN_PATH})
    endif()

    set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_CONAN_PATH})
    set(CONAN_HOST_PROFILE "${HOST_PROFILE}")
    set(CONAN_BUILD_PROFILE "${BUILD_PROFILE}")

endmacro()