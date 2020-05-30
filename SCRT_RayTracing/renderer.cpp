#include <algorithm>
#include <limits>
#include <random>

#include "math/math_utils.h"
#include "meshes/mesh_object.h"
#include "meshes/sphere.h"

#include "ray.h"
#include "renderer.h"


namespace SCRT 
{
	// namespace "Rendering" will contain everything related to rendering (colors, shading, etc.)
	// that isn't strictly needed inside the Renderer class, but isn't used outside of it.
	namespace RenderUtils
	{
		// create a linear blend and get the color of the pixel the r vector is aiming at in this blend
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

	Renderer::Renderer(int frameWidth, int frameHeight, int samples, float minDist, float maxDist) : _frameWidth(frameWidth), _frameHeight(frameHeight), _sampleCount(samples), _minRenderDistance(minDist), _maxRenderDistance(maxDist)
	{
		pixels = new Color[frameWidth * frameHeight];
	}

	void Renderer::renderScene(const Scene& s) 
	{
		int pixelIndex = 0;
		for (int y = _frameHeight - 1; y >= 0; --y)
		{
			for (int x = 0; x < _frameWidth; ++x)
			{
				SCRT::Vec3<float> meanColorApprox = Vec3<float>(0, 0, 0);
				for (int sample = 0; sample < _sampleCount; sample++)
				{
					float u = float(x + Random::randf01()) / float(_frameWidth);
					float v = float(y + Random::randf01()) / float(_frameHeight);

					SCRT::Vec3<float> rayDirection = s._camera.a() + (u * s._camera.width()) + (v * s._camera.height());
					SCRT::Ray currentRay = SCRT::Ray(s._camera.position(), rayDirection);

					meanColorApprox += _computeRayColor(currentRay, s, _maxRayDepth);
				}

				meanColorApprox /= float(_sampleCount);
				int r = int(meanColorApprox.r() * 255.99f);
				int g = int(meanColorApprox.g() * 255.99f);
				int b = int(meanColorApprox.b() * 255.99f);

				pixels[pixelIndex] = Color(r, g, b);
				pixelIndex++;
			}
		}
	}

	Vec3<float> Renderer::_computeRayColor(const Ray& r, const Scene& s, int rayDepth) 
	{
		if (rayDepth <= 0)
		{
			return Vec3<float>(0.0, 0.0, 0.0);
		}
		
		HitRecord closestHit;
		closestHit.distance = FLT_MAX;

		int meshCount = s.meshCount();
		for (int meshIndex = 0; meshIndex < meshCount; ++meshIndex)
		{
			HitRecord rHit;
			if (s.get(meshIndex)->hit(r, rHit))
			{
				if (rHit.distance < closestHit.distance)
				{
					closestHit = rHit;
				}
			}
		}

		if (closestHit.distance >= _minRenderDistance && closestHit.distance <= _maxRenderDistance)
		{
			Ray scatteredRay;
			Vec3<float> attentuation;

			if (closestHit.material_ptr->scatter(r, closestHit, attentuation, scatteredRay)) 
			{
				return attentuation * _computeRayColor(scatteredRay, s, rayDepth - 1);
			}
			else 
			{
				return Vec3<float>(0.0, 0.0, 0.0);
			}
		}
		else
		{
			Vec3<float> dir = r.getDirection().getUnitVec();
			float lightGradient = 0.5f * (dir.y() + 1.0f);
			return ((1.0f - lightGradient) * Vec3<float>(1.0f, 1.0f, 1.0f) + (lightGradient * Vec3<float>(0.5f, 0.7f, 1.0f)));
		}

		return RenderUtils::linearBlendColor(r);
	}
}