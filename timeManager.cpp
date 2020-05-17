#pragma comment(lib, "winmm.lib")
#include "stdafx.h"
#include "timeManager.h"
#include <mmsystem.h>

// timeGetTime �Լ��� ����ϱ� ���ؼ�
// �����찡 ���۵ǰ� �� �� �ð��� ���Ͻ��� �ش�
// GetTickCount���� ������ �ɿ���~ �� ����

// �ʱ�ȭ (init)
HRESULT timeManager::init(void)
{
	// ���� Ÿ�̸� ���� ���� üũ
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		// ���� Ÿ�̸Ӹ� �����ϹǷ� TRUE�� ����
		_isHardware = TRUE;
		
		// �ʴ� �ð� ��� (1�ʿ� ��� ī���� �ϴ���)
		_timeScale = 1.0f / _periodFrequency;
		
		// �ʱ�ȭ ������ �ð��� ������ �ð����� ����
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
	}
	else
	{
		// ���� Ÿ�̸Ӹ� �������� �����Ƿ� FALSE�� ����
		_isHardware = FALSE;
		_timeScale = 1.0f / 1000.0f;
		_lastTime = timeGetTime();
	}

	// ��Ÿ ���� �ʱ�ȭ
	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0;

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void timeManager::release(void)
{
}

// ������Ʈ (update)
void timeManager::update(float lockFPS)
{
	if (_isHardware)
	{
		// ���� �ð� ���
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		// ���� Ÿ�̸Ӹ� �������� �����Ƿ� ������ time �Լ��� ���
		_curTime = timeGetTime();
	}

	// �� ������ ������ �� ���
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	// ������ ��Ű��
	if (lockFPS > 0.0f)
	{
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware)
			{
				// ���� �ð� ���
				QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			}
			else
			{
				// ���� Ÿ�̸Ӹ� �������� �����Ƿ� ������ time �Լ��� ���
				_curTime = timeGetTime();
			}
			// �� ������ ������ �� ���
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	// ���� �ð� ����
	_lastTime = _curTime;
	
	// ������ �� ����
	_FPSTimeElapsed += _timeElapsed;
	
	// �� ���� �ð� ����
	_worldTime += _timeElapsed;

	// ������ �ʱ�ȭ�� 1�ʸ��� �����ϱ�
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}

	// ������ ī��Ʈ ����
	_FPSFrameCount++;
}

// ���� (render)
void timeManager::render(HDC hdc)
{
	char str[256];
	
	// ���� ��� ���
	SetBkMode(hdc, TRANSPARENT);
	
	// ���� ����
	SetTextColor(hdc, RGB(255, 0, 255));

	// FPS ���
	sprintf_s(str, "FPS: %d", _frameRate);
	TextOut(hdc, 0, 0, str, strlen(str));
	
	// ��ü �ð� ���
	sprintf_s(str, "Time: %.2f", _worldTime);
	TextOut(hdc, 0, 20, str, strlen(str));
	
	// �� ������ �� ��� �ð� ���
	// sprintf_s(str, "ElapsedTime: %.4f", _timeElapsed);
	// TextOut(hdc, 0, 40, str, strlen(str));
}