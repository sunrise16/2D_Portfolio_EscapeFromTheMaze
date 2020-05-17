#pragma once
#include "gameNode.h"
#include "player.h"
#include "object.h"
#include "clone.h"

// stage5Scene Ŭ����
class stage5Scene : public gameNode
{
private:
	// �̹��� ����
	image* stage;						// �������� �̹���
	image* resetMessage;				// ���� �޼��� �̹���
	image* messageBox;					// �޼��� �ڽ� �̹���
	image* systemMessage1;				// �޼��� �ڽ� ���� �̹��� 1
	image* systemMessage2;				// �޼��� �ڽ� ���� �̹��� 2
	int stageWidth;						// ���� ���������� ����
	int stageHeight;					// ���� ���������� ����
	int index;							// ������ �̹��� �ε���
	int alpha;							// �̹��� ���İ�
	int initCount;						// �������� 5 ���� �ʱ�ȭ ī��Ʈ

	// Ŭ���� ����
	player* _player;					// player Ŭ���� ����
	clone* _clone;						// clone Ŭ���� ����
	object* _object;					// object Ŭ���� ����

	// ���� ����
	bool stage5Restart;					// �������� 5 ���� ����� ���� �Ǻ�
	bool stageStart;					// �������� ���� ���� �Ǻ�
	bool stageCleared;					// �������� Ŭ���� ���� �Ǻ�
	bool entrySoundOutput;				// ����Ʈ ���� ���� ��� ���� �Ǻ�
	int stageRestartDelay;				// �������� ����� ������

public:
	// GET, SET �Լ�
	// �̹��� ����
	image* getStage() { return stage; }
	void setStage(image* _stage) { stage = _stage; }
	image* getResetMessage() { return resetMessage; }
	void setResetMessage(image* _resetMessage) { resetMessage = _resetMessage; }
	image* getMessageBox() { return messageBox; }
	void setMessageBox(image* _messageBox) { messageBox = _messageBox; }
	image* getSystemMessage1() { return systemMessage1; }
	void setSystemMessage1(image* _systemMessage1) { systemMessage1 = _systemMessage1; }
	image* getSystemMessage2() { return systemMessage2; }
	void setSystemMessage2(image* _systemMessage2) { systemMessage2 = _systemMessage2; }
	int getStageWidth() { return stageWidth; }
	void setStageWidth(int _stageWidth) { stageWidth = _stageWidth; }
	int getStageHeight() { return stageHeight; }
	void setStageHeight(int _stageHeight) { stageHeight = _stageHeight; }
	int getIndex() { return index; }
	void setIndex(int _index) { index = _index; }
	int getAlpha() { return alpha; }
	void setAlpha(int _alpha) { alpha = _alpha; }
	int getInitCount() { return initCount; }
	void setInitCount(int _initCount) { initCount = _initCount; }
	// ��ü ����
	player* getPlayer() { return _player; }
	void setPlayer(player* player) { _player = player; }
	clone* getClone() { return _clone; }
	void setClone(clone* clone) { _clone = clone; }
	object* getObject() { return _object; }
	void setObject(object* object) { _object = object; }
	// ��Ÿ ���� ����
	bool getStage5Restart() { return stage5Restart; }
	void setStage5Restart(bool _stage5Restart) { stage5Restart = _stage5Restart; }
	bool getStageStart() { return stageStart; }
	void setStageStart(bool _stageStart) { stageStart = _stageStart; }
	bool getStageCleared() { return stageCleared; }
	void setStageCleared(bool _stageCleared) { stageCleared = _stageCleared; }
	bool getEntrySoundOutput() { return entrySoundOutput; }
	void setEntrySoundOutput(bool _entrySoundOutput) { entrySoundOutput = _entrySoundOutput; }
	int getStageRestartDelay() { return stageRestartDelay; }
	void setStageRestartDelay(int _stageRestartDelay) { stageRestartDelay = _stageRestartDelay; }

	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// �ִϸ��̼� ó��
	void animation();

	// ������, �Ҹ���
	stage5Scene() {}
	~stage5Scene() {}
};