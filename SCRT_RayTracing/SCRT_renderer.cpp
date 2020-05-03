#include "SCRT_renderer.h"

#include "SCRT_meshObject.h"
#include "SCRT_ray.h"
#include "SCRT_sphere.h"

#include <algorithm>
#include <limits>

namespace SCRT 
{
	// namespace "Rendering" will contain everything related to rendering (colors, shading, etc.)
	// that isn't strictly needed inside the Renderer class.
	namespace RenderUtils
	{
		// Get the color of the pixel the r vector is aiming at
		// TODO: make this a reusable function for different blends and colors
		Vec3<float> linearBlendColor(const Ray& r)
		{
			Vec3<float> direction = r.getDirection();
			Vec3<float> startColor = Vec3<float>(1.0f, 1.0f, 1.0f);
			Vec3<float> endColor = Vec3<float>(0.5f, 0.7f, 1.0f);
			float t = 0.5f * (direction.y() + 1.0f);
			Vec3<float> color = ((1.0f - t) * startColor) + (t * endColor);
			return color;
		}
	}

	Renderer::Renderer(int frameWidth, int frameHeight, float minDist, float maxDist) : _frameWidth(frameWidth), _frameHeight(frameHeight), _minRenderDistance(minDist), _maxRenderDistance(maxDist)
	{
		pixels = new Color[frameWidth * frameHeight];
	}

	void Renderer::renderScene(const Scene& s) 
	{
		int pixelIndex = 0;
		for (int y = _frameHeight - 1; y > -1; --y)
		{
			for (int x = 0; x < _frameWidth; ++x)
			{
				float u = float(x) / float(_frameWidth);
				float v = float(y) / float(_frameHeight);
				
				SCRT::Vec3<float> rayDirection = s._camera.a() + (u * s._camera.width()) + (v * s._camera.height());
				SCRT::Ray currentRay = SCRT::Ray(s._camera.position(), rayDirection);
				SCRT::Vec3<float> rayColor = _computeRay(currentRay, s);

				int r = int(rayColor.r() * 255.99f);
				int g = int(rayColor.g() * 255.99f);
				int b = int(rayColor.b() * 255.99f);

				pixels[pixelIndex] = Color(r, g, b);
				pixelIndex++;
			}
		}
	}

	Vec3<float> Renderer::_computeRay(const Ray& r, const Scene& s) 
	{
		meshRayHit closestHit;
		
		closestHit.distance = FLT_MAX;

		int meshCount = s.meshCount();
		for (int meshIndex = 0; meshIndex < meshCount; ++meshIndex)
		{
			meshRayHit rHit;
			if (s.get(meshIndex)->hit(r, rHit))
			{
				if (rHit.distance < closestHit.distance)
				{
					closestHit = rHit;
				}
			}
		}

		if (closestHit.distance > _minRenderDistance && closestHit.distance < _maxRenderDistance)
		{
			Vec3<float> normal = closestHit.normal.getUnitVec();
			return 0.5f * Vec3<float>(normal.x() + 1, normal.y() + 1, normal.z() + 1);
		}

		return RenderUtils::linearBlendColor(r);
	}
}