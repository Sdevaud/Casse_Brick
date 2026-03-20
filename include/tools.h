#pragma once
#include <ostream>
#include <cmath>
#include <type_traits>
#include "constants.h"

template<typename T>
struct Vec2 {
    T x;
    T y;

    Vec2(T x_, T y_) : x(x_), y(y_) {}

    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator+=(const T& other) {
        x += other;
        y += other;
        return *this;
    }

    Vec2& operator-=(const T& other) {
        x -= other;
        y -= other;
        return *this;
    }
};

template<typename T>
Vec2<T> operator+(Vec2<T> a, const Vec2<T>& b) {
    a += b;
    return a;
}

template<typename T>
Vec2<T> operator-(Vec2<T> a, const Vec2<T>& b) {
    a -= b;
    return a;
}

template<typename T>
Vec2<T> operator+(Vec2<T> a, const T& b) {
    a += b;
    return a;
}

template<typename T>
Vec2<T> operator-(Vec2<T> a, const T& b) {
    a -= b;
    return a;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

template<typename T>
bool operator==(const Vec2<T>& a, const Vec2<T>& b) {
    if constexpr (std::is_floating_point_v<T>) {
        using std::abs;
        return abs(a.x - b.x) < cons::tol<T> && abs(a.y - b.y) < cons::tol<T>;
    } else {
        return a.x == b.x && a.y == b.y;
    }
}

template<typename T>
bool operator!=(const Vec2<T>& a, const Vec2<T>& b) {
    return !(a == b);
}
