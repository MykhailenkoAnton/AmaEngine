set(PROJECT_NAME MathLib)

set(MATH_SOURCES 
    Math.cpp )
set(MATH_INCLUDES 
    Math.h )

add_library(${PROJECT_NAME} STATIC ${MATH_SOURCES} ${MATH_INCLUDES})