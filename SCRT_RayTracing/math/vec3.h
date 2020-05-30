#ifndef SCRT_VEC3_H
#define SCRT_VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

namespace SCRT 
{
	template<class T>
	class Vec3
	{
	public:
		T val[3];

		Vec3() {}

		Vec3(T a, T b, T c)
		{
			val[0] = a;
			val[1] = b;
			val[2] = c;
		}

		// XYZ and RGB accessor functions
		// This is redundant but will make code more readable when dealing with vertices or colors
		T x() const { return val[0]; }
		T y() const { return val[1]; }
		T z() const { return val[2]; }
		T r() const { return val[0]; }
		T g() const { return val[1]; }
		T b() const { return val[2]; }

		// In-class overloaded operators
		Vec3<T>& operator+() const { return *this; }
		Vec3<T>& operator-() const { return Vec3<T>(val[0], val[1], val[2]); }

		T operator[](int i) const { return val[i]; }
		T& operator[](int i) { return val[i]; }

		Vec3<T>& operator+=(const Vec3<T>& v);
		Vec3<T>& operator-=(const Vec3<T>& v);
		Vec3<T>& operator*=(const Vec3<T>& v);
		Vec3<T>& operator/=(const Vec3<T>& v);
		Vec3<T>& operator+=(const T s);
		Vec3<T>& operator-=(const T s);
		Vec3<T>& operator*=(const T s);
		Vec3<T>& operator/=(const T s);

		// util functions
		float   length() const;
		float   lengthSq() const;
		Vec3<T> getUnitVec() const;
		void    normalize();
	};

	template<class T>
	Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator*=(const Vec3<T>& v)
	{
		val[0] *= v.val[0];
		val[1] *= v.val[1];
		val[2] *= v.val[2];
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator/=(const Vec3<T>& v)
	{
		val[0] /= v.val[0];
		val[1] /= v.val[1];
		val[2] /= v.val[2];
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator+=(const T s)
	{
		val[0] += s;
		val[1] += s;
		val[2] += s;
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator-=(const T s)
	{
		val[0] -= s;
		val[1] -= s;
		val[2] -= s;
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator*=(const T s)
	{
		val[0] *= s;
		val[1] *= s;
		val[2] *= s;
		return *this;
	}

	template<class T>
	Vec3<T>& Vec3<T>::operator/=(const T s)
	{
		val[0] /= s;
		val[1] /= s;
		val[2] /= s;
		return *this;
	}

	// util functions
	template<class T>
	float Vec3<T>::length() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}

	template<class T>
	float Vec3<T>::lengthSq() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	template<class T>
	void Vec3<T>::normalize()
	{
		float k = 1.0 / length();
		val[0] *= k;
		val[1] *= k;
		val[2] *= k;
	}

	template<class T>
	Vec3<T> Vec3<T>::getUnitVec() const
	{
		Vec3<T> result = Vec3<T>(val[0], val[1], val[2]);
		result.normalize();
		return result;
	}

	// external overloaded operators
	template<class T>
	std::istream& operator>>(std::istream& stream, Vec3<T>& v)
	{
		stream >> v.val[0] >> v.val[1] >> v.val[2];
		return stream;
	}

	template<class T>
	std::istream& operator<<(std::istream& stream, Vec3<T>& v)
	{
		stream << v.val[0] << " " << v.val[1] << " " << v.val[2];
		return stream;
	}

	template<class T>
	Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>(v1.val[0] + v2.val[0], v1.val[1] + v2.val[1], v1.val[2] + v2.val[2]);
	}

	template<class T>
	Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>(v1.val[0] - v2.val[0], v1.val[1] - v2.val[1], v1.val[2] - v2.val[2]);
	}

	template<class T>
	Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>(v1.val[0] * v2.val[0], v1.val[1] * v2.val[1], v1.val[2] * v2.val[2]);
	}

	template<class T>
	Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>(v1.val[0] / v2.val[0], v1.val[1] / v2.val[1], v1.val[2] / v2.val[2]);
	}

	template<class T>
	Vec3<T> operator+(const Vec3<T>& v, T s)
	{
		return Vec3<T>(v.val[0] + s, v.val[1] + s, v.val[2] + s);
	}

	template<class T>
	Vec3<T> operator+(T s, const Vec3<T>& v)
	{
		return Vec3<T>(v.val[0] + s, v.val[1] + s, v.val[2] + s);
	}

	template<class T>
	Vec3<T> operator-(const Vec3<T>& v, T s)
	{
		return Vec3<T>(v.val[0] - s, v.val[1] - s, v.val[2] - s);
	}

	template<class T>
	Vec3<T> operator-(T s, const Vec3<T>& v)
	{
		return Vec3<T>(v.val[0] - s, v.val[1] - s, v.val[2] - s);
	}

	template<class T>
	Vec3<T> operator*(const Vec3<T>& v, T s)
	{
		return Vec3<T>(v.val[0] * s, v.val[1] * s, v.val[2] * s);
	}

	template<class T>
	Vec3<T> operator*(T s, const Vec3<T>& v)
	{
		return Vec3<T>(v.val[0] * s, v.val[1] * s, v.val[2] * s);
	}

	template<class T>
	Vec3<T> operator/(const Vec3<T>& v, T s)
	{
		return Vec3<T>(v.val[0] / s, v.val[1] / s, v.val[2] / s);
	}

	// external util functions
	template<class T>
	T dot(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return v1.val[0] * v2.val[0] + v1.val[1] * v2.val[1] + v1.val[2] * v2.val[2];
	}

	template<class T>
	T cross(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>((v1.val[1] * v2.val[2] - v1.val[2] * v2.val[1]),
			((v1.val[0] * v2.val[2] * -1) - v1.val[2] * v2.val[0]),
			(v1.val[0] * v2.val[1] - v1.val[1] * v2.val[0]));
	}
}

#endif // SCRT_VEC3_H
