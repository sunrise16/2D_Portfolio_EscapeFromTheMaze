#include "stdafx.h"
#include "player.h"
#include "object.h"
#include "clone.h"

// 초기화 (init)
HRESULT player::init(int _currentStage)
{
	// 플레이어 이미지 찾기
	setPlayerIdle(IMAGEMANAGER->findImage("Player_Idle"));
	setPlayerRun(IMAGEMANAGER->findImage("Player_Run"));
	setPlayerJumpFall(IMAGEMANAGER->findImage("Player_JumpFall"));
	setPlayerDead(IMAGEMANAGER->findImage("Player_Dead"));

	// 플레이어 정보 초기화
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

	// 기타 변수 초기화
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

	// 초기화 종료
	return S_OK;
}
HRESULT player::init(int _currentStage, int _alpha)
{
	// 플레이어 정보 초기화
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

	// 기타 변수 초기화
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

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void player::release()
{
}

// 업데이트 (update)
void player::update()
{
	// 플레이어 RECT 위치 고정
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

	// 플레이어 타일 충돌
	// 좌측 충돌
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
	// 우측 충돌
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
	// 상단 충돌
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
	// 하단 충돌 (발판 충돌과 병합)
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

	// 타일 충돌 해제
	for (int i = 0; i < getObjectAdress()->getObject().size(); i++)
	{
		RECT rc;
		// 좌측 충돌
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

		// 우측 충돌
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

		// 하단 충돌
		if (getTileCollisionBottom() == TRUE &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectBottom1(), &getObjectAdress()->getObject()[i].objectRect) &&
			!IntersectRect(&rc, &getPlayerTileCollisionRectBottom2(), &getObjectAdress()->getObject()[i].objectRect))
		{
			setTileCollisionBottomCount(getTileCollisionBottomCount() + 1);
		}

		// 카운트 초기화
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

	// 플레이어가 사망 상태가 아닐 경우
	if (getDead() == FALSE)
	{
		// 플레이어 중력값 갱신 및 Y좌표 갱신
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

		// 화면 상 Y좌표 갱신
		if (_player.mapY < WINSIZEY / 2 && _player.playerRect.top > 0)
		{
			_player.screenY -= _player.gravity;
		}
		else if (_player.mapY > getCurrentStageHeight() - (WINSIZEY / 2) && _player.playerRect.bottom < WINSIZEY)
		{
			_player.screenY += _player.gravity;
		}

		// 화면 상 좌표와 맵 상 좌표를 같게 맞추기
		if ((_player.mapY >= WINSIZEY / 2 && _player.screenY < WINSIZEX / 2) ||
			(_player.mapY == getCurrentStageHeight() - (WINSIZEY / 2) && _player.screenY > WINSIZEX / 2))
		{
			_player.screenY = WINSIZEY / 2;
		}

		// 플레이어 캐릭터 이동
		if (getStageStart() == TRUE && getAlpha() >= 255)
		{
			// 왼쪽 이동
			if (INPUT->getKey(VK_LEFT))
			{
				// 플레이어 방향 설정
				setPlayerDirection(PLAYER_DIRECTION_LEFT);

				// 타일 충돌 처리 비활성화
				setTileCollisionRight(FALSE);

				// 충돌 상태일 경우 좌표 갱신 X
				if (getTileCollisionLeft() == FALSE && getPixelCollisionLeft() == FALSE)
				{
					// 플레이어 맵 상 X좌표 갱신
					if (_player.playerRect.left > 0)
					{
						_player.mapX -= 8;
					}
					// 플레이어 화면 상 X좌표 갱신
					if ((_player.mapX < (WINSIZEX / 2) && _player.playerRect.left > 0) ||
						(_player.mapX > getCurrentStageWidth() - (WINSIZEX / 2) && _player.playerRect.right < WINSIZEX))
					{
						_player.screenX -= 8;
					}
					// 화면 상 좌표와 맵 상 좌표를 같게 맞추기
					if (_player.mapX == getCurrentStageWidth() - (WINSIZEX / 2) && _player.screenX >= (WINSIZEX / 2) + 8)
					{
						_player.screenX = WINSIZEX / 2;
					}
				}

				// 플레이어 행동 상태 갱신
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_RUN);
				}

				// 점프, 하강 중이 아닐 경우 사운드 출력
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
			// 오른쪽 이동
			if (INPUT->getKey(VK_RIGHT))
			{
				// 플레이어 방향 설정
				setPlayerDirection(PLAYER_DIRECTION_RIGHT);

				// 타일 충돌 처리 비활성화
				setTileCollisionLeft(FALSE);

				// 충돌 상태일 경우 좌표 갱신 X
				if (getTileCollisionRight() == FALSE && getPixelCollisionRight() == FALSE)
				{
					// 플레이어 맵 상 X좌표 갱신
					if (_player.playerRect.right < WINSIZEX)
					{
						_player.mapX += 8;
					}
					// 플레이어 화면 상 X좌표 갱신
					if ((_player.mapX > getCurrentStageWidth() - (WINSIZEX / 2) && _player.playerRect.right < WINSIZEX) ||
						(_player.mapX < (WINSIZEX / 2) && _player.playerRect.left > 0))
					{
						_player.screenX += 8;
					}
					// 화면 상 좌표와 맵 상 좌표를 같게 맞추기
					if (_player.mapX == (WINSIZEX / 2) && _player.screenX <= (WINSIZEX / 2) - 8)
					{
						_player.screenX = WINSIZEX / 2;
					}
				}

				// 플레이어 행동 상태 갱신
				if (_player.jumping == FALSE && _player.falling == FALSE)
				{
					setPlayerState(PLAYER_STATE_RUN);
				}

				// 점프, 하강 중이 아닐 경우 사운드 출력
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
			// 키를 뗐을 때 플레이어의 상태 갱신
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
			// 플레이어 캐릭터 점프
			if (INPUT->getKeyDown(0x5A) && _player.jumpCount <= 1)
			{
				// 사운드 출력
				if (_player.jumpCount == 0)
				{
					SOUNDMANAGER->play("Jump1");
				}
				else if (_player.jumpCount == 1)
				{
					SOUNDMANAGER->play("Jump2");
				}

				// 워킹 사운드 중복 출력 방지
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
			// 플레이어 점프 시 체공 시간 유지
			if (INPUT->getKey(0x5A) && _player.jumpCount <= 2 && (getTileCollisionTop() == FALSE && getPixelCollisionTop() == FALSE))
			{
				_player.jumpDelay += 1;
				if (_player.jumpDelay <= 10)
				{
					_player.gravity = -8;
				}
			}
			// 플레이어 3단 점프 방지
			if (INPUT->getKeyUp(0x5A) && _player.jumpCount == 2)
			{
				_player.jumpCount += 1;
			}
			// 플레이어 발판 충돌 처리 해제
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

		// 플레이어 캐릭터 하강
		if (_player.gravity > 0)
		{
			// 워킹 사운드 중복 출력 방지
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

	// 플레이어 사망
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

	// 이미지 알파값 증감
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

	// 애니메이션 처리
	this->animation();
}

// 렌더 (render)
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

// 애니메이션 (animation)
void player::animation()
{
	switch (getPlayerState())
	{
	case PLAYER_STATE_IDLE:
		// 플레이어의 방향이 왼쪽일 때
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
		// 플레이어의 방향이 오른쪽일 때
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
		// 플레이어의 방향이 왼쪽일 때
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
		// 플레이어의 방향이 오른쪽일 때
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
		// 플레이어의 방향이 왼쪽일 때
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->setFrameY(1);
			getPlayerJumpFall()->setFrameX(0);
		}
		// 플레이어의 방향이 오른쪽일 때
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->setFrameY(0);
			getPlayerJumpFall()->setFrameX(0);
		}
		break;
	case PLAYER_STATE_FALL:
		// 플레이어의 방향이 왼쪽일 때
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerJumpFall()->setFrameY(1);
			getPlayerJumpFall()->setFrameX(1);
		}
		// 플레이어의 방향이 오른쪽일 때
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerJumpFall()->setFrameY(0);
			getPlayerJumpFall()->setFrameX(1);
		}
		break;
	case PLAYER_STATE_DEAD:
		getPlayerDead()->setFrameY(0);
		// 플레이어의 방향이 왼쪽일 때
		if (getPlayerDirection() == PLAYER_DIRECTION_LEFT)
		{
			getPlayerDead()->setFrameX(1);
		}
		// 플레이어의 방향이 오른쪽일 때
		else if (getPlayerDirection() == PLAYER_DIRECTION_RIGHT)
		{
			getPlayerDead()->setFrameX(0);
		}
		break;
	}
}