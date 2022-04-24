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
vector<2, T>& vector<2, T>::operator+=(vector<2, T> const& rhs)
{
    *this = *this + rhs;
    return *this;
}

template<typename T>
vector<2, T> vector<2, T>::operator-(vector<2, T> const& rhs) const
{
    return vector{x - rhs.x, y - rhs.y};
}

template<typename T>
vector<2, T>& vector<2, T>::operator-=(vector<2, T> const& rhs)
{
    *this = *this - rhs;
    return *this;
}

template<typename T>
vector<2, T> vector<2, T>::operator*(T const& rhs) const
{
    return vector{x * rhs, y * rhs};
}

template<typename T>
vector<2, T>& vector<2, T>::operator*=(T const& rhs)
{
    *this = *this * rhs;
    return *this;
}

template<typename T>
vector<2, T> vector<2, T>::operator/(T const& rhs) const
{
    return vector{x / rhs, y / rhs};
}

template<typename T>
vector<2, T>& vector<2, T>::operator/=(T const& rhs)
{
    *this = *this / rhs;
    return *this;
}

template<typename T>
T vector<2, T>::operator*(vector<2, T> const& rhs) const
{
    return x * rhs.x + y * rhs.y;
}

template<typename T>
bool vector<2, T>::operator==(vector<2, T> const& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

template<typename T>
bool vector<2, T>::operator!=(vector<2, T> const& rhs) const
{
    return ! ( *this == rhs);
}

template<typename T>
vector<2, T> operator+(T const& lhs, vector<2, T> const& rhs)
{
    return rhs + lhs;
}

template<typename T>
vector<2, T> operator*(T const& lhs, vector<2, T> const& rhs)
{
    return rhs * lhs;
}
