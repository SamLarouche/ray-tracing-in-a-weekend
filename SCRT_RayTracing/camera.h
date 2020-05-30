#ifndef SCRT_CAMERA_H
#define SCRT_CAMERA_H

#include "math/vec3.h"

namespace SCRT
{
	class Camera
	{
	public:
		Camera();
		Camera(const Vec3<float>& pos, const Vec3<float>& dir, int dist);

		void move(const Vec3<float>& pos, const Vec3<float>& dir, int dist);

		Vec3<float> a() const { return _viewCoords[0]; }
		Vec3<float> b() const { return _viewCoords[1]; }
		Vec3<float> c() const { return _viewCoords[2]; }
		Vec3<float> d() const { return _viewCoords[3]; }

		Vec3<float> width() const { return _viewWidthVector; }
		Vec3<float> height() const { return _viewHeightVector; }
		Vec3<float> position() const { return _position; }
		Vec3<float> direction() const { return _direction; }
		
		int distance() const { return _viewDistance; }

	private:
		const float   _xScale = 2.0;
		const float   _yScale = 1.0;

		Vec3<float> _viewCoords[4];
		Vec3<float> _viewWidthVector;
		Vec3<float> _viewHeightVector;

		Vec3<float> _position;
		Vec3<float> _direction;
		float       _viewDistance;

		void _updateView();
	};
}
#endif // SCRT_CAMERA_H 
