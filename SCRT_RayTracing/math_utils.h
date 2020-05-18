#ifndef SCRT_MATH_UTILS_H
#define SCRT_MATH_UTILS_H

#include <algorithm>
#include <limits>
#include <random>

#include "vec3.h"

namespace SCRT
{
	namespace Random 
	{
		static std::default_random_engine rdNumberGenerator;
		static std::uniform_real_distribution<float> rdRealNumberDistribution(0.0f, 1.0f);

		float randf01();
		Vec3<float> randPointInUnitSphere();
	}

	
}

#endif //SCRT_MATH_UTILS_H