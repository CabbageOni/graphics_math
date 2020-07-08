/*
MIT License

Copyright (c) 2020 Johnny Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <ostream>

namespace graphics_math
{
  template<typename T>
  union vec2
  {
  public:
    T data[2] = {0, 0};
    struct { T x, y; };
    struct { T width, height; };

    inline vec2(const T& uniform) : x(uniform), y(uniform) {}
    inline vec2(const T& x, const T& y) : x(x), y(y) {}
    inline vec2(const vec2& rhs) : x(rhs.x), y(rhs.y) {}

    inline T& operator[](const size_t index) noexcept(false) { if (index > 1) throw "index out of bound!"; return data[index]; }

    inline const vec2 operator+(const vec2& rhs) const { return { x + rhs.x, y + rhs.y }; }
    inline const vec2 operator-(const vec2& rhs) const { return { x - rhs.x, y - rhs.y }; }
    inline const vec2 operator*(const    T& rhs) const { return { x * rhs, y * rhs }; }
    inline const vec2 operator*(const vec2& rhs) const { return { x * rhs.x, y * rhs.y }; }
    inline const vec2 operator/(const    T& rhs) const { return { x / rhs, y / rhs }; }

    inline vec2& operator+=(const vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    inline vec2& operator-=(const vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
    inline vec2& operator*=(const vec2& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
    inline vec2& operator*=(const    T& rhs) { x *= rhs; y *= rhs; return *this; }
    inline vec2& operator/=(const vec2& rhs) { x /= rhs.x; y /= rhs.y; return *this; }

    inline const T    dot(const vec2& rhs) const { return x * rhs.x + y * rhs.y; }
    inline const T    length_squared() const     { return dot(*this); }
    inline const T    length() const             { return sqrt(length_squared()); }
    inline vec2&      normalize()                { return *this /= length(); }
    inline const vec2 normalized() const         { return vec2(*this) /= length(); }

    template <template<typename> class U, typename V>
    inline explicit operator U<V>() const { return { (V)x, (V)y }; }
  };

  template<typename T>
  inline std::ostream& operator<<(std::ostream& os, const vec2<T>& rhs)
  {
    return os << "(" << rhs.x << ", " << rhs.y << ")";
  }

  using fvec2 = vec2<float>;
  using ivec2 = vec2<int>;
}