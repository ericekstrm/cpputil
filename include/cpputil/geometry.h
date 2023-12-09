#pragma once

#include "vector.h"

class Circle;

/*
 Representation of a rectangle.
 The pos coordinate is in the middle of the rectangle.
*/
class Rect
{
public:
    vec2f pos;
    vec2f size;

    bool contains(vec2f const& other) const;
    bool intersects(Rect const& other) const;
    bool intersects(Circle const& other) const;
};

class Circle
{
public:
    vec2f pos;
    float radius;

    bool contains(vec2f const& other) const;
    bool intersects(Circle const& other) const;
    bool intersects(Rect const& other) const;
};
