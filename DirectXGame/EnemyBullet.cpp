#include "EnemyBullet.h"
#include <cassert>
#include "MathUtilityForText.h"

void EnemyBullet::Initialize(Model* model, const Vector3& position,const Vector3& velocity) {
	// NULLポインタチェック
	assert(model);

	model_ = model;

	// テクスチャ
	textureHandle_ = TextureManager::Load("enemyBullet.png");

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	velocity_ = velocity;
	
}

void EnemyBullet::Update() {

	worldTransform_.translation_ += velocity_;

	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}

	worldTransform_.UpdateMatrix();

}

void EnemyBullet::Draw(const Camera& camera) {

	model_->Draw(worldTransform_, camera, textureHandle_);

}
