#pragma once
#include "gameNode.h"

#define CAMSIZEX 1280
#define CAMSIZEY 960

// camera Ŭ����
class camera : public gameNode
{
private:
	// ��ü ����
	RECT _rcCam;		// ī�޶� RECT

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
	camera() {}
	~camera() {}
};

