#pragma once
#include <ostream>
#include <cmath>
#include <type_traits>
#include <algorithm>

#include "constants.h"

// ----------------------- Vec2 -----------------------------

template<typename T>
struct Vec2 {
    T x;
    T y;

    Vec2(const T& x_, const T& y_) : x(x_), y(y_) {}
    Vec2() : x(T{}), y(T{}) {}

    T norm() const {
        return (T)std::sqrt(x * x + y * y);
    }   

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

    Vec2& operator*=(const Vec2& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vec2& operator/=(const Vec2& other) {
        x /= other.x;
        y /= other.y;
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

    Vec2& operator*=(const T& other) {
        x *= other;
        y *= other;
        return *this;
    }

    Vec2& operator/=(const T& other) {
        x /= other;
        y /= other;
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
Vec2<T> operator*(Vec2<T> a, const Vec2<T>& b) {
    a *= b;
    return a;
}

template<typename T>
Vec2<T> operator/(Vec2<T> a, const Vec2<T>& b) {
    a /= b;
    return a;
}

template<typename T>
Vec2<T> operator+(Vec2<T> a, const T& b) {
    a += b;
    return a;
}

template<typename T>
Vec2<T> operator+(const T& a, Vec2<T> b) {
    return b + a;
}

template<typename T>
Vec2<T> operator-(Vec2<T> a, const T& b) {
    a -= b;
    return a;
}

template<typename T>
Vec2<T> operator-(const T& a, Vec2<T> b) {
    return b - a;
}

template<typename T>
Vec2<T> operator*(Vec2<T> a, const T& b) {
    a *= b;
    return a;
}

template<typename T>
Vec2<T> operator*(const T& a, Vec2<T> b) {
    return b * a;
}

template<typename T>
Vec2<T> operator/(Vec2<T> a, const T& b) {
    a /= b;
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
        return abs(a.x - b.x) < cst::tol<T> && abs(a.y - b.y) < cst::tol<T>;
    } else {
        return a.x == b.x && a.y == b.y;
    }
}

template<typename T>
bool operator!=(const Vec2<T>& a, const Vec2<T>& b) {
    return !(a == b);
}

template<typename T>
bool operator<=(const Vec2<T>& a, const Vec2<T>& b) {
    return a.x <= b.x && a.y <= b.y;
}

template<typename T>
bool operator>=(const Vec2<T>& a, const Vec2<T>& b) {
    return a.x >= b.x && a.y >= b.y;
}

template<typename T>
bool operator<(const Vec2<T>& a, const Vec2<T>& b) {
    return a.x < b.x && a.y < b.y;
}

template<typename T>
bool operator>(const Vec2<T>& a, const Vec2<T>& b) {
    return a.x > b.x && a.y > b.y;
}

// ----------------------- Squares -----------------------------
template <typename T>
struct Square {
    Vec2<T> pos;
    T c;

    Square(Vec2<T> pos_, T c_) : pos(pos_), c(c_) {}
    Square() : pos(Vec2<T>()), c(T{}) {}

    Square& operator+=(const Vec2<T>& other) {
        pos += other;
        return *this;
    }

    Square& operator-=(const Vec2<T>& other) {
        pos -= other;
        return *this;
    }

    Square& operator*=(const Vec2<T>& other) {
        pos *= other;
        return *this;
    }

    Square& operator/=(const Vec2<T>& other) {
        pos /= other;
        return *this;
    }

    Square& operator+=(const T& other) {
        pos += other;
        return *this;
    }

    Square& operator-=(const T& other) {
        pos -= other;
        return *this;
    }

    Square& operator*=(const T& other) {
        pos *= other;
        return *this;
    }

    Square& operator/=(const T& other) {
        pos /= other;
        return *this;
    }

    bool inside_worlds() {
        T h = c / T(2);
        Vec2<T> min((Vec2<T>) pos - h);
        Vec2<T> max((Vec2<T>) pos + h);
        Vec2<T> zero ((T) 0, (T) 0);
        Vec2<T> arena_max((T) cst::arena_size, (T) cst::arena_size);
        return zero <= min && max <= arena_max;
    }
};

template<typename T>
Square<T> operator+(Square<T> s, const Vec2<T>& v) {
    s += v;
    return s;
}

template<typename T>
Square<T> operator+(const Vec2<T>& v, Square<T> s) {
    return s + v;
}

template<typename T>
Square<T> operator-(Square<T> s, const Vec2<T>& v) {
    s -= v;
    return s;
}

template<typename T>
Square<T> operator-(const Vec2<T>& v, Square<T> s) {
    return s - v;
}

template<typename T>
Square<T> operator*(Square<T> s, const Vec2<T>& v) {
    s *= v;
    return s;
}

template<typename T>
Square<T> operator*(const Vec2<T>& v, Square<T> s) {
    return s * v;
}

template<typename T>
Square<T> operator/(Square<T> s, const Vec2<T>& v) {
    s /= v;
    return s;
}

template<typename T>
Square<T> operator+(Square<T> s, const T& v) {
    s += v;
    return s;
}

template<typename T>
Square<T> operator+(const T& v, Square<T> s) {
    return s + v;
}

template<typename T>
Square<T> operator-(Square<T> s, const T& v) {
    s -= v;
    return s;
}

template<typename T>
Square<T> operator-(const T& v, Square<T> s) {
    return s - v;
}

template<typename T>
Square<T> operator*(Square<T> s, const T& v) {
    s *= v;
    return s;
}

template<typename T>
Square<T> operator*(const T& v, Square<T> s) {
    return s * v;
}

template<typename T>
Square<T> operator/(Square<T> s, const T& v) {
    s /= v;
    return s;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Square<T>& s) {
    return os << s.pos << " c=" << s.c;
}

// ----------------------- Circles -----------------------------

template <typename T>
struct Circle {
    Vec2<T> pos;
    T r;

    Circle(Vec2<T> pos_, T r_) : pos(pos_), r(r_) {}
    Circle() : pos(Vec2<T>()), r(T{}) {}

    Circle& operator+=(const Vec2<T>& other) {
        pos += other;
        return *this;
    }

    Circle& operator-=(const Vec2<T>& other) {
        pos -= other;
        return *this;
    }

    Circle& operator*=(const Vec2<T>& other) {
        pos *= other;
        return *this;
    }

    Circle& operator/=(const Vec2<T>& other) {
        pos /= other;
        return *this;
    }

    Circle& operator+=(const T& other) {
        pos += other;
        return *this;
    }

    Circle& operator-=(const T& other) {
        pos -= other;
        return *this;
    }

    Circle& operator*=(const T& other) {
        pos *= other;
        return *this;
    }

    Circle& operator/=(const T& other) {
        pos /= other;
        return *this;
    }

    bool inside_worlds() {
        T h = r / T(2);
        Vec2<T> min((Vec2<T>) pos - h);
        Vec2<T> max((Vec2<T>) pos + h);
        Vec2<T> zero ((T) 0, (T) 0);
        Vec2<T> arena_max((T) cst::arena_size, (T) cst::arena_size);
        return zero <= min && max <= arena_max;
    }
};

template<typename T>
Circle<T> operator+(Circle<T> c, const Vec2<T>& v) {
    c += v;
    return c;
}

template<typename T>
Circle<T> operator+(const Vec2<T>& v, Circle<T> c) {
    return c + v;
}

template<typename T>
Circle<T> operator-(Circle<T> c, const Vec2<T>& v) {
    c -= v;
    return c;
}

template<typename T>
Circle<T> operator-(const Vec2<T>& v, Circle<T> c) {
    return c - v;
}

template<typename T>
Circle<T> operator*(Circle<T> c, const Vec2<T>& v) {
    c *= v;
    return c;
}

template<typename T>
Circle<T> operator*(const Vec2<T>& v, Circle<T> c) {
    return c * v;
}

template<typename T>
Circle<T> operator/(Circle<T> c, const Vec2<T>& v) {
    c /= v;
    return c;
}

template<typename T>
Circle<T> operator+(Circle<T> c, const T& v) {
    c += v;
    return c;
}

template<typename T>
Circle<T> operator+(const T& v, Circle<T> c) {
    return c + v;
}

template<typename T>
Circle<T> operator-(Circle<T> c, const T& v) {
    c -= v;
    return c;
}

template<typename T>
Circle<T> operator-(const T& v, Circle<T> c) {
    return c - v;
}

template<typename T>
Circle<T> operator*(Circle<T> c, const T& v) {
    c *= v;
    return c;
}

template<typename T>
Circle<T> operator*(const T& v, Circle<T> c) {
    return c * v;
}

template<typename T>
Circle<T> operator/(Circle<T> c, const T& v) {
    c /= v;
    return c;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Circle<T>& c) {
    return os << c.pos << " r=" << c.r;
}

// ----------------------- Shape equality -----------------------------

template<typename T>
bool operator==(const Square<T>& a, const Square<T>& b) {
    if constexpr (std::is_floating_point_v<T>) {
        using std::abs;
        return a.pos == b.pos && abs(a.c - b.c) < cst::tol<T>;
    } else {
        return a.pos == b.pos && a.c == b.c;
    }
}

template<typename T>
bool operator!=(const Square<T>& a, const Square<T>& b) {
    return !(a == b);
}

template<typename T>
bool operator==(const Circle<T>& a, const Circle<T>& b) {
    if constexpr (std::is_floating_point_v<T>) {
        using std::abs;
        return a.pos == b.pos && abs(a.r - b.r) < cst::tol<T>;
    } else {
        return a.pos == b.pos && a.r == b.r;
    }
}

template<typename T>
bool operator!=(const Circle<T>& a, const Circle<T>& b) {
    return !(a == b);
}

// ----------------------- Collision helpers -----------------------------

template<typename T>
bool intersects(const Square<T>& a, const Square<T>& b) {
    T ah = a.c / T(2);
    T bh = b.c / T(2);

    Vec2<T> aMin((Vec2<T>) a.pos - ah);
    Vec2<T> aMax((Vec2<T>) a.pos + ah);

    Vec2<T> bMin((Vec2<T>) b.pos - bh);
    Vec2<T> bMax((Vec2<T>) b.pos + bh);

    return aMin <= bMax && aMax >= bMin;
}

template<typename T>
bool intersects(const Circle<T>& a, const Circle<T>& b) {
    Vec2<T> d = a.pos - b.pos;
    T dist2 = d.x * d.x + d.y * d.y;
    T rSum = a.r + b.r;
    return dist2 <= rSum * rSum;
}

template<typename T>
bool intersects(const Square<T>& s, const Circle<T>& c) {
    T h = s.c / T(2);

    Vec2<T> min((Vec2<T>) s.pos - h);
    Vec2<T> max((Vec2<T>) s.pos + h);

    T closestX = std::clamp(c.pos.x, min.x, max.x);
    T closestY = std::clamp(c.pos.y, min.y, max.y);

    T dx = c.pos.x - closestX;
    T dy = c.pos.y - closestY;

    return dx * dx + dy * dy <= c.r * c.r;
}

template<typename T>
bool intersects(const Circle<T>& c, const Square<T>& s) {
    return intersects(s, c);
}