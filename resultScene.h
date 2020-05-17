#pragma once
#include "gameNode.h"

// tagNumber 구조체 (스코어 계산)
struct tagNumber
{
	image* elapsedTimeNumberImage[4];	// 스테이지 클리어 소요 시간 숫자 이미지
	int elapsedTime;					// 스테이지 클리어 소요 시간
	int elapsedTimeNumber[4];			// 스테이지 클리어 소요 시간 숫자
	image* scoreNumberImage[4];			// 소요 시간 비례 점수 숫자 이미지
	int score;							// 소요 시간 비례 점수
	int scoreNumber[4];					// 소요 시간 비례 점수 숫자
};
struct tagNumber2
{
	image* scoreNumberImage[5];			// 소요 시간 비례 점수 숫자 이미지
	int score;							// 소요 시간 비례 점수
	int scoreNumber[5];					// 소요 시간 비례 점수 숫자
};

// resultScene 클래스
class resultScene : public gameNode
{
private:
	// 이미지 관련
	// 백그라운드
	image* background;					// 백그라운드 이미지
	int backgroundAlpha;				// 백그라운드 이미지 알파값
	bool backgroundAlphaBoolOnce;		// 백그라운드 이미지 알파값 증감 전환 (최초 1회만)
	bool backgroundAlphaBool;			// 백그라운드 이미지 알파값 증감 전환
	// 숫자
	image* number;						// 숫자 이미지
	int numberAlpha;					// 숫자 이미지 알파값
	bool numberAlphaBool;				// 숫자 이미지 알파값 증감 전환
	// 스테이지 텍스트
	image* stage;						// 스테이지 이미지
	int stageAlpha;						// 스테이지 이미지 알파값
	bool stageAlphaBool;				// 스테이지 이미지 알파값 증감 전환
	// 기타 텍스트
	image* clearTime;					// 클리어 타임 이미지
	int clearTimeAlpha;					// 클리어 타임 이미지 알파값
	bool clearTimeAlphaBool;			// 클리어 타임 이미지 알파값 증감 전환
	image* stageScore;					// 스테이지 스코어 이미지
	int stageScoreAlpha;				// 스테이지 스코어 이미지 알파값
	bool stageScoreAlphaBool;			// 스테이지 스코어 이미지 알파값 증감 전환
	image* totalScore;					// 토탈 스코어 이미지
	int totalScoreAlpha;				// 토탈 스코어 이미지 알파값
	bool totalScoreAlphaBool;			// 토탈 스코어 이미지 알파값 증감 전환
	image* message;						// 메세지 이미지

	// 객체 관련
	tagNumber stage1Time;			// 스테이지 1 클리어 소요 시간
	tagNumber stage1Score;			// 스테이지 1 점수
	tagNumber stage2Time;			// 스테이지 2 클리어 소요 시간
	tagNumber stage2Score;			// 스테이지 2 점수
	tagNumber stage3Time;			// 스테이지 3 클리어 소요 시간
	tagNumber stage3Score;			// 스테이지 3 점수
	tagNumber stage4Time;			// 스테이지 4 클리어 소요 시간
	tagNumber stage4Score;			// 스테이지 4 점수
	tagNumber stage5Time;			// 스테이지 5 클리어 소요 시간
	tagNumber stage5Score;			// 스테이지 5 점수
	tagNumber stage6Time;			// 스테이지 6 클리어 소요 시간
	tagNumber stage6Score;			// 스테이지 6 점수
	tagNumber stage7Time;			// 스테이지 7 클리어 소요 시간
	tagNumber stage7Score;			// 스테이지 7 점수
	tagNumber stage8Time;			// 스테이지 8 클리어 소요 시간
	tagNumber stage8Score;			// 스테이지 8 점수
	tagNumber stage9Time;			// 스테이지 9 클리어 소요 시간
	tagNumber stage9Score;			// 스테이지 9 점수
	tagNumber stage10Time;			// 스테이지 10 클리어 소요 시간
	tagNumber stage10Score;			// 스테이지 10 점수
	tagNumber2 stageTotalScore;		// 스테이지 총합 점수

	// 변수 관련
	bool returnMenu;					// 메뉴 리턴

public:
	// GET, SET 함수
	// 이미지 관련
	image* getBackground() { return background; }
	void setBackground(image* _background) { background = _background; }
	int getBackgroundAlpha() { return backgroundAlpha; }
	void setBackgroundAlpha(int _backgroundAlpha) { backgroundAlpha = _backgroundAlpha; }
	bool getBackgroundAlphaBoolOnce() { return backgroundAlphaBoolOnce; }
	void setBackgroundAlphaBoolOnce(bool _backgroundAlphaBoolOnce) { backgroundAlphaBoolOnce = _backgroundAlphaBoolOnce; }
	bool getBackgroundAlphaBool() { return backgroundAlphaBool; }
	void setBackgroundAlphaBool(bool _backgroundAlphaBool) { backgroundAlphaBool = _backgroundAlphaBool; }
	image* getNumber() { return number; }
	void setNumber(image* _number) { number = _number; }
	int getNumberAlpha() { return numberAlpha; }
	void setNumberAlpha(int _numberAlpha) { numberAlpha = _numberAlpha; }
	bool getNumberAlphaBool() { return numberAlphaBool; }
	void setNumberAlphaBool(bool _numberAlphaBool) { numberAlphaBool = _numberAlphaBool; }
	image* getStage() { return stage; }
	void setStage(image* _stage) { stage = _stage; }
	int getStageAlpha() { return stageAlpha; }
	void setStageAlpha(int _stageAlpha) { stageAlpha = _stageAlpha; }
	bool getStageAlphaBool() { return stageAlphaBool; }
	void setStageAlphaBool(bool _stageAlphaBool) { stageAlphaBool = _stageAlphaBool; }
	image* getClearTime() { return clearTime; }
	void setClearTime(image* _clearTime) { clearTime = _clearTime; }
	int getClearTimeAlpha() { return clearTimeAlpha; }
	void setClearTimeAlpha(int _clearTimeAlpha) { clearTimeAlpha = _clearTimeAlpha; }
	bool getClearTimeAlphaBool() { return clearTimeAlphaBool; }
	void setClearTimeAlphaBool(bool _clearTimeAlphaBool) { clearTimeAlphaBool = _clearTimeAlphaBool; }
	image* getStageScore() { return stageScore; }
	void setStageScore(image* _stageScore) { stageScore = _stageScore; }
	int getStageScoreAlpha() { return stageScoreAlpha; }
	void setStageScoreAlpha(int _stageScoreAlpha) { stageScoreAlpha = _stageScoreAlpha; }
	bool getStageScoreAlphaBool() { return stageScoreAlphaBool; }
	void setStageScoreAlphaBool(bool _stageScoreAlphaBool) { stageScoreAlphaBool = _stageScoreAlphaBool; }
	image* getTotalScore() { return totalScore; }
	void setTotalScore(image* _totalScore) { totalScore = _totalScore; }
	int getTotalScoreAlpha() { return totalScoreAlpha; }
	void setTotalScoreAlpha(int _totalScoreAlpha) { totalScoreAlpha = _totalScoreAlpha; }
	bool getTotalScoreAlphaBool() { return totalScoreAlphaBool; }
	void setTotalScoreAlphaBool(bool _totalScoreAlphaBool) { totalScoreAlphaBool = _totalScoreAlphaBool; }
	image* getMessage() { return message; }
	void setMessage(image* _message) { message = _message; }
	// 변수 관련
	bool getReturnMenu() { return returnMenu; }
	void setReturnMenu(bool _returnMenu) { returnMenu = _returnMenu; }

	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 생성자, 소멸자
	resultScene() {}
	~resultScene() {}
};