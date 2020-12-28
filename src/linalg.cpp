#include "linalg.h"

using namespace linalg;

template <class T, std::size_t M, std::size_t N, std::size_t P>
Matrix<T, M, P> operator*(const Matrix<T, M, N> &a, const Matrix<T, N, P> &b)
{
	Matrix<T, M, P> c(T());
	for (auto i=0; i < M; ++i)
		for (auto j=0; j < P; ++j)
			for (auto k=0; k < N; ++k)
				c.m[i][j] += a.m[i][k] * b.m[k][j];

	return c;
}

template <class T, std::size_t M, std::size_t N>
bool operator==(const Matrix<T, M, N> &a, const Matrix<T, M, N> &b)
{
	for (auto i=0; i < M; ++i)
		for (auto j=0; j < N; ++j)
			if (a.m[i][j] != b.m[i][j]) return false;

	return true;
}

template <class T, std::size_t M, std::size_t N>
const T sum(Matrix<T, M, N> m)
{
	auto s = T();
	for (auto i=0; i < M; ++i)
		for (auto j=0; j < N; ++j)
			s += m.m[i][j];

	return s;
}
