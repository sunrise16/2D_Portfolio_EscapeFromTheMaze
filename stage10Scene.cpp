#include "stdafx.h"
#include "stage10Scene.h"

// 초기화 (init)
HRESULT stage10Scene::init()
{
	// 타이머 초기화
	TIMEMANAGER->init();

	// player 클래스 초기화
	setPlayer(new player);
	getPlayer()->init(10);

	// clone 클래스 초기화
	setClone(new clone);
	getClone()->init();

	// object 클래스 초기화
	setObject(new object);
	getObject()->init(10);

	// 이미지 초기화
	setStage(IMAGEMANAGER->findImage("Map_Stage10"));
	setResetMessage(IMAGEMANAGER->findImage("System_ResetMessage"));

	// 기타 변수 초기화
	setIndex(0);
	setAlpha(0);
	setStageWidth(0);
	setStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setOpenSoundOutput(FALSE);
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
void stage10Scene::release()
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
void stage10Scene::update()
{
	// BGM 출력
	if (!SOUNDMANAGER->isPlaySound("BGM3"))
	{
		SOUNDMANAGER->play("BGM3");
	}

	// player 클래스 업데이트
	getPlayer()->update();

	// clone 클래스 업데이트
	getClone()->update();

	// object 클래스 업데이트
	getObject()->update();

	// 스테이지 길이, 높이 지정
	setStageWidth(3840);
	setStageHeight(1920);
	getPlayer()->setCurrentStageWidth(getStageWidth());
	getClone()->setCurrentStageWidth(getStageWidth());
	getObject()->setCurrentStageWidth(getStageWidth());
	getPlayer()->setCurrentStageHeight(getStageHeight());
	getClone()->setCurrentStageHeight(getStageHeight());
	getObject()->setCurrentStageHeight(getStageHeight());

	// 스테이지 인식하게 하기
	getPlayer()->setCurrentStage(10);
	getClone()->setCurrentStage(10);
	getObject()->setCurrentStage(10);

	// 트리거 작동
	RECT rc1;
	// 게이트 스위치 작동 처리
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[43].objectRect))
	{
		if (getOpenSoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Open"))
		{
			SOUNDMANAGER->play("Open");
			setOpenSoundOutput(TRUE);
		}
		if (getObject()->getObject()[43].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(43, TRUE);
		}
		getObject()->setSwitchOn(43, TRUE);
		getObject()->setSwitchOn(54, TRUE);
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[43].objectRect))
		{
			if (getOpenSoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Open"))
			{
				SOUNDMANAGER->play("Open");
				setOpenSoundOutput(TRUE);
			}
			if (getObject()->getObject()[43].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(43, TRUE);
			}
			getObject()->setSwitchOn(43, TRUE);
			getObject()->setSwitchOn(54, TRUE);
			break;
		}
	}
	if (getObject()->getObject()[43].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[43].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(43, TRUE);
			getObject()->setSwitchOff(54, TRUE);

			if (getObject()->getObject()[43].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(43, FALSE);
				getObject()->setSwitchOn(43, FALSE);
				getObject()->setSwitchOff(43, FALSE);
			}
			if (getObject()->getObject()[54].switchOffDelay >= 30)
			{
				setOpenSoundOutput(FALSE);
				getObject()->setSwitchOn(54, FALSE);
				getObject()->setSwitchOff(54, FALSE);
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[43].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(43, TRUE);
						getObject()->setSwitchOff(54, TRUE);

						if (getObject()->getObject()[43].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(47, FALSE);
							getObject()->setSwitchOn(43, FALSE);
							getObject()->setSwitchOff(43, FALSE);
						}
						if (getObject()->getObject()[54].switchOffDelay >= 30)
						{
							setOpenSoundOutput(FALSE);
							getObject()->setSwitchOn(54, FALSE);
							getObject()->setSwitchOff(54, FALSE);
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	// 흰색 타일 스위치 작동 처리
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[44].objectRect))
	{
		if (getObject()->getObject()[44].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(44, TRUE);
		}
		getObject()->setSwitchOn(44, TRUE);
		for (int i = 0; i < 2; i++)
		{
			if (getObject()->getObject()[i].switchOn == FALSE)
			{
				getObject()->setSwitchOn(i, TRUE);
				if (getObject()->getObject()[i].trigger == FALSE)
				{
					getObject()->setTrigger(i, TRUE);
				}
				else
				{
					getObject()->setTrigger(i, FALSE);
				}
			}
		}
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[44].objectRect))
		{
			if (getObject()->getObject()[44].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(44, TRUE);
			}
			getObject()->setSwitchOn(44, TRUE);
			for (int j = 0; j < 2; j++)
			{
				if (getObject()->getObject()[j].switchOn == FALSE)
				{
					getObject()->setSwitchOn(j, TRUE);
					if (getObject()->getObject()[j].trigger == FALSE)
					{
						getObject()->setTrigger(j, TRUE);
					}
					else
					{
						getObject()->setTrigger(j, FALSE);
					}
				}
			}
			break;
		}
	}
	if (getObject()->getObject()[44].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[44].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(44, TRUE);
			if (getObject()->getObject()[44].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(44, FALSE);
				getObject()->setSwitchOn(44, FALSE);
				getObject()->setSwitchOff(44, FALSE);
				for (int i = 0; i < 2; i++)
				{
					if (getObject()->getObject()[i].switchOn == TRUE)
					{
						getObject()->setSwitchOn(i, FALSE);
						if (getObject()->getObject()[i].trigger == FALSE)
						{
							getObject()->setTrigger(i, TRUE);
						}
						else
						{
							getObject()->setTrigger(i, FALSE);
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[44].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(44, TRUE);

						if (getObject()->getObject()[44].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(44, FALSE);
							getObject()->setSwitchOn(44, FALSE);
							getObject()->setSwitchOff(44, FALSE);
							for (int j = 0; j < 2; j++)
							{
								if (getObject()->getObject()[j].switchOn == TRUE)
								{
									getObject()->setSwitchOn(j, FALSE);
									if (getObject()->getObject()[j].trigger == FALSE)
									{
										getObject()->setTrigger(j, TRUE);
									}
									else
									{
										getObject()->setTrigger(j, FALSE);
									}
								}
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	// 빨간색 타일 스위치 작동 처리
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[45].objectRect))
	{
		if (getObject()->getObject()[45].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(45, TRUE);
		}
		getObject()->setSwitchOn(45, TRUE);
		for (int i = 2; i < 14; i++)
		{
			if (getObject()->getObject()[i].switchOn == FALSE)
			{
				getObject()->setSwitchOn(i, TRUE);
				if (getObject()->getObject()[i].trigger == FALSE)
				{
					getObject()->setTrigger(i, TRUE);
				}
				else
				{
					getObject()->setTrigger(i, FALSE);
				}
			}
		}
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[45].objectRect))
		{
			if (getObject()->getObject()[45].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(45, TRUE);
			}
			getObject()->setSwitchOn(45, TRUE);
			for (int j = 2; j < 14; j++)
			{
				if (getObject()->getObject()[j].switchOn == FALSE)
				{
					getObject()->setSwitchOn(j, TRUE);
					if (getObject()->getObject()[j].trigger == FALSE)
					{
						getObject()->setTrigger(j, TRUE);
					}
					else
					{
						getObject()->setTrigger(j, FALSE);
					}
				}
			}
			break;
		}
	}
	if (getObject()->getObject()[45].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[45].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(45, TRUE);
			if (getObject()->getObject()[45].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(45, FALSE);
				getObject()->setSwitchOn(45, FALSE);
				getObject()->setSwitchOff(45, FALSE);
				for (int i = 2; i < 14; i++)
				{
					if (getObject()->getObject()[i].switchOn == TRUE)
					{
						getObject()->setSwitchOn(i, FALSE);
						if (getObject()->getObject()[i].trigger == FALSE)
						{
							getObject()->setTrigger(i, TRUE);
						}
						else
						{
							getObject()->setTrigger(i, FALSE);
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[45].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(45, TRUE);

						if (getObject()->getObject()[45].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(45, FALSE);
							getObject()->setSwitchOn(45, FALSE);
							getObject()->setSwitchOff(45, FALSE);
							for (int j = 2; j < 14; j++)
							{
								if (getObject()->getObject()[j].switchOn == TRUE)
								{
									getObject()->setSwitchOn(j, FALSE);
									if (getObject()->getObject()[j].trigger == FALSE)
									{
										getObject()->setTrigger(j, TRUE);
									}
									else
									{
										getObject()->setTrigger(j, FALSE);
									}
								}
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	// 초록색 타일 스위치 작동 처리
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[46].objectRect))
	{
		if (getObject()->getObject()[46].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(46, TRUE);
		}
		getObject()->setSwitchOn(46, TRUE);
		for (int i = 14; i < 26; i++)
		{
			if (getObject()->getObject()[i].switchOn == FALSE)
			{
				getObject()->setSwitchOn(i, TRUE);
				if (getObject()->getObject()[i].trigger == FALSE)
				{
					getObject()->setTrigger(i, TRUE);
				}
				else
				{
					getObject()->setTrigger(i, FALSE);
				}
			}
		}
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[46].objectRect))
		{
			if (getObject()->getObject()[46].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(46, TRUE);
			}
			getObject()->setSwitchOn(46, TRUE);
			for (int j = 14; j < 26; j++)
			{
				if (getObject()->getObject()[j].switchOn == FALSE)
				{
					getObject()->setSwitchOn(j, TRUE);
					if (getObject()->getObject()[j].trigger == FALSE)
					{
						getObject()->setTrigger(j, TRUE);
					}
					else
					{
						getObject()->setTrigger(j, FALSE);
					}
				}
			}
			break;
		}
	}
	if (getObject()->getObject()[46].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[46].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(46, TRUE);
			if (getObject()->getObject()[46].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(46, FALSE);
				getObject()->setSwitchOn(46, FALSE);
				getObject()->setSwitchOff(46, FALSE);
				for (int i = 14; i < 26; i++)
				{
					if (getObject()->getObject()[i].switchOn == TRUE)
					{
						getObject()->setSwitchOn(i, FALSE);
						if (getObject()->getObject()[i].trigger == FALSE)
						{
							getObject()->setTrigger(i, TRUE);
						}
						else
						{
							getObject()->setTrigger(i, FALSE);
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[46].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(46, TRUE);

						if (getObject()->getObject()[46].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(46, FALSE);
							getObject()->setSwitchOn(46, FALSE);
							getObject()->setSwitchOff(46, FALSE);
							for (int j = 14; j < 26; j++)
							{
								if (getObject()->getObject()[j].switchOn == TRUE)
								{
									getObject()->setSwitchOn(j, FALSE);
									if (getObject()->getObject()[j].trigger == FALSE)
									{
										getObject()->setTrigger(j, TRUE);
									}
									else
									{
										getObject()->setTrigger(j, FALSE);
									}
								}
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	// 파란색 타일 스위치 작동 처리
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[47].objectRect))
	{
		if (getObject()->getObject()[47].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(47, TRUE);
		}
		getObject()->setSwitchOn(47, TRUE);
		for (int i = 26; i < 30; i++)
		{
			if (getObject()->getObject()[i].switchOn == FALSE)
			{
				getObject()->setSwitchOn(i, TRUE);
				if (getObject()->getObject()[i].trigger == FALSE)
				{
					getObject()->setTrigger(i, TRUE);
				}
				else
				{
					getObject()->setTrigger(i, FALSE);
				}
			}
		}
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[47].objectRect))
		{
			if (getObject()->getObject()[47].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(47, TRUE);
			}
			getObject()->setSwitchOn(51, TRUE);
			for (int j = 26; j < 30; j++)
			{
				if (getObject()->getObject()[j].switchOn == FALSE)
				{
					getObject()->setSwitchOn(j, TRUE);
					if (getObject()->getObject()[j].trigger == FALSE)
					{
						getObject()->setTrigger(j, TRUE);
					}
					else
					{
						getObject()->setTrigger(j, FALSE);
					}
				}
			}
			break;
		}
	}
	if (getObject()->getObject()[47].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[47].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(47, TRUE);
			if (getObject()->getObject()[47].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(47, FALSE);
				getObject()->setSwitchOn(47, FALSE);
				getObject()->setSwitchOff(47, FALSE);
				for (int i = 26; i < 30; i++)
				{
					if (getObject()->getObject()[i].switchOn == TRUE)
					{
						getObject()->setSwitchOn(i, FALSE);
						if (getObject()->getObject()[i].trigger == FALSE)
						{
							getObject()->setTrigger(i, TRUE);
						}
						else
						{
							getObject()->setTrigger(i, FALSE);
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[47].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(47, TRUE);

						if (getObject()->getObject()[47].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(47, FALSE);
							getObject()->setSwitchOn(47, FALSE);
							getObject()->setSwitchOff(47, FALSE);
							for (int j = 26; j < 30; j++)
							{
								if (getObject()->getObject()[j].switchOn == TRUE)
								{
									getObject()->setSwitchOn(j, FALSE);
									if (getObject()->getObject()[j].trigger == FALSE)
									{
										getObject()->setTrigger(j, TRUE);
									}
									else
									{
										getObject()->setTrigger(j, FALSE);
									}
								}
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}

	// 스테이지 클리어 처리
	RECT rc2;
	if (IntersectRect(&rc2, &getPlayer()->getPlayerRect(), &getObject()->getObject()[54].objectRect) && getObject()->getObject()[54].switchOn == TRUE)
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

		// BGM 중지
		SOUNDMANAGER->stop("BGM3");

		// INI 파일 세이브
		// 경과 시간 계산 및 세이브
		int time = TIMEMANAGER->getWorldTime();
		string str = to_string(time);
		char* str1 = new char[str.length() + 1];
		strcpy(str1, str.c_str());
		INIDATA->addData("TimeInfo", "Stage10_TimeElapsed", str1);
		INIDATA->saveINI("Save");

		// 씬 전환
		SCENEMANAGER->loadScene("resultScene");
	}

	// 스테이지 재시작 (R키 작동)
	if (INPUT->getKey(0x52) && getPlayer()->getDead() == FALSE)
	{
		setStageRestartDelay(getStageRestartDelay() + 1);

		if (getStageRestartDelay() >= 90)
		{
			getPlayer()->init(10, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(10, getAlpha());
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
			getPlayer()->init(10, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(10, getAlpha());
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
void stage10Scene::render()
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

	// 리셋 메세지 출력
	if (getStageRestartDelay() > 0)
	{
		getResetMessage()->frameAlphaRender(getMemDC(), (WINSIZEX / 2) - 128, (WINSIZEY)-128, 0, 0, 256, 128, 3, 1, getAlpha());
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
	sprintf_s(str, "tileCollisionLeft : %d", getPlayer()->getTileCollisionLeft());
	TextOut(getMemDC(), 0, 440, str, strlen(str));
	sprintf_s(str, "tileCollisionRight : %d", getPlayer()->getTileCollisionRight());
	TextOut(getMemDC(), 0, 460, str, strlen(str));
	sprintf_s(str, "tileCollisionTop : %d", getPlayer()->getTileCollisionTop());
	TextOut(getMemDC(), 0, 480, str, strlen(str));
	sprintf_s(str, "tileCollisionBottom : %d", getPlayer()->getTileCollisionBottom());
	TextOut(getMemDC(), 0, 500, str, strlen(str));

	int time1 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage1_TimeElapsed");
	sprintf_s(str, "Stage1_TimeElapsed : %d", time1);
	TextOut(getMemDC(), 0, 520, str, strlen(str));
	int time2 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage2_TimeElapsed");
	sprintf_s(str, "Stage2_TimeElapsed : %d", time2);
	TextOut(getMemDC(), 0, 540, str, strlen(str));
	int time3 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage3_TimeElapsed");
	sprintf_s(str, "Stage3_TimeElapsed : %d", time3);
	TextOut(getMemDC(), 0, 560, str, strlen(str));
	int time4 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage4_TimeElapsed");
	sprintf_s(str, "Stage4_TimeElapsed : %d", time4);
	TextOut(getMemDC(), 0, 580, str, strlen(str));
	int time5 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage5_TimeElapsed");
	sprintf_s(str, "Stage5_TimeElapsed : %d", time5);
	TextOut(getMemDC(), 0, 600, str, strlen(str));
	int time6 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage6_TimeElapsed");
	sprintf_s(str, "Stage6_TimeElapsed : %d", time6);
	TextOut(getMemDC(), 0, 620, str, strlen(str));
	int time7 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage7_TimeElapsed");
	sprintf_s(str, "Stage7_TimeElapsed : %d", time7);
	TextOut(getMemDC(), 0, 640, str, strlen(str));
	int time8 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage8_TimeElapsed");
	sprintf_s(str, "Stage8_TimeElapsed : %d", time8);
	TextOut(getMemDC(), 0, 660, str, strlen(str));
	int time9 = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage9_TimeElapsed");
	sprintf_s(str, "Stage9_TimeElapsed : %d", time9);
	TextOut(getMemDC(), 0, 680, str, strlen(str));
}

// 애니메이션 (animation)
void stage10Scene::animation()
{
	getResetMessage()->setFrameY(0);
	setIndex(getStageRestartDelay() / 30);
	getResetMessage()->setFrameX(getIndex());
}