#include "math_utils.h"

namespace SCRT
{
	namespace Random
	{
		static std::mt19937 rdNumberGenerator{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		
		// returns a random float between 0.0 and 1.0
		float randf01()
		{
			std::uniform_real_distribution<float> rdRealNumberDistribution(0.0f, 1.0f);
			return rdRealNumberDistribution(rdNumberGenerator);
		}

		// returns a random point in a sphere of radius 1 sitting at the origin
		Vec3<float> randPointInUnitSphere()
		{
			Vec3<float> point(FLT_MAX, FLT_MAX, FLT_MAX);
			while (point.lengthSq() >= 1.0) // try until the point is under a distance of 1.0 from the origin
			{
				point = (Vec3<float>(randf01(), randf01(), randf01()) * 2.0f) - Vec3<float>(1.0f, 1.0f, 1.0f);
			}
			return point;
		}
	}
}
