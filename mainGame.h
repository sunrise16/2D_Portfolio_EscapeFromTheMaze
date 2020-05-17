#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "menuScene.h"
#include "resultScene.h"
#include "stage1Scene.h"
#include "stage2Scene.h"
#include "stage3Scene.h"
#include "stage4Scene.h"
#include "stage5Scene.h"
#include "stage6Scene.h"
#include "stage7Scene.h"
#include "stage8Scene.h"
#include "stage9Scene.h"
#include "stage10Scene.h"

// mainGame 클래스
class mainGame : public gameNode
{
private:
	// 클래스 관련
	loadingScene* _loadingScene;			// loadingScene 클래스 선언
	menuScene* _menuScene;					// menuScene 클래스 선언
	resultScene* _resultScene;				// resultScene 클래스 선언
	stage1Scene* _stage1Scene;				// stage1Scene 클래스 선언
	stage2Scene* _stage2Scene;				// stage1Scene 클래스 선언
	stage3Scene* _stage3Scene;				// stage1Scene 클래스 선언
	stage4Scene* _stage4Scene;				// stage1Scene 클래스 선언
	stage5Scene* _stage5Scene;				// stage1Scene 클래스 선언
	stage6Scene* _stage6Scene;				// stage1Scene 클래스 선언
	stage7Scene* _stage7Scene;				// stage1Scene 클래스 선언
	stage8Scene* _stage8Scene;				// stage1Scene 클래스 선언
	stage9Scene* _stage9Scene;				// stage1Scene 클래스 선언
	stage10Scene* _stage10Scene;			// stage1Scene 클래스 선언

public:
	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 생성자, 소멸자
	mainGame() {}
	~mainGame() {}
};