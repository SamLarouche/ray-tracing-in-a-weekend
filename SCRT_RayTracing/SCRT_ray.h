#ifndef SCRT_RAY_H
#define SCRT_RAY_H

#include "SCRT_vec3.h"

namespace SCRT
{
	class ray 
	{
	public:
		ray() {};
		ray(const vec3<float>& a, const vec3<float>& b)
		{
			_origin = a;
			_direction = b;
		}

		vec3<float> getOrigin() const { return _origin; }
		vec3<float> getDirection() const { return _direction; }
		vec3<float> eval(float x) const { return _origin + (x * _direction); }

	private:
		vec3<float> _origin;
		vec3<float> _direction;
	};
}

#endif // SCRT_RAY_H
