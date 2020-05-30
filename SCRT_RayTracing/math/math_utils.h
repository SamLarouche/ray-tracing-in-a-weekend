#ifndef SCRT_MATH_UTILS_H
#define SCRT_MATH_UTILS_H

#include <algorithm>
#include <limits>
#include <random>
#include <ctime>

#include "vec3.h"

namespace SCRT
{
	namespace Random 
	{
		float randf01();
		Vec3<float> randPointInUnitSphere();
	}
}

#endif //SCRT_MATH_UTILS_H