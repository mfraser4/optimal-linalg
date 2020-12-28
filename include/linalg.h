#ifndef __LINALG_H__
#define __LINALG_H__

#include <cstddef>

namespace linalg
{
	template<class T, std::size_t M, std::size_t N>
	class Matrix
	{
	public:
		T m[M][N];

		constexpr Matrix() : m() {}
		constexpr Matrix(T t) : m()
		{
			for (auto i = 0; i < M; ++i)
				for (auto j = 0; j < N; ++j)
					m[i][j] = t;
		}

		~Matrix() {}
		constexpr std::size_t size() { return M*N; }
		constexpr std::size_t n_rows() { return M; }
		constexpr std::size_t n_cols() { return N; }
	};

	template <class T, std::size_t M> using Vector = Matrix<T, M, 1>;

	template <class T, std::size_t M, std::size_t N, std::size_t P>
	Matrix<T, M, P>& operator*(const Matrix<T, M, N> &a, const Matrix<T, N, P> &b);

	template <class T, std::size_t M, std::size_t N>
	bool operator==(const Matrix<T, M, N> &a, const Matrix<T, M, N> &b)

	template<class T, std::size_t M, std::size_t N> T sum(Matrix<T, M, N> m);

	template<class T, std::size_t M, std::size_t N>
	inline T dot(Matrix<T, M, N> a, Matrix<T, M, N> b) { return sum(a*b); }
}

#endif /* __LINALG_H__ */
