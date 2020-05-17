#pragma once
#include "gameNode.h"

// 클래스 전방 선언
class player;
class object;

// tagClone 구조체
struct tagClone
{
	image* cloneImage;						// 클론 이미지
	RECT cloneRect;							// 클론 RECT
	RECT cloneTileCollisionRectLeft1;		// 클론 좌측 타일 충돌용 RECT 1
	RECT cloneTileCollisionRectLeft2;		// 클론 좌측 타일 충돌용 RECT 2
	RECT cloneTileCollisionRectRight1;		// 클론 우측 타일 충돌용 RECT 1
	RECT cloneTileCollisionRectRight2;		// 클론 우측 타일 충돌용 RECT 2
	RECT cloneTileCollisionRectTop1;		// 클론 상단 타일 충돌용 RECT 1
	RECT cloneTileCollisionRectTop2;		// 클론 상단 타일 충돌용 RECT 2
	RECT cloneTileCollisionRectBottom1;		// 클론 하단 타일 충돌용 RECT 1
	RECT cloneTileCollisionRectBottom2;		// 클론 하단 타일 충돌용 RECT 2
	int createX;							// 클론 최초 생성 위치 X좌표
	int createY;							// 클론 최초 생성 위치 Y좌표
	int cloneX;								// 클론 화면 상 X좌표
	int cloneY;								// 클론 화면 상 Y좌표
	int gravity;							// 클론 중력값
	int gravityDelay;						// 클론 중력값 딜레이
	int cloneDelay;							// 클론 유지 딜레이
	int cloneProbeLeftX;					// 클론 좌측 픽셀 충돌 변수값
	int cloneProbeRightX;					// 클론 우측 픽셀 충돌 변수값
	int cloneProbeTopY;						// 클론 상단 픽셀 충돌 변수값
	int cloneProbeBottomY;					// 클론 하단 픽셀 충돌 변수값
	bool tileCollisionLeft;					// 클론 좌측 타일 충돌 체크
	bool tileCollisionRight;				// 클론 우측 타일 충돌 체크
	bool tileCollisionTop;					// 클론 상단 타일 충돌 체크
	bool tileCollisionBottom;				// 클론 하단 타일 충돌 체크
	int tileCollisionLeftCount;				// 클론 타일 충돌 해제 카운트 (좌측)
	int tileCollisionRightCount;			// 클론 타일 충돌 해제 카운트 (우측)
	int tileCollisionTopCount;				// 클론 타일 충돌 해제 카운트 (상단)
	int tileCollisionBottomCount;			// 클론 타일 충돌 해제 카운트 (하단)
	bool pixelCollisionLeft;				// 클론 좌측 충돌 체크
	bool pixelCollisionRight;				// 클론 우측 충돌 체크
	bool pixelCollisionTop;					// 클론 상단 충돌 체크
	bool pixelCollisionBottom;				// 클론 하단 충돌 체크
	int count;								// 클론 프레임 돌릴 카운트 (속도 조절)
	int index;								// 클론 프레임 이미지 인덱스
};

struct tagTimer
{
	image* cloneTimerImage;					// 클론 타이머 이미지
	RECT timerRect;							// 타이머 RECT
	int index;								// 타이머 프레임 이미지 인덱스
};

// clone 클래스
class clone : public gameNode
{
private:
	// 주소값 관련
	player* _playerAdress;					// player 클래스 주소값
	object* _objectAdress;					// object 클래스 주소값

	// 이미지 관련
	int alpha;								// 이미지 알파값

	// 객체 관련
	vector<tagClone> _vClone;				// tagClone 데이터를 담은 클론 객체
	tagTimer cloneTimer[3];					// 클론 타이머 객체

	// 변수 관련
	int cloneCount;							// 클론 갯수 카운트
	int currentStage;						// 현재 스테이지
	int currentStageWidth;					// 현재 스테이지 길이
	int currentStageHeight;					// 현재 스테이지 높이
	bool stageStart;						// 스테이지 진행중
	bool stageCleared;						// 스테이지 클리어
	bool rewindSoundOutput;					// 클론 제거 사운드 출력 여부 판별

public:
	// GET, SET 함수
	// 주소값 관련
	player* getPlayerAdress() { return _playerAdress; }
	void setPlayerAdress(player* playerAdress) { _playerAdress = playerAdress; }
	object* getObjectAdress() { return _objectAdress; }
	void setObjectAdress(object* objectAdress) { _objectAdress = objectAdress; }
	// 이미지 관련
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// 객체 관련
	vector<tagClone> getClone() { return _vClone; }
	void setClone(vector<tagClone> vClone) { _vClone = vClone; }
	// 충돌 처리 관련
	void setTileCollisionLeft(int number, bool _tileCollisionLeft) { _vClone[number].tileCollisionLeft = _tileCollisionLeft; }
	void setTileCollisionRight(int number, bool _tileCollisionRight) { _vClone[number].tileCollisionRight = _tileCollisionRight; }
	void setTileCollisionTop(int number, bool _tileCollisionTop) { _vClone[number].tileCollisionTop = _tileCollisionTop; }
	void setTileCollisionBottom(int number, bool _tileCollisionBottom) { _vClone[number].tileCollisionBottom = _tileCollisionBottom; }
	void setPixelCollisionLeft(int number, bool _pixelCollisionLeft) { _vClone[number].pixelCollisionLeft = _pixelCollisionLeft; }
	void setPixelCollisionRight(int number, bool _pixelCollisionRight) { _vClone[number].pixelCollisionRight = _pixelCollisionRight; }
	void setPixelCollisionTop(int number, bool _pixelCollisionTop) { _vClone[number].pixelCollisionTop = _pixelCollisionTop; }
	void setPixelCollisionBottom(int number, bool _pixelCollisionBottom) { _vClone[number].pixelCollisionBottom = _pixelCollisionBottom; }
	// 기타 변수 관련
	int getCloneCount() { return cloneCount; }
	void setCloneCount(int _cloneCount) { cloneCount = _cloneCount; }
	int getCurrentStage() { return currentStage; }
	void setCurrentStage(int _currentStage) { currentStage = _currentStage; }
	int getCurrentStageWidth() { return currentStageWidth; }
	void setCurrentStageWidth(int _currentStageWidth) { currentStageWidth = _currentStageWidth; }
	int getCurrentStageHeight() { return currentStageHeight; }
	void setCurrentStageHeight(int _currentStageHeight) { currentStageHeight = _currentStageHeight; }
	bool getStageStart() { return stageStart; }
	void setStageStart(bool _stageStart) { stageStart = _stageStart; }
	bool getStageCleared() { return stageCleared; }
	void setStageCleared(bool _stageCleared) { stageCleared = _stageCleared; }
	bool getRewindSoundOutput() { return rewindSoundOutput; }
	void setRewindSoundOutput(bool _rewindSoundOutput) { rewindSoundOutput = _rewindSoundOutput; }

	// 초기화 처리
	HRESULT init();
	HRESULT init(int _alpha);

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 애니메이션 처리
	void animation();

public:
	// 생성자, 소멸자
	clone() {}
	~clone() {}
};