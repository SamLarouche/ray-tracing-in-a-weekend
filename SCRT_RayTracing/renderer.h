#ifndef SCRT_RENDERER_H
#define SCRT_RENDERER_H

#include <limits>

#include "materials/material.h"
#include "math/vec3.h"

#include "scene.h"


namespace SCRT
{
	class Renderer
	{
		typedef SCRT::Vec3<int> Color;

	public:
		Color* pixels;

		Renderer(int frameWidth, int frameHeight, int samples = 50,  float minRenderDist = 0.0, float maxRenderDist = FLT_MAX / 2.0f);
		void renderScene(const Scene& s); // TODO: Error handling with return
		
	private:
		int _frameWidth;
		int _frameHeight;

		int _sampleCount;

		float _minRenderDistance;
		float _maxRenderDistance;

		int _maxRayDepth = 50;
		
		Vec3<float> _computeRayColor(const Ray& r, const Scene& s, int rayDepth);
	};
}

#endif SCRT_RENDER_H