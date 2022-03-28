#pragma once


namespace sel {

	template <class T>
	struct Vec4
	{
	public:

		union
		{
			T x = 0;
			T r;
		};

		union
		{
			T y = 0;
			T g;
		};

		union
		{
			T z = 0;
			T b;
		};

		union
		{
			T w = 0;
			T a;
		};

		Vec4() = default;

		Vec4(T x, T y, T z, T w)
			: x(x), y(y), z(z), w(w) {}

		Vec4& operator+=(const Vec4& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		Vec4& operator-=(const Vec4& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

	};

	using Vec4i = Vec4<int>;
	using Vec4u = Vec4<unsigned int>;
	using Vec4f = Vec4<float>;



	template <class T>
	inline bool operator==(const Vec4<T>& lhs, const Vec4<T>& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	template <class T>
	inline bool operator!=(const Vec4<T>& lhs, const Vec4<T>& rhs)
	{ 
		return !(lhs == rhs); 
	}


	template <class T>
	inline Vec4<T> operator+(Vec4<T> lhs, const Vec4<T>& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	template <class T>
	inline Vec4<T> operator-(Vec4<T> lhs, const Vec4<T>& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

}