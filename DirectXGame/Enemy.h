#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;



class Enemy {

	

public:

	// 行動フェーズ
	enum class Phase {
		Approach,
		Leave,
	};

	Phase phase_ = Phase::Approach;

	

	void Initialize(Model* model, uint32_t textureHandle);

	void Approach();
	
	void Leave();
	
	void Update();

	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

};
