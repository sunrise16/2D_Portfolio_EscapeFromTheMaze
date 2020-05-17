#pragma once
#include "singletonBase.h"

// timeManager 클래스
class timeManager : public singletonBase <timeManager>
{
private:
	// 변수 관련
	bool _isHardware;				// 고성능 타이머를 지원하는지 체크
	float _timeScale;				// 시간 경과량
	float _timeElapsed;				// 한 프레임 당 경과량
	__int64 _curTime;				// 현재 시간
	__int64 _lastTime;				// 마지막 시간
	__int64 _periodFrequency;		// 시간 주기 (1초에 몇번이나 카운트되는지 설정)
	unsigned long _frameRate;		// FPS 레이트
	unsigned long _FPSFrameCount;	// FPS 카운트
	float _FPSTimeElapsed;			// FPS 경과량
	float _worldTime;				// 전체 경과 시간

public:
	// 초기화 처리
	HRESULT init(void);

	// 해제 처리
	void release(void);

	// 계산식 처리
	void update(float lockFPS);

	// 화면 출력 처리
	void render(HDC hdc);

	// 한 프레임 당 경과시간 가져오기
	float getElapedTime(void) { return _timeElapsed; }
	
	// 전체 경과시간 가져오기
	float getWorldTime(void) { return _worldTime; }

	// 생성자, 소멸자
	timeManager() {}
	~timeManager() {}
};