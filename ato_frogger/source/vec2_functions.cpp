#include "vec2_functions.h"

BoxRenderer::Vec2 operator+(const BoxRenderer::Vec2& lhs, const BoxRenderer::Vec2& rhs)
{
    return BoxRenderer::Vec2{lhs.x + rhs.x, lhs.y + rhs.y};
};

BoxRenderer::Vec2 operator-(const BoxRenderer::Vec2& lhs, const BoxRenderer::Vec2& rhs)
{
    return BoxRenderer::Vec2{lhs.x - rhs.x, lhs.y - rhs.y};
};

BoxRenderer::Vec2 operator*(const BoxRenderer::Vec2& lhs, float rhs)
{
    return BoxRenderer::Vec2{lhs.x * rhs, lhs.y * rhs};
};