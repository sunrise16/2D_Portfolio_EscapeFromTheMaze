#include "stdafx.h"
#include "clone.h"
#include "player.h"
#include "object.h"

// �ʱ�ȭ (init)
HRESULT clone::init()
{
	// Ŭ�� Ÿ�̸� ��ü �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer1");
		}
		else if (i == 1)
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer2");
		}
		else
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer3");
		}
		cloneTimer[i].timerRect = RectMakeCenter(100 + (100 * i), WINSIZEY - 100, 76, 76);
		cloneTimer[i].index = 0;
	}

	// ��Ÿ ���� �ʱ�ȭ
	setAlpha(0);
	setCloneCount(0);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setRewindSoundOutput(FALSE);

	// �ʱ�ȭ ����
	return S_OK;
}
HRESULT clone::init(int _alpha)
{
	_vClone.clear();

	// Ŭ�� Ÿ�̸� ��ü �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer1");
		}
		else if (i == 1)
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer2");
		}
		else
		{
			cloneTimer[i].cloneTimerImage = IMAGEMANAGER->findImage("Player_Clone_Timer3");
		}
		cloneTimer[i].timerRect = RectMakeCenter(100 + (100 * i), WINSIZEY - 100, 76, 76);
		cloneTimer[i].index = 0;
	}

	// ��Ÿ ���� �ʱ�ȭ
	setAlpha(_alpha);
	setCloneCount(0);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void clone::release()
{
}

// ������Ʈ (update)
void clone::update()
{
	// Ŭ�� Ÿ�̸� ��ü ��ġ ����
	for (int i = 0; i < 3; i++)
	{
		cloneTimer[i].timerRect = RectMakeCenter(100 + (100 * i), WINSIZEY - 100, 76, 76);
	}

	// �÷��̾� Ŭ�� ����
	if (INPUT->getKeyDown(0x58) && getCloneCount() < 3)
	{
		// ȿ���� ���
		SOUNDMANAGER->play("Create");

		// Ŭ�� ���� �ʱ�ȭ
		tagClone clone;
		ZeroMemory(&clone, sizeof(clone));
		if (getCloneCount() == 0)
		{
			clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone1");
		}
		else if (getCloneCount() == 1)
		{
			if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone1"))
			{
				clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone2");
			}
			else if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone2"))
			{
				clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone1");
			}
			else if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone3"))
			{
				clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone1");
			}
		}
		else
		{
			if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone1"))
			{
				if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone2"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone3");
				}
				else if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone3"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone2");
				}
			}
			else if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone2"))
			{
				if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone1"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone3");
				}
				else if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone3"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone1");
				}
			}
			else if (_vClone[0].cloneImage == IMAGEMANAGER->findImage("Player_Clone3"))
			{
				if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone1"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone2");
				}
				else if (_vClone[1].cloneImage == IMAGEMANAGER->findImage("Player_Clone2"))
				{
					clone.cloneImage = IMAGEMANAGER->findImage("Player_Clone1");
				}
			}
		}
		clone.createX = getPlayerAdress()->getMapX();
		clone.createY = getPlayerAdress()->getMapY();
		clone.cloneX = getPlayerAdress()->getMapX();
		clone.cloneY = getPlayerAdress()->getMapY();
		clone.gravity = 0;
		clone.gravityDelay = 0;
		clone.cloneDelay = 0;
		clone.cloneProbeLeftX = 0;
		clone.cloneProbeRightX = 0;
		clone.cloneProbeTopY = 0;
		clone.cloneProbeBottomY = 0;
		clone.tileCollisionLeft = FALSE;
		clone.tileCollisionRight = FALSE;
		clone.tileCollisionTop = FALSE;
		clone.tileCollisionBottom = FALSE;
		clone.tileCollisionLeftCount = 0;
		clone.tileCollisionRightCount = 0;
		clone.tileCollisionTopCount = 0;
		clone.tileCollisionBottomCount = 0;
		clone.pixelCollisionLeft = FALSE;
		clone.pixelCollisionRight = FALSE;
		clone.pixelCollisionTop = FALSE;
		clone.pixelCollisionBottom = FALSE;
		clone.cloneRect = RectMakeCenter(clone.cloneX, clone.cloneY, 40, 64);
		clone.cloneTileCollisionRectLeft1 = RectMakeCenter(clone.cloneX - 20, clone.cloneY - 24, 4, 2);
		clone.cloneTileCollisionRectLeft2 = RectMakeCenter(clone.cloneX - 20, clone.cloneY + 24, 4, 2);
		clone.cloneTileCollisionRectRight1 = RectMakeCenter(clone.cloneX + 20, clone.cloneY - 24, 4, 2);
		clone.cloneTileCollisionRectRight2 = RectMakeCenter(clone.cloneX + 20, clone.cloneY + 24, 4, 2);
		clone.cloneTileCollisionRectTop1 = RectMakeCenter(clone.cloneX - 14, clone.cloneY - 31, 2, 4);
		clone.cloneTileCollisionRectTop2 = RectMakeCenter(clone.cloneX + 14, clone.cloneY - 31, 2, 4);
		clone.cloneTileCollisionRectBottom1 = RectMakeCenter(clone.cloneX - 14, clone.cloneY + 31, 2, 4);
		clone.cloneTileCollisionRectBottom2 = RectMakeCenter(clone.cloneX + 14, clone.cloneY + 31, 2, 4);
		clone.count = 0;
		clone.index = 0;
		_vClone.push_back(clone);
		setCloneCount(getCloneCount() + 1);
	}

	for (int i = 0; i < _vClone.size(); i++)
	{
		// Ŭ�� ���� ������ ����
		_vClone[i].cloneDelay += 1;

		// Ŭ�� �߷°� ���� �� Ŭ�� �� �� Y��ǥ ����
		if (_vClone[i].gravity <= 8)
		{
			_vClone[i].gravityDelay += 1;
			if (_vClone[i].gravityDelay >= 3)
			{
				_vClone[i].gravity += 1;
				_vClone[i].gravityDelay = 0;
			}
		}
		if (_vClone[i].pixelCollisionBottom == TRUE)
		{
			_vClone[i].gravity = 0;
			_vClone[i].gravityDelay = 0;
		}
		if (_vClone[i].tileCollisionBottom == TRUE)
		{
			_vClone[i].gravity = 0;
			_vClone[i].gravityDelay = 0;
		}

		// Ŭ�� ���� ���� ��ġ ��ǥ�� ����
		_vClone[i].createY += _vClone[i].gravity;

		// �÷��̾��� ��ġ�� ���� Ŭ�� ȭ�� �� ��ǥ�� ����
		if (getPlayerAdress()->getMapX() >= (WINSIZEX / 2) && getPlayerAdress()->getMapX() <= getCurrentStageWidth() - (WINSIZEX / 2))
		{
			_vClone[i].cloneX = _vClone[i].createX - (getPlayerAdress()->getMapX() - (WINSIZEX / 2));
		}
		if (getPlayerAdress()->getMapY() >= (WINSIZEY / 2) && getPlayerAdress()->getMapY() <= getCurrentStageHeight() - (WINSIZEY / 2))
		{
			_vClone[i].cloneY = _vClone[i].createY - (getPlayerAdress()->getMapY() - (WINSIZEY / 2));
		}

		// Ŭ�� RECT ��ġ ����
		_vClone[i].cloneRect = RectMakeCenter(_vClone[i].cloneX, _vClone[i].cloneY, 40, 64);
		_vClone[i].cloneTileCollisionRectLeft1 = RectMakeCenter(_vClone[i].cloneX - 20, _vClone[i].cloneY - 24, 4, 2);
		_vClone[i].cloneTileCollisionRectLeft2 = RectMakeCenter(_vClone[i].cloneX - 20, _vClone[i].cloneY + 24, 4, 2);
		_vClone[i].cloneTileCollisionRectRight1 = RectMakeCenter(_vClone[i].cloneX + 20, _vClone[i].cloneY - 24, 4, 2);
		_vClone[i].cloneTileCollisionRectRight2 = RectMakeCenter(_vClone[i].cloneX + 20, _vClone[i].cloneY + 24, 4, 2);
		_vClone[i].cloneTileCollisionRectTop1 = RectMakeCenter(_vClone[i].cloneX - 14, _vClone[i].cloneY - 31, 2, 4);
		_vClone[i].cloneTileCollisionRectTop2 = RectMakeCenter(_vClone[i].cloneX + 14, _vClone[i].cloneY - 31, 2, 4);
		_vClone[i].cloneTileCollisionRectBottom1 = RectMakeCenter(_vClone[i].cloneX - 14, _vClone[i].cloneY + 31, 2, 4);
		_vClone[i].cloneTileCollisionRectBottom2 = RectMakeCenter(_vClone[i].cloneX + 14, _vClone[i].cloneY + 31, 2, 4);
		_vClone[i].cloneProbeLeftX = _vClone[i].createX - 20;
		_vClone[i].cloneProbeRightX = _vClone[i].createX + 20;
		_vClone[i].cloneProbeTopY = _vClone[i].createY - 32;
		_vClone[i].cloneProbeBottomY = _vClone[i].createY + 32;

		// Ŭ�� Ÿ�� �浹
		// ���� �浹
		for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
		{
			if (getObjectAdress()->getObject()[j].objectType != OBJECT_TYPE_TILE)
			{
				continue;
			}
			else if (getObjectAdress()->getObject()[j].trigger == FALSE)
			{
				continue;
			}

			RECT rc;
			if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft1, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionLeft = TRUE;
				//_vClone[i].cloneX = getObjectAdress()->getObject()[j].createX + 48;
				break;
			}
			else if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionLeft = TRUE;
				//_vClone[i].cloneX = getObjectAdress()->getObject()[j].createX + 48;
				break;
			}
			else
			{
				if (j == getObjectAdress()->getObject().size() - 1)
				{
					_vClone[i].tileCollisionLeft = FALSE;
					break;
				}
			}
		}
		// ���� �浹
		for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
		{
			if (getObjectAdress()->getObject()[j].objectType != OBJECT_TYPE_TILE)
			{
				continue;
			}
			else if (getObjectAdress()->getObject()[j].trigger == FALSE)
			{
				continue;
			}

			RECT rc;
			if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight1, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionRight = TRUE;
				//_vClone[i].cloneX = getObjectAdress()->getObject()[j].createX - 48;
				break;
			}
			else if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionRight = TRUE;
				//_vClone[i].cloneX = getObjectAdress()->getObject()[j].createX - 48;
				break;
			}
			else
			{
				if (j == getObjectAdress()->getObject().size() - 1)
				{
					_vClone[i].tileCollisionRight = FALSE;
					break;
				}
			}
		}
		// ��� �浹
		if (_vClone[i].tileCollisionTop == FALSE)
		{
			for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
			{
				if (getObjectAdress()->getObject()[j].objectType != OBJECT_TYPE_TILE)
				{
					continue;
				}
				else if (getObjectAdress()->getObject()[j].trigger == FALSE)
				{
					continue;
				}

				RECT rc;
				if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectTop1, &getObjectAdress()->getObject()[j].objectRect))
				{
					_vClone[i].tileCollisionTop = TRUE;
					_vClone[i].cloneY = getObjectAdress()->getObject()[j].createY + 68;
					_vClone[i].gravity *= -1;
					break;
				}
				else if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectTop2, &getObjectAdress()->getObject()[j].objectRect))
				{
					_vClone[i].tileCollisionTop = TRUE;
					_vClone[i].cloneY = getObjectAdress()->getObject()[j].createY + 68;
					_vClone[i].gravity *= -1;
					break;
				}
			}
		}
		// �ϴ� �浹
		for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
		{
			RECT rc;
			if (getObjectAdress()->getObject()[j].objectType == OBJECT_TYPE_TILE && getObjectAdress()->getObject()[j].trigger == TRUE)
			{
				if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectBottom1, &getObjectAdress()->getObject()[j].objectRect))
				{
					_vClone[i].tileCollisionBottom = TRUE;
					_vClone[i].cloneY = getObjectAdress()->getObject()[j].objectY - 64;
					break;
				}
				else if (IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectBottom2, &getObjectAdress()->getObject()[j].objectRect))
				{
					_vClone[i].tileCollisionBottom = TRUE;
					_vClone[i].cloneY = getObjectAdress()->getObject()[j].objectY - 64;
					break;
				}
			}
			else
			{
				if (j == getObjectAdress()->getObject().size() - 1)
				{
					_vClone[i].tileCollisionBottom = FALSE;
					break;
				}
			}
		}

		// Ÿ�� �浹 ����
		for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
		{
			RECT rc;
			// ���� �浹
			if (_vClone[i].tileCollisionLeft == TRUE &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft1, &getObjectAdress()->getObject()[j].objectRect) &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionLeftCount += 1;
			}
			else if (_vClone[i].tileCollisionLeft == TRUE &&
				(IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft1, &getObjectAdress()->getObject()[i].objectRect) ||
					IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectLeft2, &getObjectAdress()->getObject()[i].objectRect)) &&
				getObjectAdress()->getObject()[i].trigger == FALSE)
			{
				_vClone[i].tileCollisionLeftCount += 1;
			}

			// ���� �浹
			if (_vClone[i].tileCollisionRight == TRUE &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight1, &getObjectAdress()->getObject()[j].objectRect) &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionRightCount += 1;
			}
			else if (_vClone[i].tileCollisionRight == TRUE &&
				(IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight1, &getObjectAdress()->getObject()[i].objectRect) ||
					IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectRight2, &getObjectAdress()->getObject()[i].objectRect)) &&
				getObjectAdress()->getObject()[i].trigger == FALSE)
			{
				_vClone[i].tileCollisionRightCount += 1;
			}

			// ��� �浹
			if (_vClone[i].tileCollisionTop == TRUE &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectTop1, &getObjectAdress()->getObject()[j].objectRect) &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectTop2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionTopCount += 1;
			}

			// �ϴ� �浹
			if (_vClone[i].tileCollisionBottom == TRUE &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectBottom1, &getObjectAdress()->getObject()[j].objectRect) &&
				!IntersectRect(&rc, &_vClone[i].cloneTileCollisionRectBottom2, &getObjectAdress()->getObject()[j].objectRect))
			{
				_vClone[i].tileCollisionBottomCount += 1;
			}

			// ī��Ʈ �ʱ�ȭ
			if (j == getObjectAdress()->getObject().size() - 1)
			{
				if (_vClone[i].tileCollisionLeftCount >= getObjectAdress()->getObject().size())
				{
					_vClone[i].tileCollisionLeft = FALSE;
				}
				_vClone[i].tileCollisionLeftCount = 0;

				if (_vClone[i].tileCollisionRightCount >= getObjectAdress()->getObject().size())
				{
					_vClone[i].tileCollisionRight = FALSE;
				}
				_vClone[i].tileCollisionRightCount = 0;

				if (_vClone[i].tileCollisionTopCount >= getObjectAdress()->getObject().size())
				{
					_vClone[i].tileCollisionTop = FALSE;
				}
				_vClone[i].tileCollisionTopCount = 0;

				if (_vClone[i].tileCollisionBottomCount >= getObjectAdress()->getObject().size())
				{
					_vClone[i].tileCollisionBottom = FALSE;
				}
				_vClone[i].tileCollisionBottomCount = 0;
			}
		}

		// ���ӽð�(20��) ���� �� Ŭ�� ����
		if (_vClone[i].cloneDelay >= 1200)
		{
			SOUNDMANAGER->play("Break");
			_vClone.erase(_vClone.begin() + i);
			setCloneCount(getCloneCount() - 1);
		}

		// Ŭ�� ���ӽð� ���� ���ҽ�Ű�� �� ���� ���
		if (!_vClone.empty())
		{
			if (INPUT->getKey(0x43) && _vClone[i].cloneDelay < 1200)
			{
				if (getRewindSoundOutput() == FALSE)
				{
					setRewindSoundOutput(TRUE);
				}
				_vClone[i].cloneDelay += 10;
			}
			if (INPUT->getKeyUp(0x43))
			{
				SOUNDMANAGER->stop("Rewind");
				setRewindSoundOutput(FALSE);
			}
			if (getRewindSoundOutput() == TRUE)
			{
				if (!SOUNDMANAGER->isPlaySound("Rewind"))
				{
					SOUNDMANAGER->play("Rewind");
				}
			}
		}
		if (_vClone.empty() && SOUNDMANAGER->isPlaySound("Rewind"))
		{
			SOUNDMANAGER->stop("Rewind");
		}

		// ��ֹ��� ���� �� Ŭ�� ����
		RECT rc;
		if (!_vClone.empty())
		{
			for (int j = 0; j < getObjectAdress()->getObject().size(); j++)
			{
				if (getObjectAdress()->getObject()[j].objectType != OBJECT_TYPE_OBSTACLE)
				{
					continue;
				}

				if (IntersectRect(&rc, &_vClone[i].cloneRect, &getObjectAdress()->getObject()[j].objectRect))
				{
					SOUNDMANAGER->play("Break");
					_vClone.erase(_vClone.begin() + i);
					setCloneCount(getCloneCount() - 1);
					break;
				}
			}
		}

		// �̹��� ���İ� ����
		if (getStageStart() == TRUE && getStageCleared() == FALSE)
		{
			setAlpha(getAlpha() + 8);

			if (getAlpha() >= 255)
			{
				setAlpha(255);
			}
		}
		else if (getStageStart() == FALSE && getStageCleared() == TRUE)
		{
			setAlpha(getAlpha() - 4);

			if (getAlpha() <= 0)
			{
				setAlpha(0);
			}
		}
	}

	// �ִϸ��̼� ó��
	this->animation();
}

// ���� (render)
void clone::render()
{
	// Ŭ�� �̹��� ����
	for (int i = 0; i < _vClone.size(); i++)
	{
		_vClone[i].cloneImage->frameAlphaRender(getMemDC(), _vClone[i].cloneRect.left, _vClone[i].cloneRect.top, _vClone[i].cloneImage->getFrameX(), 0, getAlpha());

		// Ŭ�� Ÿ�̸� �̹��� ����
		cloneTimer[i].cloneTimerImage->frameRender(getMemDC(), cloneTimer[i].timerRect.left, cloneTimer[i].timerRect.top, cloneTimer[i].cloneTimerImage->getFrameX(), 0);
	}
}

// �ִϸ��̼� (animation)
void clone::animation()
{
	// Ŭ�� �̹��� �ִϸ��̼�
	for (int i = 0; i < _vClone.size(); i++)
	{
		_vClone[i].count++;
		_vClone[i].cloneImage->setFrameY(0);
		if (_vClone[i].count % 4 == 0)
		{
			_vClone[i].index++;
			if (_vClone[i].index > 3)
			{
				_vClone[i].index = 0;
			}
			_vClone[i].cloneImage->setFrameX(_vClone[i].index);
		}

		// Ŭ�� Ÿ�̸� �̹��� �ִϸ��̼�
		cloneTimer[i].cloneTimerImage->setFrameY(0);
		cloneTimer[i].index = _vClone[i].cloneDelay / 120;
		cloneTimer[i].cloneTimerImage->setFrameX(cloneTimer[i].index);
	}
}