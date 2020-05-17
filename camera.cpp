#include "stdafx.h"
#include "camera.h"

// �ʱ�ȭ (init)
HRESULT camera::init()
{
	// ī�޶� RECT ��ġ �ʱ�ȭ
	_rcCam = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, CAMSIZEX, CAMSIZEY);

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void camera::release()
{
}

// ������Ʈ (update)
void camera::update()
{
	// ī�޶� �̵�
	if (INPUT->getKey(VK_LEFT) && _rcCam.left > 0)
	{
		_rcCam.left -= 5;
		_rcCam.right -= 5;
	}
	if (INPUT->getKey(VK_RIGHT) && _rcCam.right < WINSIZEX)
	{
		_rcCam.left += 5;
		_rcCam.right += 5;
	}
	if (INPUT->getKey('W') && _rcCam.top > 0)
	{
		_rcCam.top -= 5;
		_rcCam.bottom -= 5;
	}
	if (INPUT->getKey('S') && _rcCam.bottom < WINSIZEY)
	{
		_rcCam.top += 5;
		_rcCam.bottom += 5;
	}
}

// ���� (render)
void camera::render()
{
	// ī�޶� ����
	// Rectangle(getMemDC(), _rcCam);
	FrameRect(getMemDC(), _rcCam, RGB(255, 255, 0));
}
