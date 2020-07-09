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

// vec2 implementation
namespace graphics_math
{
  template<typename T>
  union vec2
  {
    T data[2] = { 0, 0 };
    struct { T x, y; };
    struct { T width, height; };

    inline vec2(const T& uniform) : x(uniform), y(uniform) {}
    inline vec2(const T& x, const T& y) : x(x), y(y) {}
    inline vec2(const vec2& rhs) : x(rhs.x), y(rhs.y) {}

    inline const vec2 operator+(const vec2& rhs) const { return { x + rhs.x, y + rhs.y }; }
    inline const vec2 operator-(const vec2& rhs) const { return { x - rhs.x, y - rhs.y }; }
    inline const vec2 operator*(const vec2& rhs) const { return { x * rhs.x, y * rhs.y }; }
    inline const vec2 operator*(const    T& rhs) const { return { x * rhs, y * rhs }; }
    inline const vec2 operator/(const    T& rhs) const { return { x / rhs, y / rhs }; }

    inline vec2& operator+=(const vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    inline vec2& operator-=(const vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
    inline vec2& operator*=(const vec2& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
    inline vec2& operator*=(const    T& rhs) { x *= rhs; y *= rhs; return *this; }
    inline vec2& operator/=(const    T& rhs) { x /= rhs; y /= rhs; return *this; }

    inline         T& operator[](const size_t index) noexcept(false) { if (index > 1) throw "index out of bound!"; return data[index]; }
    inline const vec2                    operator-()           const { return { -x, -y }; }

    inline    const T dot(const vec2& rhs) const { return x * rhs.x + y * rhs.y; }
    inline    const T     length_squared() const { return dot(*this); }
    inline    const T             length() const { return sqrt(length_squared()); }
    inline      vec2&          normalize()       { return *this /= length(); }
    inline const vec2         normalized() const { return vec2(*this) /= length(); }

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

// vec3 implementation
namespace graphics_math
{
  template<typename T>
  union vec3
  {
    T data[3] = { 0, 0, 0 };
    struct { T x, y, z; };
    struct { T r, g, b; };

    inline vec3(const T& uniform) : x(uniform), y(uniform), z(uniform) {}
    inline vec3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
    inline vec3(const vec3& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}
  
    inline const vec3 operator+(const vec3& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; }
    inline const vec3 operator-(const vec3& rhs) const { return { x - rhs.x, y - rhs.y, z - rhs.z }; }
    inline const vec3 operator*(const vec3& rhs) const { return { x * rhs.x, y * rhs.y, z * rhs.z }; }
    inline const vec3 operator*(const    T& rhs) const { return { x * rhs, y * rhs, z * rhs }; }
    inline const vec3 operator/(const    T& rhs) const { return { x / rhs, y / rhs, z / rhs }; }

    inline vec3& operator+=(const vec3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
    inline vec3& operator-=(const vec3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
    inline vec3& operator*=(const vec3& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; return *this; }
    inline vec3& operator*=(const    T& rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
    inline vec3& operator/=(const    T& rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }

    inline         T& operator[](const size_t index) noexcept(false) { if (index > 2) throw "index out of bound!"; return data[index]; }
    inline const vec3                    operator-()           const { return { -x, -y, -z }; }

    inline    const T   dot(const vec3& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
    inline const vec3 cross(const vec3& rhs) const { return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x}; }
    inline    const T       length_squared() const { return dot(*this); }
    inline    const T               length() const { return sqrt(length_squared()); }
    inline      vec3&            normalize()       { return *this /= length(); }
    inline const vec3           normalized() const { return vec3(*this) /= length(); }

    template <template<typename> class U, typename V>
    inline explicit operator U<V>() const { return { (V)x, (V)y, (V)z }; }
  };


  template<typename T>
  inline std::ostream& operator<<(std::ostream& os, const vec3<T>& rhs)
  {
    return os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
  }

  using fvec3 = vec3<float>;
  using ivec3 = vec3<int>;
}

// vec4 implementation
namespace graphics_math
{
  template<typename T>
  union vec4
  {
    T data[4] = { 0, 0, 0, 0 };
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };

    inline vec4(const T& uniform) : x(uniform), y(uniform), z(uniform), w(uniform) {}
    inline vec4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
    inline vec4(const vec4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}
  
    inline const vec4 operator+(const vec4& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }
    inline const vec4 operator-(const vec4& rhs) const { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }
    inline const vec4 operator*(const vec4& rhs) const { return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w }; }
    inline const vec4 operator*(const    T& rhs) const { return { x * rhs, y * rhs, z * rhs, w * rhs }; }
    inline const vec4 operator/(const    T& rhs) const { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

    inline vec4& operator+=(const vec4& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
    inline vec4& operator-=(const vec4& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; }
    inline vec4& operator*=(const vec4& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; return *this; }
    inline vec4& operator*=(const    T& rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; return *this; }
    inline vec4& operator/=(const    T& rhs) { x /= rhs; y /= rhs; z /= rhs; w /= rhs; return *this; }

    inline         T& operator[](const size_t index) noexcept(false) { if (index > 3) throw "index out of bound!"; return data[index]; }
    inline const vec4                    operator-()           const { return { -x, -y, -z, -w }; }

    inline    const T   dot(const vec4& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }
    inline    const T       length_squared() const { return dot(*this); }
    inline    const T               length() const { return sqrt(length_squared()); }
    inline      vec4&            normalize()       { return *this /= length(); }
    inline const vec4           normalized() const { return vec4(*this) /= length(); }

    template <template<typename> class U, typename V>
    inline explicit operator U<V>() const { return { (V)x, (V)y, (V)z, (V)w }; }
  };


  template<typename T>
  inline std::ostream& operator<<(std::ostream& os, const vec4<T>& rhs)
  {
    return os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.w << ")";
  }

  using fvec4 = vec4<float>;
  using ivec4 = vec4<int>;
}
