#include "Metallic.h"
#include "../math/math_utils.h"

namespace SCRT
{
	bool Metallic::scatter(const Ray& incomingRay, const HitRecord& hit, Vec3<float>& attenuation, Ray& scatteredRay) const
	{
		Vec3<float> reflection = reflect(incomingRay.getDirection().getUnitVec(), hit.normal);
		scatteredRay = Ray(hit.coordinate, reflection);
		attenuation = _albedo;
		//return (dot(scatteredRay.getDirection(), hit.normal) > 0);
		return true;
	}
}