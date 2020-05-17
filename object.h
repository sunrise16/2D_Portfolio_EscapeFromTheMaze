#pragma once
#include "gameNode.h"

// 클래스 전방 선언
class player;
class clone;

// 오브젝트 타입 열거문
enum OBJECT_TYPE
{
	OBJECT_TYPE_NULL = 0,					// NULL 값
	OBJECT_TYPE_TILE = 1,					// 색깔별 타일
	OBJECT_TYPE_OBSTACLE = 2,				// 장애물
	OBJECT_TYPE_SWITCH = 3,					// 스위치
	OBJECT_TYPE_LEDGE = 4,					// 얇은 발판
	OBJECT_TYPE_MESSAGE = 5,				// 메세지 박스
	OBJECT_TYPE_AUTOGATE = 6,				// 게이트 (스위치 작동 필요 X)
	OBJECT_TYPE_CLOSEGATE = 7				// 게이트 (스위치 작동 필요 O)
};

// 타일 타입 열거문
enum TILE_TYPE
{
	TILE_TYPE_NULL = 0,						// NULL 값
	TILE_TYPE_WHITE = 1,					// 흰색 타일
	TILE_TYPE_RED = 2,						// 빨간색 타일
	TILE_TYPE_GREEN = 3,					// 초록색 타일
	TILE_TYPE_BLUE = 4						// 파란색 타일
};

// 스위치 타입 열거문
enum SWITCH_TYPE
{
	SWITCH_TYPE_NULL = 0,					// NULL 값
	SWITCH_TYPE_GATE = 1,					// 게이트 스위치
	SWITCH_TYPE_WHITE = 2,					// 흰색 타일 스위치
	SWITCH_TYPE_RED = 3,					// 빨간색 타일 스위치
	SWITCH_TYPE_GREEN = 4,					// 초록색 타일 스위치
	SWITCH_TYPE_BLUE = 5					// 파랑색 타일 스위치
};

// 발판 타입 열거문
enum LEDGE_TYPE
{
	LEDGE_TYPE_NULL = 0,					// NULL 값
	LEDGE_TYPE_SHORT = 1,					// 짧은 발판
	LEDGE_TYPE_NORMAL = 2,					// 일반 발판
	LEDGE_TYPE_LONG = 3						// 긴 발판
};

// tagObject 구조체
struct tagObject
{
	image* objectImage;						// 오브젝트 이미지
	RECT objectRect;						// 오브젝트 RECT
	OBJECT_TYPE objectType;					// 오브젝트 타입
	TILE_TYPE tileType;						// 타일 타입 (타일일 경우에만)
	SWITCH_TYPE switchType;					// 스위치 타입 (스위치일 경우에만)
	LEDGE_TYPE ledgeType;					// 발판 타입 (발판일 경우에만)
	int createX;							// 오브젝트 최초 생성 X좌표
	int createY;							// 오브젝트 최초 생성 Y좌표
	int objectX;							// 오브젝트 현재 X좌표
	int objectY;							// 오브젝트 현재 Y좌표
	bool trigger;							// 오브젝트 활성화
	bool switchOn;							// 오브젝트 스위치 ON
	bool switchOff;							// 오브젝트 스위치 OFF
	bool switchSoundOutput;					// 스위치 사운드 출력 여부 판별
	int switchOffDelay;						// 오브젝트 비활성화 딜레이
	int count;								// 프레임 돌릴 카운트 (속도 조절)
	int index;								// 프레임 이미지 인덱스
};

// object 클래스
class object : public gameNode
{
private:
	// 주소값 관련
	player* _playerAdress;					// player 클래스 주소값
	clone* _cloneAdress;					// clone 클래스 주소값

	// 이미지 관련
	int alpha;								// 이미지 알파값

	// 객체 관련
	vector<tagObject> _vObject;				// tagObject 데이터를 담은 오브젝트 객체

	// 변수 관련
	int currentStage;						// 현재 스테이지
	int currentStageWidth;					// 현재 스테이지 길이
	int currentStageHeight;					// 현재 스테이지 높이
	bool stageStart;						// 스테이지 진행중
	bool stageCleared;						// 스테이지 클리어

public:
	// GET, SET 함수
	// 주소값 관련
	player* getPlayerAdress() { return _playerAdress; }
	void setPlayerAdress(player* playerAdress) { _playerAdress = playerAdress; }
	clone* getCloneAdress() { return _cloneAdress; }
	void setCloneAdress(clone* cloneAdress) { _cloneAdress = cloneAdress; }
	// 이미지 관련
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// 객체 관련
	vector<tagObject> getObject() { return _vObject; }
	void setObject(vector<tagObject> vObject) { _vObject = vObject; }
	// 기타 변수 관련
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

	// 초기화 처리
	HRESULT init(int _currentStage);
	HRESULT init(int _currentStage, int _alpha);
	HRESULT initStage5(int _initCount, int _alpha);

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 애니메이션 출력 처리
	void animation();

	// 트리거 작동
	void setTrigger(int objectNumber, bool trigger);

	// 스위치 ON
	void setSwitchOn(int objectNumber, bool switchOn);

	// 스위치 OFF
	void setSwitchOff(int objectNumber, bool switchOff);

	// 스위치 사운드 출력 조정
	void setSwitchSoundOutput(int objectNumber, bool switchSoundOutput);

	// 생성자, 소멸자
	object() {}
	~object() {}
};