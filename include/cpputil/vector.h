#pragma once

#include <string>
#include <iostream>

template<uint8_t N, typename T>
class vector;

template<uint8_t N, typename T>
vector<N, T>& operator+=(vector<N, T> & lhs, vector<N, T> const& rhs);

template<uint8_t N, typename T>
vector<N, T>  operator- (vector<N, T> const& lhs, vector<N, T> const& rhs);

template<uint8_t N, typename T>
vector<N, T>& operator-=(vector<N, T> & lhs, vector<N, T> const& rhs);

template<uint8_t N, typename T>
vector<N, T>& operator*=(vector<N, T> & lhs, T const& rhs);

template<uint8_t N, typename T>
vector<N, T>& operator/=(vector<N, T> & lhs, T const& rhs);

template<uint8_t N, typename T>
bool operator!=(vector<N, T> const& lhs, vector<N, T> const& rhs);

template<uint8_t N, typename T>
vector<N, T> operator*(T const& lhs, vector<N, T> const& rhs);

template<uint8_t N, typename T>
std::ostream& operator<<(std::ostream& os, vector<N, T> const& rhs);

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

    vector();
    vector(T const& x, T const& y);
    
    vector<2, T> operator+ (vector<2, T> const& rhs) const;
    vector<2, T> operator- () const;
    vector<2, T> operator* (T const& rhs) const;
    vector<2, T> operator/ (T const& rhs) const;
    
    bool operator==(vector<2, T> const& rhs) const;
    operator std::string() const;

    double length() const;
    void normalize();

    //dot product
    T operator*(vector<2, T> const& rhs) const;
        
};

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

    vector();
    vector(T const& x, T const& y, T const& z);
    
    vector<3, T> operator+ (vector<3, T> const& rhs) const;
    vector<3, T> operator- () const;
    vector<3, T> operator* (T const& rhs) const;
    vector<3, T> operator/ (T const& rhs) const;

    bool operator==(vector<3, T> const& rhs) const;
    operator std::string() const; 

    double length() const;
    void normalize();

    //dot product
    T operator*(vector<3, T> const& rhs) const;
    
};

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

    vector();
    vector(T const& x, T const& y, T const& z, T const& w);
    
    vector<4, T> operator+ (vector<4, T> const& rhs) const;
    vector<4, T> operator- () const;
    vector<4, T> operator* (T const& rhs) const;
    vector<4, T> operator/ (T const& rhs) const;

    bool operator==(vector<4, T> const& rhs) const;
    operator std::string() const; 

    double length() const;
    void normalize();

    //dot product
    T operator*(vector<4, T> const& rhs) const;
    
};

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
using vec3i = vector<3, int>;
using vec3f = vector<3, float>;
using vec4i = vector<4, int>;
using vec4f = vector<4, float>;

#include "vector.tcc"
