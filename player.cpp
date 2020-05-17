#include "stdafx.h"
#include "player.h"
#include "object.h"
#include "clone.h"

// �ʱ�ȭ (init)
HRESULT player::init(int _currentStage)
{
	// �÷��̾� �̹��� ã��
	setPlayerIdle(IMAGEMANAGER->findImage("Player_Idle"));
	setPlayerRun(IMAGEMANAGER->findImage("Player_Run"));
	setPlayerJumpFall(IMAGEMANAGER->findImage("Player_JumpFall"));
	setPlayerDead(IMAGEMANAGER->findImage("Player_Dead"));

	// �÷��̾� ���� �ʱ�ȭ
	tagPlayer player;
	ZeroMemory(&player, sizeof(player));
	switch (_currentStage)
	{
	case 1:
		player.mapX = 1056;
		player.mapY = 928;
		break;
	case 2:
		player.mapX = 928;
		player.mapY = 992;
		break;
	case 3:
		player.mapX = 1120;
		player.mapY = 928;
		break;
	case 4:
		player.mapX = 1280;
		player.mapY = 1056;
		break;
	case 5:
		player.mapX = 768;
		player.mapY = 608;
		break;
	case 6:
		player.mapX = 1280;
		player.mapY = 992;
		break;
	case 7:
		player.mapX = 736;
		player.mapY = 672;
		break;
	case 8:
		player.mapX = 800;
		player.mapY = 1248;
		break;
	case 9:
		player.mapX = 1792;
		player.mapY = 992;
		break;
	case 10:
		player.mapX = 1792;
		player.mapY = 672;
		break;
	}
	player.screenX = WINSIZEX / 2;
	player.screenY = WINSIZEY / 2;
	player.gravity = 0;
	player.gravityDelay = 0;
	player.jumpDelay = 0;
	player.jumpCount = 0;
	player.jumping = FALSE;
	player.falling = FALSE;
	player.dead = FALSE;
	player.playerRect = RectMakeCenter(player.screenX, player.screenY, 40, 64);
	player.playerTileCollisionRectLeft1 = RectMakeCenter(player.screenX - 20, player.screenY - 24, 4, 2);
	player.playerTileCollisionRectLeft2 = RectMakeCenter(player.screenX - 20, player.screenY + 24, 4, 2);
	player.playerTileCollisionRectRight1 = RectMakeCenter(player.screenX + 20, player.screenY - 24, 4, 2);
	player.playerTileCollisionRectRight2 = RectMakeCenter(player.screenX + 20, player.screenY + 24, 4, 2);
	player.playerTileCollisionRectTop1 = RectMakeCenter(player.screenX - 14, player.screenY - 31, 2, 4);
	player.playerTileCollisionRectTop2 = RectMakeCenter(player.screenX + 14, player.screenY - 31, 2, 4);
	player.playerTileCollisionRectBottom1 = RectMakeCenter(player.screenX - 14, player.screenY + 31, 2, 4);
	player.playerTileCollisionRectBottom2 = RectMakeCenter(player.screenX + 14, player.screenY + 31, 2, 4);
	_player.screenX = player.screenX;
	_player.screenY = player.screenY;
	_player.mapX = player.mapX;
	_player.mapY = player.mapY;
	_player.gravity = player.gravity;
	_player.gravityDelay = player.gravity;
	_player.jumpDelay = player.jumpDelay;
	_player.jumpCount = player.jumpCount;
	_player.jumping = player.jumping;
	_player.falling = player.falling;
	_player.dead = player.dead;
	_player.playerRect = player.playerRect;

	// ��Ÿ ���� �ʱ�ȭ
	setCount(0);
	setIndex(0);
	setAlpha(0);
	setPlayerDirection(PLAYER_DIRECTION_RIGHT);
	setPlayerState(PLAYER_STATE_IDLE);
	setPlayerProbeLeftX(0);
	setPlayerProbeRightX(0);
	setPlayerProbeTopY(0);
	setPlayerProbeBottomY(0);
	setTileCollisionLeft(FALSE);
	setTileCollisionRight(FALSE);
	setTileCollisionTop(FALSE);
	setTileCollisionBottom(FALSE);
	setPixelCollisionLeft(FALSE);
	setPixelCollisionRight(FALSE);
	setPixelCollisionTop(FALSE);
	setPixelCollisionBottom(FALSE);
	setTileCollisionLeftCount(0);
	setTileCollisionRightCount(0);
	setTileCollisionTopCount(0);
	setTileCollisionBottomCount(0);
	setWalkDelay(0);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setDeadSoundOutput(FALSE);

	// �ʱ�ȭ ����
	return S_OK;
}
HRESULT player::init(int _currentStage, int _alpha)
{
	// �÷��̾� ���� �ʱ�ȭ
	tagPlayer player;
	ZeroMemory(&player, sizeof(player));
	switch (_currentStage)
	{
	case 1:
		player.mapX = 1056;
		player.mapY = 928;
		break;
	case 2:
		player.mapX = 928;
		player.mapY = 992;
		break;
	case 3:
		player.mapX = 1120;
		player.mapY = 928;
		break;
	case 4:
		player.mapX = 1280;
		player.mapY = 1056;
		break;
	case 5:
		player.mapX = 768;
		player.mapY = 608;
		break;
	case 6:
		player.mapX = 1280;
		player.mapY = 992;
		break;
	case 7:
		player.mapX = 736;
		player.mapY = 672;
		break;
	case 8:
		player.mapX = 800;
		player.mapY = 1248;
		break;
	case 9:
		player.mapX = 1792;
		player.mapY = 992;
		break;
	case 10:
		player.mapX = 1792;
		player.mapY = 672;
		break;
	}
	player.screenX = WINSIZEX / 2;
	player.screenY = WINSIZEY / 2;
	player.gravity = 0;
	player.gravityDelay = 0;
	player.jumpDelay = 0;
	player.jumpCount = 0;
	player.jumping = FALSE;
	player.falling = FALSE;
	player.dead = FALSE;
	player.playerRect = RectMakeCenter(player.screenX, player.screenY, 40, 64);
	player.playerTileCollisionRectLeft1 = RectMakeCenter(player.screenX - 20, player.screenY - 24, 4, 2);
	player.playerTileCollisionRectLeft2 = RectMakeCenter(player.screenX - 20, player.screenY + 24, 4, 2);
	player.playerTileCollisionRectRight1 = RectMakeCenter(player.screenX + 20, player.screenY - 24, 4, 2);
	player.playerTileCollisionRectRight2 = RectMakeCenter(player.screenX + 20, player.screenY + 24, 4, 2);
	player.playerTileCollisionRectTop1 = RectMakeCenter(player.screenX - 14, player.screenY - 31, 2, 4);
	player.playerTileCollisionRectTop2 = RectMakeCenter(player.screenX + 14, player.screenY - 31, 2, 4);
	player.playerTileCollisionRectBottom1 = RectMakeCenter(player.screenX - 14, player.screenY + 31, 2, 4);
	player.playerTileCollisionRectBottom2 = RectMakeCenter(player.screenX + 14, player.screenY + 31, 2, 4);
	_player.screenX = player.screenX;
	_player.screenY = player.screenY;
	_player.mapX = player.mapX;
	_player.mapY = player.mapY;
	_player.gravity = player.gravity;
	_player.gravityDelay = player.gravity;
	_player.jumpDelay = player.jumpDelay;
	_player.jumpCount = player.jumpCount;
	_player.jumping = player.jumping;
	_player.falling = player.falling;
	_player.dead = player.dead;
	_player.playerRect = player.playerRect;

	// ��Ÿ ���� �ʱ�ȭ
	setCount(0);
	setIndex(0);
	setAlpha(_alpha);
	setPlayerDirection(PLAYER_DIRECTION_RIGHT);
	setPlayerState(PLAYER_STATE_IDLE);
	setPlayerProbeLeftX(0);
	setPlayerProbeRightX(0);
	setPlayerProbeTopY(0);
	setPlayerProbeBottomY(0);
	setTileCollisionLeft(FALSE);
	setTileCollisionRight(FALSE);
	setTileCollisionTop(FALSE);
	setTileCollisionBottom(FALSE);
	setPixelCollisionLeft(FALSE);
	setPixelCollisionRight(FALSE);
	setPixelCollisionTop(FALSE);
	setPixelCollisionBottom(FALSE);
	setTileCollisionLeftCount(0);
	setTileCollisionRightCount(0);
	setTileCollisionTopCount(0);
	setTileCollisionBottomCount(0);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setDeadSoundOutput(FALSE);

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void player::release()
{
}

// ������Ʈ (update)
void player::update()
{
	// �÷��̾� RECT ��ġ ����
	_player.playerRect = RectMakeCenter(_player.screenX, _player.screenY, 40, 64);
	_player.playerTileCollisionRectLeft1 = RectMakeCenter(_player.screenX - 20, _player.screenY - 24, 4, 2);
	_player.playerTileCollisionRectLeft2 = RectMakeCenter(_player.screenX - 20, _player.screenY + 24, 4, 2);
	_player.playerTileCollisionRectRight1 = RectMakeCenter(_player.screenX + 20, _player.screenY - 24, 4, 2);
	_player.playerTileCollisionRectRight2 = RectMakeCenter(_player.screenX + 20, _player.screenY + 24, 4, 2);
	_player.playerTileCollisionRectTop1 = RectMakeCenter(_player.screenX - 14, _player.screenY - 31, 2, 4);
	_player.playerTileCollisionRectTop2 = RectMakeCenter(_player.screenX + 14, _player.screenY - 31, 2, 4);
	_player.playerTileCollisionRectBottom1 = RectMakeCenter(_player.screenX - 14, _player.screenY + 31, 2, 4);
	_player.playerTileCollisionRectBottom2 = RectMakeCenter(_player.screenX + 14, _player.screenY + 31, 2, 4);
	setPlayerProbeLeftX(_player.mapX - 20);
	setPlayerProbeRightX(_player.mapX + 20);
	setPlayerProbeTopY(_player.mapY - 32);
	setPlayerProbeBottomY(_player.mapY + 32);

	// �÷��̾� Ÿ�� �浹
	// ���� �浹
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		if (getObjectAdress()->getObject()[i].objectType != OBJECT_TYPE_TILE)
		{
			continue;
		}
		else if (getObjectAdress()->getObject()[i].trigger == FALSE)
		{
			continue;
		}

		RECT rc;
		if (IntersectRect(&rc, &getPlayerTileCollisionRectLeft1(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionLeft(TRUE);
			//setMapX(getObjectAdress()->getObject()[i].createX + 48);
			break;
		}
		else if (IntersectRect(&rc, &getPlayerTileCollisionRectLeft2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionLeft(TRUE);
			//setMapX(getObjectAdress()->getObject()[i].createX + 48);
			break;
		}
		else
		{
			if (i == getObjectAdress()->getObject().size() - 1)
			{
				setTileCollisionLeft(FALSE);
				break;
			}
		}
	}
	// ���� �浹
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		if (getObjectAdress()->getObject()[i].objectType != OBJECT_TYPE_TILE)
		{
			continue;
		}
		else if (getObjectAdress()->getObject()[i].trigger == FALSE)
		{
			continue;
		}

		RECT rc;
		if (IntersectRect(&rc, &getPlayerTileCollisionRectRight1(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionRight(TRUE);
			//setMapX(getObjectAdress()->getObject()[i].createX - 48);
			break;
		}
		else if (IntersectRect(&rc, &getPlayerTileCollisionRectRight2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionRight(TRUE);
			//setMapX(getObjectAdress()->getObject()[i].createX - 48);
			break;
		}
		else
		{
			if (i == getObjectAdress()->getObject().size() - 1)
			{
				setTileCollisionRight(FALSE);
				break;
			}
		}
	}
	// ��� �浹
	if (getTileCollisionTop() == FALSE && getJumping() == TRUE)
	{
		for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
		{
			if (getObjectAdress()->getObject()[i].objectType != OBJECT_TYPE_TILE)
			{
				continue;
			}
			else if (getObjectAdress()->getObject()[i].trigger == FALSE)
			{
				continue;
			}

			RECT rc;
			if (IntersectRect(&rc, &getPlayerTileCollisionRectTop1(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setTileCollisionTop(TRUE);
				setJumping(FALSE);
				setFalling(TRUE);
				setMapY(getObjectAdress()->getObject()[i].createY + 68);
				setGravity(getGravity() * -1);
				break;
			}
			else if (IntersectRect(&rc, &getPlayerTileCollisionRectTop2(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setTileCollisionTop(TRUE);
				setJumping(FALSE);
				setFalling(TRUE);
				setMapY(getObjectAdress()->getObject()[i].createY + 68);
				setGravity(getGravity() * -1);
				break;
			}
		}
	}
	// �ϴ� �浹 (���� �浹�� ����)
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		RECT rc;
		if (getObjectAdress()->getObject()[i].objectType == OBJECT_TYPE_TILE && getObjectAdress()->getObject()[i].trigger == TRUE && getJumping() == FALSE)
		{
			if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom1(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setJumpCount(0);
				setPixelCollisionTop(FALSE);
				setTileCollisionTop(FALSE);
				setTileCollisionBottom(TRUE);
				setFalling(FALSE);
				setMapY(getObjectAdress()->getObject()[i].createY - 64);
				break;
			}
			else if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom2(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setJumpCount(0);
				setPixelCollisionTop(FALSE);
				setTileCollisionTop(FALSE);
				setTileCollisionBottom(TRUE);
				setFalling(FALSE);
				setMapY(getObjectAdress()->getObject()[i].createY - 64);
				break;
			}
		}
		else if (getObjectAdress()->getObject()[i].objectType == OBJECT_TYPE_LEDGE && getJumping() == FALSE)
		{
			if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom1(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setJumpCount(0);
				setPixelCollisionTop(FALSE);
				setTileCollisionTop(FALSE);
				setTileCollisionBottom(TRUE);
				setFalling(FALSE);
				setMapY(getObjectAdress()->getObject()[i].createY - 36);
				break;
			}
			else if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom2(), &getObjectAdress()->getObject()[i].objectRect))
			{
				setJumpCount(0);
				setPixelCollisionTop(FALSE);
				setTileCollisionTop(FALSE);
				setTileCollisionBottom(TRUE);
				setFalling(FALSE);
				setMapY(getObjectAdress()->getObject()[i].createY - 36);
				break;
			}
		}
		else
		{
			if (i == getObjectAdress()->getObject().size() - 1)
			{
				setTileCollisionBottom(FALSE);
				break;
			}
		}
	}

	// Ÿ�� �浹 ����
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		RECT rc;
		// ���� �浹
		if (getTileCollisionLeft() == TRUE &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectLeft1(), &getObjectAdress()->getObject()[i].objectRect) &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectLeft2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionLeftCount(getTileCollisionLeftCount() + 1);
		}
		else if (getTileCollisionLeft() == TRUE &&
			(IntersectRect(&rc, &getPlayerTileCollisionRectLeft1(), &getObjectAdress()->getObject()[i].objectRect) ||
			IntersectRect(&rc, &getPlayerTileCollisionRectLeft2(), &getObjectAdress()->getObject()[i].objectRect)) &&
			getObjectAdress()->getObject()[i].trigger == FALSE)
		{
			setTileCollisionLeftCount(getTileCollisionLeftCount() + 1);
		}

		// ���� �浹
		if (getTileCollisionRight() == TRUE &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectRight1(), &getObjectAdress()->getObject()[i].objectRect) &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectRight2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionRightCount(getTileCollisionRightCount() + 1);
		}
		else if (getTileCollisionRight() == TRUE &&
			(IntersectRect(&rc, &getPlayerTileCollisionRectRight1(), &getObjectAdress()->getObject()[i].objectRect) ||
			IntersectRect(&rc, &getPlayerTileCollisionRectRight2(), &getObjectAdress()->getObject()[i].objectRect)) &&
			getObjectAdress()->getObject()[i].trigger == FALSE)
		{
			setTileCollisionRightCount(getTileCollisionRightCount() + 1);
		}

		// �ϴ� �浹
		if (getTileCollisionBottom() == TRUE &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectBottom1(), &getObjectAdress()->getObject()[i].objectRect) &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectBottom2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionBottomCount(getTileCollisionBottomCount() + 1);
		}

		// ī��Ʈ �ʱ�ȭ
		if (i == getObjectAdress()->getObject().size() - 1)
		{
			if (getTileCollisionLeftCount() >= getObjectAdress()->getObject().size())
			{
				setTileCollisionLeft(FALSE);
			}
			setTileCollisionLeftCount(0);

			if (getTileCollisionRightCount() >= getObjectAdress()->getObject().size())
			{
				setTileCollisionRight(FALSE);
			}
			setTileCollisionRightCount(0);

			if (getTileCollisionBottomCount() >= getObjectAdress()->getObject().size())
			{
				setTileCollisionBottom(FALSE);
			}
			setTileCollisionBottomCount(0);
		}
	}

	// �÷��̾ ��� ���°� �ƴ� ���
	if (getDead() == FALSE)
	{
		// �÷��̾� �߷°� ���� �� Y��ǥ ����
		if (getTileCollisionBottom() == FALSE && getPixelCollisionBottom() == FALSE && getGravity() <= 8)
		{
			_player.gravityDelay += 1;
			if (_player.gravityDelay >= 3)
			{
				_player.gravityDelay = 0;
				_player.gravity += 1;
			}
		}
		if (getTileCollisionBottom() == TRUE)
		{
			_player.gravityDelay = 0;
			_player.gravity = 0;
		}
		else if (getPixelCollisionBottom() == TRUE)
		{
			_player.gravityDelay = 0;
			_player.gravity = 0;
		}
		_player.mapY += _player.gravity;

		// ȭ�� �� Y��ǥ ����
		if (_player.mapY < WINSIZEY / 2 && _player.playerRect.top > 0)
		{
			_player.screenY -= _player.gravity;
		}
		else if (_player.mapY > getCurrentStageHeight() - (WINSIZEY / 2) && _player.playerRect.bottom < WINSIZEY)
		{
			_player.screenY += _player.gravity;
		}

		// ȭ�� �� ��ǥ�� �� �� ��ǥ�� ���� ���߱�
		if ((_player.mapY >= WINSIZEY / 2 && _player.screenY < WINSIZEX / 2) ||
			(_player.mapY == getCurrentStageHeight() - (WINSIZEY / 2) && _player.screenY > WINSIZEX / 2))
		{
			_player.screenY = WINSIZEY / 2;
		}

		// �÷��̾� ĳ���� �̵�
		if (getStageStart() == TRUE && getAlpha() >= 255)
		{
			// ���� �̵�
			if (INPUT->getKey(VK_LEFT))
			{
				// �÷��̾� ���� ����
				setPlayerDirection(PLAYER_DIRECTION_LEFT);

				// Ÿ�� �浹 ó�� ��Ȱ��ȭ
				setTileCollisionRight(FALSE);

				// �浹 ������ ��� ��ǥ ���� X
				if (getTileCollisionLeft() == FALSE && getPixelCollisionLeft() == FALSE)
				{
					// �÷��̾� �� �� X��ǥ ����
					if (_player.playerRect.left > 0)
					{
						_player.mapX -= 8;
					}
					// �÷��̾� ȭ�� �� X��ǥ ����
					if ((_player.mapX < (WINSIZEX / 2) && _player.playerRect.left > 0) ||
						(_player.mapX > getCurrentStageWidth() - (WINSIZEX / 2) && _player.playerRect.right < WINSIZEX))
					{
						_player.screenX -= 8;
					}
					// ȭ�� �� ��ǥ�� �� �� ��ǥ�� ���� ���߱�
					if (_player.mapX == getCurrentStageWidth() - (WINSIZEX / 2) && _player.screenX >= (WINSIZEX / 2) + 8)
					{
						_player.screenX = WINSIZEX / 2;
					}
				}

				// �÷��̾� �ൿ ���� ����
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_RUN);
				}

				// ����, �ϰ� ���� �ƴ� ��� ���� ���
				if (getJumping() == FALSE && getFalling() == FALSE)
				{
					setWalkDelay(getWalkDelay() + 1);

					if (getWalkDelay() >= 15)
					{
						setWalkDelay(0);
					}
				}
				if (getWalkDelay() == 1)
				{
					SOUNDMANAGER->play("Walk");
				}
			}
			// ������ �̵�
			if (INPUT->getKey(VK_RIGHT))
			{
				// �÷��̾� ���� ����
				setPlayerDirection(PLAYER_DIRECTION_RIGHT);

				// Ÿ�� �浹 ó�� ��Ȱ��ȭ
				setTileCollisionLeft(FALSE);

				// �浹 ������ ��� ��ǥ ���� X
				if (getTileCollisionRight() == FALSE && getPixelCollisionRight() == FALSE)
				{
					// �÷��̾� �� �� X��ǥ ����
					if (_player.playerRect.right < WINSIZEX)
					{
						_player.mapX += 8;
					}
					// �÷��̾� ȭ�� �� X��ǥ ����
					if ((_player.mapX > getCurrentStageWidth() - (WINSIZEX / 2) && _player.playerRect.right < WINSIZEX) ||
						(_player.mapX < (WINSIZEX / 2) && _player.playerRect.left > 0))
					{
						_player.screenX += 8;
					}
					// ȭ�� �� ��ǥ�� �� �� ��ǥ�� ���� ���߱�
					if (_player.mapX == (WINSIZEX / 2) && _player.screenX <= (WINSIZEX / 2) - 8)
					{
						_player.screenX = WINSIZEX / 2;
					}
				}

				// �÷��̾� �ൿ ���� ����
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_RUN);
				}

				// ����, �ϰ� ���� �ƴ� ��� ���� ���
				if (getJumping() == FALSE && getFalling() == FALSE)
				{
					setWalkDelay(getWalkDelay() + 1);

					if (getWalkDelay() >= 15)
					{
						setWalkDelay(0);
					}
				}
				if (getWalkDelay() == 1)
				{
					SOUNDMANAGER->play("Walk");
				}
			}
			// Ű�� ���� �� �÷��̾��� ���� ����
			if (INPUT->getKeyUp(VK_LEFT))
			{
				setPlayerDirection(PLAYER_DIRECTION_LEFT);
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_IDLE);
				}
				setWalkDelay(0);
			}
			if (INPUT->getKeyUp(VK_RIGHT))
			{
				setPlayerDirection(PLAYER_DIRECTION_RIGHT);
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_IDLE);
				}
				setWalkDelay(0);
			}
			// �÷��̾� ĳ���� ����
			if (INPUT->getKeyDown(0x5A) && _player.jumpCount <= 1)
			{
				// ���� ���
				if (_player.jumpCount == 0)
				{
					SOUNDMANAGER->play("Jump1");
				}
				else if (_player.jumpCount == 1)
				{
					SOUNDMANAGER->play("Jump2");
				}

				// ��ŷ ���� �ߺ� ��� ����
				if (getWalkDelay() == 1)
				{
					setWalkDelay(getWalkDelay() + 1);
				}

				_player.jumpDelay = 0;
				_player.jumping = TRUE;
				_player.falling = FALSE;
				_player.gravity = -8;
				setTileCollisionTop(FALSE);
				setTileCollisionBottom(FALSE);
				setPixelCollisionTop(FALSE);
				setPixelCollisionBottom(FALSE);
				_player.jumpCount += 1;
				setPlayerState(PLAYER_STATE_JUMP);
			}
			// �÷��̾� ���� �� ü�� �ð� ����
			if (INPUT->getKey(0x5A) && _player.jumpCount <= 2 && (getTileCollisionTop() == FALSE && getPixelCollisionTop() == FALSE))
			{
				_player.jumpDelay += 1;
				if (_player.jumpDelay <= 10)
				{
					_player.gravity = -8;
				}
			}
			// �÷��̾� 3�� ���� ����
			if (INPUT->getKeyUp(0x5A) && _player.jumpCount == 2)
			{
				_player.jumpCount += 1;
			}
			// �÷��̾� ���� �浹 ó�� ����
			if (INPUT->getKeyDown(VK_DOWN))
			{
				for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
				{
					if (getObjectAdress()->getObject()[i].objectType != OBJECT_TYPE_LEDGE)
					{
						continue;
					}

					RECT rc;
					if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom1(), &getObjectAdress()->getObject()[i].objectRect) &&
						getObjectAdress()->getObject()[i].objectType == OBJECT_TYPE_LEDGE && getTileCollisionBottom() == TRUE)
					{
						setMapY(getMapY() + 16);
						setTileCollisionBottom(FALSE);
					}
					else if (IntersectRect(&rc, &getPlayerTileCollisionRectBottom2(), &getObjectAdress()->getObject()[i].objectRect) &&
						getObjectAdress()->getObject()[i].objectType == OBJECT_TYPE_LEDGE && getTileCollisionBottom() == TRUE)
					{
						setMapY(getMapY() + 16);
						setTileCollisionBottom(FALSE);
					}
					else
					{
						if (i != getObjectAdress()->getObject().size() - 1)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
			}
		}

		// �÷��̾� ĳ���� �ϰ�
		if (_player.gravity > 0)
		{
			// ��ŷ ���� �ߺ� ��� ����
			if (getWalkDelay() == 1)
			{
				setWalkDelay(getWalkDelay() + 1);
			}

			_player.jumping = FALSE;
			_player.falling = TRUE;
			setPlayerState(PLAYER_STATE_FALL);
		}
		if (getPlayerState() == PLAYER_STATE_FALL && getTileCollisionBottom() == TRUE)
		{
			setWalkDelay(0);
			_player.falling = FALSE;
			_player.jumpCount = 0;
			_player.jumpDelay = 0;
			setTileCollisionTop(FALSE);
			setPixelCollisionTop(FALSE);
			if (INPUT->getKey(VK_LEFT) || INPUT->getKey(VK_RIGHT))
			{
				setPlayerState(PLAYER_STATE_RUN);
			}
			else
			{
				setPlayerState(PLAYER_STATE_IDLE);
			}
		}
		if (getPlayerState() == PLAYER_STATE_FALL && getPixelCollisionBottom() == TRUE)
		{
			setWalkDelay(0);
			_player.falling = FALSE;
			_player.jumpCount = 0;
			_player.jumpDelay = 0;
			setTileCollisionTop(FALSE);
			setPixelCollisionTop(FALSE);
			if (INPUT->getKey(VK_LEFT) || INPUT->getKey(VK_RIGHT))
			{
				setPlayerState(PLAYER_STATE_RUN);
			}
			else
			{
				setPlayerState(PLAYER_STATE_IDLE);
			}
		}
	}

	// �÷��̾� ���
	RECT rc;
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		if (getObjectAdress()->getObject()[i].objectType != OBJECT_TYPE_OBSTACLE)
		{
			continue;
		}

		if (IntersectRect(&rc, &_player.playerRect, &getObjectAdress()->getObject()[i].objectRect))
		{
			if (getDeadSoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Break"))
			{
				SOUNDMANAGER->play("Break");
				setDeadSoundOutput(TRUE);
			}
			setDead(TRUE);
			getCloneAdress()->init(getAlpha());
			setPlayerState(PLAYER_STATE_DEAD);
			break;
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

	// �ִϸ��̼� ó��
	this->animation();
}

// ���� (render)
void player::render()
{
	switch (getPlayerState())
	{
	case PLAYER_STATE_IDLE:
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerIdle()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, getPlayerIdle()->getFrameX(), 1, getAlpha());
		}
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerIdle()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, getPlayerIdle()->getFrameX(), 0, getAlpha());
		}
		break;
	case PLAYER_STATE_RUN:
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerRun()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, getPlayerRun()->getFrameX(), 1, getAlpha());
		}
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerRun()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, getPlayerRun()->getFrameX(), 0, getAlpha());
		}
		break;
	case PLAYER_STATE_JUMP:
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, 0, 64, 40, 64, 1, 1, getAlpha());
		}
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, 0, 0, 40, 64, 1, 1, getAlpha());
		}
		break;
	case PLAYER_STATE_FALL:
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, 40, 64, 40, 64, 1, 1, getAlpha());
		}
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->frameAlphaRender(getMemDC(), _player.playerRect.left, _player.playerRect.top, 40, 0, 40, 64, 1, 1, getAlpha());
		}
		break;
	case PLAYER_STATE_DEAD:
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerDead()->frameAlphaRender(getMemDC(), _player.playerRect.left - 12, _player.playerRect.top + 12, 0, 0, 64, 40, 1, 1, getAlpha());
		}
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerDead()->frameAlphaRender(getMemDC(), _player.playerRect.left - 12, _player.playerRect.top + 12, 0, 0, 64, 40, 1, 1, getAlpha());
		}
		break;
	}
}

// �ִϸ��̼� (animation)
void player::animation()
{
	switch (getPlayerState())
	{
	case PLAYER_STATE_IDLE:
		// �÷��̾��� ������ ������ ��
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			setCount(getCount() + 1);
			getPlayerIdle()->setFrameY(1);
			if (getCount() % 10 == 0)
			{
				setIndex(getIndex() + 1);
				if (getIndex() > 2)
				{
					setIndex(0);
				}
				getPlayerIdle()->setFrameX(getIndex());
			}
		}
		// �÷��̾��� ������ �������� ��
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			setCount(getCount() + 1);
			getPlayerIdle()->setFrameY(0);
			if (getCount() % 10 == 0)
			{
				setIndex(getIndex() + 1);
				if (getIndex() > 2)
				{
					setIndex(0);
				}
				getPlayerIdle()->setFrameX(getIndex());
			}
		}
		break;
	case PLAYER_STATE_RUN:
		// �÷��̾��� ������ ������ ��
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			setCount(getCount() + 1);
			getPlayerRun()->setFrameY(1);
			if (getCount() % 4 == 0)
			{
				setIndex(getIndex() + 1);
				if (getIndex() > 9)
				{
					setIndex(0);
				}
				getPlayerRun()->setFrameX(getIndex());
			}
		}
		// �÷��̾��� ������ �������� ��
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			setCount(getCount() + 1);
			getPlayerRun()->setFrameY(0);
			if (getCount() % 4 == 0)
			{
				setIndex(getIndex() + 1);
				if (getIndex() > 9)
				{
					setIndex(0);
				}
				getPlayerRun()->setFrameX(getIndex());
			}
		}
		break;
	case PLAYER_STATE_JUMP:
		// �÷��̾��� ������ ������ ��
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->setFrameY(1);
			getPlayerJumpFall()->setFrameX(0);
		}
		// �÷��̾��� ������ �������� ��
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->setFrameY(0);
			getPlayerJumpFall()->setFrameX(0);
		}
		break;
	case PLAYER_STATE_FALL:
		// �÷��̾��� ������ ������ ��
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->setFrameY(1);
			getPlayerJumpFall()->setFrameX(1);
		}
		// �÷��̾��� ������ �������� ��
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->setFrameY(0);
			getPlayerJumpFall()->setFrameX(1);
		}
		break;
	case PLAYER_STATE_DEAD:
		getPlayerDead()->setFrameY(0);
		// �÷��̾��� ������ ������ ��
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerDead()->setFrameX(1);
		}
		// �÷��̾��� ������ �������� ��
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerDead()->setFrameX(0);
		}
		break;
	}
}