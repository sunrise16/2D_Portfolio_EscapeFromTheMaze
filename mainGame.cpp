#include "stdafx.h"
#include "mainGame.h"

// �ʱ�ȭ (init)
HRESULT mainGame::init()
{
	// gameNode �ʱ�ȭ
	gameNode::init();

	// loadingScene Ŭ���� ���� �Ҵ� ����
	_loadingScene = new loadingScene;
	_loadingScene->init();

	// menuScene Ŭ���� ���� �Ҵ� ����
	_menuScene = new menuScene;
	_menuScene->init();

	// resultScene Ŭ���� ���� �Ҵ� ����
	_resultScene = new resultScene;
	_resultScene->init();

	// stage1Scene Ŭ���� ���� �Ҵ� ����
	_stage1Scene = new stage1Scene;
	_stage1Scene->init();

	// stage2Scene Ŭ���� ���� �Ҵ� ����
	_stage2Scene = new stage2Scene;
	_stage2Scene->init();

	// stage3Scene Ŭ���� ���� �Ҵ� ����
	_stage3Scene = new stage3Scene;
	_stage3Scene->init();

	// stage4Scene Ŭ���� ���� �Ҵ� ����
	_stage4Scene = new stage4Scene;
	_stage4Scene->init();

	// stage5Scene Ŭ���� ���� �Ҵ� ����
	_stage5Scene = new stage5Scene;
	_stage5Scene->init();

	// stage6Scene Ŭ���� ���� �Ҵ� ����
	_stage6Scene = new stage6Scene;
	_stage6Scene->init();

	// stage7Scene Ŭ���� ���� �Ҵ� ����
	_stage7Scene = new stage7Scene;
	_stage7Scene->init();

	// stage8Scene Ŭ���� ���� �Ҵ� ����
	_stage8Scene = new stage8Scene;
	_stage8Scene->init();

	// stage9Scene Ŭ���� ���� �Ҵ� ����
	_stage9Scene = new stage9Scene;
	_stage9Scene->init();

	// stage10Scene Ŭ���� ���� �Ҵ� ����
	_stage10Scene = new stage10Scene;
	_stage10Scene->init();

	// �� �߰�
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

	// ���� �� ����
	SCENEMANAGER->loadScene("loadingScene");

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void mainGame::release()
{
	// gameNode ����
	gameNode::release();
}

// ������Ʈ (update)
void mainGame::update()
{
	// gameNode ������Ʈ
	gameNode::update();
	
	// �� �Ŵ��� ������Ʈ
	SCENEMANAGER->update();

	// ���� �Ŵ��� ������Ʈ
	SOUNDMANAGER->update();
}

// ���� (render)
void mainGame::render()
{
	// ��� �� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	// ���ڻ� ��� ���ֱ�
	SetBkMode(getMemDC(), TRANSPARENT);

	// �� �Ŵ��� ����
	SCENEMANAGER->render();

	// Ÿ�� �Ŵ��� ����
	TIMEMANAGER->render(getMemDC());

	// ����� ������ ȭ�� DC�� �׸���
	this->getBackBuffer()->render(getHDC());
}