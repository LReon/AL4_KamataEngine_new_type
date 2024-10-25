#include <cassert>
#include "PlayerBullet.h"

void PlayerBullet::Initialize(Model* model, const Vector3& position) {

	// NULLポインタチェック
	assert(model);

	model_ = model;
	// テクスチャの読み込み
	textureHandle_ = TextureManager::Load("black.png");

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;


}

void PlayerBullet::Update() {

	// ワールドトランスフォームの更新
	worldTransform_.UpdateMatrix();

}

void PlayerBullet::Draw(const Camera& camera) {

	// モデルの描画
	model_->Draw(worldTransform_, camera, textureHandle_);

}
