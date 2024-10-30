#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

#include <list>

#include "affine.h"
#include "PlayerBullet.h"

class Player {

public:

	// キーボード入力
	Input* input_ = nullptr;

	// 初期化
	void Initialize(Model* model, uint32_t textureHandle);

	// 回転
	void Rotate();

	// 攻撃
	void Attack();

	// 弾
	std::list<PlayerBullet*> bullets_;

	// 更新
	void Update();

	// 描画
	void Draw(Camera& camera);

	// 弾
	PlayerBullet* bullet_ = nullptr;

	// デストラクタ
	~Player();

private:

	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	
};
