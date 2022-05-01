
template<uint8_t N, typename T>
vector<N, T>& operator+=(vector<N, T> & lhs, vector<N, T> const& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template<uint8_t N, typename T>
vector<N, T> operator-(vector<N, T> const& lhs, vector<N, T> const& rhs)
{
    return vector<N, T>{lhs + (-rhs)};
}

template<uint8_t N, typename T>
vector<N, T>& operator-=(vector<N, T> & lhs, vector<N, T> const& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

template<uint8_t N, typename T>
vector<N, T>& operator*=(vector<N, T> & lhs, T const& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template<uint8_t N, typename T>
bool operator!=(vector<N, T> const& lhs, vector<N, T> const& rhs)
{
    return ! ( lhs == rhs);
}

template<uint8_t N, typename T>
vector<N, T>& operator/=(vector<N, T> & lhs, T const& rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

template<uint8_t N, typename T>
vector<N, T> operator*(T const& lhs, vector<N, T> const& rhs)
{
    return rhs * lhs;
}

// ==================
// ===| vector 2 |===
// ==================

template<typename T>
vector<2, T>::vector()
    : vector{T{}, T{}}
{}

template<typename T>
vector<2, T>::vector(T const& x, T const& y)
    : x {x}, y {y}
{ }

template<typename T>
vector<2, T> vector<2, T>::operator+(vector<2, T> const& rhs) const
{
    return vector{x + rhs.x, y + rhs.y};
}

template<typename T>
vector<2, T> vector<2, T>::operator-() const
{
    return vector{-x, -y};
}

template<typename T>
vector<2, T> vector<2, T>::operator*(T const& rhs) const
{
    return vector{x * rhs, y * rhs};
}

template<typename T>
vector<2, T> vector<2, T>::operator/(T const& rhs) const
{
    return vector<2, T>{x / rhs, y / rhs};
}

template<typename T>
bool vector<2, T>::operator==(vector<2, T> const& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

template<typename T>
vector<2, T>::operator std::string() const
{
    return "[" + std::to_string(x) + " " + std::to_string(y) + "]";
}

template<typename T>
T vector<2, T>::operator*(vector<2, T> const& rhs) const
{
    return x * rhs.x + y * rhs.y;
}

// ==================
// ===| vector 3 |===
// ==================

template<typename T>
vector<3, T>::vector()
    : vector{T{}, T{}, T{}}
{}

template<typename T>
vector<3, T>::vector(T const& x, T const& y, T const& z)
    : x {x}, y {y}, z {z}
{ }

template<typename T>
vector<3, T> vector<3, T>::operator+(vector<3, T> const& rhs) const
{
    return vector{x + rhs.x, y + rhs.y, z + rhs.z};
}

template<typename T>
vector<3, T> vector<3, T>::operator-() const
{
    return vector{-x, -y, -z};
}

template<typename T>
vector<3, T> vector<3, T>::operator*(T const& rhs) const
{
    return vector{x * rhs, y * rhs, z * rhs};
}

template<typename T>
vector<3, T> vector<3, T>::operator/(T const& rhs) const
{
    return vector{x / rhs, y / rhs, z / rhs};
}

template<typename T>
T vector<3, T>::operator*(vector<3, T> const& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

template<typename T>
bool vector<3, T>::operator==(vector<3, T> const& rhs) const
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

template<typename T>
vector<3, T>::operator std::string() const
{
    return "[" + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "]";
}
