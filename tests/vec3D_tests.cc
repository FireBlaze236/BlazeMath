#include <gtest/gtest.h>
#include "vec.h"

namespace VectorTests {

	TEST(Vector3DTests, Vector3DConstructorEmpty) {
		using namespace BlazeMath;
		Vec3D a;
		EXPECT_FLOAT_EQ(a.x, 0);
		EXPECT_FLOAT_EQ(a.y, 0);
		EXPECT_FLOAT_EQ(a.z, 0);
	}

	TEST(Vector3DTests, Vector3DConstructorFloat) {
		using namespace BlazeMath;
		Vec3D a(1.0f);
		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);

		Vec3D b(1.0f, 2.0f, 3.0f);
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 2.0f);
		EXPECT_FLOAT_EQ(b.z, 3.0f);
	}

	TEST(Vector3DTests, Vector3DLength) {
		using namespace BlazeMath;
		Vec3D a(2.0f, 2.0f, 2.0f);
		EXPECT_FLOAT_EQ(a.length_squared(), 12.0f);
		EXPECT_FLOAT_EQ(a.length(), std::sqrtf(12.0f));
	}

	TEST(Vector3DTests, Vector3DOperatorAssign) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 1.0f, 1.0f);
		Vec3D b = a;
		EXPECT_FLOAT_EQ(b.x, a.x);
		EXPECT_FLOAT_EQ(b.y, a.y);
		EXPECT_FLOAT_EQ(b.z, a.z);
	}

	TEST(Vector3DTests, Vector3DOperatorAssignAdd) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 1.0f, 1.0f);
		Vec3D b(1.0f, 2.0f, 3.0f);
		b += a;
		EXPECT_FLOAT_EQ(b.x, 2.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
		EXPECT_FLOAT_EQ(b.z, 4.0f);
	}
	TEST(Vector3DTests, Vector3DAddOperator) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 1.0f, 1.0f);
		Vec3D b(1.0f, 2.0f, 3.0f);
		Vec3D c = a + b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
		EXPECT_FLOAT_EQ(c.z, 4.0f);
	}
	TEST(Vector3DTests, Vector3DSubOperator) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 1.0f, 1.0f);
		Vec3D b(1.0f, 2.0f, 3.0f);
		Vec3D c = a - b;
		EXPECT_FLOAT_EQ(c.x, 0.0f);
		EXPECT_FLOAT_EQ(c.y, -1.0f);
		EXPECT_FLOAT_EQ(c.z, -2.0f);
	}

	TEST(Vector3DTests, Vector3DOperatorAssignSub) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 1.0f, 1.0f);
		Vec3D b(1.0f, 2.0f, 3.0f);
		b -= a;
		EXPECT_FLOAT_EQ(b.x, 0.0f);
		EXPECT_FLOAT_EQ(b.y, 1.0f);
		EXPECT_FLOAT_EQ(b.z, 2.0f);
	}

	TEST(Vector3DTests, Vector3DOperatorAssignElementMul) {
		using namespace BlazeMath;
		Vec3D a(3.0f, 4.0f, 2.0f);
		Vec3D b(3.0f, 3.0f, 2.0f);
		b *= a;
		EXPECT_FLOAT_EQ(b.x, 9.0f);
		EXPECT_FLOAT_EQ(b.y, 12.0f);
		EXPECT_FLOAT_EQ(b.z, 4.0f);
	}
	TEST(Vector3DTests, Vector3DOperatorAssignElementDiv) {
		using namespace BlazeMath;
		Vec3D a(3.0f, 3.0f, 2.0f);
		Vec3D b(3.0f, 9.0f, 4.0f);
		b /= a;
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
		EXPECT_FLOAT_EQ(b.z, 2.0f);
	}
	TEST(Vector3DTests, Vector3DOperatorFloatMul) {
		using namespace BlazeMath;
		Vec3D a(3.0f, 4.0f, 3.0f);
		float f = 3.0f;
		a *= f;
		EXPECT_FLOAT_EQ(a.x, 9.0f);
		EXPECT_FLOAT_EQ(a.y, 12.0f);
		EXPECT_FLOAT_EQ(a.z, 9.0f);
	}
	TEST(Vector3DTests, Vector3DOperatorFloatDiv) {
		using namespace BlazeMath;
		Vec3D a(12.0f, 6.0f, 3.0f);
		float f = 3.0f;
		a /= f;
		EXPECT_FLOAT_EQ(a.x, 4.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
	}
	TEST(Vector3DTests, Vector3DElemMulOperator) {
		using namespace BlazeMath;
		Vec3D a(2.0f, 3.0f, 4.0f);
		Vec3D b(2.0f, 2.0f, 2.0f);
		Vec3D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
		EXPECT_FLOAT_EQ(c.z, 8.0f);
	}
	TEST(Vector3DTests, Vector3DFloatMulOperator) {
		using namespace BlazeMath;
		Vec3D a(2.0f, 3.0f, 5.0f);
		float b = 2.0f;
		Vec3D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
		EXPECT_FLOAT_EQ(c.z, 10.0f);
	}
	TEST(Vector3DTests, Vector3DFloatDivOperator) {
		using namespace BlazeMath;
		Vec3D a(4.0f, 6.0f, 5.0f);
		float b = 2.0f;
		Vec3D c = a / b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
		EXPECT_FLOAT_EQ(c.z, 2.5f);
	}

	TEST(Vector3DTests, Vector3DNormalizationTests) {
		using namespace BlazeMath;
		Vec3D a(4.0f, 6.0f, 12.0f);
		Vec3D b = a.normalized();
		EXPECT_FLOAT_EQ(b.length(), 1.0f);
		a.normalize();
		EXPECT_FLOAT_EQ(a.length(), 1.0f);
	}

	TEST(Vector3DTests, Vector3DDot) {
		using namespace BlazeMath;
		Vec3D a(1.0f, 0.0f, 0.0f);
		Vec3D b(0.0f, 1.0f, 0.0f);
		Vec3D c(-1.0f, 1.0f, 0.0f);
		EXPECT_FLOAT_EQ(a.dot(b), 0.0f);
		EXPECT_FLOAT_EQ(b.dot(a), 0.0f);
		EXPECT_FLOAT_EQ(a.dot(c), -1.0f);
		Vec3D x(0.5f, 0.5f, 0.0f);
		ASSERT_TRUE(x.dot(a) > 0.0f);
	}

	TEST(Vector3DTests, Vector3DCross) {
		using namespace BlazeMath;
		Vec3D a(12.0f, 30.0f, 40.0f);
		Vec3D b(2.0f, 12.0f, 2.0f);
		Vec3D x = cross(a, b);
		EXPECT_FLOAT_EQ(x.x, -420.0f);
		EXPECT_FLOAT_EQ(x.y, 56.0f);
		EXPECT_FLOAT_EQ(x.z, 84.0f);
	}

}
