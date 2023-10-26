#include "vec.h"

namespace BlazeMath {
	////////////////////////////////
	/// Vec2D
	////////////////////////////////
	Vec2D& Vec2D::operator=(const Vec2D& rhs)
	{
		e[0] = rhs.e[0];
		e[1] = rhs.e[1];
		return *this;
	}

	Vec2D& Vec2D::operator+=(const Vec2D& rhs)
	{
		e[0] += rhs.e[0];
		e[1] += rhs.e[1];
		return *this;
	}

	Vec2D& Vec2D::operator-=(const Vec2D& rhs)
	{
		e[0] -= rhs.e[0];
		e[1] -= rhs.e[1];
		return *this;
	}

	Vec2D& Vec2D::operator*=(const Vec2D& rhs)
	{
		e[0] *= rhs.e[0];
		e[1] *= rhs.e[1];
		return *this;
	}

	Vec2D& Vec2D::operator/=(const Vec2D& rhs)
	{
		e[0] /= rhs.e[0];
		e[1] /= rhs.e[1];
		return *this;
	}

	Vec2D& Vec2D::operator*=(const float rhs)
	{
		e[0] *= rhs;
		e[1] *= rhs;
		return *this;
	}

	Vec2D& Vec2D::operator/=(const float rhs)
	{
		float k = 1.0f / rhs;
		return *this *= k;
	}

	Vec2D operator+(const Vec2D& lhs, const Vec2D& rhs)
	{
		return Vec2D(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vec2D operator-(const Vec2D& lhs, const Vec2D& rhs)
	{
		return Vec2D(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vec2D operator*(const Vec2D& lhs, const Vec2D& rhs)
	{
		return Vec2D(lhs.x * rhs.x, lhs.y * rhs.y);
	}
	
	Vec2D operator*(const Vec2D& lhs, const float rhs)
	{
		return Vec2D(lhs.x * rhs, lhs.y * rhs);
	}

	Vec2D operator*(const float lhs, const Vec2D& rhs)
	{
		return Vec2D(lhs * rhs.x, lhs * rhs.y);
	}

	Vec2D operator/(const Vec2D& lhs, const Vec2D& rhs)
	{
		return Vec2D(lhs.x / rhs.x, lhs.y / rhs.y);
	}

	Vec2D operator/(const Vec2D& lhs, const float rhs)
	{
		float k = 1.0f / rhs;
		return Vec2D(lhs.x * k, lhs.y * k);
	}


	std::ostream& operator<<(std::ostream& out, const Vec2D& vec)
	{
		out << "(" << vec.x << ", " << vec.y << ")";
		return out;
	}

	///////////////////////////////////////
	/// VEC3D
	///////////////////////////////////////

	Vec3D operator+(const Vec3D& lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	Vec3D operator-(const Vec3D& lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	Vec3D operator*(const Vec3D& lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}

	Vec3D operator/(const Vec3D& lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	}

	Vec3D operator*(const Vec3D& lhs, const float rhs)
	{
		return Vec3D(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
	}


	Vec3D operator*(const float lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
	}

	Vec3D operator/(const Vec3D& lhs, const float rhs)
	{
		float k = 1.0f / rhs;
		return Vec3D(lhs.x * k, lhs.y * k, lhs.z * k);
	}

	Vec3D cross(const Vec3D& lhs, const Vec3D& rhs)
	{
		return Vec3D(lhs.y*rhs.z - lhs.z*rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
	}


	float dot(const Vec3D& lhs, const Vec3D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	float dot(const Vec2D& lhs, const Vec2D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}



	Vec3D& Vec3D::operator=(const Vec3D& rhs)
	{
		e[0] = rhs.e[0];
		e[1] = rhs.e[1];
		e[2] = rhs.e[2];
		return *this;
	}

	Vec3D& Vec3D::operator+=(const Vec3D& rhs)
	{
		e[0] += rhs.e[0];
		e[1] += rhs.e[1];
		e[2] += rhs.e[2];
		return *this;
	}

	Vec3D& Vec3D::operator-=(const Vec3D& rhs)
	{
		e[0] -= rhs.e[0];
		e[1] -= rhs.e[1];
		e[2] -= rhs.e[2];
		return *this;
	}

	Vec3D& Vec3D::operator*=(const Vec3D& rhs)
	{
		e[0] *= rhs.e[0];
		e[1] *= rhs.e[1];
		e[2] *= rhs.e[2];
		return *this;
	}

	Vec3D& Vec3D::operator/=(const Vec3D& rhs)
	{
		e[0] /= rhs.e[0];
		e[1] /= rhs.e[1];
		e[2] /= rhs.e[2];
		return *this;
	}

	Vec3D& Vec3D::operator*=(const float rhs)
	{
		e[0] *= rhs;
		e[1] *= rhs;
		e[2] *= rhs;
		return *this;
	}

	Vec3D& Vec3D::operator/=(const float rhs)
	{
		float k = 1.0f / rhs;
		return *this *= k;
	}

	std::ostream& operator<<(std::ostream& out, const Vec3D& vec)
	{
		out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return out;
	}


	////////////////////////////////
	/// VEC4D
	////////////////////////////////

	Vec4D& Vec4D::operator=(const Vec4D& rhs)
	{	
		e[0] = rhs.e[0];
		e[1] = rhs.e[1];
		e[2] = rhs.e[2];
		e[3] = rhs.e[3];
		return *this;
	}
	Vec4D& Vec4D::operator+=(const Vec4D& rhs)
	{
		e[0] += rhs.e[0];
		e[1] += rhs.e[1];
		e[2] += rhs.e[2];
		e[3] += rhs.e[3];
		return *this;
	}
	Vec4D& Vec4D::operator-=(const Vec4D& rhs)
	{
		e[0] -= rhs.e[0];
		e[1] -= rhs.e[1];
		e[2] -= rhs.e[2];
		e[3] -= rhs.e[3];
		return *this;
	}
	Vec4D& Vec4D::operator*=(const Vec4D& rhs)
	{
		e[0] *= rhs.e[0];
		e[1] *= rhs.e[1];
		e[2] *= rhs.e[2];
		e[3] *= rhs.e[3];
		return *this;
	}
	Vec4D& Vec4D::operator/=(const Vec4D& rhs)
	{
		e[0] /= rhs.e[0];
		e[1] /= rhs.e[1];
		e[2] /= rhs.e[2];
		e[3] /= rhs.e[3];
		return *this;
	}
	Vec4D& Vec4D::operator*=(const float rhs)
	{
		float k = rhs;
		e[0] *= k;
		e[1] *= k;
		e[2] *= k;
		e[3] *= k;
		return *this;
	}
	Vec4D& Vec4D::operator/=(const float rhs)
	{
		float k = 1.0f / rhs;
		e[0] *= k;
		e[1] *= k;
		e[2] *= k;
		e[3] *= k;
		return *this;
	}
	Vec4D operator+(const Vec4D& lhs, const Vec4D& rhs)
	{
		return Vec4D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	}
	Vec4D operator-(const Vec4D& lhs, const Vec4D& rhs)
	{
		return Vec4D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
	}
	Vec4D operator*(const Vec4D& lhs, const Vec4D& rhs)
	{
		return Vec4D(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	}
	Vec4D operator/(const Vec4D& lhs, const Vec4D& rhs)
	{
		return Vec4D(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
	}

	Vec4D operator*(const Vec4D& lhs, const float rhs)
	{
		return Vec4D(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
	}

	Vec4D operator*(const float lhs, const Vec4D& rhs)
	{
		return Vec4D(lhs * rhs.x, lhs * rhs.x, lhs * rhs.x, lhs * rhs.x);
	}

	Vec4D operator/(const Vec4D& lhs, const float rhs)
	{
		float k = 1.0f / rhs;
		return Vec4D(lhs.x * k, lhs.y * k, lhs.z * k, lhs.w * k);
	}


	float dot(const Vec4D& lhs, const Vec4D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w + rhs.w;
	}


	Vec4D operator*(const Vec4D& lhs, const Vec4D rhs)
	{
		return Vec4D(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	}

}
