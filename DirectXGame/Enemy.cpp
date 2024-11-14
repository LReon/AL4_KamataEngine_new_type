#include <cassert>
#include "Enemy.h"
#include "MathUtilityForText.h"

void Enemy::Initialize(Model* model, uint32_t textureHandle) {

	// NULLポインタチェック
	assert(model);
	// シングルインスタンスを取得する
	input_ = Input::GetInstance(); 
	// メンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	flag = 0;
	timer = 0.0f;

}

void Enemy::Approach() {

	// 敵の移動ベクトル
	Vector3 move = {0.0f, 0.0f, 0.0f};
	Vector3 speed = {0.1f, 0.0f, 0.0f};

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

void Enemy::Fire() {

	timer++;
	if (timer >= 20.0f) {
		flag = 1;
	} else {
		flag = 0;
	}

	

	if (flag == 1) {

		const float kEnemyBulletSpeed = 1.0f;
		Vector3 velocity(0, 0, kEnemyBulletSpeed);

		velocity = TransformNormal(velocity, worldTransform_.matWorld_);

		if (enemyBullet_) {
			delete enemyBullet_;
			enemyBullet_ = nullptr;

		}
			EnemyBullet* newEnemyBullet = new EnemyBullet();
			newEnemyBullet->Initialize(model_, worldTransform_.translation_,velocity);
			//enemyBullet_ = newEnemyBullet;
		    enemyBullets_.push_back(newEnemyBullet);
			timer = 0.0f;
		}
	

}

void Enemy::Update() {

	enemyBullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});


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
	
	Fire();

	/*if (enemyBullet_) {
		enemyBullet_->Update();
	}*/


	// 移動限界座標
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 19.0f;

	// 範囲を超えない処理
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	for (EnemyBullet* enemyBullet : enemyBullets_) {
	
		enemyBullet->Update();
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

	/*if (enemyBullet_) {
		enemyBullet_->Draw(camera);
	}*/

	for (EnemyBullet* enemyBullet : enemyBullets_) {

		enemyBullet->Draw(camera);
	}

}

Enemy::~Enemy() {

	delete enemyBullet_;



}
