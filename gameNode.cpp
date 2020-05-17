#include "stdafx.h"
#include "gameNode.h"

// 초기화 (init)
HRESULT gameNode::init()
{
	// HDC 초기화
	_hdc = GetDC(_hWnd);

	// 입력 매니저 초기화
	INPUT->init();

	// 랜덤 매니저 초기화
	RANDOM->init();

	// 이미지 매니저 초기화
	IMAGEMANAGER->init();

	// 플레이어 데이터 초기화
	PLAYERDATA->init();

	// 씬 매니저 초기화
	SCENEMANAGER->init();

	// INI 데이터 초기화
	INIDATA->init();

	// 사운드 매니저 초기화
	SOUNDMANAGER->init();

	// 타임 매니저 초기화
	TIMEMANAGER->init();
	
	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void gameNode::release()
{
	// 입력 매니저 해제
	INPUT->release();
	INPUT->releaseSingleton();

	// 랜덤 매니저 해제
	RANDOM->release();
	RANDOM->releaseSingleton();

	// 이미지 매니저 해제
	IMAGEMANAGER->release();
	IMAGEMANAGER->releaseSingleton();

	// 플레이어 데이터 해제
	PLAYERDATA->release();
	PLAYERDATA->releaseSingleton();

	// 씬 매니저 해제
	SCENEMANAGER->release();
	SCENEMANAGER->releaseSingleton();

	// INI 데이터 해제
	INIDATA->release();
	INIDATA->releaseSingleton();

	// 사운드 매니저 해제
	SOUNDMANAGER->release();
	SOUNDMANAGER->releaseSingleton();

	// 타임 매니저 해제
	TIMEMANAGER->release();
	TIMEMANAGER->releaseSingleton();

	// HDC 해제
	ReleaseDC(_hWnd, _hdc);
}

// 업데이트 (update)
void gameNode::update()
{
	// 새로고침 (이후 고성능 타이머를 만든 후에는 사용하지 않음)
	// InvalidateRect(_hWnd, NULL, FALSE);
}

// 렌더 (render)
void gameNode::render()
{
}

// 메인 프로시저 (MainProc)
LRESULT gameNode::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	// 마우스 커서 좌표 체크
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	// 마우스 커서 눌렀을 때 좌표 체크
	case WM_LBUTTONDOWN:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	// 키보드 키가 눌렸을때 메세지 발생
	case WM_KEYDOWN:
		switch (wParam)
		{
		// Esc 키를 누르면 화면 종료
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	// 소멸자
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// 윈도우 프로시저에서 처리되지 않은 나머지 메세지를 처리
	return (DefWindowProc(hWnd, message, wParam, lParam));
}