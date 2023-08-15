#pragma once

template <typename C, typename T = typename C::value_type>
std::ostream& operator<<(std::ostream& os, C const& container);

#include "container.tcc"
