#ifndef SCRT_RAY_H
#define SCRT_RAY_H

#include "SCRT_vec3.h"

namespace SCRT
{
	class Ray 
	{
	public:
		Ray() {};
		Ray(const Vec3<float>& a, const Vec3<float>& b)
		{
			_origin = a;
			_direction = b;
		}

		Vec3<float> getOrigin() const { return _origin; }
		Vec3<float> getDirection() const { return _direction; }
		Vec3<float> eval(float x) const { return _origin + (x * _direction); }

	private:
		Vec3<float> _origin;
		Vec3<float> _direction;
	};
}

#endif // SCRT_RAY_H
