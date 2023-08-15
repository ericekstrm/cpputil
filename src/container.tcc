#include <ostream>

template <typename C, typename T = typename C::value_type>
std::ostream& operator<<(std::ostream& os, C const& container)
{
    if (container.empty())
    {
        return os;
    }

    os << *container.begin();
    
    for ( auto it { container.begin() + 1 }; it != container.end(); ++it )
    {
        os << ", " << *it;
    }
    return os;
}
