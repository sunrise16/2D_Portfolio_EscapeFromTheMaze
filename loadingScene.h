#pragma once
#include "gameNode.h"
#include "loading.h"

// loadingScene Ŭ����
class loadingScene : public gameNode
{
private:
	// Ŭ���� ����
	loading* _loading;					// loading Ŭ���� ����

	// �̹��� ����
	image* loadingImage;				// �ε� �̹���
	bool loadingStart;					// �ε� ����
	int loadingAlpha;					// �ε� �̹��� ���İ�
	bool loadingAlphaBool;				// �ε� �̹��� ���İ� ���� ��ȯ
	bool loadingEnd;					// �ε� ��

	// ���� ����
	bool loadingOutput;					// �ε� ��� ����

public:
	// GET, SET �Լ�
	// �̹��� ����
	image* getLoadingImage() { return loadingImage; }
	void setLoadingImage(image* _loadingImage) { loadingImage = _loadingImage; }
	bool getLoadingStart() { return loadingStart; }
	void setLoadingStart(bool _loadingStart) { loadingStart = _loadingStart; }
	int getLoadingAlpha() { return loadingAlpha; }
	void setLoadingAlpha(int _loadingAlpha) { loadingAlpha = _loadingAlpha; }
	bool getLoadingAlphaBool() { return loadingAlphaBool; }
	void setLoadingAlphaBool(bool _loadingAlphaBool) { loadingAlphaBool = _loadingAlphaBool; }
	bool getLoadingEnd() { return loadingEnd; }
	void setLoadingEnd(bool _loadingEnd) { loadingEnd = _loadingEnd; }
	// ��ü ����
	loading* getLoading() { return _loading; }
	void setLoading(loading* loading) { _loading = loading; }
	// ��Ÿ ���� ����
	bool getLoadingOutput() { return loadingOutput; }
	void setLoadingOutput(bool _loadingOutput) { loadingOutput = _loadingOutput; }

	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// �̹��� �ε�
	void loadImage();

	// ������, �Ҹ���
	loadingScene() {}
	~loadingScene() {}
};