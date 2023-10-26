#include <gtest/gtest.h>

#include "mat.h"

namespace MatrixTests {
	void TestMat4ValuesEq(float m[4][4], float e[4][4]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				EXPECT_NEAR(m[i][j], e[i][j], 0.1f) << "Matrices not equal at:" << i << "," << j;
			}
		}

	}
	TEST(Mat4Tests, Mat4ConstructorEmpty) {
		using namespace BlazeMath;

		Mat4 mat;
		auto a = mat.GetMatPtr();
		float e[4][4] = {
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		TestMat4ValuesEq(a, e);
	}
	TEST(Mat4Tests, Mat4ConstructorFloatArrays) {
		using namespace BlazeMath;
		float v[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 2, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};

		Mat4 mat(v);
		auto a = mat.GetMatPtr();
		float e[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 2, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};
		TestMat4ValuesEq(a, e);
	}
	TEST(Mat4Tests, Mat4ConstructorFloat) {
		using namespace BlazeMath;

		Mat4 mat(1.0f);
		auto a = mat.GetMatPtr();
		float e[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};
		TestMat4ValuesEq(a, e);
	}

	TEST(Mat4Tests, Mat4ConstructorVec4) {
		using namespace BlazeMath;
		Vec4D a[4] = {
			Vec4D(1, 0, 0, 0),
			Vec4D(0, 1, 2, 0),
			Vec4D(0, 0, 1, 0),
			Vec4D(0, 0, 0, 1),
		};
		Mat4 mat(a);

		auto x = mat.GetMatPtr();
		float e[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 2, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};
		TestMat4ValuesEq(x, e);
	}
	
	TEST(Mat4Tests, Mat4SetMultiplicationTest) {
		using namespace BlazeMath;
		float v[4][4] = {
			{1, 2, 3, 4},
			{4, 3, 2, 1},
			{1, 2, 3, 4},
			{4, 3, 2, 1}
		};

		Mat4 mata(v), matb(v);
		Mat4 mat = mata * matb;
		auto a = mat.GetMatPtr();
		float e[4][4] = {
			{28, 26, 24, 22},
			{22, 24, 26, 28},
			{28, 26, 24, 22},
			{22, 24, 26, 28}
		};

		TestMat4ValuesEq(a, e);
	}


	TEST(Mat4Tests, Mat4SetTranslationTest) {
		using namespace BlazeMath;
		Mat4 t(1.0f);
		t.SetTranslation(Vec3D(2, 3, 4));

		Mat4 mat(1.0f);
		mat = mat * t;

		auto x = mat.GetMatPtr();
		float e[4][4] = {
			{1, 0, 0, 2},
			{0, 1, 0, 3},
			{0, 0, 1, 4},
			{0, 0, 0, 1}
		};
		TestMat4ValuesEq(x, e);
	}
	TEST(Mat4Tests, Mat4SetScaleTest) {
		using namespace BlazeMath;
		Mat4 t(1.0f);
		t.SetScale(2.0f);

		Mat4 mat(1.0f);
		mat = mat * t;

		auto x = mat.GetMatPtr();
		float e[4][4] = {
			{2, 0, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 1}
		};
		TestMat4ValuesEq(x, e);
	}

	TEST(Mat4Tests, Mat4SetRotationTest) {
		using namespace BlazeMath;
		Mat4 t(1.0f);
		float angle = 64.0f;
		t.SetRotation(angle, Vec3D(0.74f, 0.06f, 0.67f));

		Mat4 mat(1.0f);
		mat = mat * t;

		auto x = mat.GetMatPtr();
		float e[4][4] = {
			{0.7458884, -0.5772281,  0.3323527, 0.0f},
			{0.6270958,  0.4403928, -0.6424991, 0.0f},
			{0.2245028,  0.6876495,  0.6904612, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};
		TestMat4ValuesEq(x, e);
	}

}