#include "stdafx.h"
#include "menuScene.h"

// �ʱ�ȭ (init)
HRESULT menuScene::init()
{
	// ��׶��� �̹��� ã��
	setBackground(IMAGEMANAGER->findImage("Menu_Background"));

	// Ÿ��Ʋ �̹��� ã��
	setTitle(IMAGEMANAGER->findImage("Menu_Title"));

	// �ɺ� �̹��� ã��
	setSymbol(IMAGEMANAGER->findImage("Menu_Symbol"));

	// ���� �޴� �̹��� ã��
	setGameStart(IMAGEMANAGER->findImage("Menu_GameStart"));
	setGameLoad(IMAGEMANAGER->findImage("Menu_GameLoad"));
	setQuit(IMAGEMANAGER->findImage("Menu_Quit"));
	setGameStartMessage(IMAGEMANAGER->findImage("Menu_GameStartMessage"));
	setGameLoadMessage(IMAGEMANAGER->findImage("Menu_GameLoadMessage"));
	setQuitMessage(IMAGEMANAGER->findImage("Menu_QuitMessage"));
	setPointer(IMAGEMANAGER->findImage("Menu_Pointer"));

	// ��Ÿ ���� �ʱ�ȭ
	setBackgroundAlpha(0);
	setBackgroundAlphaBoolOnce(TRUE);
	setBackgroundAlphaBool(FALSE);
	setTitleAlpha(0);
	setTitleAlphaBool(FALSE);
	setSymbolAlpha(0);
	setSymbolAlphaBool(FALSE);
	setGameStartAlpha(0);
	setGameLoadAlpha(0);
	setQuitAlpha(0);
	setPointerX(0);
	setPointerXBool(TRUE);
	setSelectMenuComplete(FALSE);
	setMenuSelect(FALSE);
	setCurrentMenu(MENU_NULL);
	setCurrentMenuValue(0);
	setSelectMenuValue(0);

	// �ʱ�ȭ ����
	return S_OK;
}

// ���� (release)
void menuScene::release()
{
}

// ������Ʈ (update)
void menuScene::update()
{
	// BGM ���
	if (!SOUNDMANAGER->isPlaySound("Main"))
	{
		SOUNDMANAGER->play("Main");
	}

	// �޴��� ����
	switch (getCurrentMenuValue())
	{
	case 1:
		setCurrentMenu(MENU_GAMESTART);
		break;
	case 2:
		setCurrentMenu(MENU_GAMELOAD);
		break;
	case 3:
		setCurrentMenu(MENU_QUIT);
		break;
	default:
		setCurrentMenu(MENU_NULL);
		break;
	}

	// �޴� ����
	if (getMenuSelect() == TRUE)
	{
		// �� ��� ������ X�� ��ȭ
		if (getPointerXBool() == TRUE)
		{
			setPointerX(getPointerX() + 1);

			if (getPointerX() >= 30)
			{
				setPointerXBool(FALSE);
			}
		}
		else
		{
			setPointerX(getPointerX() - 1);

			if (getPointerX() <= 0)
			{
				setPointerXBool(TRUE);
			}
		}

		// ����Ű�� �޴� ����
		if (INPUT->getKeyDown(VK_UP))
		{
			SOUNDMANAGER->play("Walk");
			if (getCurrentMenuValue() == 1)
			{
				setCurrentMenuValue(3);
			}
			else
			{
				setCurrentMenuValue(getCurrentMenuValue() - 1);
			}
		}
		else if (INPUT->getKeyDown(VK_DOWN))
		{
			SOUNDMANAGER->play("Walk");
			if (getCurrentMenuValue() == 3)
			{
				setCurrentMenuValue(1);
			}
			else
			{
				setCurrentMenuValue(getCurrentMenuValue() + 1);
			}
		}
		setSelectMenuValue(getCurrentMenuValue());

		// �޴� ����
		if (INPUT->getKeyDown(VK_RETURN) || INPUT->getKeyDown(0x5A))
		{
			SOUNDMANAGER->play("Create");
			SOUNDMANAGER->play("Entry");
			setMenuSelect(FALSE);
			setSelectMenuComplete(TRUE);
		}
	}

	// �޴� ���� �� �� ��ȯ
	if (getSelectMenuComplete() == TRUE && (getBackgroundAlpha() <= 0 && getTitleAlpha() <= 0 && getSymbolAlpha() <= 0))
	{
		// BGM ����
		SOUNDMANAGER->stop("Main");

		int num = INIDATA->loadDataInteger("Save", "StageInfo", "Player_CurrentStage");
		switch (getCurrentMenu())
		{
		case MENU_GAMESTART:
			// INI ���� ���̺�
			INIDATA->addData("StageInfo", "Player_CurrentStage", "1");
			INIDATA->saveINI("Save");

			SCENEMANAGER->loadScene("stage1Scene");
			break;
		case MENU_GAMELOAD:
			switch (num)
			{
			case 1:
				SCENEMANAGER->loadScene("stage1Scene");
				break;
			case 2:
				SCENEMANAGER->loadScene("stage2Scene");
				break;
			case 3:
				SCENEMANAGER->loadScene("stage3Scene");
				break;
			case 4:
				SCENEMANAGER->loadScene("stage4Scene");
				break;
			case 5:
				SCENEMANAGER->loadScene("stage5Scene");
				break;
			case 6:
				SCENEMANAGER->loadScene("stage6Scene");
				break;
			case 7:
				SCENEMANAGER->loadScene("stage7Scene");
				break;
			case 8:
				SCENEMANAGER->loadScene("stage8Scene");
				break;
			case 9:
				SCENEMANAGER->loadScene("stage9Scene");
				break;
			case 10:
				SCENEMANAGER->loadScene("stage10Scene");
				break;
			}
			break;
		case MENU_QUIT:
			// ESC�� ���� ���·� �ν��ϰ� ���� ���� �����Ű��
			keybd_event(0x1B, 0, 0, 0);
			break;
		}
	}
}

// ���� (render)
void menuScene::render()
{
	// ��׶��� �̹��� ���
	getBackground()->alphaRender(getMemDC(), 0, 0, getBackgroundAlpha());

	// Ÿ��Ʋ �̹��� ���
	getTitle()->alphaRender(getMemDC(), 50, 50, getTitleAlpha());

	// �ɺ� �̹��� ���
	getSymbol()->alphaRender(getMemDC(), -700, -700, getSymbolAlpha());

	// ��׶��� �̹��� ���İ�
	if (getBackgroundAlphaBool() == TRUE)
	{
		setBackgroundAlpha(getBackgroundAlpha() + 1);
		
		if (getBackgroundAlpha() >= 255)
		{
			setBackgroundAlpha(255);
		}
	}
	else
	{
		setBackgroundAlpha(getBackgroundAlpha() - 1);

		if (getBackgroundAlpha() <= 0)
		{
			setBackgroundAlpha(0);
		}
	}

	// Ÿ��Ʋ �̹��� ���İ�
	if (getTitleAlphaBool() == TRUE)
	{
		setTitleAlpha(getTitleAlpha() + 1);

		if (getTitleAlpha() >= 255)
		{
			setTitleAlpha(255);
		}
	}
	else
	{
		setTitleAlpha(getTitleAlpha() - 1);

		if (getTitleAlpha() <= 0)
		{
			setTitleAlpha(0);
		}
	}

	// �ɺ� �̹��� ���İ�
	if (getSymbolAlphaBool() == TRUE)
	{
		setSymbolAlpha(getSymbolAlpha() + 1);

		if (getSymbolAlpha() >= 255)
		{
			setSymbolAlpha(255);
		}
	}
	else
	{
		setSymbolAlpha(getSymbolAlpha() - 1);

		if (getSymbolAlpha() <= 0)
		{
			setSymbolAlpha(0);
		}
	}

	// ��׶��� �̹��� ���İ� ���� ��ȯ
	if (getBackgroundAlphaBoolOnce() == TRUE)
	{
		setBackgroundAlpha(getBackgroundAlpha() + 2);
		
		if (getBackgroundAlpha() >= 180)
		{
			setBackgroundAlphaBoolOnce(FALSE);
			setBackgroundAlphaBool(TRUE);
			setTitleAlphaBool(TRUE);
			setSymbolAlphaBool(TRUE);
			setMenuSelect(TRUE);
			setCurrentMenuValue(1);
		}
	}
	else
	{
		if (getMenuSelect() == TRUE)
		{
			if (getBackgroundAlpha() >= 180)
			{
				setBackgroundAlphaBool(FALSE);
			}
			else if (getBackgroundAlpha() <= 90)
			{
				setBackgroundAlphaBool(TRUE);
			}
		}
		else
		{
			setBackgroundAlphaBool(FALSE);
		}
	}

	// ��� �̹���
	if (getMenuSelect() == TRUE)
	{
		// Ÿ��Ʋ �̹��� ���İ� ���� ��ȯ
		if (getTitleAlpha() >= 200)
		{
			setTitleAlphaBool(FALSE);
		}
		else if (getTitleAlpha() <= 160)
		{
			setTitleAlphaBool(TRUE);
		}

		// �ɺ� �̹��� ���İ� ���� ��ȯ
		if (getSymbolAlpha() >= 40)
		{
			setSymbolAlphaBool(FALSE);
		}
		else if (getSymbolAlpha() <= 20)
		{
			setSymbolAlphaBool(TRUE);
		}
	}
	else
	{
		setTitleAlphaBool(FALSE);
		setSymbolAlphaBool(FALSE);
	}

	// ���� �޴� �̹��� ���İ�
	if (getMenuSelect() == TRUE)
	{
		setGameStartAlpha(getGameStartAlpha() + 5);
		setGameLoadAlpha(getGameLoadAlpha() + 5);
		setQuitAlpha(getQuitAlpha() + 5);

		if (getGameStartAlpha() >= 255)
		{
			setGameStartAlpha(255);
		}
		if (getGameLoadAlpha() >= 255)
		{
			setGameLoadAlpha(255);
		}
		if (getQuitAlpha() >= 255)
		{
			setQuitAlpha(255);
		}

		// ���� �޴� �޼��� �̹��� ���
		if (getGameStartAlpha() >= 255 && getCurrentMenu() == MENU_GAMESTART)
		{
			getGameStartMessage()->render(getMemDC(), 440, 860);
		}
		else if (getGameLoadAlpha() >= 255 && getCurrentMenu() == MENU_GAMELOAD)
		{
			getGameLoadMessage()->render(getMemDC(), 290, 860);
		}
		else if (getQuitAlpha() >= 255 && getCurrentMenu() == MENU_QUIT)
		{
			getQuitMessage()->render(getMemDC(), 440, 860);
		}

		// �� ��� ������ �̹��� ���
		switch (getCurrentMenu())
		{
		case MENU_GAMESTART:
			getPointer()->render(getMemDC(), 770 - pointerX, 630);
			break;
		case MENU_GAMELOAD:
			getPointer()->render(getMemDC(), 795 - pointerX, 710);
			break;
		case MENU_QUIT:
			getPointer()->render(getMemDC(), 820 - pointerX, 790);
			break;
		}
	}
	else
	{
		setGameStartAlpha(getGameStartAlpha() - 5);
		setGameLoadAlpha(getGameLoadAlpha() - 5);
		setQuitAlpha(getQuitAlpha() - 5);

		if (getGameStartAlpha() <= 0)
		{
			setGameStartAlpha(0);
		}
		if (getGameLoadAlpha() <= 0)
		{
			setGameLoadAlpha(0);
		}
		if (getQuitAlpha() <= 0)
		{
			setQuitAlpha(0);
		}
	}
	getGameStart()->alphaRender(getMemDC(), 890, 640, getGameStartAlpha());
	getGameLoad()->alphaRender(getMemDC(), 915, 720, getGameLoadAlpha());
	getQuit()->alphaRender(getMemDC(), 940, 800, getQuitAlpha());
}