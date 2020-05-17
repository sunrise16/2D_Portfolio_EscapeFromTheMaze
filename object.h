#pragma once
#include "gameNode.h"

// Ŭ���� ���� ����
class player;
class clone;

// ������Ʈ Ÿ�� ���Ź�
enum OBJECT_TYPE
{
	OBJECT_TYPE_NULL = 0,					// NULL ��
	OBJECT_TYPE_TILE = 1,					// ���� Ÿ��
	OBJECT_TYPE_OBSTACLE = 2,				// ��ֹ�
	OBJECT_TYPE_SWITCH = 3,					// ����ġ
	OBJECT_TYPE_LEDGE = 4,					// ���� ����
	OBJECT_TYPE_MESSAGE = 5,				// �޼��� �ڽ�
	OBJECT_TYPE_AUTOGATE = 6,				// ����Ʈ (����ġ �۵� �ʿ� X)
	OBJECT_TYPE_CLOSEGATE = 7				// ����Ʈ (����ġ �۵� �ʿ� O)
};

// Ÿ�� Ÿ�� ���Ź�
enum TILE_TYPE
{
	TILE_TYPE_NULL = 0,						// NULL ��
	TILE_TYPE_WHITE = 1,					// ��� Ÿ��
	TILE_TYPE_RED = 2,						// ������ Ÿ��
	TILE_TYPE_GREEN = 3,					// �ʷϻ� Ÿ��
	TILE_TYPE_BLUE = 4						// �Ķ��� Ÿ��
};

// ����ġ Ÿ�� ���Ź�
enum SWITCH_TYPE
{
	SWITCH_TYPE_NULL = 0,					// NULL ��
	SWITCH_TYPE_GATE = 1,					// ����Ʈ ����ġ
	SWITCH_TYPE_WHITE = 2,					// ��� Ÿ�� ����ġ
	SWITCH_TYPE_RED = 3,					// ������ Ÿ�� ����ġ
	SWITCH_TYPE_GREEN = 4,					// �ʷϻ� Ÿ�� ����ġ
	SWITCH_TYPE_BLUE = 5					// �Ķ��� Ÿ�� ����ġ
};

// ���� Ÿ�� ���Ź�
enum LEDGE_TYPE
{
	LEDGE_TYPE_NULL = 0,					// NULL ��
	LEDGE_TYPE_SHORT = 1,					// ª�� ����
	LEDGE_TYPE_NORMAL = 2,					// �Ϲ� ����
	LEDGE_TYPE_LONG = 3						// �� ����
};

// tagObject ����ü
struct tagObject
{
	image* objectImage;						// ������Ʈ �̹���
	RECT objectRect;						// ������Ʈ RECT
	OBJECT_TYPE objectType;					// ������Ʈ Ÿ��
	TILE_TYPE tileType;						// Ÿ�� Ÿ�� (Ÿ���� ��쿡��)
	SWITCH_TYPE switchType;					// ����ġ Ÿ�� (����ġ�� ��쿡��)
	LEDGE_TYPE ledgeType;					// ���� Ÿ�� (������ ��쿡��)
	int createX;							// ������Ʈ ���� ���� X��ǥ
	int createY;							// ������Ʈ ���� ���� Y��ǥ
	int objectX;							// ������Ʈ ���� X��ǥ
	int objectY;							// ������Ʈ ���� Y��ǥ
	bool trigger;							// ������Ʈ Ȱ��ȭ
	bool switchOn;							// ������Ʈ ����ġ ON
	bool switchOff;							// ������Ʈ ����ġ OFF
	bool switchSoundOutput;					// ����ġ ���� ��� ���� �Ǻ�
	int switchOffDelay;						// ������Ʈ ��Ȱ��ȭ ������
	int count;								// ������ ���� ī��Ʈ (�ӵ� ����)
	int index;								// ������ �̹��� �ε���
};

// object Ŭ����
class object : public gameNode
{
private:
	// �ּҰ� ����
	player* _playerAdress;					// player Ŭ���� �ּҰ�
	clone* _cloneAdress;					// clone Ŭ���� �ּҰ�

	// �̹��� ����
	int alpha;								// �̹��� ���İ�

	// ��ü ����
	vector<tagObject> _vObject;				// tagObject �����͸� ���� ������Ʈ ��ü

	// ���� ����
	int currentStage;						// ���� ��������
	int currentStageWidth;					// ���� �������� ����
	int currentStageHeight;					// ���� �������� ����
	bool stageStart;						// �������� ������
	bool stageCleared;						// �������� Ŭ����

public:
	// GET, SET �Լ�
	// �ּҰ� ����
	player* getPlayerAdress() { return _playerAdress; }
	void setPlayerAdress(player* playerAdress) { _playerAdress = playerAdress; }
	clone* getCloneAdress() { return _cloneAdress; }
	void setCloneAdress(clone* cloneAdress) { _cloneAdress = cloneAdress; }
	// �̹��� ����
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	// ��ü ����
	vector<tagObject> getObject() { return _vObject; }
	void setObject(vector<tagObject> vObject) { _vObject = vObject; }
	// ��Ÿ ���� ����
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

	// �ʱ�ȭ ó��
	HRESULT init(int _currentStage);
	HRESULT init(int _currentStage, int _alpha);
	HRESULT initStage5(int _initCount, int _alpha);

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// �ִϸ��̼� ��� ó��
	void animation();

	// Ʈ���� �۵�
	void setTrigger(int objectNumber, bool trigger);

	// ����ġ ON
	void setSwitchOn(int objectNumber, bool switchOn);

	// ����ġ OFF
	void setSwitchOff(int objectNumber, bool switchOff);

	// ����ġ ���� ��� ����
	void setSwitchSoundOutput(int objectNumber, bool switchSoundOutput);

	// ������, �Ҹ���
	object() {}
	~object() {}
};