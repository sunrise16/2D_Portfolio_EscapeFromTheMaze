#include "stdafx.h"
#include "camera.h"

// 초기화 (init)
HRESULT camera::init()
{
	// 카메라 RECT 위치 초기화
	_rcCam = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, CAMSIZEX, CAMSIZEY);

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void camera::release()
{
}

// 업데이트 (update)
void camera::update()
{
	// 카메라 이동
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

// 렌더 (render)
void camera::render()
{
	// 카메라 렌더
	// Rectangle(getMemDC(), _rcCam);
	FrameRect(getMemDC(), _rcCam, RGB(255, 255, 0));
}
