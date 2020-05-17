#pragma once
#include "gameNode.h"

// Ŭ���� ���� ����
class player;
class object;

// tagClone ����ü
struct tagClone
{
	image* cloneImage;						// Ŭ�� �̹���
	RECT cloneRect;							// Ŭ�� RECT
	RECT cloneTileCollisionRectLeft1;		// Ŭ�� ���� Ÿ�� �浹�� RECT 1
	RECT cloneTileCollisionRectLeft2;		// Ŭ�� ���� Ÿ�� �浹�� RECT 2
	RECT cloneTileCollisionRectRight1;		// Ŭ�� ���� Ÿ�� �浹�� RECT 1
	RECT cloneTileCollisionRectRight2;		// Ŭ�� ���� Ÿ�� �浹�� RECT 2
	RECT cloneTileCollisionRectTop1;		// Ŭ�� ��� Ÿ�� �浹�� RECT 1
	RECT cloneTileCollisionRectTop2;		// Ŭ�� ��� Ÿ�� �浹�� RECT 2
	RECT cloneTileCollisionRectBottom1;		// Ŭ�� �ϴ� Ÿ�� �浹�� RECT 1
	RECT cloneTileCollisionRectBottom2;		// Ŭ�� �ϴ� Ÿ�� �浹�� RECT 2
	int createX;							// Ŭ�� ���� ���� ��ġ X��ǥ
	int createY;							// Ŭ�� ���� ���� ��ġ Y��ǥ
	int cloneX;								// Ŭ�� ȭ�� �� X��ǥ
	int cloneY;								// Ŭ�� ȭ�� �� Y��ǥ
	int gravity;							// Ŭ�� �߷°�
	int gravityDelay;						// Ŭ�� �߷°� ������
	int cloneDelay;							// Ŭ�� ���� ������
	int cloneProbeLeftX;					// Ŭ�� ���� �ȼ� �浹 ������
	int cloneProbeRightX;					// Ŭ�� ���� �ȼ� �浹 ������
	int cloneProbeTopY;						// Ŭ�� ��� �ȼ� �浹 ������
	int cloneProbeBottomY;					// Ŭ�� �ϴ� �ȼ� �浹 ������
	bool tileCollisionLeft;					// Ŭ�� ���� Ÿ�� �浹 üũ
	bool tileCollisionRight;				// Ŭ�� ���� Ÿ�� �浹 üũ
	bool tileCollisionTop;					// Ŭ�� ��� Ÿ�� �浹 üũ
	bool tileCollisionBottom;				// Ŭ�� �ϴ� Ÿ�� �浹 üũ
	int tileCollisionLeftCount;				// Ŭ�� Ÿ�� �浹 ���� ī��Ʈ (����)
	int tileCollisionRightCount;			// Ŭ�� Ÿ�� �浹 ���� ī��Ʈ (����)
	int tileCollisionTopCount;				// Ŭ�� Ÿ�� �浹 ���� ī��Ʈ (���)
	int tileCollisionBottomCount;			// Ŭ�� Ÿ�� �浹 ���� ī��Ʈ (�ϴ�)
	bool pixelCollisionLeft;				// Ŭ�� ���� �浹 üũ
	bool pixelCollisionRight;				// Ŭ�� ���� �浹 üũ
	bool pixelCollisionTop;					// Ŭ�� ��� �浹 üũ
	bool pixelCollisionBottom;				// Ŭ�� �ϴ� �浹 üũ
	int count;								// Ŭ�� ������ ���� ī��Ʈ (�ӵ� ����)
	int index;								// Ŭ�� ������ �̹��� �ε���
};

struct tagTimer
{
	image* cloneTimerImage;					// Ŭ�� Ÿ�̸� �̹���
	RECT timerRect;							// Ÿ�̸� RECT
	int index;								// Ÿ�̸� ������ �̹��� �ε���
};

// clone Ŭ����
class clone : public gameNode
{
private:
	// �ּҰ� ����
	player* _playerAdress;					// player Ŭ���� �ּҰ�
	object* _objectAdress;					// object Ŭ���� �ּҰ�

	// �̹��� ����
	int alpha;								// �̹��� ���İ�

	// ��ü ����
	vector<tagClone> _vClone;				// tagClone �����͸� ���� Ŭ�� ��ü
	tagTimer cloneTimer[3];					// Ŭ�� Ÿ�̸� ��ü

	// ���� ����
	int cloneCount;							// Ŭ�� ���� ī��Ʈ
	int currentStage;						// ���� ��������
	int currentStageWidth;					// ���� �������� ����
	int currentStageHeight;					// ���� �������� ����
	bool stageStart;						// �������� ������
	bool stageCleared;						// �������� Ŭ����
	bool rewindSoundOutput;					// Ŭ�� ���� ���� ��� ���� �Ǻ�

public:
	// GET, SET �Լ�
	// �ּҰ� ����
	player* getPlayerAdress() { return _playerAdress; }
	void setPlayerAdress(player* playerAdress) { _playerAdress = playerAdress; }
	object* getObjectAdress() { return _objectAdress; }
	void setObjectAdress(object* objectAdress) { _objectAdress = objectAdress; }
	// �̹��� ����
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// ��ü ����
	vector<tagClone> getClone() { return _vClone; }
	void setClone(vector<tagClone> vClone) { _vClone = vClone; }
	// �浹 ó�� ����
	void setTileCollisionLeft(int number, bool _tileCollisionLeft) { _vClone[number].tileCollisionLeft = _tileCollisionLeft; }
	void setTileCollisionRight(int number, bool _tileCollisionRight) { _vClone[number].tileCollisionRight = _tileCollisionRight; }
	void setTileCollisionTop(int number, bool _tileCollisionTop) { _vClone[number].tileCollisionTop = _tileCollisionTop; }
	void setTileCollisionBottom(int number, bool _tileCollisionBottom) { _vClone[number].tileCollisionBottom = _tileCollisionBottom; }
	void setPixelCollisionLeft(int number, bool _pixelCollisionLeft) { _vClone[number].pixelCollisionLeft = _pixelCollisionLeft; }
	void setPixelCollisionRight(int number, bool _pixelCollisionRight) { _vClone[number].pixelCollisionRight = _pixelCollisionRight; }
	void setPixelCollisionTop(int number, bool _pixelCollisionTop) { _vClone[number].pixelCollisionTop = _pixelCollisionTop; }
	void setPixelCollisionBottom(int number, bool _pixelCollisionBottom) { _vClone[number].pixelCollisionBottom = _pixelCollisionBottom; }
	// ��Ÿ ���� ����
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

	// �ʱ�ȭ ó��
	HRESULT init();
	HRESULT init(int _alpha);

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// �ִϸ��̼� ó��
	void animation();

public:
	// ������, �Ҹ���
	clone() {}
	~clone() {}
};