#pragma once

#include <vector>

#include "vector.h"

/*
  Returns the closest point on the line segment [l1, l2] to 'point' also considering the end points.

  Project 'point' onto the line from l1 to l2. Check it, l1 and l2 against 'point'.
*/
inline vec2f closest_point_on_line(vec2f const& l1, vec2f const& l2, vec2f const& point)
{
    vec2f line_dir {l2 - l1};
    line_dir.normalize();

    float scalar_product {line_dir * (point - l1)};
    if (scalar_product < 0)
        return l1;
    if (scalar_product > (l1 - l2).length())
        return l1;

    // project point in line
    return l1 + scalar_product * line_dir;
}
