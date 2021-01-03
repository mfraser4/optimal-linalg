#include "../include/linalg.h"

using namespace linalg;

// Trivial matrices
constexpr int a1[1][1] = { {4} };
constexpr int a2[1][1] = { {4} };
constexpr int a3[1][1] = { {8} };
constexpr int a4[1][1] = { {32} };

constexpr Matrix<int, 1, 1> m1(a1);
constexpr Matrix<int, 1, 1> m2(a2);
constexpr Matrix<int, 1, 1> m3(a3);
constexpr Matrix<int, 1, 1> m4(a4);

static_assert(m1[0][0] == 4, "linalg::Matrix::operator[] should be constexpr");
static_assert(m1 == m2, "linalg::Matrix::operator== should be constexpr");
static_assert(m1 != m3, "linalg::Matrix::operator!= should be constexpr");
static_assert((m1 * m3) == m4, "linalg::Matrix::operator* and operator== should be constexpr");
static_assert((2 * m2) == m3, "linalg::Matrix::operator* and operator== should be constexpr");

// Trivial vectors
constexpr Vector<int, 1> v1(a1);
constexpr Vector<int, 1> v2(a2);
constexpr Vector<int, 1> v3(a3);
constexpr Vector<int, 1> v4(a4);

static_assert(v1[0] == 4, "linalg::Vector::operator[] should be constexpr");
static_assert(v1 == v2, "linalg::Vector::operator== should be constexpr");
static_assert(v1 != v3, "linalg::Vector::operator!= should be constexpr");
static_assert((v1 * v3) == v4, "linalg::Vector::operator* should be constexpr");

// 2x2 matrices
constexpr float b1[2][2] = { {1.0f, 2.0f}, {3.0f, 4.0f} };
constexpr float b2[2][2] = { {2.0f, 4.0f}, {6.0f, 8.0f} };

constexpr Matrix<float, 2, 2> m5(b1);
constexpr Matrix<float, 2, 2> m6(b2);

static_assert(m5 != m6, "linalg::Matrix::operator!= should be constexpr");
static_assert((2.0f * m5) == m6, "linalg::Matrix::operator* and operator== should be constexpr");

// 2d vectors
constexpr float c1[2][1] = { {1.0f}, {2.0f} };
constexpr float c2[2][1] = { {2.0f}, {4.0f} };

constexpr Vector<float, 2> v5(c1);
constexpr Vector<float, 2> v6(c2);

static_assert(v5 != v6, "linalg::Vector::operator!= should be constexpr");
static_assert((2.0f * v5) == v6, "linalg::Vector::operator* and operator== should be constexpr");

// MxN matrix times NxP matrix
constexpr double d1[3][2] =
{
	{1.0, 2.0},
	{3.0, 4.0},
	{5.0, 6.0},
};

constexpr double d2[2][4] =
{
	{8.0,  9.0,  10.0, 11.0},
	{12.0, 13.0, 14.0, 15.0},
};

constexpr double d3[3][4] =
{
	{32.0,  35.0,  38.0,  41.0},
	{72.0,  79.0,  86.0,  93.0},
	{112.0, 123.0, 134.0, 145.0},
};

constexpr Matrix<double, 3, 2> m7(d1);
constexpr Matrix<double, 2, 4> m8(d2);
constexpr Matrix<double, 3, 4> m9(d3);

static_assert((m7 * m8) == m9, "linalg::Matrix::operator* should be constexpr");

// Mx1 matrices and vectors should be checkable for equivalence
static_assert(Matrix<float, 2, 1>(c1) == Vector<float, 2>(c1));

// TODO: check that matrix value can be changed at runtime
