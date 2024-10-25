#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

#include "affine.h"

class Player {

public:

	// キーボード入力
	Input* input_ = nullptr;

	// 初期化
	void Initialize(Model* model, uint32_t textureHandle);

	// 更新
	void Update();

	// 描画
	void Draw(Camera& camera);

private:

	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	

};
