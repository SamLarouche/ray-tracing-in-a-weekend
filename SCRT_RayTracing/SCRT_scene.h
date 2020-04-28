#ifndef SCRT_SCENE_H
#define SCRT_SCENE_H

#include <vector>
#include "SCRT_meshObject.h"
#include "SCRT_camera.h"

namespace SCRT
{
	class scene
	{
	public:
		scene() {}
		void addMesh(meshObject* mesh);
	private:
		std::vector<meshObject*> _meshes;
		camera _camera;
	};
}

#endif // SCRT_SCENE_H