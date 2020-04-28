#ifndef SCRT_VEC3_H
#define SCRT_VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

namespace SCRT 
{
	template<class T>
	class vec3
	{
	public:
		T val[3];

		vec3() {}

		vec3(T a, T b, T c)
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
		vec3<T>& operator+() const { return *this; }
		vec3<T>& operator-() const { return vec3<T>(val[0], val[1], val[2]); }

		T operator[](int i) const { return val[i]; }
		T& operator[](int i) { return val[i]; }

		vec3<T>& operator+=(const vec3<T>& v);
		vec3<T>& operator-=(const vec3<T>& v);
		vec3<T>& operator*=(const vec3<T>& v);
		vec3<T>& operator/=(const vec3<T>& v);
		vec3<T>& operator+=(const T s);
		vec3<T>& operator-=(const T s);
		vec3<T>& operator*=(const T s);
		vec3<T>& operator/=(const T s);

		// util functions
		float   length() const;
		float   lengthSq() const;
		vec3<T> getUnitVec() const;
		void    normalize();
	};

	template<class T>
	vec3<T>& vec3<T>::operator+=(const vec3<T>& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator-=(const vec3<T>& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator*=(const vec3<T>& v)
	{
		val[0] *= v.val[0];
		val[1] *= v.val[1];
		val[2] *= v.val[2];
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator/=(const vec3<T>& v)
	{
		val[0] /= v.val[0];
		val[1] /= v.val[1];
		val[2] /= v.val[2];
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator+=(const T s)
	{
		val[0] += s;
		val[1] += s;
		val[2] += s;
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator-=(const T s)
	{
		val[0] -= s;
		val[1] -= s;
		val[2] -= s;
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator*=(const T s)
	{
		val[0] *= s;
		val[1] *= s;
		val[2] *= s;
		return *this;
	}

	template<class T>
	vec3<T>& vec3<T>::operator/=(const T s)
	{
		val[0] /= s;
		val[1] /= s;
		val[2] /= s;
		return *this;
	}

	// util functions
	template<class T>
	float vec3<T>::length() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}

	template<class T>
	float vec3<T>::lengthSq() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	template<class T>
	void vec3<T>::normalize()
	{
		float k = 1.0 / length();
		val[0] *= k;
		val[1] *= k;
		val[2] *= k;
	}

	template<class T>
	vec3<T> vec3<T>::getUnitVec() const
	{
		vec3<T> result = vec3<T>(val[0], val[1], val[2]);
		result.normalize();
		return result;
	}

	// external overloaded operators
	template<class T>
	std::istream& operator>>(std::istream& stream, vec3<T>& v)
	{
		stream >> v.val[0] >> v.val[1] >> v.val[2];
		return stream;
	}

	template<class T>
	std::istream& operator<<(std::istream& stream, vec3<T>& v)
	{
		stream << v.val[0] << " " << v.val[1] << " " << v.val[2];
		return stream;
	}

	template<class T>
	vec3<T> operator+(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>(v1.val[0] + v2.val[0], v1.val[1] + v2.val[1], v1.val[2] + v2.val[2]);
	}

	template<class T>
	vec3<T> operator-(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>(v1.val[0] - v2.val[0], v1.val[1] - v2.val[1], v1.val[2] - v2.val[2]);
	}

	template<class T>
	vec3<T> operator*(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>(v1.val[0] * v2.val[0], v1.val[1] * v2.val[1], v1.val[2] * v2.val[2]);
	}

	template<class T>
	vec3<T> operator/(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>(v1.val[0] / v2.val[0], v1.val[1] / v2.val[1], v1.val[2] / v2.val[2]);
	}

	template<class T>
	vec3<T> operator+(const vec3<T>& v, T s)
	{
		return vec3<T>(v.val[0] + s, v.val[1] + s, v.val[2] + s);
	}

	template<class T>
	vec3<T> operator+(T s, const vec3<T>& v)
	{
		return vec3<T>(v.val[0] + s, v.val[1] + s, v.val[2] + s);
	}

	template<class T>
	vec3<T> operator-(const vec3<T>& v, T s)
	{
		return vec3<T>(v.val[0] - s, v.val[1] - s, v.val[2] - s);
	}

	template<class T>
	vec3<T> operator-(T s, const vec3<T>& v)
	{
		return vec3<T>(v.val[0] - s, v.val[1] - s, v.val[2] - s);
	}
	
	template<class T>
	vec3<T> operator*(const vec3<T>& v, T s)
	{
		return vec3<T>(v.val[0] * s, v.val[1] * s, v.val[2] * s);
	}

	template<class T>
	vec3<T> operator*(T s, const vec3<T>& v)
	{
		return vec3<T>(v.val[0] * s, v.val[1] * s, v.val[2] * s);
	}
	
	template<class T>
	vec3<T> operator/(const vec3<T>& v, T s)
	{
		return vec3<T>(v.val[0] / s, v.val[1] / s, v.val[2] / s);
	}

	// external util functions
	template<class T>
	T dot(const vec3<T>& v1, const vec3<T>& v2)
	{
		return v1.val[0] * v2.val[0] + v1.val[1] * v2.val[1] + v1.val[2] * v2.val[2];
	}

	template<class T>
	T cross(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>((v1.val[1] * v2.val[2] - v1.val[2] * v2.val[1]),
			((v1.val[0] * v2.val[2] * -1) - v1.val[2] * v2.val[0]),
			(v1.val[0] * v2.val[1] - v1.val[1] * v2.val[0]));
	}
}

#endif // SCRT_VEC3_H
