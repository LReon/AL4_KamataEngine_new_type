#include <cassert>
#include "Enemy.h"
#include "MathUtilityForText.h"

void Enemy::Initialize(Model* model, uint32_t textureHandle) {

	// NULLポインタチェック
	assert(model);
	// メンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;
	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Enemy::Approach() {

	// 敵の移動ベクトル
	Vector3 move = {0.0f, 0.0f, 0.0f};
	Vector3 speed = {-0.1f, 0.1f, 0.0f};

	// 移動
	worldTransform_.translation_ += speed;

	if (worldTransform_.translation_.z < 0.0f) {
		phase_ = Phase::Leave;
	}

}

void Enemy::Leave() {

	// 敵の移動ベクトル
	Vector3 move = {0.0f, 0.0f, 0.0f};
	Vector3 speed = {-0.1f, 0.1f, 0.0f};

	// 移動
	worldTransform_.translation_ += speed;

}

void Enemy::Update() {

	
	// 敵のフェーズ
	switch (phase_) {
	case Enemy::Phase::Approach:
	default:

		Approach();

		break;
	case Enemy::Phase::Leave:

		Leave();

		break;
	
	}
	

	// 敵の移動速度
	/*const float kEnemySpeedY = 0.005f;
	const float kEnemySpeedZ = 0.2f;

	move.y += kEnemySpeedY;
	move.z -= kEnemySpeedZ;

	worldTransform_.translation_ += move;*/

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

}

void Enemy::Draw(Camera& camera) {

	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, textureHandle_);

}
