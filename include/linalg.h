#ifndef __OPTIMAL_LINALG_H__
#define __OPTIMAL_LINALG_H__

#include <cassert>
#include <cstddef>

namespace linalg
{
	template<class T, std::size_t M, std::size_t N>
	class Matrix
	{
	protected:
		T _m[M][N];

	public:

		constexpr Matrix() : _m() {}
		constexpr Matrix(const T m[M][N]) : _m()
		{
			for (std::size_t i = 0; i < M; ++i)
				for (std::size_t j = 0; j < N; ++j)
					_m[i][j] = m[i][j];
		}

		constexpr const T* operator[](const std::size_t i) const {
			assert(i < M);
			return _m[i];
		}
	};

	template <class T, std::size_t M>
	class Vector : public Matrix<T, M, 1>
	{
		using Matrix<T, M, 1>::_m;

	public:
		constexpr Vector() : Matrix<T, M, 1>() {}
		constexpr Vector(const T m[M][1]) : Matrix<T, M, 1>(m) {}

		constexpr T operator[](const std::size_t i) const
		{
			assert(i < M);
			return _m[i][0];
		}
	};

	template <class T, std::size_t M, std::size_t N, std::size_t P>
	constexpr Matrix<T, M, P> operator*(const Matrix<T, M, N> &a, const Matrix<T, N, P> &b)
	{
		T c[M][P] = { T() };
		for (std::size_t i=0; i < M; ++i)
			for (std::size_t j=0; j < P; ++j)
				for (std::size_t k=0; k < N; ++k)
					c[i][j] += a[i][k] * b[k][j];

		return Matrix<T, M, P>(c);
	}

	template <class T, std::size_t M, std::size_t N>
	constexpr Matrix<T, M, N> operator*(const T &a, const Matrix<T, M, N> &b)
	{
		T c[M][N] = { T() };
		for (std::size_t i=0; i < M; ++i)
			for (std::size_t j=0; j < N; ++j)
				c[i][j] = a * b[i][j];

		return Matrix<T, M, N>(c);
	}

	template <class T, std::size_t M, std::size_t N>
	constexpr bool operator==(const Matrix<T, M, N> &a, const Matrix<T, M, N> &b)
	{
		for (std::size_t i=0; i < M; ++i)
			for (std::size_t j=0; j < N; ++j)
				if (a[i][j] != b[i][j])
					return false;

		return true;
	}

	template <class T, std::size_t M, std::size_t N>
	constexpr bool operator!=(const Matrix<T, M, N> &a, const Matrix<T, M, N> &b)
	{
		for (std::size_t i=0; i < M; ++i)
			for (std::size_t j=0; j < N; ++j)
				if (a[i][j] != b[i][j])
					return true;

		return false;
	}

	template<class T, std::size_t M, std::size_t N>
	constexpr T sum(const Matrix<T, M, N> m)
	{
		auto s = T();
		for (std::size_t i = 0; i < M; ++i)
			for (std::size_t j = 0; j < N; ++j)
				s += m[i][j];

		return s;
	}

	template<class T, std::size_t M, std::size_t N>
	constexpr T dot(const Matrix<T, M, N> a, const Matrix<T, M, N> b) { return sum(a*b); }
} // namespace linalg

#endif // __OPTIMAL_LINALG_H__
