#include "mat.h"
#include "vec.h"

namespace BlazeMath {
	Mat4::Mat4()
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m[i][j] = 0;
			}
		}
	}
	Mat4::Mat4(float val)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m[i][j] = 0;
				if (i == j) m[i][j] = val;
			}
		}
	}
	Mat4::Mat4(Vec4D rows[4])
	{
		for (int i = 0; i < 4; i++) {
			m[i][0] = rows[i].x;
			m[i][1] = rows[i].y;
			m[i][2] = rows[i].z;
			m[i][3] = rows[i].w;
		}
	}
	Mat4::Mat4(float rows[4][4])
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m[i][j] = rows[i][j];
			}
		}

	}
	void Mat4::Reset()
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m[i][j] = 0;
				if (i == j) m[i][j] = 1.0f;
			}
		}
	}
	void Mat4::Transpose()
	{
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 4; j++) {
				std::swap(m[i][j], m[j][i]);
			}
		}
	}
	Mat4 Mat4::Transposed()
	{
		Mat4 ret(GetMatPtr());
		ret.Transpose();
		return ret;
	}
	void Mat4::SetRotationEulers(const Vec3D& euler)
	{
		float a = euler.z * PI / 180.0f;
		float b = euler.y * PI / 180.0f;
		float c = euler.x * PI / 180.0f;
		using namespace std;
		m[0][0] = cosf(b) * cosf(c);
		m[1][0] = cosf(b) * sinf(c);
		m[2][0] = -sinf(b);


		m[0][1] = sinf(a)*sinf(b)*cosf(c) - cosf(a)*sinf(c);
		m[1][1] = sinf(a)*sinf(b)*sinf(c) + cosf(a)*cosf(c);
		m[2][1] = sinf(a) * cosf(b);

		m[0][2] = cosf(a)*sinf(b)*cosf(c) + sinf(a)*sinf(c);
		m[1][2] = cosf(a)*sinf(b)*sinf(c) - sinf(a)*cosf(c);
		m[2][2] = cosf(a) * cosf(b);
	}
	void Mat4::SetTranslation(const Vec3D& translation)
	{	
		m[0][3] = translation.x;
		m[1][3] = translation.y;
		m[2][3] = translation.z;
		m[3][3] = 1.0f;

	}
	void Mat4::SetScale(const Vec3D& scale)
	{
		m[0][0] = scale.x;
		m[1][1] = scale.y;
		m[2][2] = scale.z;
		m[3][3] = 1.0f;

	}
	void Mat4::SetRotation(const float angleDeg, const Vec3D& axis)
	{
		double angle = angleDeg * PI / 180.0;
		float rcos = std::cos(angle);
		float rsin = std::sin(angle);
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		Vec4D r[4];

		r[0].x = rcos + x * x * (1.0f - rcos);
		r[0].y = x * y * (1.0f - rcos) - z * rsin;
		r[0].z = x * z * (1.0f - rcos) + y * rsin;
		r[0].w = 0.0f;

		r[1].x = y * x * (1.0f - rcos) + z * rsin;
		r[1].y = rcos + y * y * (1.0f - rcos);
		r[1].z = y * z * (1.0f - rcos) - x * rsin;
		r[1].w = 0.0f;

		r[2].x = z * x * (1.0f - rcos) - y * rsin;
		r[2].y = z * y * (1.0f - rcos) + x * rsin;
		r[2].z = rcos + z * z * (1.0f - rcos);
		r[2].w = 0.0f;

		r[3].x = 0.0f;
		r[3].y = 0.0f;
		r[3].z = 0.0f;
		r[3].w = 1.0f;

		*this = Mat4(r);
	}
	void Mat4::LookAt(const Vec3D& eye, const Vec3D& target, const Vec3D& up)
	{
		Vec3D forward = (eye - target).normalized();
		Vec3D right = cross(up, forward).normalized();
		Vec3D newUp = cross(forward, right);

		Mat4 trans = Mat4(1.0f);
		trans.SetTranslation(eye * -1.0f);


		m[0][0] = right.x;
		m[0][1] = right.y;
		m[0][2] = right.z;

		m[1][0] = newUp.x;
		m[1][1] = newUp.y;
		m[1][2] = newUp.z;

		m[2][0] = forward.x;
		m[2][1] = forward.y;
		m[2][2] = forward.z;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;

		m[3][3] = 1.0f;

		*this = *this * trans;
	}
	void Mat4::Perspective(const float fov, const float aspect, const float near, const float far)
	{
		float a = (fov / 2.0f) * PI / 180.0f;
		float S = 1.0f / std::tanf(a);

		Vec4D rows[4];
		rows[0].x = S / aspect;
		rows[0].y = 0;
		rows[0].z = 0;
		rows[0].w = 0;

		rows[1].x = 0;
		rows[1].y = S;
		rows[1].z = 0;
		rows[1].w = 0;

		rows[2].x = 0;
		rows[2].y = 0;
		rows[2].z = - (far + near) / (far - near);
		rows[2].w = - ( 2.0f * far *near / (far - near));

		rows[3].x = 0;
		rows[3].y = 0;
		rows[3].z = -1;
		rows[3].w = 0;

		*this = Mat4(rows);
	}
	Mat4 operator*(const Mat4& a, const Mat4& b)
	{
		float v[4][4] = {
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				float sum = 0;
				for (int x = 0; x < 4; x++) {
					sum += a.m[i][x] * b.m[x][j];
				}
				v[i][j] = sum;
			}
		}

		return Mat4(v);
	}
	Vec3D operator*(const Vec3D& a, const Mat4& b)
	{
		Vec3D res(0.0f);
		for (int i = 0; i < 3; i++) {
			float sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += a.e[k] * b.m[i][k];
			}

			res.e[i] = sum;
		}
		return res;
	}
	Vec4D operator*(const Vec4D& a, const Mat4& b)
	{
		Vec4D res(0.0f);
		for (int i = 0; i < 4; i++) {
			float sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += a.e[k] * b.m[i][k];
			}

			res.e[i] = sum;
		}
		return res;
	}
	std::ostream& operator<<(std::ostream& out, const Mat4& mat)
	{
		out << "Mat4: \n";
		out << "{\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				out << mat.m[i][j] << ", ";
			}
			out << '\n';
		}
		out << "}\n";
		return out;
	}
}
