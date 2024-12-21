#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <sstream>
#include <iomanip>

template<uint8_t N, typename T>
class vector;

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>& operator+=(vector<N, T> & lhs, vector<N, V> const& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T, V>> operator-(vector<N, T> const& lhs, vector<N, V> const& rhs)
{
    return vector<N, std::common_type_t<T, V>>{lhs + (-rhs)};
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>& operator-=(vector<N, T> & lhs, vector<N, V> const& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>  operator- (vector<N, T> const& lhs, V const& rhs)
{
    return lhs + (-rhs);
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>&  operator-= (vector<N, T> const& lhs, V const& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>&  operator+= (vector<N, T> const& lhs, V const& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>& operator*=(vector<N, T> & lhs, V const& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
bool operator!=(vector<N, T> const& lhs, vector<N, V> const& rhs)
{
    return ! ( lhs == rhs);
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>>& operator/=(vector<N, T> & lhs, V const& rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

template<uint8_t N, typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<N, std::common_type_t<T,V>> operator*(T const& lhs, vector<N, V> const& rhs)
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
class vector<2, T>
{
public: 
    
    union {
        struct { T x, y; };
        struct { T r, g; };
        struct { T s, t; };
    };

    vector()
        : vector{T{}, T{}} {}
    
    vector(T const& x, T const& y)
        : x {x}, y {y} {}

    template<typename V>
    requires std::convertible_to<V, T> 
    vector(vector<2, V> const& other)
        : vector {static_cast<T>(other.x), static_cast<T>(other.y)}
    {}

    template<typename V>
    requires std::convertible_to<T, V> 
    operator vector<2, V>()
    {
        return vector<2, V>{static_cast<V>(x), static_cast<V>(y)};
    }
    
    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<2, std::common_type_t<T,V>> operator+(vector<2, V> const& rhs) const
    {
        return vector<2, std::common_type_t<T, V>>{x + rhs.x, y + rhs.y};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<2, std::common_type_t<T, V>> operator*(vector<2, V> const& rhs) const
    {
        return {x * rhs.x, y * rhs.y};
    }

    vector<2, T> operator-() const
    {
        return vector{-x, -y};
    }
    
    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<2, std::common_type_t<T, V>> operator+(V const& rhs) const
    {
        return {x + rhs, y + rhs};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<2, std::common_type_t<T, V>> operator*(V const& rhs) const
    {
        return {x * rhs, y * rhs};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<2, std::common_type_t<T, V>> operator/(V const& rhs) const
    {
        return vector<2, T>{x / rhs, y / rhs};
    }
    
    bool operator==(vector<2, T> const& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    operator std::string() const
    {
        std::ostringstream oss {};
        oss << std::setprecision(3) << std::fixed;
        oss << "[" << x << " " << y << "]";
        return oss.str();
    }

    double length() const
    {
        return sqrt(x*x + y*y);
    }

    void normalize()
    {
        double l {length()};
        if (l < 0.000001) return;
        x /= l;
        y /= l;
    }
};

template<typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
std::common_type_t<T,V> dot(vector<2, T> const& lhs, vector<2, V> const& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

// ==================
// ===| vector 3 |===
// ==================

template<typename T>
class vector<3, T>
{
public: 
    
    union {
        struct { T x, y, z; };
        struct { T r, g, b; };
        struct { T s, t, v; };
    };

    vector()
        : vector{T{}, T{}, T{}} {}

    vector(T const& x, T const& y, T const& z)
        : x {x}, y {y}, z {z} {}
    
    template<typename V>
    requires std::convertible_to<V, T>
    vector(vector<3,V> const& other)
        : vector {static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)}
    {}

    template<typename V>
    requires std::convertible_to<T, V>
    operator vector<3, V>()
    {
        return vector<3, V>{static_cast<V>(x), static_cast<V>(y), static_cast<V>(z)};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<3, std::common_type_t<T, V>> operator+(vector<3, V> const& rhs) const
    {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<3, std::common_type_t<T, V>> operator*(vector<3, V> const& rhs) const
    {
        return {x + rhs.x, y * rhs.y, z * rhs.z};
    }

    vector<3, T> operator-() const
    {
        return {-x, -y, -z};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<3, std::common_type_t<T, V>> operator+(V const& rhs) const
    {
        return {x + rhs, y + rhs, z + rhs};
    }
    
    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<3, std::common_type_t<T, V>> operator*(V const& rhs) const
    {
        return {x * rhs, y * rhs, z * rhs};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<3, std::common_type_t<T, V>> operator/(V const& rhs) const
    {
        return {x / rhs, y / rhs, z / rhs};
    }

    bool operator==(vector<3, T> const& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    operator std::string() const
    {
        std::ostringstream oss {};
        oss << std::setprecision(3) << std::fixed;
        oss << "[" << x << " " << y << " " << z << "]";
        return oss.str();
    }

    double length() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    void normalize()
    {
        double l {length()};
        if (l < 0.000001) return;
        x /= l;
        y /= l;
        z /= l;
    }
};

template<typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
std::common_type_t<T, V> dot(vector<3, T> const& lhs, vector<3, V> const& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
vector<3, std::common_type_t<T, V>> cross(vector<3, T> const& lhs, vector<3, V> const& rhs)
{
    return {lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x};
}

// ==================
// ===| vector 4 |===
// ==================

template<typename T>
class vector<4, T>
{
public: 
    
    union {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        struct { T s, t, v, u; };
    };

    vector()
        : vector{T{}, T{}, T{}, T{}} {}

    vector(T const& x, T const& y, T const& z, T const& w)
        : x {x}, y {y}, z {z}, w{w} {}
    
    template<typename V>
    requires std::convertible_to<V, T>
    vector(vector<4,V> const& other)
        : vector {static_cast<T>(other.x), static_cast<T>(other.y),
                  static_cast<T>(other.z), static_cast<T>(other.w)}
    {}

    template<typename V>
    requires std::convertible_to<T, V>
    operator vector<4, V>()
    {
        return vector<4, V>{static_cast<V>(x), static_cast<V>(y), static_cast<V>(z), static_cast<V>(w)};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<4, std::common_type_t<T, V>> operator+(vector<4, V> const& rhs) const
    {
        return vector{x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<4, std::common_type_t<T, V>> operator*(vector<4, V> const& rhs) const
    {
        return vector{x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w};
    }

    vector<4, T> operator-() const
    {
        return vector{-x, -y, -z, -w};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<4, std::common_type_t<T, V>> operator+(V const& rhs) const
    {
        return vector{x + rhs, y + rhs, z + rhs, w + rhs};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<4, std::common_type_t<T, V>> operator*(V const& rhs) const
    {
        return vector{x * rhs, y * rhs, z * rhs, w * rhs};
    }

    template<typename V>
    requires std::convertible_to<T, V> || std::convertible_to<V, T>
    vector<4, std::common_type_t<T, V>> operator/(V const& rhs) const
    {
        return vector{x / rhs, y / rhs, z / rhs, w / rhs};
    }

    bool operator==(vector<4, T> const& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
    }

    operator std::string() const
    {
        std::ostringstream oss {};
        oss << std::setprecision(3) << std::fixed;
        oss << "[" << x << " " << y << " " << z << " " << w << "]";
        return oss.str();
    }

    double length() const
    {
        return sqrt(x*x + y*y + z*z + w*w);
    }

    void normalize()
    {
        double l {length()};
        if (l < 0.000001) return;
        x /= l;
        y /= l;
        z /= l;
        w /= l;
    }
};

template<typename T, typename V>
requires std::convertible_to<T, V> || std::convertible_to<V, T>
std::common_type_t<T, V> dot(vector<4, T> const& lhs, vector<4, V> const& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

// ========================
// ===| hash functions |===
// ========================

template <typename T>
struct std::hash<vector<2, T>>
{
    std::size_t operator()(::vector<2, T> const& v) const
    {
        std::size_t hash_value {};
        hash_value ^= std::hash<T>{}(v.x) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.y) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        return hash_value;
    }
};

template <typename T>
struct std::hash<vector<3, T>>
{
    std::size_t operator()(::vector<3, T> const& v) const
    {
        std::size_t hash_value {};
        hash_value ^= std::hash<T>{}(v.x) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.y) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.z) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        return hash_value;
    }
};

template <typename T>
struct std::hash<vector<4, T>>
{
    std::size_t operator()(::vector<4, T> const& v) const
    {
        std::size_t hash_value {};
        hash_value ^= std::hash<T>{}(v.x) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.y) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.z) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        hash_value ^= std::hash<T>{}(v.w) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        return hash_value;
    }
};

// ===========================
// ===| type declarations |===
// ===========================

using vec2i = vector<2, int>;
using vec2f = vector<2, float>;
using vec2d = vector<2, double>;
using vec3i = vector<3, int>;
using vec3f = vector<3, float>;
using vec3d = vector<3, double>;
using vec4i = vector<4, int>;
using vec4f = vector<4, float>;
using vec4d = vector<4, double>;
