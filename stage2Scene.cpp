#include "stdafx.h"
#include "stage2Scene.h"

// 초기화 (init)
HRESULT stage2Scene::init()
{
	// 타이머 초기화
	TIMEMANAGER->init();

	// player 클래스 초기화
	setPlayer(new player);
	getPlayer()->init(2);

	// clone 클래스 초기화
	setClone(new clone);
	getClone()->init();

	// object 클래스 초기화
	setObject(new object);
	getObject()->init(2);

	// 이미지 초기화
	setStage(IMAGEMANAGER->findImage("Map_Stage2"));
	setResetMessage(IMAGEMANAGER->findImage("System_ResetMessage"));
	setMessageBox(IMAGEMANAGER->findImage("System_MessageBox"));
	setSystemMessage1(IMAGEMANAGER->findImage("System_SystemMessage2"));
	setSystemMessage2(IMAGEMANAGER->findImage("System_SystemMessage3"));

	// 기타 변수 초기화
	setIndex(0);
	setAlpha(0);
	setStageWidth(0);
	setStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setEntrySoundOutput(FALSE);
	setStageRestartDelay(0);

	// 주소값 전달
	getPlayer()->setObjectAdress(getObject());
	getPlayer()->setCloneAdress(getClone());
	getClone()->setPlayerAdress(getPlayer());
	getClone()->setObjectAdress(getObject());
	getObject()->setPlayerAdress(getPlayer());
	getObject()->setCloneAdress(getClone());

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void stage2Scene::release()
{
	// player 클래스 해제
	getPlayer()->release();
	SAFE_DELETE(_player);

	// clone 클래스 초기화
	getClone()->release();
	SAFE_DELETE(_clone);

	// object 클래스 해제
	getObject()->release();
	SAFE_DELETE(_object);
}

// 업데이트 (update)
void stage2Scene::update()
{
	// BGM 출력
	if (!SOUNDMANAGER->isPlaySound("BGM1"))
	{
		SOUNDMANAGER->play("BGM1");
	}

	// player 클래스 업데이트
	getPlayer()->update();

	// clone 클래스 업데이트
	getClone()->update();

	// object 클래스 업데이트
	getObject()->update();

	// 스테이지 길이, 높이 지정
	setStageWidth(2560);
	setStageHeight(1920);
	getPlayer()->setCurrentStageWidth(getStageWidth());
	getClone()->setCurrentStageWidth(getStageWidth());
	getObject()->setCurrentStageWidth(getStageWidth());
	getPlayer()->setCurrentStageHeight(getStageHeight());
	getClone()->setCurrentStageHeight(getStageHeight());
	getObject()->setCurrentStageHeight(getStageHeight());

	// 스테이지 인식하게 하기
	getPlayer()->setCurrentStage(2);
	getClone()->setCurrentStage(2);
	getObject()->setCurrentStage(2);

	// 스테이지 클리어 처리
	RECT rc1;
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[4].objectRect))
	{
		if (getEntrySoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Entry"))
		{
			if (!getClone()->getClone().empty())
			{
				SOUNDMANAGER->play("Break");
			}
			SOUNDMANAGER->play("Entry");
			setEntrySoundOutput(TRUE);
		}
		setStageStart(FALSE);
		setStageCleared(TRUE);
		getClone()->init(getAlpha());
		getPlayer()->setStageStart(FALSE);
		getClone()->setStageStart(FALSE);
		getObject()->setStageStart(FALSE);
		getPlayer()->setStageCleared(TRUE);
		getClone()->setStageCleared(TRUE);
		getObject()->setStageCleared(TRUE);
	}

	// 다음 스테이지로 넘어가기
	if (getStageCleared() == TRUE && getAlpha() <= 0)
	{
		// 사운드 중지
		if (SOUNDMANAGER->isPlaySound("Rewind"))
		{
			SOUNDMANAGER->stop("Rewind");
		}

		// INI 파일 세이브
		// 스테이지 정보 세이브
		INIDATA->addData("StageInfo", "Player_CurrentStage", "3");
		// 경과 시간 계산 및 세이브
		int time = TIMEMANAGER->getWorldTime();
		string str = to_string(time);
		char* str1 = new char[str.length() + 1];
		strcpy(str1, str.c_str());
		INIDATA->addData("TimeInfo", "Stage2_TimeElapsed", str1);
		INIDATA->saveINI("Save");

		// 씬 전환
		SCENEMANAGER->loadScene("stage3Scene");
	}

	// 스테이지 재시작 (R키 작동)
	if (INPUT->getKey(0x52) && getPlayer()->getDead() == FALSE)
	{
		setStageRestartDelay(getStageRestartDelay() + 1);

		if (getStageRestartDelay() >= 90)
		{
			getPlayer()->init(2, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(2, getAlpha());
			setStageRestartDelay(0);
		}
	}
	if (INPUT->getKeyUp(0x52) && getStageRestartDelay() < 90)
	{
		setStageRestartDelay(0);
	}

	// 스테이지 재시작 (사망)
	if (getPlayer()->getDead() == TRUE)
	{
		setStageRestartDelay(getStageRestartDelay() + 1);

		if (getStageRestartDelay() >= 90)
		{
			getPlayer()->init(2, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(2, getAlpha());
			setStageRestartDelay(0);
		}
	}

	// 플레이어 충돌 처리 (좌측)
	for (int i = getPlayer()->getPlayerProbeLeftX() + 8; i >= getPlayer()->getPlayerProbeLeftX() - 8; i--)
	{
		COLORREF color1 = GetPixel(getStage()->getMemDC(), i, getPlayer()->getMapY() - 31);
		int R1 = GetRValue(color1);
		int G1 = GetGValue(color1);
		int B1 = GetBValue(color1);

		COLORREF color2 = GetPixel(getStage()->getMemDC(), i, getPlayer()->getMapY() + 31);
		int R2 = GetRValue(color2);
		int G2 = GetGValue(color2);
		int B2 = GetBValue(color2);

		if (!(R1 == 255 && G1 == 0 && B1 == 255))
		{
			getPlayer()->setPixelCollisionLeft(TRUE);
			break;
		}
		else if (!(R2 == 255 && G2 == 0 && B2 == 255))
		{
			getPlayer()->setPixelCollisionLeft(TRUE);
			break;
		}
		else
		{
			getPlayer()->setPixelCollisionLeft(FALSE);
		}
	}
	// 플레이어 충돌 처리 (우측)
	for (int i = getPlayer()->getPlayerProbeRightX() - 8; i <= getPlayer()->getPlayerProbeRightX() + 8; i++)
	{
		COLORREF color1 = GetPixel(getStage()->getMemDC(), i, getPlayer()->getMapY() - 31);
		int R1 = GetRValue(color1);
		int G1 = GetGValue(color1);
		int B1 = GetBValue(color1);

		COLORREF color2 = GetPixel(getStage()->getMemDC(), i, getPlayer()->getMapY() + 31);
		int R2 = GetRValue(color2);
		int G2 = GetGValue(color2);
		int B2 = GetBValue(color2);

		if (!(R1 == 255 && G1 == 0 && B1 == 255))
		{
			getPlayer()->setPixelCollisionRight(TRUE);
			break;
		}
		else if (!(R2 == 255 && G2 == 0 && B2 == 255))
		{
			getPlayer()->setPixelCollisionRight(TRUE);
			break;
		}
		else
		{
			getPlayer()->setPixelCollisionRight(FALSE);
		}
	}
	// 플레이어 충돌 처리 (상단)
	if (getPlayer()->getPixelCollisionTop() == FALSE && getPlayer()->getJumping() == TRUE)
	{
		for (int i = getPlayer()->getPlayerProbeTopY() + 8; i >= getPlayer()->getPlayerProbeTopY() - 8; i--)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				getPlayer()->setPixelCollisionTop(TRUE);
				getPlayer()->setJumping(FALSE);
				getPlayer()->setFalling(TRUE);
				getPlayer()->setMapY(i + 32);
				getPlayer()->setGravity(getPlayer()->getGravity() * -1);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				getPlayer()->setPixelCollisionTop(TRUE);
				getPlayer()->setJumping(FALSE);
				getPlayer()->setFalling(TRUE);
				getPlayer()->setMapY(i + 32);
				getPlayer()->setGravity(getPlayer()->getGravity() * -1);
				break;
			}
		}
	}
	// 2단 점프 시 topCollision FALSE 처리
	if (getPlayer()->getPixelCollisionTop() == TRUE && INPUT->getKeyDown(0x5A))
	{
		getPlayer()->setPixelCollisionTop(FALSE);
	}
	// 플레이어 충돌 처리 (하단)
	if (getPlayer()->getPixelCollisionBottom() == TRUE && getPlayer()->getGravity() == 0)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY(); i <= getPlayer()->getPlayerProbeBottomY() + 4; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if ((R1 == 255 && G1 == 0 && B1 == 255) && (R2 == 255 && G2 == 0 && B2 == 255))
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
				break;
			}
		}
	}
	else if (getPlayer()->getGravity() > 0 && getPlayer()->getGravity() <= 2)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 4; i <= getPlayer()->getPlayerProbeBottomY() + 4; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}
	else if (getPlayer()->getGravity() > 2 && getPlayer()->getGravity() <= 5)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 8; i <= getPlayer()->getPlayerProbeBottomY() + 8; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}
	else if (getPlayer()->getGravity() > 5 && getPlayer()->getGravity() <= 10)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 16; i <= getPlayer()->getPlayerProbeBottomY() + 16; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}
	else if (getPlayer()->getGravity() > 10 && getPlayer()->getGravity() <= 20)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 32; i <= getPlayer()->getPlayerProbeBottomY() + 32; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}
	else if (getPlayer()->getGravity() > 20 && getPlayer()->getGravity() <= 40)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 64; i <= getPlayer()->getPlayerProbeBottomY() + 64; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}
	else if (getPlayer()->getGravity() > 40)
	{
		for (int i = getPlayer()->getPlayerProbeBottomY() - 128; i <= getPlayer()->getPlayerProbeBottomY() + 128; i++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() - 15, i);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), getPlayer()->getMapX() + 15, i);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				if (getPlayer()->getJumping() == FALSE)
				{
					getPlayer()->setPixelCollisionBottom(TRUE);
				}
				getPlayer()->setJumpCount(0);
				getPlayer()->setMapY(i - 32);
				break;
			}
			else
			{
				getPlayer()->setPixelCollisionBottom(FALSE);
			}
		}
	}

	// 클론 충돌 처리
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		// 클론 충돌 처리 (좌측)
		for (int j = getClone()->getClone()[i].cloneProbeLeftX + 8; j > getClone()->getClone()[i].cloneProbeLeftX - 8; j--)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), j, getClone()->getClone()[i].createY - 31);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), j, getClone()->getClone()[i].createY + 31);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				getClone()->setPixelCollisionLeft(i, TRUE);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				getClone()->setPixelCollisionLeft(i, TRUE);
				break;
			}
			else
			{
				getClone()->setPixelCollisionLeft(i, FALSE);
			}
		}
		// 클론 충돌 처리 (우측)
		for (int j = getClone()->getClone()[i].cloneProbeRightX - 8; j < getClone()->getClone()[i].cloneProbeRightX + 8; j++)
		{
			COLORREF color1 = GetPixel(getStage()->getMemDC(), j, getClone()->getClone()[i].createY - 31);
			int R1 = GetRValue(color1);
			int G1 = GetGValue(color1);
			int B1 = GetBValue(color1);

			COLORREF color2 = GetPixel(getStage()->getMemDC(), j, getClone()->getClone()[i].createY + 31);
			int R2 = GetRValue(color2);
			int G2 = GetGValue(color2);
			int B2 = GetBValue(color2);

			if (!(R1 == 255 && G1 == 0 && B1 == 255))
			{
				getClone()->setPixelCollisionRight(i, TRUE);
				break;
			}
			else if (!(R2 == 255 && G2 == 0 && B2 == 255))
			{
				getClone()->setPixelCollisionRight(i, TRUE);
				break;
			}
			else
			{
				getClone()->setPixelCollisionRight(i, FALSE);
			}
		}
		// 클론 충돌 처리 (상단)
		if (getClone()->getClone()[i].pixelCollisionTop == FALSE)
		{
			for (int j = getClone()->getClone()[i].cloneProbeTopY + 4; j > getClone()->getClone()[i].cloneProbeTopY - 4; j--)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionTop(i, TRUE);
					getClone()->getClone()[i].gravity *= -1;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionTop(i, TRUE);
					getClone()->getClone()[i].gravity *= -1;
					break;
				}
				else
				{
					getClone()->setPixelCollisionTop(i, FALSE);
				}
			}
		}
		// 클론 충돌 처리 (하단)
		if (getClone()->getClone()[i].pixelCollisionBottom == TRUE && getClone()->getClone()[i].gravity == 0)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY; j < getClone()->getClone()[i].cloneProbeBottomY + 4; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if ((R1 == 255 && G1 == 0 && B1 == 255) && (R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
					break;
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 0 && getClone()->getClone()[i].gravity <= 2)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 4; j < getClone()->getClone()[i].cloneProbeBottomY + 4; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 2 && getClone()->getClone()[i].gravity <= 5)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 8; j < getClone()->getClone()[i].cloneProbeBottomY + 8; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 5 && getClone()->getClone()[i].gravity <= 10)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 16; j < getClone()->getClone()[i].cloneProbeBottomY + 16; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 10 && getClone()->getClone()[i].gravity <= 20)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 32; j < getClone()->getClone()[i].cloneProbeBottomY + 32; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 20 && getClone()->getClone()[i].gravity <= 40)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 64; j < getClone()->getClone()[i].cloneProbeBottomY + 64; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
		}
		else if (getClone()->getClone()[i].gravity > 40)
		{
			for (int j = getClone()->getClone()[i].cloneProbeBottomY - 128; j < getClone()->getClone()[i].cloneProbeBottomY + 128; j++)
			{
				COLORREF color1 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX - 15, j);
				int R1 = GetRValue(color1);
				int G1 = GetGValue(color1);
				int B1 = GetBValue(color1);

				COLORREF color2 = GetPixel(getStage()->getMemDC(), getClone()->getClone()[i].createX + 15, j);
				int R2 = GetRValue(color2);
				int G2 = GetGValue(color2);
				int B2 = GetBValue(color2);

				if (!(R1 == 255 && G1 == 0 && B1 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else if (!(R2 == 255 && G2 == 0 && B2 == 255))
				{
					getClone()->setPixelCollisionBottom(i, TRUE);
					getClone()->getClone()[i].createY = j - 32;
					break;
				}
				else
				{
					getClone()->setPixelCollisionBottom(i, FALSE);
				}
			}
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
void stage2Scene::render()
{
	// 맵 이미지 렌더 (이미지 잘라서 보여주기)
	if (getPlayer()->getMapX() > (WINSIZEX / 2) && getPlayer()->getMapX() < getStageWidth() - (WINSIZEX / 2))
	{
		if (getPlayer()->getMapY() > (WINSIZEY / 2) && getPlayer()->getMapY() < getStageHeight() - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, getPlayer()->getMapX() - (WINSIZEX / 2), getPlayer()->getMapY() - (WINSIZEY / 2), 1280, 960, getAlpha());
		}
		else if (getPlayer()->getMapY() <= (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, getPlayer()->getMapX() - (WINSIZEX / 2), 0, WINSIZEX, WINSIZEY, getAlpha());
		}
		else if (getPlayer()->getMapY() >= getStageHeight() - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, getPlayer()->getMapX() - (WINSIZEX / 2), WINSIZEY, WINSIZEX, WINSIZEY, getAlpha());
		}
	}
	if (getPlayer()->getMapX() <= (WINSIZEX / 2))
	{
		if (getPlayer()->getMapY() > (WINSIZEY / 2) && getPlayer()->getMapY() < getStageHeight() - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, 0, getPlayer()->getMapY() - (WINSIZEY / 2), WINSIZEX, WINSIZEY, getAlpha());
		}
		else if (getPlayer()->getMapY() <= (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, 0, 0, WINSIZEX, WINSIZEY, getAlpha());
		}
		else if (getPlayer()->getMapY() >= getStageHeight() - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, 0, WINSIZEY, WINSIZEX, WINSIZEY, getAlpha());
		}
	}
	if (getPlayer()->getMapX() >= getStageWidth() - (WINSIZEX / 2))
	{
		if (getPlayer()->getMapY() > (WINSIZEY / 2) && getPlayer()->getMapY() < getStageHeight() - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, WINSIZEX, getPlayer()->getMapY() - (WINSIZEY / 2), WINSIZEX, WINSIZEY, getAlpha());
		}
		else if (getPlayer()->getMapY() <= (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, WINSIZEX, 0, WINSIZEX, WINSIZEY, getAlpha());
		}
		else if (getPlayer()->getMapY() >= 1920 - (WINSIZEY / 2))
		{
			getStage()->alphaRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WINSIZEX, WINSIZEY, getAlpha());
		}
	}

	// object 클래스 렌더
	getObject()->render();

	// clone 클래스 렌더
	getClone()->render();

	// player 클래스 렌더 (서순 맞추기)
	getPlayer()->render();

	// 메세지 출력 1
	RECT rc2;
	if (IntersectRect(&rc2, &getPlayer()->getPlayerRect(), &getObject()->getObject()[2].objectRect))
	{
		getMessageBox()->render(getMemDC(), 0, WINSIZEY - 300);
		getSystemMessage1()->render(getMemDC(), 0, WINSIZEY - 300);
	}

	// 메세지 출력 2
	RECT rc3;
	if (IntersectRect(&rc3, &getPlayer()->getPlayerRect(), &getObject()->getObject()[3].objectRect))
	{
		getMessageBox()->render(getMemDC(), 0, WINSIZEY - 300);
		getSystemMessage2()->render(getMemDC(), 0, WINSIZEY - 300);
	}

	// 리셋 메세지 출력
	if (getStageRestartDelay() > 0)
	{
		getResetMessage()->frameAlphaRender(getMemDC(), (WINSIZEX / 2) - 128, (WINSIZEY) - 128, 0, 0, 256, 128, 3, 1, getAlpha());
	}

	// 디버그용
	char str[256];
	// 글자 배경 모드
	SetBkMode(getMemDC(), TRANSPARENT);
	// 글자 색상
	SetTextColor(getMemDC(), RGB(255, 0, 255));
	// 변수 출력 (디버그용)
	sprintf_s(str, "player_screenX : %d", getPlayer()->getScreenX());
	TextOut(getMemDC(), 0, 40, str, strlen(str));
	sprintf_s(str, "player_screenY : %d", getPlayer()->getScreenY());
	TextOut(getMemDC(), 0, 60, str, strlen(str));
	sprintf_s(str, "player_mapX : %d", getPlayer()->getMapX());
	TextOut(getMemDC(), 0, 80, str, strlen(str));
	sprintf_s(str, "player_mapY : %d", getPlayer()->getMapY());
	TextOut(getMemDC(), 0, 100, str, strlen(str));
	sprintf_s(str, "pixelCollisionLeft : %d", getPlayer()->getPixelCollisionLeft());
	TextOut(getMemDC(), 0, 120, str, strlen(str));
	sprintf_s(str, "pixelCollisionRight : %d", getPlayer()->getPixelCollisionRight());
	TextOut(getMemDC(), 0, 140, str, strlen(str));
	sprintf_s(str, "pixelCollisionTop : %d", getPlayer()->getPixelCollisionTop());
	TextOut(getMemDC(), 0, 160, str, strlen(str));
	sprintf_s(str, "pixelCollisionBottom : %d", getPlayer()->getPixelCollisionBottom());
	TextOut(getMemDC(), 0, 180, str, strlen(str));
	sprintf_s(str, "currentStage : %d", getPlayer()->getCurrentStage());
	TextOut(getMemDC(), 0, 200, str, strlen(str));
	sprintf_s(str, "jumpCount : %d", getPlayer()->getJumpCount());
	TextOut(getMemDC(), 0, 220, str, strlen(str));
	sprintf_s(str, "player_gravity : %d", getPlayer()->getGravity());
	TextOut(getMemDC(), 0, 240, str, strlen(str));
	sprintf_s(str, "jumping : %d", getPlayer()->getJumping());
	TextOut(getMemDC(), 0, 260, str, strlen(str));
	sprintf_s(str, "falling : %d", getPlayer()->getFalling());
	TextOut(getMemDC(), 0, 280, str, strlen(str));
	sprintf_s(str, "player_direction : %d", getPlayer()->getPlayerDirection());
	TextOut(getMemDC(), 0, 300, str, strlen(str));
	sprintf_s(str, "player_state : %d", getPlayer()->getPlayerState());
	TextOut(getMemDC(), 0, 320, str, strlen(str));
	sprintf_s(str, "player_cloneCount : %d", getClone()->getCloneCount());
	TextOut(getMemDC(), 0, 340, str, strlen(str));
	sprintf_s(str, "player_probeLeftX : %d", getPlayer()->getPlayerProbeLeftX());
	TextOut(getMemDC(), 0, 360, str, strlen(str));
	sprintf_s(str, "player_probeRightX : %d", getPlayer()->getPlayerProbeRightX());
	TextOut(getMemDC(), 0, 380, str, strlen(str));
	sprintf_s(str, "player_probeTopY : %d", getPlayer()->getPlayerProbeTopY());
	TextOut(getMemDC(), 0, 400, str, strlen(str));
	sprintf_s(str, "player_probeBottomY : %d", getPlayer()->getPlayerProbeBottomY());
	TextOut(getMemDC(), 0, 420, str, strlen(str));
	if (!getClone()->getClone().empty())
	{
		sprintf_s(str, "clone_createX : %d", getClone()->getClone()[0].createX);
		TextOut(getMemDC(), 0, 440, str, strlen(str));
		sprintf_s(str, "clone_createY : %d", getClone()->getClone()[0].createY);
		TextOut(getMemDC(), 0, 460, str, strlen(str));
		sprintf_s(str, "clone_cloneX : %d", getClone()->getClone()[0].cloneX);
		TextOut(getMemDC(), 0, 480, str, strlen(str));
		sprintf_s(str, "clone_cloneY : %d", getClone()->getClone()[0].cloneY);
		TextOut(getMemDC(), 0, 500, str, strlen(str));
		sprintf_s(str, "clone_leftCollision : %d", getClone()->getClone()[0].pixelCollisionLeft);
		TextOut(getMemDC(), 0, 520, str, strlen(str));
		sprintf_s(str, "clone_rightCollision : %d", getClone()->getClone()[0].pixelCollisionRight);
		TextOut(getMemDC(), 0, 540, str, strlen(str));
		sprintf_s(str, "clone_topCollision : %d", getClone()->getClone()[0].pixelCollisionTop);
		TextOut(getMemDC(), 0, 560, str, strlen(str));
		sprintf_s(str, "clone_bottomCollision : %d", getClone()->getClone()[0].pixelCollisionBottom);
		TextOut(getMemDC(), 0, 580, str, strlen(str));
		sprintf_s(str, "clone_gravity : %d", getClone()->getClone()[0].gravity);
		TextOut(getMemDC(), 0, 600, str, strlen(str));
		sprintf_s(str, "clone_probeLeftX : %d", getClone()->getClone()[0].cloneProbeLeftX);
		TextOut(getMemDC(), 0, 620, str, strlen(str));
		sprintf_s(str, "clone_probeRightX : %d", getClone()->getClone()[0].cloneProbeRightX);
		TextOut(getMemDC(), 0, 640, str, strlen(str));
		sprintf_s(str, "clone_probeTopY : %d", getClone()->getClone()[0].cloneProbeTopY);
		TextOut(getMemDC(), 0, 660, str, strlen(str));
		sprintf_s(str, "clone_probeBottomY : %d", getClone()->getClone()[0].cloneProbeBottomY);
		TextOut(getMemDC(), 0, 680, str, strlen(str));
	}
}

// 애니메이션 (animation)
void stage2Scene::animation()
{
	getResetMessage()->setFrameY(0);
	setIndex(getStageRestartDelay() / 30);
	getResetMessage()->setFrameX(getIndex());
}