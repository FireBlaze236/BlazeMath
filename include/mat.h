#ifndef MAT_H
#define MAT_H
#include <vector>

#include "constants.h"
#include "vec.h"

// COL x ROW
// 00 10 20 30
// 01 11 21 31
// 02 12 22 32
// 03 13 23 33
namespace BlazeMath {
	struct Mat2 {

	};
	struct Mat3 {

	};
	struct Mat4 {
		Mat4();
		Mat4(float val);
		Mat4(Vec4D rows[4]);
		Mat4(float rows[4][4]);

		inline const float* const GetPtr() const { return &m[0][0]; } ;
		inline auto GetMatPtr() { return m; }

		void Reset();
		void Transpose();
		Mat4 Transposed();
		void SetRotationEulers(const Vec3D& euler);
		void SetTranslation(const Vec3D& translation);
		void SetScale(const Vec3D& scale);
		void SetRotation(const float angleDeg, const Vec3D& axis);
		void LookAt(const Vec3D& eye, const Vec3D& target, const Vec3D& up);
		void Perspective(const float fov, const float aspect, const float near,const float far);
	private:
		float m[4][4];
	public:
		friend Mat4 operator *(const Mat4& a, const Mat4& b);
		friend Vec3D operator *(const Vec3D& a, const Mat4& b);
		friend Vec4D operator *(const Vec4D& a, const Mat4& b);
		friend std::ostream& operator<<(std::ostream& out, const Mat4& mat);
	};


	Mat4 operator *(const Mat4& a, const Mat4& b);
	std::ostream& operator<<(std::ostream& out, const Mat4& mat);
}


#endif