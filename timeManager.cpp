#pragma comment(lib, "winmm.lib")
#include "stdafx.h"
#include "timeManager.h"
#include <mmsystem.h>

// timeGetTime 함수를 사용하기 위해서
// 윈도우가 시작되고 난 후 시간을 리턴시켜 준다
// GetTickCount보다 성능이 쪼오끔~ 더 좋다

// 초기화 (init)
HRESULT timeManager::init(void)
{
	// 고성능 타이머 지원 여부 체크
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		// 고성능 타이머를 지원하므로 TRUE로 설정
		_isHardware = TRUE;
		
		// 초당 시간 계산 (1초에 몇번 카운팅 하는지)
		_timeScale = 1.0f / _periodFrequency;
		
		// 초기화 시점의 시간을 마지막 시간으로 설정
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
	}
	else
	{
		// 고성능 타이머를 지원하지 않으므로 FALSE로 설정
		_isHardware = FALSE;
		_timeScale = 1.0f / 1000.0f;
		_lastTime = timeGetTime();
	}

	// 기타 변수 초기화
	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0;

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void timeManager::release(void)
{
}

// 업데이트 (update)
void timeManager::update(float lockFPS)
{
	if (_isHardware)
	{
		// 현재 시간 얻기
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		// 고성능 타이머를 지원하지 않으므로 기존의 time 함수를 사용
		_curTime = timeGetTime();
	}

	// 한 프레임 간격의 초 계산
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	// 프레임 스키핑
	if (lockFPS > 0.0f)
	{
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware)
			{
				// 현재 시간 얻기
				QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			}
			else
			{
				// 고성능 타이머를 지원하지 않으므로 기존의 time 함수를 사용
				_curTime = timeGetTime();
			}
			// 한 프레임 간격의 초 계산
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	// 지난 시간 갱신
	_lastTime = _curTime;
	
	// 프레임 초 누적
	_FPSTimeElapsed += _timeElapsed;
	
	// 총 지난 시간 누적
	_worldTime += _timeElapsed;

	// 프레임 초기화를 1초마다 진행하기
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}

	// 프레임 카운트 증가
	_FPSFrameCount++;
}

// 렌더 (render)
void timeManager::render(HDC hdc)
{
	char str[256];
	
	// 글자 배경 모드
	SetBkMode(hdc, TRANSPARENT);
	
	// 글자 색상
	SetTextColor(hdc, RGB(255, 0, 255));

	// FPS 출력
	sprintf_s(str, "FPS: %d", _frameRate);
	TextOut(hdc, 0, 0, str, strlen(str));
	
	// 전체 시간 출력
	sprintf_s(str, "Time: %.2f", _worldTime);
	TextOut(hdc, 0, 20, str, strlen(str));
	
	// 한 프레임 당 경과 시간 출력
	// sprintf_s(str, "ElapsedTime: %.4f", _timeElapsed);
	// TextOut(hdc, 0, 40, str, strlen(str));
}