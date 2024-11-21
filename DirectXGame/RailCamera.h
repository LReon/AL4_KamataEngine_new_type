#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

class RailCamera {

public:
	void Initialize();

	void Update();

private:

	WorldTransform worldTransform;
	Camera* camera_;

};
