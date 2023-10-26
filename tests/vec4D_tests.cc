#include <gtest/gtest.h>
#include "vec.h"

namespace VectorTests {

	TEST(Vector4DTests, Vector4DConstructorEmpty) {
		using namespace BlazeMath;
		Vec4D a;
		EXPECT_FLOAT_EQ(a.x, 0);
		EXPECT_FLOAT_EQ(a.y, 0);
		EXPECT_FLOAT_EQ(a.z, 0);
		EXPECT_FLOAT_EQ(a.w, 0);
	}

	TEST(Vector4DTests, Vector4DConstructorFloat) {
		using namespace BlazeMath;
		Vec4D a(1.0f);
		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
		EXPECT_FLOAT_EQ(a.w, 1.0f);

		Vec4D b(1.0f, 2.0f, 3.0f, 4.0f);
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 2.0f);
		EXPECT_FLOAT_EQ(b.z, 3.0f);
		EXPECT_FLOAT_EQ(b.w, 4.0f);
	}

	TEST(Vector4DTests, Vector4DLength) {
		using namespace BlazeMath;
		Vec4D a(2.0f, 2.0f, 2.0f, 2.0f);
		EXPECT_FLOAT_EQ(a.length_squared(), 16.0f);
		EXPECT_FLOAT_EQ(a.length(), 4.0f);
	}

	TEST(Vector4DTests, Vector4DOperatorAssign) {
		using namespace BlazeMath;
		Vec4D a(1.0f, 1.0f, 1.0f, 1.0f);
		Vec4D b = a;
		EXPECT_FLOAT_EQ(b.x, a.x);
		EXPECT_FLOAT_EQ(b.y, a.y);
		EXPECT_FLOAT_EQ(b.z, a.z);
		EXPECT_FLOAT_EQ(b.w, a.w);
	}

	TEST(Vector4DTests, Vector4DOperatorAssignAdd) {
		using namespace BlazeMath;
		Vec4D a(1.0f, 1.0f, 1.0f, 1.0f);
		Vec4D b(1.0f, 2.0f, 3.0f, 4.0f);
		b += a;
		EXPECT_FLOAT_EQ(b.x, 2.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
		EXPECT_FLOAT_EQ(b.z, 4.0f);
		EXPECT_FLOAT_EQ(b.w, 5.0f);
	}
	TEST(Vector4DTests, Vector4DAddOperator) {
		using namespace BlazeMath;
		Vec4D a(1.0f, 1.0f, 1.0f, 1.0f);
		Vec4D b(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4D c = a + b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
		EXPECT_FLOAT_EQ(c.z, 4.0f);
		EXPECT_FLOAT_EQ(c.w, 5.0f);
	}
	TEST(Vector4DTests, Vector4DSubOperator) {
		using namespace BlazeMath;
		Vec4D a(1.0f, 1.0f, 1.0f, 1.0f);
		Vec4D b(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4D c = a - b;
		EXPECT_FLOAT_EQ(c.x, 0.0f);
		EXPECT_FLOAT_EQ(c.y, -1.0f);
		EXPECT_FLOAT_EQ(c.z, -2.0f);
		EXPECT_FLOAT_EQ(c.w, -3.0f);
	}

	TEST(Vector4DTests, Vector4DOperatorAssignSub) {
		using namespace BlazeMath;
		Vec4D a(1.0f, 1.0f, 1.0f, 1.0f);
		Vec4D b(1.0f, 2.0f, 3.0f, 4.0f);
		b -= a;
		EXPECT_FLOAT_EQ(b.x, 0.0f);
		EXPECT_FLOAT_EQ(b.y, 1.0f);
		EXPECT_FLOAT_EQ(b.z, 2.0f);
		EXPECT_FLOAT_EQ(b.w, 3.0f);
	}

	TEST(Vector4DTests, Vector4DOperatorAssignElementMul) {
		using namespace BlazeMath;
		Vec4D a(3.0f, 4.0f, 2.0f, 1.0f);
		Vec4D b(3.0f, 3.0f, 2.0f, 6.0f);
		b *= a;
		EXPECT_FLOAT_EQ(b.x, 9.0f);
		EXPECT_FLOAT_EQ(b.y, 12.0f);
		EXPECT_FLOAT_EQ(b.z, 4.0f);
		EXPECT_FLOAT_EQ(b.w, 6.0f);
	}
	TEST(Vector4DTests, Vector4DOperatorAssignElementDiv) {
		using namespace BlazeMath;
		Vec4D a(3.0f, 3.0f, 2.0f, 5.0f);
		Vec4D b(3.0f, 9.0f, 4.0f, 20.0f);
		b /= a;
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
		EXPECT_FLOAT_EQ(b.z, 2.0f);
		EXPECT_FLOAT_EQ(b.w, 4.0f);
	}
	TEST(Vector4DTests, Vector4DOperatorFloatMul) {
		using namespace BlazeMath;
		Vec4D a(3.0f, 4.0f, 3.0f, 12.0f);
		float f = 3.0f;
		a *= f;
		EXPECT_FLOAT_EQ(a.x, 9.0f);
		EXPECT_FLOAT_EQ(a.y, 12.0f);
		EXPECT_FLOAT_EQ(a.z, 9.0f);
		EXPECT_FLOAT_EQ(a.w, 36.0f);
	}
	TEST(Vector4DTests, Vector4DOperatorFloatDiv) {
		using namespace BlazeMath;
		Vec4D a(12.0f, 6.0f, 3.0f, 18.0f);
		float f = 3.0f;
		a /= f;
		EXPECT_FLOAT_EQ(a.x, 4.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
		EXPECT_FLOAT_EQ(a.w, 6.0f);
	}
	TEST(Vector4DTests, Vector4DElemMulOperator) {
		using namespace BlazeMath;
		Vec4D a(2.0f, 3.0f, 4.0f, 5.0f);
		Vec4D b(2.0f, 2.0f, 2.0f, 2.0f);
		Vec4D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
		EXPECT_FLOAT_EQ(c.z, 8.0f);
		EXPECT_FLOAT_EQ(c.w, 10.0f);
	}
	TEST(Vector4DTests, Vector4DFloatMulOperator) {
		using namespace BlazeMath;
		Vec4D a(2.0f, 3.0f, 5.0f, 6.0f);
		float b = 2.0f;
		Vec4D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
		EXPECT_FLOAT_EQ(c.z, 10.0f);
		EXPECT_FLOAT_EQ(c.w, 12.0f);
	}
	TEST(Vector4DTests, Vector4DFloatDivOperator) {
		using namespace BlazeMath;
		Vec4D a(4.0f, 6.0f, 5.0f, 22.0f);
		float b = 2.0f;
		Vec4D c = a / b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
		EXPECT_FLOAT_EQ(c.z, 2.5f);
		EXPECT_FLOAT_EQ(c.w, 11.0f);
	}

	TEST(Vector4DTests, Vector4DNormalizationTests) {
		using namespace BlazeMath;
		Vec4D a(4.0f, 6.0f, 12.0f, 11.0f);
		Vec4D b = a.normalized();
		EXPECT_FLOAT_EQ(b.length(), 1.0f);
		a.normalize();
		EXPECT_FLOAT_EQ(a.length(), 1.0f);
	}

	TEST(Vector4DTests, Vector4DDot) {
		using namespace BlazeMath;
		Vec4D a(12.0f, 30.0f, 40.0f, 80.0f);
		Vec4D b(2.0f, 12.0f, 2.0f, 20.0f);
		float c = a.dot(b);
		EXPECT_FLOAT_EQ(c, 2064);
	}

}
