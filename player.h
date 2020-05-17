#pragma once
#include "gameNode.h"

// Ŭ���� ���� ����
class object;
class clone;

// �÷��̾��� ���� ���Ź�
enum PLAYER_DIRECTION
{
	PLAYER_DIRECTION_NULL = 0,				// NULL ��
	PLAYER_DIRECTION_LEFT = 1,				// ���� ����
	PLAYER_DIRECTION_RIGHT = 2				// ������ ����
};

// �÷��̾��� ���� ���Ź�
enum PLAYER_STATE
{
	PLAYER_STATE_NULL = 0,					// NULL ��
	PLAYER_STATE_IDLE = 1,					// �����ε� ����
	PLAYER_STATE_RUN = 2,					// �޸��� ����
	PLAYER_STATE_JUMP = 3,					// ���� ����
	PLAYER_STATE_FALL = 4,					// �ϰ� ����
	PLAYER_STATE_DEAD = 5					// ��� ����
};

// tagPlayer ����ü
struct tagPlayer
{
	RECT playerRect;						// �÷��̾� RECT
	RECT playerTileCollisionRectLeft1;		// �÷��̾� ���� Ÿ�� �浹�� RECT 1
	RECT playerTileCollisionRectLeft2;		// �÷��̾� ���� Ÿ�� �浹�� RECT 2
	RECT playerTileCollisionRectRight1;		// �÷��̾� ���� Ÿ�� �浹�� RECT 1
	RECT playerTileCollisionRectRight2;		// �÷��̾� ���� Ÿ�� �浹�� RECT 2
	RECT playerTileCollisionRectTop1;		// �÷��̾� ��� Ÿ�� �浹�� RECT 1
	RECT playerTileCollisionRectTop2;		// �÷��̾� ��� Ÿ�� �浹�� RECT 2
	RECT playerTileCollisionRectBottom1;	// �÷��̾� �ϴ� Ÿ�� �浹�� RECT 1
	RECT playerTileCollisionRectBottom2;	// �÷��̾� �ϴ� Ÿ�� �浹�� RECT 2
	int screenX;							// �÷��̾� ȭ�� �� X��ǥ
	int screenY;							// �÷��̾� ȭ�� �� Y��ǥ
	int mapX;								// �÷��̾� �� �� X��ǥ
	int mapY;								// �÷��̾� �� �� Y��ǥ
	int gravity;							// �÷��̾� �߷°�
	int gravityDelay;						// �÷��̾� �߷°� ������
	int jumpDelay;							// �÷��̾� ���� ������ (�� ����)
	int jumpCount;							// �÷��̾� ���� ī��Ʈ (2�� ���� üũ)
	bool jumping;							// �÷��̾� ������ üũ
	bool falling;							// �÷��̾� �ϰ��� üũ
	bool dead;								// �÷��̾� ��� üũ
	int playerProbeLeftX;					// �÷��̾� ���� �ȼ� �浹 ������
	int playerProbeRightX;					// �÷��̾� ���� �ȼ� �浹 ������
	int playerProbeTopY;					// �÷��̾� ��� �ȼ� �浹 ������
	int playerProbeBottomY;					// �÷��̾� �ϴ� �ȼ� �浹 ������
	bool tileCollisionLeft;					// �÷��̾� ���� Ÿ�� �浹 üũ
	bool tileCollisionRight;				// �÷��̾� ���� Ÿ�� �浹 üũ
	bool tileCollisionTop;					// �÷��̾� ��� Ÿ�� �浹 üũ
	bool tileCollisionBottom;				// �÷��̾� �ϴ� Ÿ�� �浹 üũ
	bool pixelCollisionLeft;				// �÷��̾� ���� �ȼ� �浹 üũ
	bool pixelCollisionRight;				// �÷��̾� ���� �ȼ� �浹 üũ
	bool pixelCollisionTop;					// �÷��̾� ��� �ȼ� �浹 üũ
	bool pixelCollisionBottom;				// �÷��̾� �ϴ� �ȼ� �浹 üũ
};

// player Ŭ����
class player : public gameNode
{
private:
	// �ּҰ� ����
	object* _objectAdress;					// object Ŭ���� �ּҰ�
	clone* _cloneAdress;					// clone Ŭ���� �ּҰ�

	// �̹��� ����
	image* playerIdle;						// �÷��̾� �̹��� (IDLE)
	image* playerRun;						// �÷��̾� �̹��� (RUN)
	image* playerJumpFall;					// �÷��̾� �̹��� (JUMP, FALL)
	image* playerDead;						// �÷��̾� �̹��� (DEAD)
	int count;								// ������ ���� ī��Ʈ (�ӵ� ����)
	int index;								// ������ �̹��� �ε���
	int alpha;								// �̹��� ���İ�

	// ��ü ����
	tagPlayer _player;						// tagPlayer �����͸� ���� �÷��̾� ��ü

	// ���� ����
	PLAYER_DIRECTION playerDirection;		// �÷��̾� ���� ����
	PLAYER_STATE playerState;				// �÷��̾� ���� ����
	int tileCollisionLeftCount;				// �÷��̾� Ÿ�� �浹 ���� ī��Ʈ (����)
	int tileCollisionRightCount;			// �÷��̾� Ÿ�� �浹 ���� ī��Ʈ (����)
	int tileCollisionTopCount;				// �÷��̾� Ÿ�� �浹 ���� ī��Ʈ (���)
	int tileCollisionBottomCount;			// �÷��̾� Ÿ�� �浹 ���� ī��Ʈ (�ϴ�)
	int walkDelay;							// �÷��̾� �̵� �� ���� ��� ������
	int currentStage;						// ���� ��������
	int currentStageWidth;					// ���� �������� ����
	int currentStageHeight;					// ���� �������� ����
	bool stageStart;						// �������� ������
	bool stageCleared;						// �������� Ŭ����
	bool deadSoundOutput;					// �÷��̾� ��� ���� ��� ���� �Ǻ�

public:
	// GET, SET �Լ�
	// �ּҰ� ����
	object* getObjectAdress() { return _objectAdress; }
	void setObjectAdress(object* objectAdress) { _objectAdress = objectAdress; }
	clone* getCloneAdress() { return _cloneAdress; }
	void setCloneAdress(clone* cloneAdress) { _cloneAdress = cloneAdress; }
	// �̹��� ����
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
	// ��ü ����
	tagPlayer getPlayer() { return _player; }
	void setPlayer(tagPlayer player) { _player = player; }
	// ����ü ����
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
	// �浹 ó�� ����
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
	// ��Ÿ ���� ����
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

	// �ʱ�ȭ ó��
	HRESULT init(int _currentStage);
	HRESULT init(int _currentStage, int _alpha);

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// �ִϸ��̼� ó��
	void animation();

	// ������, �Ҹ���
	player() {}
	~player() {}
};