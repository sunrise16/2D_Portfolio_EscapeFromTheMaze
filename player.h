#pragma once
#include "gameNode.h"

// 클래스 전방 선언
class object;
class clone;

// 플레이어의 방향 열거문
enum PLAYER_DIRECTION
{
	PLAYER_DIRECTION_NULL = 0,				// NULL 값
	PLAYER_DIRECTION_LEFT = 1,				// 왼쪽 방향
	PLAYER_DIRECTION_RIGHT = 2				// 오른쪽 방향
};

// 플레이어의 상태 열거문
enum PLAYER_STATE
{
	PLAYER_STATE_NULL = 0,					// NULL 값
	PLAYER_STATE_IDLE = 1,					// 직립부동 상태
	PLAYER_STATE_RUN = 2,					// 달리는 상태
	PLAYER_STATE_JUMP = 3,					// 점프 상태
	PLAYER_STATE_FALL = 4,					// 하강 상태
	PLAYER_STATE_DEAD = 5					// 사망 상태
};

// tagPlayer 구조체
struct tagPlayer
{
	RECT playerRect;						// 플레이어 RECT
	RECT playerTileCollisionRectLeft1;		// 플레이어 좌측 타일 충돌용 RECT 1
	RECT playerTileCollisionRectLeft2;		// 플레이어 좌측 타일 충돌용 RECT 2
	RECT playerTileCollisionRectRight1;		// 플레이어 우측 타일 충돌용 RECT 1
	RECT playerTileCollisionRectRight2;		// 플레이어 우측 타일 충돌용 RECT 2
	RECT playerTileCollisionRectTop1;		// 플레이어 상단 타일 충돌용 RECT 1
	RECT playerTileCollisionRectTop2;		// 플레이어 상단 타일 충돌용 RECT 2
	RECT playerTileCollisionRectBottom1;	// 플레이어 하단 타일 충돌용 RECT 1
	RECT playerTileCollisionRectBottom2;	// 플레이어 하단 타일 충돌용 RECT 2
	int screenX;							// 플레이어 화면 상 X좌표
	int screenY;							// 플레이어 화면 상 Y좌표
	int mapX;								// 플레이어 맵 상 X좌표
	int mapY;								// 플레이어 맵 상 Y좌표
	int gravity;							// 플레이어 중력값
	int gravityDelay;						// 플레이어 중력값 딜레이
	int jumpDelay;							// 플레이어 점프 딜레이 (힘 조절)
	int jumpCount;							// 플레이어 점프 카운트 (2단 점프 체크)
	bool jumping;							// 플레이어 점프중 체크
	bool falling;							// 플레이어 하강중 체크
	bool dead;								// 플레이어 사망 체크
	int playerProbeLeftX;					// 플레이어 좌측 픽셀 충돌 변수값
	int playerProbeRightX;					// 플레이어 우측 픽셀 충돌 변수값
	int playerProbeTopY;					// 플레이어 상단 픽셀 충돌 변수값
	int playerProbeBottomY;					// 플레이어 하단 픽셀 충돌 변수값
	bool tileCollisionLeft;					// 플레이어 좌측 타일 충돌 체크
	bool tileCollisionRight;				// 플레이어 우측 타일 충돌 체크
	bool tileCollisionTop;					// 플레이어 상단 타일 충돌 체크
	bool tileCollisionBottom;				// 플레이어 하단 타일 충돌 체크
	bool pixelCollisionLeft;				// 플레이어 좌측 픽셀 충돌 체크
	bool pixelCollisionRight;				// 플레이어 우측 픽셀 충돌 체크
	bool pixelCollisionTop;					// 플레이어 상단 픽셀 충돌 체크
	bool pixelCollisionBottom;				// 플레이어 하단 픽셀 충돌 체크
};

// player 클래스
class player : public gameNode
{
private:
	// 주소값 관련
	object* _objectAdress;					// object 클래스 주소값
	clone* _cloneAdress;					// clone 클래스 주소값

	// 이미지 관련
	image* playerIdle;						// 플레이어 이미지 (IDLE)
	image* playerRun;						// 플레이어 이미지 (RUN)
	image* playerJumpFall;					// 플레이어 이미지 (JUMP, FALL)
	image* playerDead;						// 플레이어 이미지 (DEAD)
	int count;								// 프레임 돌릴 카운트 (속도 조절)
	int index;								// 프레임 이미지 인덱스
	int alpha;								// 이미지 알파값

	// 객체 관련
	tagPlayer _player;						// tagPlayer 데이터를 담은 플레이어 객체

	// 변수 관련
	PLAYER_DIRECTION playerDirection;		// 플레이어 현재 방향
	PLAYER_STATE playerState;				// 플레이어 현재 상태
	int tileCollisionLeftCount;				// 플레이어 타일 충돌 해제 카운트 (좌측)
	int tileCollisionRightCount;			// 플레이어 타일 충돌 해제 카운트 (우측)
	int tileCollisionTopCount;				// 플레이어 타일 충돌 해제 카운트 (상단)
	int tileCollisionBottomCount;			// 플레이어 타일 충돌 해제 카운트 (하단)
	int walkDelay;							// 플레이어 이동 시 사운드 출력 딜레이
	int currentStage;						// 현재 스테이지
	int currentStageWidth;					// 현재 스테이지 길이
	int currentStageHeight;					// 현재 스테이지 높이
	bool stageStart;						// 스테이지 진행중
	bool stageCleared;						// 스테이지 클리어
	bool deadSoundOutput;					// 플레이어 사망 사운드 출력 여부 판별

public:
	// GET, SET 함수
	// 주소값 관련
	object* getObjectAdress() { return _objectAdress; }
	void setObjectAdress(object* objectAdress) { _objectAdress = objectAdress; }
	clone* getCloneAdress() { return _cloneAdress; }
	void setCloneAdress(clone* cloneAdress) { _cloneAdress = cloneAdress; }
	// 이미지 관련
	image* getPlayerIdle() { return playerIdle; }
	void setPlayerIdle(image* _playerIdle) { playerIdle = _playerIdle; }
	image* getPlayerRun() { return playerRun; }
	void setPlayerRun(image* _playerRun) { playerRun = _playerRun; }
	image* getPlayerJumpFall() { return playerJumpFall; }
	void setPlayerJumpFall(image* _playerJumpFall) { playerJumpFall = _playerJumpFall; }
	image* getPlayerDead() { return playerDead; }
	void setPlayerDead(image* _playerDead) { playerDead = _playerDead; }
	int getCount() { return count; }
	void setCount(int _count) { count = _count; }
	int getIndex() { return index; }
	void setIndex(int _index) { index = _index; }
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// 객체 관련
	tagPlayer getPlayer() { return _player; }
	void setPlayer(tagPlayer player) { _player = player; }
	// 구조체 관련
	RECT getPlayerRect() { return _player.playerRect; }
	void setPlayerRect(RECT _playerRect) { _player.playerRect = _playerRect; }
	RECT getPlayerTileCollisionRectLeft1() { return _player.playerTileCollisionRectLeft1; }
	void setPlayerTileCollisionRectLeft1(RECT _playerTileCollisionRectLeft1) { _player.playerTileCollisionRectLeft1 = _playerTileCollisionRectLeft1; }
	RECT getPlayerTileCollisionRectLeft2() { return _player.playerTileCollisionRectLeft2; }
	void setPlayerTileCollisionRectLeft2(RECT _playerTileCollisionRectLeft2) { _player.playerTileCollisionRectLeft2 = _playerTileCollisionRectLeft2; }
	RECT getPlayerTileCollisionRectRight1() { return _player.playerTileCollisionRectRight1; }
	void setPlayerTileCollisionRectRight1(RECT _playerTileCollisionRectRight1) { _player.playerTileCollisionRectRight1 = _playerTileCollisionRectRight1; }
	RECT getPlayerTileCollisionRectRight2() { return _player.playerTileCollisionRectRight2; }
	void setPlayerTileCollisionRectRight2(RECT _playerTileCollisionRectRight2) { _player.playerTileCollisionRectRight2 = _playerTileCollisionRectRight2; }
	RECT getPlayerTileCollisionRectTop1() { return _player.playerTileCollisionRectTop1; }
	void setPlayerTileCollisionRectTop1(RECT _playerTileCollisionRectTop1) { _player.playerTileCollisionRectTop1 = _playerTileCollisionRectTop1; }
	RECT getPlayerTileCollisionRectTop2() { return _player.playerTileCollisionRectTop2; }
	void setPlayerTileCollisionRectTop2(RECT _playerTileCollisionRectTop2) { _player.playerTileCollisionRectTop2 = _playerTileCollisionRectTop2; }
	RECT getPlayerTileCollisionRectBottom1() { return _player.playerTileCollisionRectBottom1; }
	void setPlayerTileCollisionRectBottom1(RECT _playerTileCollisionRectBottom1) { _player.playerTileCollisionRectBottom1 = _playerTileCollisionRectBottom1; }
	RECT getPlayerTileCollisionRectBottom2() { return _player.playerTileCollisionRectBottom2; }
	void setPlayerTileCollisionRectBottom2(RECT _playerTileCollisionRectBottom2) { _player.playerTileCollisionRectBottom2 = _playerTileCollisionRectBottom2; }
	int getScreenX() { return _player.screenX; }
	void setScreenX(int _screenX) { _player.screenX = _screenX; }
	int getScreenY() { return _player.screenY; }
	void setScreenY(int _screenY) { _player.screenY = _screenY; }
	int getMapX() { return _player.mapX; }
	void setMapX(int _mapX) { _player.mapX = _mapX; }
	int getMapY() { return _player.mapY; }
	void setMapY(int _mapY) { _player.mapY = _mapY; }
	int getGravity() { return _player.gravity; }
	void setGravity(int _gravity) { _player.gravity = _gravity; }
	int getGravityDelay() { return _player.gravityDelay; }
	void setGravityDelay(int _gravityDelay) { _player.gravityDelay = _gravityDelay; }
	int getJumpDelay() { return _player.jumpDelay; }
	void setJumpDelay(int _jumpDelay) { _player.jumpDelay = _jumpDelay; }
	int getJumpCount() { return _player.jumpCount; }
	void setJumpCount(int _jumpCount) { _player.jumpCount = _jumpCount; }
	bool getJumping() { return _player.jumping; }
	void setJumping(bool _jumping) { _player.jumping = _jumping; }
	bool getFalling() { return _player.falling; }
	void setFalling(bool _falling) { _player.falling = _falling; }
	bool getDead() { return _player.dead; }
	void setDead(bool _dead) { _player.dead = _dead; }
	// 충돌 처리 관련
	int getPlayerProbeLeftX() { return _player.playerProbeLeftX; }
	void setPlayerProbeLeftX(int _playerProbeLeftX) { _player.playerProbeLeftX = _playerProbeLeftX; }
	int getPlayerProbeRightX() { return _player.playerProbeRightX; }
	void setPlayerProbeRightX(int _playerProbeRightX) { _player.playerProbeRightX = _playerProbeRightX; }
	int getPlayerProbeTopY() { return _player.playerProbeTopY; }
	void setPlayerProbeTopY(int _playerProbeTopY) { _player.playerProbeTopY = _playerProbeTopY; }
	int getPlayerProbeBottomY() { return _player.playerProbeBottomY; }
	void setPlayerProbeBottomY(int _playerProbeBottomY) { _player.playerProbeBottomY = _playerProbeBottomY; }
	bool getTileCollisionLeft() { return _player.tileCollisionLeft; }
	void setTileCollisionLeft(bool _tileCollisionLeft) { _player.tileCollisionLeft = _tileCollisionLeft; }
	bool getTileCollisionRight() { return _player.tileCollisionRight; }
	void setTileCollisionRight(bool _tileCollisionRight) { _player.tileCollisionRight = _tileCollisionRight; }
	bool getTileCollisionTop() { return _player.tileCollisionTop; }
	void setTileCollisionTop(bool _tileCollisionTop) { _player.tileCollisionTop = _tileCollisionTop; }
	bool getTileCollisionBottom() { return _player.tileCollisionBottom; }
	void setTileCollisionBottom(bool _tileCollisionBottom) { _player.tileCollisionBottom = _tileCollisionBottom; }
	bool getPixelCollisionLeft() { return _player.pixelCollisionLeft; }
	void setPixelCollisionLeft(bool _pixelCollisionLeft) { _player.pixelCollisionLeft = _pixelCollisionLeft; }
	bool getPixelCollisionRight() { return _player.pixelCollisionRight; }
	void setPixelCollisionRight(bool _pixelCollisionRight) { _player.pixelCollisionRight = _pixelCollisionRight; }
	bool getPixelCollisionTop() { return _player.pixelCollisionTop; }
	void setPixelCollisionTop(bool _pixelCollisionTop) { _player.pixelCollisionTop = _pixelCollisionTop; }
	bool getPixelCollisionBottom() { return _player.pixelCollisionBottom; }
	void setPixelCollisionBottom(bool _pixelCollisionBottom) { _player.pixelCollisionBottom = _pixelCollisionBottom; }
	// 기타 변수 관련
	PLAYER_DIRECTION getPlayerDirection() { return playerDirection; }
	void setPlayerDirection(PLAYER_DIRECTION _playerDirection) { playerDirection = _playerDirection; }
	PLAYER_STATE getPlayerState() { return playerState; }
	void setPlayerState(PLAYER_STATE _playerState) { playerState = _playerState; }
	int getWalkDelay() { return walkDelay; }
	void setWalkDelay(int _walkDelay) { walkDelay = _walkDelay; }
	int getCurrentStage() { return currentStage; }
	void setCurrentStage(int _currentStage) { currentStage = _currentStage; }
	int getTileCollisionLeftCount() { return tileCollisionLeftCount; }
	void setTileCollisionLeftCount(int _tileCollisionLeftCount) { tileCollisionLeftCount = _tileCollisionLeftCount; }
	int getTileCollisionRightCount() { return tileCollisionRightCount; }
	void setTileCollisionRightCount(int _tileCollisionRightCount) { tileCollisionRightCount = _tileCollisionRightCount; }
	int getTileCollisionTopCount() { return tileCollisionTopCount; }
	void setTileCollisionTopCount(int _tileCollisionTopCount) { tileCollisionTopCount = _tileCollisionTopCount; }
	int getTileCollisionBottomCount() { return tileCollisionBottomCount; }
	void setTileCollisionBottomCount(int _tileCollisionBottomCount) { tileCollisionBottomCount = _tileCollisionBottomCount; }
	int getCurrentStageWidth() { return currentStageWidth; }
	void setCurrentStageWidth(int _currentStageWidth) { currentStageWidth = _currentStageWidth; }
	int getCurrentStageHeight() { return currentStageHeight; }
	void setCurrentStageHeight(int _currentStageHeight) { currentStageHeight = _currentStageHeight; }
	bool getStageStart() { return stageStart; }
	void setStageStart(bool _stageStart) { stageStart = _stageStart; }
	bool getStageCleared() { return stageCleared; }
	void setStageCleared(bool _stageCleared) { stageCleared = _stageCleared; }
	bool getDeadSoundOutput() { return deadSoundOutput; }
	void setDeadSoundOutput(bool _deadSoundOutput) { deadSoundOutput = _deadSoundOutput; }

	// 초기화 처리
	HRESULT init(int _currentStage);
	HRESULT init(int _currentStage, int _alpha);

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 애니메이션 처리
	void animation();

	// 생성자, 소멸자
	player() {}
	~player() {}
};