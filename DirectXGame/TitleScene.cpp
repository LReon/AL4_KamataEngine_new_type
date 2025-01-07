#include "TitleScene.h"


void TitleScene::Initialize() { 
	
	textureHandle_ = TextureManager::Load("clear.png");

	model = Model::CreateFromOBJ("title", true);
	// ワールド変換の初期化
	worldTransform.Initialize();
	camera.Initialize();

}

void TitleScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
	
		finished_ = true;

	}

}

void TitleScene::Draw() {

	 

}
