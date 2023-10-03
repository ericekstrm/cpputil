#pragma once

#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& container);

#include "container.tcc"
