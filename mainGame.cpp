#include "stdafx.h"
#include "mainGame.h"

// 초기화 (init)
HRESULT mainGame::init()
{
	// gameNode 초기화
	gameNode::init();

	// loadingScene 클래스 동적 할당 생성
	_loadingScene = new loadingScene;
	_loadingScene->init();

	// menuScene 클래스 동적 할당 생성
	_menuScene = new menuScene;
	_menuScene->init();

	// resultScene 클래스 동적 할당 생성
	_resultScene = new resultScene;
	_resultScene->init();

	// stage1Scene 클래스 동적 할당 생성
	_stage1Scene = new stage1Scene;
	_stage1Scene->init();

	// stage2Scene 클래스 동적 할당 생성
	_stage2Scene = new stage2Scene;
	_stage2Scene->init();

	// stage3Scene 클래스 동적 할당 생성
	_stage3Scene = new stage3Scene;
	_stage3Scene->init();

	// stage4Scene 클래스 동적 할당 생성
	_stage4Scene = new stage4Scene;
	_stage4Scene->init();

	// stage5Scene 클래스 동적 할당 생성
	_stage5Scene = new stage5Scene;
	_stage5Scene->init();

	// stage6Scene 클래스 동적 할당 생성
	_stage6Scene = new stage6Scene;
	_stage6Scene->init();

	// stage7Scene 클래스 동적 할당 생성
	_stage7Scene = new stage7Scene;
	_stage7Scene->init();

	// stage8Scene 클래스 동적 할당 생성
	_stage8Scene = new stage8Scene;
	_stage8Scene->init();

	// stage9Scene 클래스 동적 할당 생성
	_stage9Scene = new stage9Scene;
	_stage9Scene->init();

	// stage10Scene 클래스 동적 할당 생성
	_stage10Scene = new stage10Scene;
	_stage10Scene->init();

	// 씬 추가
	SCENEMANAGER->addScene("loadingScene", _loadingScene);
	SCENEMANAGER->addScene("menuScene", _menuScene);
	SCENEMANAGER->addScene("resultScene", _resultScene);
	SCENEMANAGER->addScene("stage1Scene", _stage1Scene);
	SCENEMANAGER->addScene("stage2Scene", _stage2Scene);
	SCENEMANAGER->addScene("stage3Scene", _stage3Scene);
	SCENEMANAGER->addScene("stage4Scene", _stage4Scene);
	SCENEMANAGER->addScene("stage5Scene", _stage5Scene);
	SCENEMANAGER->addScene("stage6Scene", _stage6Scene);
	SCENEMANAGER->addScene("stage7Scene", _stage7Scene);
	SCENEMANAGER->addScene("stage8Scene", _stage8Scene);
	SCENEMANAGER->addScene("stage9Scene", _stage9Scene);
	SCENEMANAGER->addScene("stage10Scene", _stage10Scene);

	// 현재 씬 설정
	SCENEMANAGER->loadScene("loadingScene");

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void mainGame::release()
{
	// gameNode 해제
	gameNode::release();
}

// 업데이트 (update)
void mainGame::update()
{
	// gameNode 업데이트
	gameNode::update();
	
	// 씬 매니저 업데이트
	SCENEMANAGER->update();

	// 사운드 매니저 업데이트
	SOUNDMANAGER->update();
}

// 렌더 (render)
void mainGame::render()
{
	// 흰색 빈 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	// 글자색 배경 없애기
	SetBkMode(getMemDC(), TRANSPARENT);

	// 씬 매니저 렌더
	SCENEMANAGER->render();

	// 타임 매니저 렌더
	TIMEMANAGER->render(getMemDC());

	// 백버퍼 내용을 화면 DC에 그리기
	this->getBackBuffer()->render(getHDC());
}