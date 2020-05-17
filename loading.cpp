#include "stdafx.h"
#include "loading.h"

// �ʱ�ȭ (init) - loadItem Ŭ����
HRESULT loadItem::init(string strKey, int width, int height)
{
	// �ε� ���� �ʱ�ȭ
	_kind = LOAD_KIND_IMAGE_0;
	
	// �̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = strKey;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}
HRESULT loadItem::init(string strKey, const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// �ε� ���� �ʱ�ȭ
	_kind = LOAD_KIND_IMAGE_1;
	
	// �̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = strKey;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.isTrans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}
HRESULT loadItem::init(string strKey, const char * fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
	// �ε� ���� �ʱ�ȭ
	_kind = LOAD_KIND_IMAGE_2;

	// �̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = strKey;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.isTrans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}
HRESULT loadItem::init(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// �ε� ���� �ʱ�ȭ
	_kind = LOAD_KIND_FRAMEIMAGE_0;

	// �̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = strKey;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.isTrans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}
HRESULT loadItem::init(string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// �ε� ���� �ʱ�ȭ
	_kind = LOAD_KIND_FRAMEIMAGE_1;

	// �̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = strKey;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.isTrans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

// �ʱ�ȭ (init) - loading Ŭ����
HRESULT loading::init()
{
	// �ε��� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("LoadingBarFront", "Images/Loading/LoadingBarFront.bmp", 0, 0, 1000, 16, TRUE, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("LoadingBarBack", "Images/Loading/LoadingBarBack.bmp", 0, 0, 1000, 16, TRUE, RGB(255, 0, 255));
	
	// �ε��� Ŭ���� �ʱ�ȭ
	_loadingBar = new progressBar;
	_loadingBar->init("LoadingBarFront", "LoadingBarBack");
	//_loadingBar->setGauge(0, 0);
	
	// �ε��� ��ġ
	_loadingBar->setPos(140, 910);

	// ���� ������
	_currentGauge = 0;

	return S_OK;
}

// ���� (release)
void loading::release()
{
	// �ε��� ����
	_loadingBar->release();
	SAFE_DELETE(_loadingBar);
}

// ������Ʈ (update)
void loading::update()
{
	// �ε��� ������Ʈ
	_loadingBar->update();
}

// ���� (render)
void loading::render(BYTE alpha)
{
	// �ε��� ����
	_loadingBar->render(alpha);
}

// �̹��� �ε�
void loading::loadImage(string strKey, int width, int height)
{
	loadItem* item = new loadItem;
	item->init(strKey, width, height);
	_vLoadItem.push_back(item);
}
void loading::loadImage(string strKey, const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}
void loading::loadImage(string strKey, const char * fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, x, y, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}
void loading::loadFrameImage(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, width, height, frameX, frameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}
void loading::loadFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, x, y, width, height, frameX, frameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}

// �ε� �Ϸ� �� ȭ�� ��ȯ
bool loading::loadingDone()
{
	// �ε� �Ϸ�
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	loadItem* item = _vLoadItem[_currentGauge];

	switch (item->getLoadKind())
	{
		case LOAD_KIND_IMAGE_0:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.width, img.height);
		}
		break;
		
		case LOAD_KIND_IMAGE_1:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName, img.width, img.height, img.isTrans, img.transColor);
		}
		break;
		
		case LOAD_KIND_IMAGE_2:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.isTrans, img.transColor);
		}
		break;
		
		case LOAD_KIND_FRAMEIMAGE_0:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.width, img.height, img.frameX, img.frameY, img.isTrans, img.transColor);
		}
		break;

		case LOAD_KIND_FRAMEIMAGE_1:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.frameX, img.frameY, img.isTrans, img.transColor);
		}
		break;
		
		// �� ���� ���� ���� ���� �غ���!!
		case LOAD_KIND_SOUND:
		{
		}
		break;
	}

	// ���� ������ ����
	_currentGauge++;

	// �ε��� �̹��� ����
	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());

	return FALSE;
}
