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