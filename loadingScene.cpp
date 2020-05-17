#include "stdafx.h"
#include "loadingScene.h"

// 초기화 (init)
HRESULT loadingScene::init()
{
	// loading 클래스 초기화
	setLoading(new loading);
	getLoading()->init();

	// 로딩 중 이미지 찾기
	setLoadingImage(IMAGEMANAGER->addImage("Loading_Message", "Images/Loading/Loading_Message.bmp", 0, 0, 400, 200, TRUE, RGB(255, 0, 255)));

	// 기타 변수 초기화
	setLoadingStart(TRUE);
	setLoadingAlpha(0);
	setLoadingAlphaBool(TRUE);
	setLoadingEnd(FALSE);
	setLoadingOutput(TRUE);

	// 이미지 로딩 초기화
	this->loadImage();

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void loadingScene::release()
{
	// loading 클래스 해제
	getLoading()->release();
	SAFE_DELETE(_loading);
}

// 업데이트 (update)
void loadingScene::update()
{
	// loading 클래스 업데이트
	getLoading()->update();

	// 로딩 완료 후 화면 변경
	if (getLoading()->loadingDone() == TRUE)
	{
		// 로딩 중 화면 투명화
		setLoadingStart(FALSE);
		setLoadingEnd(TRUE);
		setLoadingAlphaBool(FALSE);
	}
	if (getLoadingEnd() == TRUE && getLoadingAlpha() <= 0)
	{
		setLoadingOutput(FALSE);
		SCENEMANAGER->loadScene("menuScene");
	}
}

// 렌더 (render)
void loadingScene::render()
{
	// 인트로 이미지 렌더
	if (getLoadingOutput() == TRUE)
	{
		// 화면 깜빡이는 연출
		if (getLoadingAlphaBool() == TRUE)
		{
			setLoadingAlpha(getLoadingAlpha() + 5);
		}
		else
		{
			if (getLoadingEnd() == TRUE)
			{
				setLoadingAlpha(getLoadingAlpha() - 1);
			}
			else
			{
				setLoadingAlpha(getLoadingAlpha() - 5);
			}
		}

		// 알파값 제한
		if (getLoadingAlpha() >= 150)
		{
			setLoadingAlpha(150);
			if (getLoadingStart() == TRUE)
			{
				setLoadingAlphaBool(FALSE);
			}
		}
		else if (getLoadingAlpha() <= 0)
		{
			setLoadingAlpha(0);
			if (getLoadingStart() == TRUE)
			{
				setLoadingAlphaBool(TRUE);
			}
		}

		// 인트로 이미지 출력
		getLoadingImage()->alphaRender(getMemDC(), 440, 700, loadingAlpha);
	}

	// loading 클래스 렌더
	if (getLoadingStart() == TRUE && getLoadingEnd() == FALSE)
	{
		getLoading()->render(255);
	}
	else if (getLoadingStart() == FALSE && getLoadingEnd() == TRUE)
	{
		getLoading()->render(getLoadingAlpha());
	}
}

// 이미지 로딩
void loadingScene::loadImage()
{
	// 사운드 관련
	SOUNDMANAGER->addSound("Main", "Sound/Main.mp3");
	SOUNDMANAGER->addSound("BGM1", "Sound/BGM1.mp3");
	SOUNDMANAGER->addSound("BGM2", "Sound/BGM2.mp3");
	SOUNDMANAGER->addSound("BGM3", "Sound/BGM3.mp3");
	SOUNDMANAGER->addSound("Result", "Sound/Result.mp3");
	SOUNDMANAGER->addSound("Walk", "Sound/Walk.mp3");
	SOUNDMANAGER->addSound("Jump1", "Sound/Jump1.mp3");
	SOUNDMANAGER->addSound("Jump2", "Sound/Jump2.mp3");
	SOUNDMANAGER->addSound("Create", "Sound/Create.mp3");
	SOUNDMANAGER->addSound("Switch", "Sound/Switch.mp3");
	SOUNDMANAGER->addSound("Break", "Sound/Break.mp3");
	SOUNDMANAGER->addSound("Open", "Sound/Open.mp3");
	SOUNDMANAGER->addSound("Entry", "Sound/Entry.mp3");
	SOUNDMANAGER->addSound("Rewind", "Sound/Rewind.mp3");

	// 맵 관련
	getLoading()->loadImage("Map_Stage1", "Images/Map/Stage1.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage2", "Images/Map/Stage2.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage3", "Images/Map/Stage3.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage4", "Images/Map/Stage4.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage5", "Images/Map/Stage5.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage6", "Images/Map/Stage6.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage7", "Images/Map/Stage7.bmp", 0, 0, 2560, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage8", "Images/Map/Stage8.bmp", 0, 0, 3840, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage9", "Images/Map/Stage9.bmp", 0, 0, 3840, 1920, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Map_Stage10", "Images/Map/Stage10.bmp", 0, 0, 3840, 1920, TRUE, RGB(255, 0, 255));

	// 오브젝트, 시스템 관련
	getLoading()->loadFrameImage("Player_Idle", "Images/Player/Player_Idle.bmp", 0, 0, 120, 128, 3, 2, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Run", "Images/Player/Player_Run.bmp", 0, 0, 400, 128, 10, 2, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_JumpFall", "Images/Player/Player_JumpFall.bmp", 0, 0, 80, 128, 2, 2, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Dead", "Images/Player/Player_Dead.bmp", 0, 0, 128, 40, 2, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone1", "Images/Player/Player_Clone.bmp", 0, 0, 160, 64, 4, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone2", "Images/Player/Player_Clone.bmp", 0, 0, 160, 64, 4, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone3", "Images/Player/Player_Clone.bmp", 0, 0, 160, 64, 4, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone_Timer1", "Images/Player/Player_Clone_Timer.bmp", 0, 0, 760, 76, 10, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone_Timer2", "Images/Player/Player_Clone_Timer.bmp", 0, 0, 760, 76, 10, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Player_Clone_Timer3", "Images/Player/Player_Clone_Timer.bmp", 0, 0, 760, 76, 10, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Object_Obstacle", "Images/Object/Obstacle.bmp", 0, 0, 64, 64, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Object_Switch", "Images/Object/Switch.bmp", 0, 0, 128, 320, 2, 5, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Object_SwitchTile", "Images/Object/SwitchTile.bmp", 0, 0, 128, 256, 2, 4, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Object_MessageObject", "Images/Object/MessageObject.bmp", 0, 0, 2304, 128, 18, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Object_AutoGate", "Images/Object/AutoGate.bmp", 0, 0, 128, 128, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Object_CloseGate", "Images/Object/CloseGate.bmp", 0, 0, 768, 128, 6, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Object_Ledge", "Images/Object/Ledge.bmp", 0, 0, 192, 24, 1, 3, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_MessageBox", "Images/System/MessageBox.bmp", 0, 0, 1280, 300, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("System_ResetMessage", "Images/System/ResetMessage.bmp", 0, 0, 768, 128, 3, 1, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage1", "Images/System/SystemMessage1.bmp", 0, 0, 880, 75, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage2", "Images/System/SystemMessage2.bmp", 0, 0, 725, 75, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage3", "Images/System/SystemMessage3.bmp", 0, 0, 1280, 130, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage4", "Images/System/SystemMessage4.bmp", 0, 0, 1280, 300, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage5", "Images/System/SystemMessage5.bmp", 0, 0, 1280, 180, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage6", "Images/System/SystemMessage6.bmp", 0, 0, 840, 75, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage7", "Images/System/SystemMessage7.bmp", 0, 0, 1280, 125, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("System_SystemMessage8", "Images/System/SystemMessage8.bmp", 0, 0, 840, 75, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_Background", "Images/Menu/Menu_Background.bmp", 1280, 960);
	getLoading()->loadImage("Menu_Title", "Images/Menu/Menu_Title.bmp", 0, 0, 500, 250, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_Symbol", "Images/Menu/Menu_Symbol.bmp", 0, 0, 1600, 1600, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_GameStart", "Images/Menu/Menu_GameStart.bmp", 0, 0, 200, 60, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_GameLoad", "Images/Menu/Menu_GameLoad.bmp", 0, 0, 200, 60, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_Quit", "Images/Menu/Menu_Quit.bmp", 0, 0, 70, 60, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_GameStartMessage", "Images/Menu/Menu_GameStartMessage.bmp", 0, 0, 400, 100, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_GameLoadMessage", "Images/Menu/Menu_GameLoadMessage.bmp", 0, 0, 800, 100, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_QuitMessage", "Images/Menu/Menu_QuitMessage.bmp", 0, 0, 400, 100, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Menu_Pointer", "Images/Menu/Menu_Pointer.bmp", 0, 0, 100, 80, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Result_Background", "Images/Result/Result_Background.bmp", 1280, 960);
	getLoading()->loadImage("Result_Message", "Images/Result/Result_Message.bmp", 0, 0, 900, 100, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Result_Stage", "Images/Result/Result_Stage.bmp", 0, 0, 220, 700, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Result_ClearTime", "Images/Result/Result_ClearTime.bmp", 0, 0, 200, 56, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Result_StageScore", "Images/Result/Result_StageScore.bmp", 0, 0, 240, 56, TRUE, RGB(255, 0, 255));
	getLoading()->loadImage("Result_TotalScore", "Images/Result/Result_TotalScore.bmp", 0, 0, 240, 56, TRUE, RGB(255, 0, 255));
	getLoading()->loadFrameImage("Result_Number", "Images/Result/Result_Number.bmp", 0, 0, 400, 50, 10, 1, TRUE, RGB(255, 0, 255));
}