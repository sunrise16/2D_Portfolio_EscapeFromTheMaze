#pragma once
#include "gameNode.h"
#include "progressBar.h"

// �ε��� �̹����� ���� ���Ź�
enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,			// �� ��Ʈ�� �̹���
	LOAD_KIND_IMAGE_1,			// �Ϲ� �̹���
	LOAD_KIND_IMAGE_2,			// �Ϲ� �̹��� (��ǥ)
	LOAD_KIND_FRAMEIMAGE_0,		// ������ �̹���
	LOAD_KIND_FRAMEIMAGE_1,		// ������ �̹��� (��ǥ)
	LOAD_KIND_SOUND,			// ����
	LOAD_KIND_END
};

// �̹��� ���ҽ� ����ü
struct tagImageResource
{
	string keyName;				// �̹��� Ű��
	const char* fileName;		// �̹��� ���� �̸�
	int x, y;					// ��ġ ��ǥ
	int width, height;			// ����, ���α���
	int frameX, frameY;			// ������ X��ǥ, Y��ǥ ����
	bool isTrans;				// ��� ����ȭ ����
	COLORREF transColor;		// ����ȭ��ų ��
};

// loadItem Ŭ����
class loadItem
{
private:
	// Ŭ���� ����
	LOAD_KIND _kind;
	tagImageResource _imageResource;

public:
	// �ʱ�ȭ ó��
	HRESULT init(string strKey, int width, int height);
	HRESULT init(string strKey, const char* fileName, int width, int height, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));

	// ������ ���� ��������
	LOAD_KIND getLoadKind() { return _kind; }
	
	// �̹��� ���ҽ� ��������
	tagImageResource getImageResource() { return _imageResource; }

	// ������, �Ҹ���
	loadItem() {}
	~loadItem() {}
};

// loading Ŭ����
class loading : public gameNode
{
private:
	// �̹��� ����
	progressBar* _loadingBar;
	int _currentGauge;

	// Ŭ���� ����
	// loadItem Ŭ������ ���� ���� �� �ݺ���
	typedef vector<loadItem*> vLoadItem;
	typedef vector<loadItem*>::iterator viLoadItem;
	vLoadItem _vLoadItem;

	// ���� ����
	// int _loadingBarPercentage[4];

public:
	// GET, SET �Լ�
	vLoadItem getLoadItem() { return _vLoadItem; }
	int getCurrentGauge() { return _currentGauge; }

	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render(BYTE alpha);

	// �̹��� �ε�
	void loadImage(string strKey, int width, int height);
	void loadImage(string strKey, const char* fileName, int width, int height, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	void loadImage(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	void loadFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	void loadFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));

	// �ε� �Ϸ� �� ȭ�� ��ȯ
	bool loadingDone();

	// ������, �Ҹ���
	loading() {}
	~loading() {}
};