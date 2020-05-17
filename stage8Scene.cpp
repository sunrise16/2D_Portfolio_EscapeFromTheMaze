#include "stdafx.h"
#include "stage8Scene.h"

// �ʱ�ȭ (init)
HRESULT stage8Scene::init()
{
	// Ÿ�̸� �ʱ�ȭ
	TIMEMANAGER->init();

	// player Ŭ���� �ʱ�ȭ
	setPlayer(new player);
	getPlayer()->init(8);

	// clone Ŭ���� �ʱ�ȭ
	setClone(new clone);
	getClone()->init();

	// object Ŭ���� �ʱ�ȭ
	setObject(new object);
	getObject()->init(8);

	// �̹��� �ʱ�ȭ
	setStage(IMAGEMANAGER->findImage("Map_Stage8"));
	setResetMessage(IMAGEMANAGER->findImage("System_ResetMessage"));
	setMessageBox(IMAGEMANAGER->findImage("System_MessageBox"));
	setSystemMessage(IMAGEMANAGER->findImage("System_SystemMessage8"));

	// ��Ÿ ���� �ʱ�ȭ
	setIndex(0);
	setAlpha(0);
	setStageWidth(0);
	setStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);
	setOpenSoundOutput(FALSE);
	setEntrySoundOutput(FALSE);
	setStageRestartDelay(0);

	// �ּҰ� ����
	getPlayer()->setObjectAdress(getObject());
	getPlayer()->setCloneAdress(getClone());
	getClone()->setPlayerAdress(getPlayer());
	getClone()->setObjectAdress(getObject());
	getObject()->setPlayerAdress(getPlayer());
	getObject()->setCloneAdress(getClone());

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void stage8Scene::release()
{
	// player Ŭ���� ����
	getPlayer()->release();
	SAFE_DELETE(_player);

	// clone Ŭ���� �ʱ�ȭ
	getClone()->release();
	SAFE_DELETE(_clone);

	// object Ŭ���� ����
	getObject()->release();
	SAFE_DELETE(_object);
}

// ������Ʈ (update)
void stage8Scene::update()
{
	// BGM ���
	if (!SOUNDMANAGER->isPlaySound("BGM2"))
	{
		SOUNDMANAGER->play("BGM2");
	}

	// player Ŭ���� ������Ʈ
	getPlayer()->update();

	// clone Ŭ���� ������Ʈ
	getClone()->update();

	// object Ŭ���� ������Ʈ
	getObject()->update();

	// �������� ����, ���� ����
	setStageWidth(3840);
	setStageHeight(1920);
	getPlayer()->setCurrentStageWidth(getStageWidth());
	getClone()->setCurrentStageWidth(getStageWidth());
	getObject()->setCurrentStageWidth(getStageWidth());
	getPlayer()->setCurrentStageHeight(getStageHeight());
	getClone()->setCurrentStageHeight(getStageHeight());
	getObject()->setCurrentStageHeight(getStageHeight());

	// �������� �ν��ϰ� �ϱ�
	getPlayer()->setCurrentStage(8);
	getClone()->setCurrentStage(8);
	getObject()->setCurrentStage(8);

	// Ʈ���� �۵�
	RECT rc1;
	// ����Ʈ ����ġ �۵� ó��
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[25].objectRect))
	{
		if (getOpenSoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Open"))
		{
			SOUNDMANAGER->play("Open");
			setOpenSoundOutput(TRUE);
		}
		if (getObject()->getObject()[25].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(25, TRUE);
		}
		getObject()->setSwitchOn(25, TRUE);
		getObject()->setSwitchOn(35, TRUE);
	}
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[25].objectRect))
		{
			if (getOpenSoundOutput() == FALSE && !SOUNDMANAGER->isPlaySound("Open"))
			{
				SOUNDMANAGER->play("Open");
				setOpenSoundOutput(TRUE);
			}
			if (getObject()->getObject()[25].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(25, TRUE);
			}
			getObject()->setSwitchOn(25, TRUE);
			getObject()->setSwitchOn(35, TRUE);
			break;
		}
	}
	if (getObject()->getObject()[25].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[25].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(25, TRUE);
			getObject()->setSwitchOff(35, TRUE);

			if (getObject()->getObject()[25].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(25, FALSE);
				getObject()->setSwitchOn(25, FALSE);
				getObject()->setSwitchOff(25, FALSE);
			}
			if (getObject()->getObject()[35].switchOffDelay >= 30)
			{
				setOpenSoundOutput(FALSE);
				getObject()->setSwitchOn(35, FALSE);
				getObject()->setSwitchOff(35, FALSE);
			}
		}
		else
		{
			for (int i = 0; i < getClone()->getClone().size(); i++)
			{
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[25].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(25, TRUE);
						getObject()->setSwitchOff(35, TRUE);

						if (getObject()->getObject()[25].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(25, FALSE);
							getObject()->setSwitchOn(25, FALSE);
							getObject()->setSwitchOff(25, FALSE);
						}
						if (getObject()->getObject()[35].switchOffDelay >= 30)
						{
							setOpenSoundOutput(FALSE);
							getObject()->setSwitchOn(35, FALSE);
							getObject()->setSwitchOff(35, FALSE);
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
	// ��� Ÿ�� ����ġ �۵� ó��
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[26].objectRect))
	{
		if (getObject()->getObject()[26].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(26, TRUE);
		}
		getObject()->setSwitchOn(26, TRUE);
		for (int i = 0; i < 4; i++)
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
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[26].objectRect))
		{
			if (getObject()->getObject()[26].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(26, TRUE);
			}
			getObject()->setSwitchOn(26, TRUE);
			for (int j = 0; j < 4; j++)
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
	if (getObject()->getObject()[26].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[26].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(26, TRUE);
			if (getObject()->getObject()[26].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(26, FALSE);
				getObject()->setSwitchOn(26, FALSE);
				getObject()->setSwitchOff(26, FALSE);
				for (int i = 0; i < 4; i++)
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
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[26].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(26, TRUE);

						if (getObject()->getObject()[26].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(26, FALSE);
							getObject()->setSwitchOn(26, FALSE);
							getObject()->setSwitchOff(26, FALSE);
							for (int j = 0; j < 4; j++)
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
	// ������ Ÿ�� ����ġ �۵� ó��
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[27].objectRect))
	{
		if (getObject()->getObject()[27].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(27, TRUE);
		}
		getObject()->setSwitchOn(27, TRUE);
		for (int i = 4; i < 7; i++)
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
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[27].objectRect))
		{
			if (getObject()->getObject()[27].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(27, TRUE);
			}
			getObject()->setSwitchOn(27, TRUE);
			for (int j = 4; j < 7; j++)
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
	if (getObject()->getObject()[27].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[27].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(27, TRUE);
			if (getObject()->getObject()[27].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(27, FALSE);
				getObject()->setSwitchOn(27, FALSE);
				getObject()->setSwitchOff(27, FALSE);
				for (int i = 4; i < 7; i++)
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
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[27].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(27, TRUE);

						if (getObject()->getObject()[27].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(27, FALSE);
							getObject()->setSwitchOn(27, FALSE);
							getObject()->setSwitchOff(27, FALSE);
							for (int j = 4; j < 7; j++)
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
	// �ʷϻ� Ÿ�� ����ġ �۵� ó��
	if (IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[28].objectRect))
	{
		if (getObject()->getObject()[28].switchSoundOutput == FALSE)
		{
			SOUNDMANAGER->play("Switch");
			getObject()->setSwitchSoundOutput(28, TRUE);
		}
		getObject()->setSwitchOn(28, TRUE);
		for (int i = 7; i < 10; i++)
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
		if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[28].objectRect))
		{
			if (getObject()->getObject()[28].switchSoundOutput == FALSE)
			{
				SOUNDMANAGER->play("Switch");
				getObject()->setSwitchSoundOutput(28, TRUE);
			}
			getObject()->setSwitchOn(28, TRUE);
			for (int j = 7; j < 10; j++)
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
	if (getObject()->getObject()[28].switchOn == TRUE &&
		(!IntersectRect(&rc1, &getPlayer()->getPlayerRect(), &getObject()->getObject()[28].objectRect)))
	{
		if (getClone()->getClone().empty())
		{
			getObject()->setSwitchOff(28, TRUE);
			if (getObject()->getObject()[28].switchOffDelay >= 30)
			{
				getObject()->setSwitchSoundOutput(28, FALSE);
				getObject()->setSwitchOn(28, FALSE);
				getObject()->setSwitchOff(28, FALSE);
				for (int i = 7; i < 10; i++)
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
				if (IntersectRect(&rc1, &getClone()->getClone()[i].cloneRect, &getObject()->getObject()[28].objectRect))
				{
					break;
				}
				else
				{
					if (i == getClone()->getClone().size() - 1)
					{
						getObject()->setSwitchOff(28, TRUE);

						if (getObject()->getObject()[28].switchOffDelay >= 30)
						{
							getObject()->setSwitchSoundOutput(28, FALSE);
							getObject()->setSwitchOn(28, FALSE);
							getObject()->setSwitchOff(28, FALSE);
							for (int j = 7; j < 10; j++)
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

	// �������� Ŭ���� ó��
	RECT rc2;
	if (IntersectRect(&rc2, &getPlayer()->getPlayerRect(), &getObject()->getObject()[35].objectRect) && getObject()->getObject()[35].switchOn == TRUE)
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

	// ���� ���������� �Ѿ��
	if (getStageCleared() == TRUE && getAlpha() <= 0)
	{
		// ���� ����
		if (SOUNDMANAGER->isPlaySound("Rewind"))
		{
			SOUNDMANAGER->stop("Rewind");
		}

		// BGM ����
		SOUNDMANAGER->stop("BGM2");

		// INI ���� ���̺�
		// �������� ���� ���̺�
		INIDATA->addData("StageInfo", "Player_CurrentStage", "9");
		// ��� �ð� ��� �� ���̺�
		int time = TIMEMANAGER->getWorldTime();
		string str = to_string(time);
		char* str1 = new char[str.length() + 1];
		strcpy(str1, str.c_str());
		INIDATA->addData("TimeInfo", "Stage8_TimeElapsed", str1);
		INIDATA->saveINI("Save");

		// �� ��ȯ
		SCENEMANAGER->loadScene("stage9Scene");
	}

	// �������� ����� (RŰ �۵�)
	if (INPUT->getKey(0x52) && getPlayer()->getDead() == FALSE)
	{
		setStageRestartDelay(getStageRestartDelay() + 1);

		if (getStageRestartDelay() >= 90)
		{
			getPlayer()->init(8, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(8, getAlpha());
			setStageRestartDelay(0);
		}
	}
	if (INPUT->getKeyUp(0x52) && getStageRestartDelay() < 90)
	{
		setStageRestartDelay(0);
	}

	// �������� ����� (���)
	if (getPlayer()->getDead() == TRUE)
	{
		setStageRestartDelay(getStageRestartDelay() + 1);

		if (getStageRestartDelay() >= 90)
		{
			getPlayer()->init(8, getAlpha());
			getClone()->init(getAlpha());
			getObject()->getObject().clear();
			getObject()->init(8, getAlpha());
			setStageRestartDelay(0);
		}
	}

	// �÷��̾� �浹 ó�� (����)
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
	// �÷��̾� �浹 ó�� (����)
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
	// �÷��̾� �浹 ó�� (���)
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
	// 2�� ���� �� topCollision FALSE ó��
	if (getPlayer()->getPixelCollisionTop() == TRUE && INPUT->getKeyDown(0x5A))
	{
		getPlayer()->setPixelCollisionTop(FALSE);
	}
	// �÷��̾� �浹 ó�� (�ϴ�)
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

	// Ŭ�� �浹 ó��
	for (int i = 0; i < getClone()->getClone().size(); i++)
	{
		// Ŭ�� �浹 ó�� (����)
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
		// Ŭ�� �浹 ó�� (����)
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
		// Ŭ�� �浹 ó�� (���)
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
		// Ŭ�� �浹 ó�� (�ϴ�)
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
void stage8Scene::render()
{
	// �� �̹��� ���� (�̹��� �߶� �����ֱ�)
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

	// object Ŭ���� ����
	getObject()->render();

	// clone Ŭ���� ����
	getClone()->render();

	// player Ŭ���� ���� (���� ���߱�)
	getPlayer()->render();

	// �޼��� ���
	RECT rc2;
	if (IntersectRect(&rc2, &getPlayer()->getPlayerRect(), &getObject()->getObject()[34].objectRect))
	{
		getMessageBox()->render(getMemDC(), 0, WINSIZEY - 300);
		getSystemMessage()->render(getMemDC(), 0, WINSIZEY - 300);
	}

	// ���� �޼��� ���
	if (getStageRestartDelay() > 0)
	{
		getResetMessage()->frameAlphaRender(getMemDC(), (WINSIZEX / 2) - 128, (WINSIZEY)-128, 0, 0, 256, 128, 3, 1, getAlpha());
	}

	// ����׿�
	char str[256];
	// ���� ��� ���
	SetBkMode(getMemDC(), TRANSPARENT);
	// ���� ����
	SetTextColor(getMemDC(), RGB(255, 0, 255));
	// ���� ��� (����׿�)
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
}

// �ִϸ��̼� (animation)
void stage8Scene::animation()
{
	getResetMessage()->setFrameY(0);
	setIndex(getStageRestartDelay() / 30);
	getResetMessage()->setFrameX(getIndex());
}