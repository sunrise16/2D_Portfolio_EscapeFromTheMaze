#pragma once
#include "gameNode.h"

#define CAMSIZEX 1280
#define CAMSIZEY 960

// camera 클래스
class camera : public gameNode
{
private:
	// 객체 관련
	RECT _rcCam;		// 카메라 RECT

public:
	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 생성자, 소멸자
	camera() {}
	~camera() {}
};

