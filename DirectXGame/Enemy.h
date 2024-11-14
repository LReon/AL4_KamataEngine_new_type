#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;
#include "EnemyBullet.h"


class Enemy {

	

public:

	// 行動フェーズ
	enum class Phase {
		Approach,
		Leave,
	};

	Phase phase_ = Phase::Approach;

	// キーボード入力
	Input* input_ = nullptr;

	void Initialize(Model* model, uint32_t textureHandle);

	void Approach();
	
	void Leave();

	void Fire();

	
	
	void Update();

	void Draw(Camera& camera);

	~Enemy();

	// 弾
	EnemyBullet* enemyBullet_ = nullptr;

	std::list<EnemyBullet*> enemyBullets_;


	int flag;
	float timer;
	

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

};
