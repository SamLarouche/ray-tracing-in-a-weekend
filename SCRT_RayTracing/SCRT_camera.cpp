#include "SCRT_camera.h"

namespace SCRT
{
	Camera::Camera() : _position(Vec3<float>(0, 0, 0)), _direction(Vec3<float>(0, 0, -1)), _viewDistance(1.0f)
	{
		_updateView();
	}

	Camera::Camera(const Vec3<float>& pos, const Vec3<float>& dir, int dist) : _position(pos), _direction(dir), _viewDistance(dist)
	{
		_updateView();
	}

	void Camera::move(const Vec3<float>& pos, const Vec3<float>& dir, int dist)
	{
		_position = pos;
		_direction = dir;
		_viewDistance = dist;
		_updateView();
	}

	void Camera::_updateView()
	{
		_viewCoords[0] = _position + (_viewDistance * _direction) - (Vec3<float>(1, 0, 0) * _xScale) - (Vec3<float>(0, 1, 0) * _yScale);
		_viewCoords[1] = _position + (_viewDistance * _direction) + (Vec3<float>(1, 0, 0) * _xScale) - (Vec3<float>(0, 1, 0) * _yScale);
		_viewCoords[2] = _position + (_viewDistance * _direction) + (Vec3<float>(1, 0, 0) * _xScale) + (Vec3<float>(0, 1, 0) * _yScale);
		_viewCoords[3] = _position + (_viewDistance * _direction) - (Vec3<float>(1, 0, 0) * _xScale) + (Vec3<float>(0, 1, 0) * _yScale);

		_viewWidthVector = Vec3<float>(_viewCoords[1].x() - _viewCoords[0].x(), 0, 0);
		_viewHeightVector = Vec3<float>(0, _viewCoords[3].y() - _viewCoords[0].y(), 0);
	}
}