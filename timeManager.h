#pragma once
#include "singletonBase.h"

// timeManager Ŭ����
class timeManager : public singletonBase <timeManager>
{
private:
	// ���� ����
	bool _isHardware;				// ���� Ÿ�̸Ӹ� �����ϴ��� üũ
	float _timeScale;				// �ð� �����
	float _timeElapsed;				// �� ������ �� �����
	__int64 _curTime;				// ���� �ð�
	__int64 _lastTime;				// ������ �ð�
	__int64 _periodFrequency;		// �ð� �ֱ� (1�ʿ� ����̳� ī��Ʈ�Ǵ��� ����)
	unsigned long _frameRate;		// FPS ����Ʈ
	unsigned long _FPSFrameCount;	// FPS ī��Ʈ
	float _FPSTimeElapsed;			// FPS �����
	float _worldTime;				// ��ü ��� �ð�

public:
	// �ʱ�ȭ ó��
	HRESULT init(void);

	// ���� ó��
	void release(void);

	// ���� ó��
	void update(float lockFPS);

	// ȭ�� ��� ó��
	void render(HDC hdc);

	// �� ������ �� ����ð� ��������
	float getElapedTime(void) { return _timeElapsed; }
	
	// ��ü ����ð� ��������
	float getWorldTime(void) { return _worldTime; }

	// ������, �Ҹ���
	timeManager() {}
	~timeManager() {}
};