#pragma once
#include "gameNode.h"

// tagNumber ����ü (���ھ� ���)
struct tagNumber
{
	image* elapsedTimeNumberImage[4];	// �������� Ŭ���� �ҿ� �ð� ���� �̹���
	int elapsedTime;					// �������� Ŭ���� �ҿ� �ð�
	int elapsedTimeNumber[4];			// �������� Ŭ���� �ҿ� �ð� ����
	image* scoreNumberImage[4];			// �ҿ� �ð� ��� ���� ���� �̹���
	int score;							// �ҿ� �ð� ��� ����
	int scoreNumber[4];					// �ҿ� �ð� ��� ���� ����
};
struct tagNumber2
{
	image* scoreNumberImage[5];			// �ҿ� �ð� ��� ���� ���� �̹���
	int score;							// �ҿ� �ð� ��� ����
	int scoreNumber[5];					// �ҿ� �ð� ��� ���� ����
};

// resultScene Ŭ����
class resultScene : public gameNode
{
private:
	// �̹��� ����
	// ��׶���
	image* background;					// ��׶��� �̹���
	int backgroundAlpha;				// ��׶��� �̹��� ���İ�
	bool backgroundAlphaBoolOnce;		// ��׶��� �̹��� ���İ� ���� ��ȯ (���� 1ȸ��)
	bool backgroundAlphaBool;			// ��׶��� �̹��� ���İ� ���� ��ȯ
	// ����
	image* number;						// ���� �̹���
	int numberAlpha;					// ���� �̹��� ���İ�
	bool numberAlphaBool;				// ���� �̹��� ���İ� ���� ��ȯ
	// �������� �ؽ�Ʈ
	image* stage;						// �������� �̹���
	int stageAlpha;						// �������� �̹��� ���İ�
	bool stageAlphaBool;				// �������� �̹��� ���İ� ���� ��ȯ
	// ��Ÿ �ؽ�Ʈ
	image* clearTime;					// Ŭ���� Ÿ�� �̹���
	int clearTimeAlpha;					// Ŭ���� Ÿ�� �̹��� ���İ�
	bool clearTimeAlphaBool;			// Ŭ���� Ÿ�� �̹��� ���İ� ���� ��ȯ
	image* stageScore;					// �������� ���ھ� �̹���
	int stageScoreAlpha;				// �������� ���ھ� �̹��� ���İ�
	bool stageScoreAlphaBool;			// �������� ���ھ� �̹��� ���İ� ���� ��ȯ
	image* totalScore;					// ��Ż ���ھ� �̹���
	int totalScoreAlpha;				// ��Ż ���ھ� �̹��� ���İ�
	bool totalScoreAlphaBool;			// ��Ż ���ھ� �̹��� ���İ� ���� ��ȯ
	image* message;						// �޼��� �̹���

	// ��ü ����
	tagNumber stage1Time;			// �������� 1 Ŭ���� �ҿ� �ð�
	tagNumber stage1Score;			// �������� 1 ����
	tagNumber stage2Time;			// �������� 2 Ŭ���� �ҿ� �ð�
	tagNumber stage2Score;			// �������� 2 ����
	tagNumber stage3Time;			// �������� 3 Ŭ���� �ҿ� �ð�
	tagNumber stage3Score;			// �������� 3 ����
	tagNumber stage4Time;			// �������� 4 Ŭ���� �ҿ� �ð�
	tagNumber stage4Score;			// �������� 4 ����
	tagNumber stage5Time;			// �������� 5 Ŭ���� �ҿ� �ð�
	tagNumber stage5Score;			// �������� 5 ����
	tagNumber stage6Time;			// �������� 6 Ŭ���� �ҿ� �ð�
	tagNumber stage6Score;			// �������� 6 ����
	tagNumber stage7Time;			// �������� 7 Ŭ���� �ҿ� �ð�
	tagNumber stage7Score;			// �������� 7 ����
	tagNumber stage8Time;			// �������� 8 Ŭ���� �ҿ� �ð�
	tagNumber stage8Score;			// �������� 8 ����
	tagNumber stage9Time;			// �������� 9 Ŭ���� �ҿ� �ð�
	tagNumber stage9Score;			// �������� 9 ����
	tagNumber stage10Time;			// �������� 10 Ŭ���� �ҿ� �ð�
	tagNumber stage10Score;			// �������� 10 ����
	tagNumber2 stageTotalScore;		// �������� ���� ����

	// ���� ����
	bool returnMenu;					// �޴� ����

public:
	// GET, SET �Լ�
	// �̹��� ����
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
	// ���� ����
	bool getReturnMenu() { return returnMenu; }
	void setReturnMenu(bool _returnMenu) { returnMenu = _returnMenu; }

	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// ������, �Ҹ���
	resultScene() {}
	~resultScene() {}
};