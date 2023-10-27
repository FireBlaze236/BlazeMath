#ifndef VEC_H
#define VEC_H
#include <cmath>
#include <iostream>

#include "constants.h"

namespace BlazeMath {

	struct Vec2D;
	struct Vec3D;
	struct Vec4D;

	struct Vec2D {
		union {
			float e[2];
			struct { float x, y; };
		};
		//inline Vec2D(const Vec2D& rhs) { e[0] = rhs.e[0]; e[1] = rhs.e[1]; }
		inline const float* const GetPtr() const { return &e[0]; }
		inline Vec2D() : e{ 0,0 } {}
		inline Vec2D(float a) : e{ a, a } {}
		inline Vec2D(float a, float b) : e{ a, b } {}

		inline float length_squared() const { return x * x + y * y; }
		inline float length() const { return std::sqrt(length_squared()); }

		//Operator overloads
		Vec2D& operator=(const Vec2D& rhs);
		Vec2D& operator+=(const Vec2D& rhs);
		Vec2D& operator-=(const Vec2D& rhs);
		Vec2D& operator*=(const Vec2D& rhs);
		Vec2D& operator/=(const Vec2D& rhs);

		Vec2D& operator*=(const float rhs);
		Vec2D& operator/=(const float rhs);

		inline Vec2D normalized() const { float l = 1.0f / length(); return Vec2D(x * l, y * l); }
		inline Vec2D& normalize() { float l = 1.0f / length(); x *= l;  y *= l; return *this; }

	};

	Vec2D operator+(const Vec2D& lhs, const Vec2D& rhs);
	Vec2D operator-(const Vec2D& lhs, const Vec2D& rhs);
	Vec2D operator*(const Vec2D& lhs, const Vec2D& rhs);
	Vec2D operator/(const Vec2D& lhs, const Vec2D& rhs);
	Vec2D operator*(const Vec2D& lhs, const float rhs);
	Vec2D operator*(const float lhs, const Vec2D& rhs);
	Vec2D operator/(const Vec2D& lhs, const float rhs);

	// DEBUG OUTPUT
	std::ostream& operator<<(std::ostream& out, const Vec2D& vec);


	struct Vec3D {
		union {
			float e[3];
			struct { float x, y, z; };
			struct { float r, g, b; };
		};

		inline const float* const GetPtr() const { return &e[0]; }
		inline Vec3D(const Vec3D& rhs) { e[0] = rhs.e[0]; e[1] = rhs.e[1]; e[2] = rhs.e[2]; }
		inline Vec3D(float a) : e{ a,a,a } {}
		inline Vec3D() : e{ 0,0,0 } {}
		inline Vec3D(float a, float b, float c) : e{ a, b, c } {}

		inline float length_squared() const { return x * x + y * y + z * z; }
		inline float length() const { return std::sqrt(length_squared()); }
		//Operator overloads
		Vec3D& operator=(const Vec3D& rhs);
		Vec3D& operator+=(const Vec3D& rhs);
		Vec3D& operator-=(const Vec3D& rhs);
		Vec3D& operator*=(const Vec3D& rhs);
		Vec3D& operator/=(const Vec3D& rhs);

		Vec3D& operator*=(const float rhs);
		Vec3D& operator/=(const float rhs);

		inline Vec3D normalized() const { float l = 1.0f / length(); return Vec3D(x * l, y * l, z * l); }
		inline Vec3D& normalize() { float l = 1.0f / length(); x *= l;  y *= l; z *= l; return *this; }

		inline float dot(Vec3D& other) { return x * other.x + y * other.y + z * other.z; }

	};
	Vec3D operator+(const Vec3D& lhs, const Vec3D& rhs);
	Vec3D operator-(const Vec3D& lhs, const Vec3D& rhs);
	Vec3D operator*(const Vec3D& lhs, const Vec3D& rhs);
	Vec3D operator/(const Vec3D& lhs, const Vec3D& rhs);
	Vec3D operator*(const Vec3D& lhs, const float rhs);
	Vec3D operator*(const float lhs, const Vec3D& rhs);
	Vec3D operator/(const Vec3D& lhs, const float rhs);

	// DEBUG OUTPUT
	std::ostream& operator<<(std::ostream& out, const Vec3D& vec);


	struct Vec4D {
		union {
			float e[4];
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
		inline const float* const GetPtr() const { return &e[0]; }
		inline Vec4D() : e{ 0,0,0,0 } {}
		inline Vec4D(float a) : e{ a, a, a, a } {}
		inline Vec4D(float a, float b, float c, float d) : e{ a, b, c, d } {}

		inline float length_squared() const { return x * x + y * y + z * z + w * w; }
		inline float length() const { return std::sqrt(length_squared()); }
		inline Vec4D normalized() const { float l = 1.0f / length(); return Vec4D(x * l, y * l, z * l, w * l); }
		inline Vec4D& normalize() { float l = 1.0f / length(); x *= l;  y *= l; z *= l; w *= l; return *this; }
		inline float dot(Vec4D& other) { return x * other.x + y * other.y + z * other.z + w * other.w; }
		Vec4D& operator=(const Vec4D& rhs);
		Vec4D& operator+=(const Vec4D& rhs);
		Vec4D& operator-=(const Vec4D& rhs);
		Vec4D& operator*=(const Vec4D& rhs);
		Vec4D& operator/=(const Vec4D& rhs);

		Vec4D& operator*=(const float rhs);
		Vec4D& operator/=(const float rhs);

		inline operator Vec2D() { return Vec2D(x, y); }
		inline operator Vec3D() { return Vec3D(x, y, z); }
	};
	Vec4D operator+(const Vec4D& lhs, const Vec4D& rhs);
	Vec4D operator-(const Vec4D& lhs, const Vec4D& rhs);
	Vec4D operator*(const Vec4D& lhs, const Vec4D& rhs);
	Vec4D operator/(const Vec4D& lhs, const Vec4D& rhs);
	Vec4D operator*(const Vec4D& lhs, const float rhs);
	Vec4D operator*(const float lhs, const Vec4D& rhs);
	Vec4D operator/(const Vec4D& lhs, const float rhs);

	// Cross products
	Vec3D cross(const Vec3D& lhs, const Vec3D& rhs);
	// Dot products
	float dot(const Vec4D& lhs, const Vec4D& rhs);
	float dot(const Vec3D& lhs, const Vec3D& rhs);
	float dot(const Vec2D& lhs, const Vec2D& rhs);


}
#endif
