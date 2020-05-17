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

// mainGame Ŭ����
class mainGame : public gameNode
{
private:
	// Ŭ���� ����
	loadingScene* _loadingScene;			// loadingScene Ŭ���� ����
	menuScene* _menuScene;					// menuScene Ŭ���� ����
	resultScene* _resultScene;				// resultScene Ŭ���� ����
	stage1Scene* _stage1Scene;				// stage1Scene Ŭ���� ����
	stage2Scene* _stage2Scene;				// stage1Scene Ŭ���� ����
	stage3Scene* _stage3Scene;				// stage1Scene Ŭ���� ����
	stage4Scene* _stage4Scene;				// stage1Scene Ŭ���� ����
	stage5Scene* _stage5Scene;				// stage1Scene Ŭ���� ����
	stage6Scene* _stage6Scene;				// stage1Scene Ŭ���� ����
	stage7Scene* _stage7Scene;				// stage1Scene Ŭ���� ����
	stage8Scene* _stage8Scene;				// stage1Scene Ŭ���� ����
	stage9Scene* _stage9Scene;				// stage1Scene Ŭ���� ����
	stage10Scene* _stage10Scene;			// stage1Scene Ŭ���� ����

public:
	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// ������, �Ҹ���
	mainGame() {}
	~mainGame() {}
};