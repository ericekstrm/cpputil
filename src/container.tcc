#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& container)
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
