#pragma once
#include <list>
#include <KamataEngine.h>
using namespace KamataEngine;

class TitleScene {

public:
	void Initialize();

	void Update();

	void Draw();
	
	bool finished_ = false;



	bool IsFinished() const { return finished_; }

private:
	uint32_t textureHandle_ = 0u;

	Model* model = nullptr;

	WorldTransform worldTransform;
	Camera camera;

};
