#ifndef SCRT_RENDERER_H
#define SCRT_RENDERER_H

#include "SCRT_scene.h"
#include "SCRT_vec3.h"
#include <limits>

namespace SCRT
{
	class Renderer
	{
		typedef SCRT::Vec3<int> Color;

	public:
		Color* pixels;

		Renderer(int frameWidth, int frameHeight, float minRenderDist = 0.0, float maxRenderDist = FLT_MAX);
		void renderScene(const Scene& s); // TODO: Error handling with return
		
	private:
		int _frameWidth;
		int _frameHeight;

		float _minRenderDistance;
		float _maxRenderDistance;
		
		Vec3<float> _computeRay(const Ray& r, const Scene& s);
	};
}

#endif SCRT_RENDER_H