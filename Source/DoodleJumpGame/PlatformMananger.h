#pragma once
#include "raylib.h"

#include <vector>
#include "Types.h"

class PlatformManager
{
public:
    PlatformManager(const ScreenSize& screenSize, RandomFunc randFunc);

    const std::vector<Rectangle>& platforms() const;

    void applyScroll(float scrollOffset);

private:
    void regeneratePlatform(Rectangle& platform);

private:

    const ScreenSize c_screenSize;
    std::vector<Rectangle> m_platforms;

    const float c_verticalSpacing;

    RandomFunc m_randFunc;
};