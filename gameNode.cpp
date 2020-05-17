#include "stdafx.h"
#include "gameNode.h"

// �ʱ�ȭ (init)
HRESULT gameNode::init()
{
	// HDC �ʱ�ȭ
	_hdc = GetDC(_hWnd);

	// �Է� �Ŵ��� �ʱ�ȭ
	INPUT->init();

	// ���� �Ŵ��� �ʱ�ȭ
	RANDOM->init();

	// �̹��� �Ŵ��� �ʱ�ȭ
	IMAGEMANAGER->init();

	// �÷��̾� ������ �ʱ�ȭ
	PLAYERDATA->init();

	// �� �Ŵ��� �ʱ�ȭ
	SCENEMANAGER->init();

	// INI ������ �ʱ�ȭ
	INIDATA->init();

	// ���� �Ŵ��� �ʱ�ȭ
	SOUNDMANAGER->init();

	// Ÿ�� �Ŵ��� �ʱ�ȭ
	TIMEMANAGER->init();
	
	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void gameNode::release()
{
	// �Է� �Ŵ��� ����
	INPUT->release();
	INPUT->releaseSingleton();

	// ���� �Ŵ��� ����
	RANDOM->release();
	RANDOM->releaseSingleton();

	// �̹��� �Ŵ��� ����
	IMAGEMANAGER->release();
	IMAGEMANAGER->releaseSingleton();

	// �÷��̾� ������ ����
	PLAYERDATA->release();
	PLAYERDATA->releaseSingleton();

	// �� �Ŵ��� ����
	SCENEMANAGER->release();
	SCENEMANAGER->releaseSingleton();

	// INI ������ ����
	INIDATA->release();
	INIDATA->releaseSingleton();

	// ���� �Ŵ��� ����
	SOUNDMANAGER->release();
	SOUNDMANAGER->releaseSingleton();

	// Ÿ�� �Ŵ��� ����
	TIMEMANAGER->release();
	TIMEMANAGER->releaseSingleton();

	// HDC ����
	ReleaseDC(_hWnd, _hdc);
}

// ������Ʈ (update)
void gameNode::update()
{
	// ���ΰ�ħ (���� ���� Ÿ�̸Ӹ� ���� �Ŀ��� ������� ����)
	// InvalidateRect(_hWnd, NULL, FALSE);
}

// ���� (render)
void gameNode::render()
{
}

// ���� ���ν��� (MainProc)
LRESULT gameNode::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	// ���콺 Ŀ�� ��ǥ üũ
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	// ���콺 Ŀ�� ������ �� ��ǥ üũ
	case WM_LBUTTONDOWN:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	// Ű���� Ű�� �������� �޼��� �߻�
	case WM_KEYDOWN:
		switch (wParam)
		{
		// Esc Ű�� ������ ȭ�� ����
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	// �Ҹ���
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// ������ ���ν������� ó������ ���� ������ �޼����� ó��
	return (DefWindowProc(hWnd, message, wParam, lParam));
}