#include <gtest/gtest.h>
#include "vec.h"

namespace VectorTests {

	TEST(Vector2DTests, Vector2DConstructorEmpty) {
		using namespace BlazeMath;
		Vec2D a;
		EXPECT_FLOAT_EQ(a.x, 0);
		EXPECT_FLOAT_EQ(a.y, 0);
	}

	TEST(Vector2DTests, Vector2DConstructorFloat) {
		using namespace BlazeMath;
		Vec2D a(1.0f);
		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);

		Vec2D b(1.0f, 2.0f);
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 2.0f);
	}

	TEST(Vector2DTests, Vector2DLength) {
		using namespace BlazeMath;
		Vec2D a(3.0f, 4.0f);
		EXPECT_FLOAT_EQ(a.length_squared(), 25.0f);
		EXPECT_FLOAT_EQ(a.length(), 5.0f);
	}

	TEST(Vector2DTests, Vector2DOperatorAssign) {
		using namespace BlazeMath;
		Vec2D a(1.0f, 1.0f);
		Vec2D b = a;
		EXPECT_FLOAT_EQ(b.x, a.x);
		EXPECT_FLOAT_EQ(b.y, a.y);
	}

	TEST(Vector2DTests, Vector2DOperatorAssignAdd) {
		using namespace BlazeMath;
		Vec2D a(1.0f, 1.0f);
		Vec2D b(1.0f, 2.0f);
		b += a;
		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);
		EXPECT_FLOAT_EQ(b.x, 2.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
	}
	TEST(Vector2DTests, Vector2DAddOperator) {
		using namespace BlazeMath;
		Vec2D a(1.0f, 1.0f);
		Vec2D b(1.0f, 2.0f);
		Vec2D c = a + b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
	}
	TEST(Vector2DTests, Vector2DSubOperator) {
		using namespace BlazeMath;
		Vec2D a(1.0f, 1.0f);
		Vec2D b(1.0f, 2.0f);
		Vec2D c = a - b;
		EXPECT_FLOAT_EQ(c.x, 0.0f);
		EXPECT_FLOAT_EQ(c.y, -1.0f);
	}

	TEST(Vector2DTests, Vector2DOperatorAssignSub) {
		using namespace BlazeMath;
		Vec2D a(1.0f, 1.0f);
		Vec2D b(1.0f, 2.0f);
		b -= a;
		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);
		EXPECT_FLOAT_EQ(b.x, 0.0f);
		EXPECT_FLOAT_EQ(b.y, 1.0f);
	}

	TEST(Vector2DTests, Vector2DOperatorAssignElementMul) {
		using namespace BlazeMath;
		Vec2D a(3.0f, 4.0f);
		Vec2D b(3.0f, 3.0f);
		b *= a;
		EXPECT_FLOAT_EQ(b.x, 9.0f);
		EXPECT_FLOAT_EQ(b.y, 12.0f);
	}
	TEST(Vector2DTests, Vector2DOperatorAssignElementDiv) {
		using namespace BlazeMath;
		Vec2D a(3.0f, 3.0f);
		Vec2D b(3.0f, 9.0f);
		b /= a;
		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 3.0f);
	}
	TEST(Vector2DTests, Vector2DOperatorFloatMul) {
		using namespace BlazeMath;
		Vec2D a(3.0f, 4.0f);
		float f = 3.0f;
		a *= f;
		EXPECT_FLOAT_EQ(a.x, 9.0f);
		EXPECT_FLOAT_EQ(a.y, 12.0f);
	}
	TEST(Vector2DTests, Vector2DOperatorFloatDiv) {
		using namespace BlazeMath;
		Vec2D a(12.0f, 6.0f);
		float f = 3.0f;
		a /= f;
		EXPECT_FLOAT_EQ(a.x, 4.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
	}
	TEST(Vector2DTests, Vector2DElemMulOperator) {
		using namespace BlazeMath;
		Vec2D a(2.0f, 3.0f);
		Vec2D b(2.0f, 2.0f);
		Vec2D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
	}
	TEST(Vector2DTests, Vector2DFloatMulOperator) {
		using namespace BlazeMath;
		Vec2D a(2.0f, 3.0f);
		float b = 2.0f;
		Vec2D c = a * b;
		EXPECT_FLOAT_EQ(c.x, 4.0f);
		EXPECT_FLOAT_EQ(c.y, 6.0f);
	}
	TEST(Vector2DTests, Vector2DFloatDivOperator) {
		using namespace BlazeMath;
		Vec2D a(4.0f, 6.0f);
		float b = 2.0f;
		Vec2D c = a / b;
		EXPECT_FLOAT_EQ(c.x, 2.0f);
		EXPECT_FLOAT_EQ(c.y, 3.0f);
	}

	TEST(Vector2DTests, Vector2DNormalizationTests) {
		using namespace BlazeMath;
		Vec2D a(4.0f, 6.0f);
		Vec2D b = a.normalized();
		EXPECT_FLOAT_EQ(b.length(), 1.0f);
		a.normalize();
		EXPECT_FLOAT_EQ(a.length(), 1.0f);
	}


}
