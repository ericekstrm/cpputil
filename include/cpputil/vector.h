#pragma once

#include <string>

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

    //dot product
    T operator*(vector<3, T> const& rhs) const;
    
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
