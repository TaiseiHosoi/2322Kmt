#pragma once
#include "WorldTransform.h"
#include "Vector3.h"
#include "Matrix.h"
#include "ViewProjection.h"
#include "memory"
#include "Model.h"
#include "Input.h"
#include "Ease.h"

//レーンの列挙型
	enum Lane
	{
		Left,
		Center,
		Right
	};

class Field
{
public:
	void Initialize(Model* model, uint32_t textureHandle, Lane lane);	//レーンのX座標を決めて初期化
	void Draw(ViewProjection viewProjection);
	void Update();
	//ゲッター
	Vector3 GetTransration() { return worldTransform_.translation_; };
	int GetLane() { return lane_; };

	void LaneChange();
private:

	Input* input_ = nullptr;
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;

	float length = 200.0f;	//レーンの長さ
	float zLen_ = 165.0f;	//okuyuki
	//現在のレーン
	Lane lane_;

	//レーンの幅
	float laneWidth = 10.0f;
	//イージング用
	Ease* ease_ = nullptr;
	bool isChangeRight_ = false;		//レーンチェンジ
	bool isChangeLeft_ = false;
	const int maxTime_ = 10;
	int time_ = 0;
	int changeMode_ = 0; //1が←2が右


};

