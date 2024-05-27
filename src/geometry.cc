#include "cpputil/geometry.h"
#include "cpputil/linalg.h"

#include <iostream>

bool Rect::contains(vec2f const& other) const
{
    return other.x >= pos.x - size.x / 2.0
       and other.x <= pos.x + size.x / 2.0
       and other.y >= pos.y - size.y / 2.0
       and other.y <= pos.y + size.y / 2.0;
}

bool Rect::intersects(Rect const& other) const
{
    return pos.x - size.x / 2.0 <= other.pos.x + other.size.x / 2.0
       and pos.x + size.x / 2.0 >= other.pos.x - other.size.x / 2.0
       and pos.y - size.y / 2.0 <= other.pos.y + other.size.y / 2.0
       and pos.y + size.y / 2.0 >= other.pos.y - other.size.y / 2.0;
}

bool Rect::intersects(Circle const& circle) const
{

    // The circles center is inside the rectangle
    if (contains(circle.pos)) return true;

    // The rectangles center is inside the circle
    if (circle.contains(pos)) return true;

    vec2f top_left {pos - size / 2};
    vec2f top_right {pos.x + size.x / 2, pos.y - size.y / 2};
    vec2f bot_left {pos.x - size.x / 2, pos.y + size.y / 2};
    vec2f bot_right {pos + size / 2};

    return (circle.contains(closest_point_on_line(top_left, top_right, circle.pos)) or
            circle.contains(closest_point_on_line(top_right, bot_right, circle.pos)) or
            circle.contains(closest_point_on_line(bot_right, bot_left, circle.pos)) or
            circle.contains(closest_point_on_line(bot_left, top_left, circle.pos)));
}

bool Circle::contains(vec2f const& other) const
{
    return std::pow(other.x - pos.x, 2) + std::pow(other.y - pos.y, 2) < std::pow(radius, 2);
}

bool Circle::intersects(Circle const& other) const
{
    return std::pow(other.pos.x - pos.x, 2) + std::pow(other.pos.y - pos.y, 2) < std::pow(radius + other.radius, 2);
}

bool Circle::intersects(Rect const& other) const
{
    return other.intersects(*this);
}
