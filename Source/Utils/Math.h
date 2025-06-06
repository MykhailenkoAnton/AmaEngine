#pragma once
#include <vector>

// clang-format off
#if defined(WIN32) || defined(WINDOWS)
    #ifdef _EXPORTING
        #define MATH_API __declspec(dllexport)
    #elif _IMPORTING
        #define MATH_API __declspec(dllimport)
    #else
        #define MATH_API
    #endif
#else
    #define MATH_API __attribute__ ((visibility ("default")))
#endif
// clang-format on

namespace LifeEXEsimpoe
{

MATH_API int max(int x, int y);
MATH_API int factorial(int n);
MATH_API int sum(int n);
MATH_API int randomInt(int min, int max);
MATH_API float randomFloat(float min, float max);
}  // namespace LifeEXEsimpoe