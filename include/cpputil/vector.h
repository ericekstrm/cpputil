#pragma once

template<unsigned N, typename T>
class vector;

template<typename T>
class vector<2, T>
{
public: 
    
    union {
        struct { T x, y; };
        struct { T r, g; };
        struct { T s, t; }; //p, q
    };

    vector(T const& x, T const& y);
    
    vector<2, T>  operator+ (vector<2, T> const& rhs) const;
    vector<2, T>& operator+=(vector<2, T> const& rhs);
    vector<2, T>  operator- (vector<2, T> const& rhs) const;
    vector<2, T>& operator-=(vector<2, T> const& rhs);

    vector<2, T>  operator* (T const& rhs) const;
    vector<2, T>& operator*=(T const& rhs);
    vector<2, T>  operator/ (T const& rhs) const;
    vector<2, T>& operator/=(T const& rhs);

    //dot product
    T operator*(vector<2, T> const& rhs) const;

    bool operator==(vector<2, T> const& rhs) const;
    bool operator!=(vector<2, T> const& rhs) const;
        
};

template<typename T>
vector<2, T> operator+(T const& lhs, vector<2, T> const& rhs);

template<typename T>
vector<2, T> operator*(T const& lhs, vector<2, T> const& rhs);

#include "vector.tcc"
