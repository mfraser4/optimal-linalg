#include "CppUTest/TestHarness.h"
#include "../include/linalg.h"

TEST_GROUP(ConstMatrixOps) {};

TEST(ConstMatrixOps, Set)
{
	linalg::Matrix<int, 2, 2> mat;
	LONGS_EQUAL(mat[0][0], 0);
	LONGS_EQUAL(mat[0][1], 0);
	LONGS_EQUAL(mat[1][0], 0);
	LONGS_EQUAL(mat[1][1], 0);

	mat.set(0, 0, 4);
	mat.set(0, 1, 3);
	mat.set(1, 0, 2);
	mat.set(1, 1, 1);

	LONGS_EQUAL(mat[0][0], 4);
	LONGS_EQUAL(mat[0][1], 3);
	LONGS_EQUAL(mat[1][0], 2);
	LONGS_EQUAL(mat[1][1], 1);
}

TEST(ConstMatrixOps, Add)
{
	int vals1[2][3] = {
		{1, 2, 3},
		{4, 5, 6},
	};
	linalg::Matrix<int, 2, 3> a(vals1);

	int vals2[2][3] = {
		{7,  8,  9},
		{10, 11, 12},
	};
	linalg::Matrix<int, 2, 3> b(vals2);

	int vals3[2][3] = {
		{8,  10, 12},
		{14, 16, 18},
	};
	linalg::Matrix<int, 2, 3> c(vals3);

	CHECK_TEXT(a + b == c, "a + b = c FAILED");
}
