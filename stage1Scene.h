#pragma once
#include "gameNode.h"
#include "player.h"
#include "object.h"
#include "clone.h"

// stage1Scene 클래스
class stage1Scene : public gameNode
{
private:
	// 이미지 관련
	image* stage;						// 스테이지 이미지
	image* resetMessage;				// 리셋 메세지 이미지
	image* messageBox;					// 메세지 박스 이미지
	image* systemMessage;				// 메세지 박스 내용 이미지
	int stageWidth;						// 현재 스테이지의 길이
	int stageHeight;					// 현재 스테이지의 높이
	int index;							// 프레임 이미지 인덱스
	int alpha;							// 이미지 알파값

	// 클래스 관련
	player* _player;					// player 클래스 선언
	clone* _clone;						// clone 클래스 선언
	object* _object;					// object 클래스 선언

	// 변수 관련
	bool stageStart;					// 스테이지 시작 여부 판별
	bool stageCleared;					// 스테이지 클리어 여부 판별
	bool entrySoundOutput;				// 게이트 입장 사운드 출력 여부 판별
	int stageRestartDelay;				// 스테이지 재시작 딜레이

public:
	// GET, SET 함수
	// 이미지 관련
	image* getStage() { return stage; }
	void setStage(image* _stage) { stage = _stage; }
	image* getResetMessage() { return resetMessage; }
	void setResetMessage(image* _resetMessage) { resetMessage = _resetMessage; }
	image* getMessageBox() { return messageBox; }
	void setMessageBox(image* _messageBox) { messageBox = _messageBox; }
	image* getSystemMessage() { return systemMessage; }
	void setSystemMessage(image* _systemMessage) { systemMessage = _systemMessage; }
	int getStageWidth() { return stageWidth; }
	void setStageWidth(int _stageWidth) { stageWidth = _stageWidth; }
	int getStageHeight() { return stageHeight; }
	void setStageHeight(int _stageHeight) { stageHeight = _stageHeight; }
	int getIndex() { return index; }
	void setIndex(int _index) { index = _index; }
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// 객체 관련
	player* getPlayer() { return _player; }
	void setPlayer(player* player) { _player = player; }
	clone* getClone() { return _clone; }
	void setClone(clone* clone) { _clone = clone; }
	object* getObject() { return _object; }
	void setObject(object* object) { _object = object; }
	// 기타 변수 관련
	bool getStageStart() { return stageStart; }
	void setStageStart(bool _stageStart) { stageStart = _stageStart; }
	bool getStageCleared() { return stageCleared; }
	void setStageCleared(bool _stageCleared) { stageCleared = _stageCleared; }
	bool getEntrySoundOutput() { return entrySoundOutput; }
	void setEntrySoundOutput(bool _entrySoundOutput) { entrySoundOutput = _entrySoundOutput; }
	int getStageRestartDelay() { return stageRestartDelay; }
	void setStageRestartDelay(int _stageRestartDelay) { stageRestartDelay = _stageRestartDelay; }

	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 애니메이션 처리
	void animation();

	// 생성자, 소멸자
	stage1Scene() {}
	~stage1Scene() {}
};