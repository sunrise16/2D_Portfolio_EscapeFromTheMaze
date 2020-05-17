#pragma once
#include "gameNode.h"
#include "loading.h"

// loadingScene 클래스
class loadingScene : public gameNode
{
private:
	// 클래스 관련
	loading* _loading;					// loading 클래스 선언

	// 이미지 관련
	image* loadingImage;				// 로딩 이미지
	bool loadingStart;					// 로딩 시작
	int loadingAlpha;					// 로딩 이미지 알파값
	bool loadingAlphaBool;				// 로딩 이미지 알파값 증감 전환
	bool loadingEnd;					// 로딩 끝

	// 변수 관련
	bool loadingOutput;					// 로딩 출력 여부

public:
	// GET, SET 함수
	// 이미지 관련
	image* getLoadingImage() { return loadingImage; }
	void setLoadingImage(image* _loadingImage) { loadingImage = _loadingImage; }
	bool getLoadingStart() { return loadingStart; }
	void setLoadingStart(bool _loadingStart) { loadingStart = _loadingStart; }
	int getLoadingAlpha() { return loadingAlpha; }
	void setLoadingAlpha(int _loadingAlpha) { loadingAlpha = _loadingAlpha; }
	bool getLoadingAlphaBool() { return loadingAlphaBool; }
	void setLoadingAlphaBool(bool _loadingAlphaBool) { loadingAlphaBool = _loadingAlphaBool; }
	bool getLoadingEnd() { return loadingEnd; }
	void setLoadingEnd(bool _loadingEnd) { loadingEnd = _loadingEnd; }
	// 객체 관련
	loading* getLoading() { return _loading; }
	void setLoading(loading* loading) { _loading = loading; }
	// 기타 변수 관련
	bool getLoadingOutput() { return loadingOutput; }
	void setLoadingOutput(bool _loadingOutput) { loadingOutput = _loadingOutput; }

	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 이미지 로딩
	void loadImage();

	// 생성자, 소멸자
	loadingScene() {}
	~loadingScene() {}
};