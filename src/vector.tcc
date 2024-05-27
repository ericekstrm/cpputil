#include <cmath>
#include <sstream>
#include <iomanip>

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

template<uint8_t N, typename T>
std::ostream& operator<<(std::ostream& os, vector<N, T> const& rhs)
{
    return os << static_cast<std::string>(rhs);
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
    std::ostringstream oss {};
    oss << std::setprecision(3) << std::fixed;
    oss << "[" << x << " " << y << "]";
    return oss.str();
}

template<typename T>
double vector<2, T>::length() const
{
    return sqrt(x*x + y*y);
}

template<typename T>
void vector<2, T>::normalize()
{
    double l {length()};
    if (l < 0.000001) return;
    x /= l;
    y /= l;
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
double vector<3, T>::length() const
{
    return sqrt(x*x + y*y + z*z);
}

template<typename T>
void vector<3, T>::normalize()
{
    double l {length()};
    if (l < 0.000001) return;
    x /= l;
    y /= l;
    z /= l;
}

template<typename T>
vector<3, T>::operator std::string() const
{
    std::ostringstream oss {};
    oss << std::setprecision(3) << std::fixed;
    oss << "[" << x << " " << y << " " << z << "]";
    return oss.str();
}

// ==================
// ===| vector 4 |===
// ==================

template<typename T>
vector<4, T>::vector()
    : vector{T{}, T{}, T{}, T{}}
{}

template<typename T>
vector<4, T>::vector(T const& x, T const& y, T const& z, T const& w)
    : x {x}, y {y}, z {z}, w{w}
{ }

template<typename T>
vector<4, T> vector<4, T>::operator+(vector<4, T> const& rhs) const
{
    return vector{x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
}

template<typename T>
vector<4, T> vector<4, T>::operator-() const
{
    return vector{-x, -y, -z, -w};
}

template<typename T>
vector<4, T> vector<4, T>::operator*(T const& rhs) const
{
    return vector{x * rhs, y * rhs, z * rhs, w * rhs};
}

template<typename T>
vector<4, T> vector<4, T>::operator/(T const& rhs) const
{
    return vector{x / rhs, y / rhs, z / rhs, w / rhs};
}

template<typename T>
T vector<4, T>::operator*(vector<4, T> const& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

template<typename T>
bool vector<4, T>::operator==(vector<4, T> const& rhs) const
{
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

template<typename T>
double vector<4, T>::length() const
{
    return sqrt(x*x + y*y + z*z + w*w);
}

template<typename T>
void vector<4, T>::normalize()
{
    double l {length()};
    if (l < 0.000001) return;
    x /= l;
    y /= l;
    z /= l;
    w /= l;
}

template<typename T>
vector<4, T>::operator std::string() const
{
    std::ostringstream oss {};
    oss << std::setprecision(3) << std::fixed;
    oss << "[" << x << " " << y << " " << z << " " << w << "]";
    return oss.str();
}
