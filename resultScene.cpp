#include "stdafx.h"
#include "resultScene.h"

// 초기화 (init)
HRESULT resultScene::init()
{
	// 백그라운드 이미지 찾기
	setBackground(IMAGEMANAGER->findImage("Result_Background"));

	// 숫자 이미지 찾기
	setNumber(IMAGEMANAGER->findImage("Result_Number"));

	// 스테이지 텍스트 이미지 찾기
	setStage(IMAGEMANAGER->findImage("Result_Stage"));

	// 구조체 초기화
	ZeroMemory(&stage1Time, sizeof(stage1Time));
	ZeroMemory(&stage1Score, sizeof(stage1Score));
	ZeroMemory(&stage2Time, sizeof(stage2Time));
	ZeroMemory(&stage2Score, sizeof(stage2Score));
	ZeroMemory(&stage3Time, sizeof(stage3Time));
	ZeroMemory(&stage3Score, sizeof(stage3Score));
	ZeroMemory(&stage4Time, sizeof(stage4Time));
	ZeroMemory(&stage4Score, sizeof(stage4Score));
	ZeroMemory(&stage5Time, sizeof(stage5Time));
	ZeroMemory(&stage5Score, sizeof(stage5Score));
	ZeroMemory(&stage6Time, sizeof(stage6Time));
	ZeroMemory(&stage6Score, sizeof(stage6Score));
	ZeroMemory(&stage7Time, sizeof(stage7Time));
	ZeroMemory(&stage7Score, sizeof(stage7Score));
	ZeroMemory(&stage8Time, sizeof(stage8Time));
	ZeroMemory(&stage8Score, sizeof(stage8Score));
	ZeroMemory(&stage9Time, sizeof(stage9Time));
	ZeroMemory(&stage9Score, sizeof(stage9Score));
	ZeroMemory(&stage10Time, sizeof(stage10Time));
	ZeroMemory(&stage10Score, sizeof(stage10Score));
	ZeroMemory(&stageTotalScore, sizeof(stageTotalScore));

	// 스테이지 클리어 소요 시간 및 점수 계산
	// 스테이지 1
	stage1Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage1_TimeElapsed");
	if (stage1Time.elapsedTime <= 3)
	{
		stage1Score.score = 1000;
	}
	else if (stage1Time.elapsedTime == 4)
	{
		stage1Score.score = 900;
	}
	else if (stage1Time.elapsedTime == 5)
	{
		stage1Score.score = 800;
	}
	else if (stage1Time.elapsedTime == 6)
	{
		stage1Score.score = 700;
	}
	else if (stage1Time.elapsedTime == 7)
	{
		stage1Score.score = 600;
	}
	else if (stage1Time.elapsedTime == 8)
	{
		stage1Score.score = 500;
	}
	else if (stage1Time.elapsedTime == 9)
	{
		stage1Score.score = 400;
	}
	else if (stage1Time.elapsedTime == 10)
	{
		stage1Score.score = 300;
	}
	else if (stage1Time.elapsedTime > 10 && stage1Time.elapsedTime <= 12)
	{
		stage1Score.score = 200;
	}
	else if (stage1Time.elapsedTime > 12)
	{
		stage1Score.score = 100;
	}
	stage1Time.elapsedTimeNumber[0] = stage1Time.elapsedTime % 10;
	stage1Time.elapsedTimeNumber[1] = ((stage1Time.elapsedTime % 100) - stage1Time.elapsedTimeNumber[0]) / 10;
	stage1Time.elapsedTimeNumber[2] = ((stage1Time.elapsedTime % 1000) - stage1Time.elapsedTimeNumber[1]) / 100;
	stage1Time.elapsedTimeNumber[3] = ((stage1Time.elapsedTime % 10000) - stage1Time.elapsedTimeNumber[2]) / 1000;
	stage1Score.scoreNumber[0] = stage1Score.score % 10;
	stage1Score.scoreNumber[1] = ((stage1Score.score % 100) - stage1Score.scoreNumber[0]) / 10;
	stage1Score.scoreNumber[2] = ((stage1Score.score % 1000) - stage1Score.scoreNumber[1]) / 100;
	stage1Score.scoreNumber[3] = ((stage1Score.score % 10000) - stage1Score.scoreNumber[2]) / 1000;
	// 스테이지 2
	stage2Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage2_TimeElapsed");
	if (stage2Time.elapsedTime <= 4)
	{
		stage2Score.score = 1000;
	}
	else if (stage2Time.elapsedTime == 5)
	{
		stage2Score.score = 900;
	}
	else if (stage2Time.elapsedTime == 6)
	{
		stage2Score.score = 800;
	}
	else if (stage2Time.elapsedTime == 7)
	{
		stage2Score.score = 700;
	}
	else if (stage2Time.elapsedTime == 8)
	{
		stage2Score.score = 600;
	}
	else if (stage2Time.elapsedTime == 9)
	{
		stage2Score.score = 500;
	}
	else if (stage2Time.elapsedTime == 10)
	{
		stage2Score.score = 400;
	}
	else if (stage2Time.elapsedTime > 10 && stage2Time.elapsedTime <= 12)
	{
		stage2Score.score = 300;
	}
	else if (stage2Time.elapsedTime > 12 && stage2Time.elapsedTime <= 15)
	{
		stage2Score.score = 200;
	}
	else if (stage2Time.elapsedTime > 15)
	{
		stage2Score.score = 100;
	}
	stage2Time.elapsedTimeNumber[0] = stage2Time.elapsedTime % 10;
	stage2Time.elapsedTimeNumber[1] = ((stage2Time.elapsedTime % 100) - stage2Time.elapsedTimeNumber[0]) / 10;
	stage2Time.elapsedTimeNumber[2] = ((stage2Time.elapsedTime % 1000) - stage2Time.elapsedTimeNumber[1]) / 100;
	stage2Time.elapsedTimeNumber[3] = ((stage2Time.elapsedTime % 10000) - stage2Time.elapsedTimeNumber[2]) / 1000;
	stage2Score.scoreNumber[0] = stage2Score.score % 10;
	stage2Score.scoreNumber[1] = ((stage2Score.score % 100) - stage2Score.scoreNumber[0]) / 10;
	stage2Score.scoreNumber[2] = ((stage2Score.score % 1000) - stage2Score.scoreNumber[1]) / 100;
	stage2Score.scoreNumber[3] = ((stage2Score.score % 10000) - stage2Score.scoreNumber[2]) / 1000;
	// 스테이지 3
	stage3Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage3_TimeElapsed");
	if (stage3Time.elapsedTime <= 5)
	{
		stage3Score.score = 1000;
	}
	else if (stage3Time.elapsedTime == 6)
	{
		stage3Score.score = 900;
	}
	else if (stage3Time.elapsedTime == 7)
	{
		stage3Score.score = 800;
	}
	else if (stage3Time.elapsedTime == 8)
	{
		stage3Score.score = 700;
	}
	else if (stage3Time.elapsedTime == 9)
	{
		stage3Score.score = 600;
	}
	else if (stage3Time.elapsedTime == 10)
	{
		stage3Score.score = 500;
	}
	else if (stage3Time.elapsedTime > 10 && stage3Time.elapsedTime <= 12)
	{
		stage3Score.score = 400;
	}
	else if (stage3Time.elapsedTime > 12 && stage3Time.elapsedTime <= 15)
	{
		stage3Score.score = 300;
	}
	else if (stage3Time.elapsedTime > 15 && stage3Time.elapsedTime <= 20)
	{
		stage3Score.score = 200;
	}
	else if (stage3Time.elapsedTime > 20)
	{
		stage3Score.score = 100;
	}
	stage3Time.elapsedTimeNumber[0] = stage3Time.elapsedTime % 10;
	stage3Time.elapsedTimeNumber[1] = ((stage3Time.elapsedTime % 100) - stage3Time.elapsedTimeNumber[0]) / 10;
	stage3Time.elapsedTimeNumber[2] = ((stage3Time.elapsedTime % 1000) - stage3Time.elapsedTimeNumber[1]) / 100;
	stage3Time.elapsedTimeNumber[3] = ((stage3Time.elapsedTime % 10000) - stage3Time.elapsedTimeNumber[2]) / 1000;
	stage3Score.scoreNumber[0] = stage3Score.score % 10;
	stage3Score.scoreNumber[1] = ((stage3Score.score % 100) - stage3Score.scoreNumber[0]) / 10;
	stage3Score.scoreNumber[2] = ((stage3Score.score % 1000) - stage3Score.scoreNumber[1]) / 100;
	stage3Score.scoreNumber[3] = ((stage3Score.score % 10000) - stage3Score.scoreNumber[2]) / 1000;
	// 스테이지 4
	stage4Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage4_TimeElapsed");
	if (stage4Time.elapsedTime <= 10)
	{
		stage4Score.score = 1000;
	}
	else if (stage4Time.elapsedTime == 11)
	{
		stage4Score.score = 900;
	}
	else if (stage4Time.elapsedTime == 12)
	{
		stage4Score.score = 800;
	}
	else if (stage4Time.elapsedTime == 13)
	{
		stage4Score.score = 700;
	}
	else if (stage4Time.elapsedTime == 14)
	{
		stage4Score.score = 600;
	}
	else if (stage4Time.elapsedTime == 15)
	{
		stage4Score.score = 500;
	}
	else if (stage4Time.elapsedTime == 16)
	{
		stage4Score.score = 400;
	}
	else if (stage4Time.elapsedTime > 16 && stage4Time.elapsedTime <= 18)
	{
		stage4Score.score = 300;
	}
	else if (stage4Time.elapsedTime > 18 && stage4Time.elapsedTime <= 20)
	{
		stage4Score.score = 200;
	}
	else if (stage4Time.elapsedTime > 20)
	{
		stage4Score.score = 100;
	}
	stage4Time.elapsedTimeNumber[0] = stage4Time.elapsedTime % 10;
	stage4Time.elapsedTimeNumber[1] = ((stage4Time.elapsedTime % 100) - stage4Time.elapsedTimeNumber[0]) / 10;
	stage4Time.elapsedTimeNumber[2] = ((stage4Time.elapsedTime % 1000) - stage4Time.elapsedTimeNumber[1]) / 100;
	stage4Time.elapsedTimeNumber[3] = ((stage4Time.elapsedTime % 10000) - stage4Time.elapsedTimeNumber[2]) / 1000;
	stage4Score.scoreNumber[0] = stage4Score.score % 10;
	stage4Score.scoreNumber[1] = ((stage4Score.score % 100) - stage4Score.scoreNumber[0]) / 10;
	stage4Score.scoreNumber[2] = ((stage4Score.score % 1000) - stage4Score.scoreNumber[1]) / 100;
	stage4Score.scoreNumber[3] = ((stage4Score.score % 10000) - stage4Score.scoreNumber[2]) / 1000;
	// 스테이지 5
	stage5Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage5_TimeElapsed");
	if (stage5Time.elapsedTime <= 12)
	{
		stage5Score.score = 1000;
	}
	else if (stage5Time.elapsedTime == 13)
	{
		stage5Score.score = 900;
	}
	else if (stage5Time.elapsedTime == 14)
	{
		stage5Score.score = 800;
	}
	else if (stage5Time.elapsedTime == 15)
	{
		stage5Score.score = 700;
	}
	else if (stage5Time.elapsedTime == 16)
	{
		stage5Score.score = 600;
	}
	else if (stage5Time.elapsedTime == 17)
	{
		stage5Score.score = 500;
	}
	else if (stage5Time.elapsedTime ==18)
	{
		stage5Score.score = 400;
	}
	else if (stage5Time.elapsedTime == 19)
	{
		stage5Score.score = 300;
	}
	else if (stage5Time.elapsedTime == 20)
	{
		stage5Score.score = 200;
	}
	else if (stage5Time.elapsedTime > 20)
	{
		stage5Score.score = 100;
	}
	stage5Time.elapsedTimeNumber[0] = stage5Time.elapsedTime % 10;
	stage5Time.elapsedTimeNumber[1] = ((stage5Time.elapsedTime % 100) - stage5Time.elapsedTimeNumber[0]) / 10;
	stage5Time.elapsedTimeNumber[2] = ((stage5Time.elapsedTime % 1000) - stage5Time.elapsedTimeNumber[1]) / 100;
	stage5Time.elapsedTimeNumber[3] = ((stage5Time.elapsedTime % 10000) - stage5Time.elapsedTimeNumber[2]) / 1000;
	stage5Score.scoreNumber[0] = stage5Score.score % 10;
	stage5Score.scoreNumber[1] = ((stage5Score.score % 100) - stage5Score.scoreNumber[0]) / 10;
	stage5Score.scoreNumber[2] = ((stage5Score.score % 1000) - stage5Score.scoreNumber[1]) / 100;
	stage5Score.scoreNumber[3] = ((stage5Score.score % 10000) - stage5Score.scoreNumber[2]) / 1000;
	// 스테이지 6
	stage6Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage6_TimeElapsed");
	if (stage6Time.elapsedTime <= 12)
	{
		stage6Score.score = 1000;
	}
	else if (stage6Time.elapsedTime > 12 && stage6Time.elapsedTime <= 14)
	{
		stage6Score.score = 900;
	}
	else if (stage6Time.elapsedTime > 14 && stage6Time.elapsedTime <= 16)
	{
		stage6Score.score = 800;
	}
	else if (stage6Time.elapsedTime > 16 && stage6Time.elapsedTime <= 18)
	{
		stage6Score.score = 700;
	}
	else if (stage6Time.elapsedTime > 18 && stage6Time.elapsedTime <= 20)
	{
		stage6Score.score = 600;
	}
	else if (stage6Time.elapsedTime > 20 && stage6Time.elapsedTime <= 22)
	{
		stage6Score.score = 500;
	}
	else if (stage6Time.elapsedTime > 22 && stage6Time.elapsedTime <= 24)
	{
		stage6Score.score = 400;
	}
	else if (stage6Time.elapsedTime > 24 && stage6Time.elapsedTime <= 27)
	{
		stage6Score.score = 300;
	}
	else if (stage6Time.elapsedTime > 27 && stage6Time.elapsedTime <= 30)
	{
		stage6Score.score = 200;
	}
	else if (stage6Time.elapsedTime > 30)
	{
		stage6Score.score = 100;
	}
	stage6Time.elapsedTimeNumber[0] = stage6Time.elapsedTime % 10;
	stage6Time.elapsedTimeNumber[1] = ((stage6Time.elapsedTime % 100) - stage6Time.elapsedTimeNumber[0]) / 10;
	stage6Time.elapsedTimeNumber[2] = ((stage6Time.elapsedTime % 1000) - stage6Time.elapsedTimeNumber[1]) / 100;
	stage6Time.elapsedTimeNumber[3] = ((stage6Time.elapsedTime % 10000) - stage6Time.elapsedTimeNumber[2]) / 1000;
	stage6Score.scoreNumber[0] = stage6Score.score % 10;
	stage6Score.scoreNumber[1] = ((stage6Score.score % 100) - stage6Score.scoreNumber[0]) / 10;
	stage6Score.scoreNumber[2] = ((stage6Score.score % 1000) - stage6Score.scoreNumber[1]) / 100;
	stage6Score.scoreNumber[3] = ((stage6Score.score % 10000) - stage6Score.scoreNumber[2]) / 1000;
	// 스테이지 7
	stage7Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage7_TimeElapsed");
	if (stage7Time.elapsedTime <= 20)
	{
		stage7Score.score = 1000;
	}
	else if (stage7Time.elapsedTime > 20 && stage7Time.elapsedTime <= 22)
	{
		stage7Score.score = 900;
	}
	else if (stage7Time.elapsedTime > 22 && stage7Time.elapsedTime <= 24)
	{
		stage7Score.score = 800;
	}
	else if (stage7Time.elapsedTime > 24 && stage7Time.elapsedTime <= 26)
	{
		stage7Score.score = 700;
	}
	else if (stage7Time.elapsedTime > 26 && stage7Time.elapsedTime <= 28)
	{
		stage7Score.score = 600;
	}
	else if (stage7Time.elapsedTime > 28 && stage7Time.elapsedTime <= 30)
	{
		stage7Score.score = 500;
	}
	else if (stage7Time.elapsedTime > 30 && stage7Time.elapsedTime <= 35)
	{
		stage7Score.score = 400;
	}
	else if (stage7Time.elapsedTime > 35 && stage7Time.elapsedTime <= 40)
	{
		stage7Score.score = 300;
	}
	else if (stage7Time.elapsedTime > 40 && stage7Time.elapsedTime <= 45)
	{
		stage7Score.score = 200;
	}
	else if (stage7Time.elapsedTime > 45)
	{
		stage7Score.score = 100;
	}
	stage7Time.elapsedTimeNumber[0] = stage7Time.elapsedTime % 10;
	stage7Time.elapsedTimeNumber[1] = ((stage7Time.elapsedTime % 100) - stage7Time.elapsedTimeNumber[0]) / 10;
	stage7Time.elapsedTimeNumber[2] = ((stage7Time.elapsedTime % 1000) - stage7Time.elapsedTimeNumber[1]) / 100;
	stage7Time.elapsedTimeNumber[3] = ((stage7Time.elapsedTime % 10000) - stage7Time.elapsedTimeNumber[2]) / 1000;
	stage7Score.scoreNumber[0] = stage7Score.score % 10;
	stage7Score.scoreNumber[1] = ((stage7Score.score % 100) - stage7Score.scoreNumber[0]) / 10;
	stage7Score.scoreNumber[2] = ((stage7Score.score % 1000) - stage7Score.scoreNumber[1]) / 100;
	stage7Score.scoreNumber[3] = ((stage7Score.score % 10000) - stage7Score.scoreNumber[2]) / 1000;
	// 스테이지 8
	stage8Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage8_TimeElapsed");
	if (stage8Time.elapsedTime <= 25)
	{
		stage8Score.score = 1000;
	}
	else if (stage8Time.elapsedTime > 25 && stage8Time.elapsedTime <= 30)
	{
		stage8Score.score = 900;
	}
	else if (stage8Time.elapsedTime > 30 && stage8Time.elapsedTime <= 35)
	{
		stage8Score.score = 800;
	}
	else if (stage8Time.elapsedTime > 35 && stage8Time.elapsedTime <= 40)
	{
		stage8Score.score = 700;
	}
	else if (stage8Time.elapsedTime > 40 && stage8Time.elapsedTime <= 45)
	{
		stage8Score.score = 600;
	}
	else if (stage8Time.elapsedTime > 45 && stage8Time.elapsedTime <= 50)
	{
		stage8Score.score = 500;
	}
	else if (stage8Time.elapsedTime > 50 && stage8Time.elapsedTime <= 55)
	{
		stage8Score.score = 400;
	}
	else if (stage8Time.elapsedTime > 55 && stage8Time.elapsedTime <= 60)
	{
		stage8Score.score = 300;
	}
	else if (stage8Time.elapsedTime > 60 && stage8Time.elapsedTime <= 70)
	{
		stage8Score.score = 200;
	}
	else if (stage8Time.elapsedTime > 70)
	{
		stage8Score.score = 100;
	}
	stage8Time.elapsedTimeNumber[0] = stage8Time.elapsedTime % 10;
	stage8Time.elapsedTimeNumber[1] = ((stage8Time.elapsedTime % 100) - stage8Time.elapsedTimeNumber[0]) / 10;
	stage8Time.elapsedTimeNumber[2] = ((stage8Time.elapsedTime % 1000) - stage8Time.elapsedTimeNumber[1]) / 100;
	stage8Time.elapsedTimeNumber[3] = ((stage8Time.elapsedTime % 10000) - stage8Time.elapsedTimeNumber[2]) / 1000;
	stage8Score.scoreNumber[0] = stage8Score.score % 10;
	stage8Score.scoreNumber[1] = ((stage8Score.score % 100) - stage8Score.scoreNumber[0]) / 10;
	stage8Score.scoreNumber[2] = ((stage8Score.score % 1000) - stage8Score.scoreNumber[1]) / 100;
	stage8Score.scoreNumber[3] = ((stage8Score.score % 10000) - stage8Score.scoreNumber[2]) / 1000;
	// 스테이지 9
	stage9Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage9_TimeElapsed");
	if (stage9Time.elapsedTime <= 40)
	{
		stage9Score.score = 1000;
	}
	else if (stage9Time.elapsedTime > 40 && stage9Time.elapsedTime <= 50)
	{
		stage9Score.score = 900;
	}
	else if (stage9Time.elapsedTime > 50 && stage9Time.elapsedTime <= 60)
	{
		stage9Score.score = 800;
	}
	else if (stage9Time.elapsedTime > 60 && stage9Time.elapsedTime <= 70)
	{
		stage9Score.score = 700;
	}
	else if (stage9Time.elapsedTime > 70 && stage9Time.elapsedTime <= 80)
	{
		stage9Score.score = 600;
	}
	else if (stage9Time.elapsedTime > 80 && stage9Time.elapsedTime <= 90)
	{
		stage9Score.score = 500;
	}
	else if (stage9Time.elapsedTime > 90 && stage9Time.elapsedTime <= 100)
	{
		stage9Score.score = 400;
	}
	else if (stage9Time.elapsedTime > 100 && stage9Time.elapsedTime <= 110)
	{
		stage9Score.score = 300;
	}
	else if (stage9Time.elapsedTime > 110 && stage9Time.elapsedTime <= 120)
	{
		stage9Score.score = 200;
	}
	else if (stage9Time.elapsedTime > 120)
	{
		stage9Score.score = 100;
	}
	stage9Time.elapsedTimeNumber[0] = stage9Time.elapsedTime % 10;
	stage9Time.elapsedTimeNumber[1] = ((stage9Time.elapsedTime % 100) - stage9Time.elapsedTimeNumber[0]) / 10;
	stage9Time.elapsedTimeNumber[2] = ((stage9Time.elapsedTime % 1000) - stage9Time.elapsedTimeNumber[1]) / 100;
	stage9Time.elapsedTimeNumber[3] = ((stage9Time.elapsedTime % 10000) - stage9Time.elapsedTimeNumber[2]) / 1000;
	stage9Score.scoreNumber[0] = stage9Score.score % 10;
	stage9Score.scoreNumber[1] = ((stage9Score.score % 100) - stage9Score.scoreNumber[0]) / 10;
	stage9Score.scoreNumber[2] = ((stage9Score.score % 1000) - stage9Score.scoreNumber[1]) / 100;
	stage9Score.scoreNumber[3] = ((stage9Score.score % 10000) - stage9Score.scoreNumber[2]) / 1000;
	// 스테이지 10
	stage10Time.elapsedTime = INIDATA->loadDataInteger("Save", "TimeInfo", "Stage10_TimeElapsed");
	if (stage10Time.elapsedTime <= 60)
	{
		stage10Score.score = 1000;
	}
	else if (stage10Time.elapsedTime > 60 && stage10Time.elapsedTime <= 70)
	{
		stage10Score.score = 900;
	}
	else if (stage10Time.elapsedTime > 70 && stage10Time.elapsedTime <= 80)
	{
		stage10Score.score = 800;
	}
	else if (stage10Time.elapsedTime > 80 && stage10Time.elapsedTime <= 90)
	{
		stage10Score.score = 700;
	}
	else if (stage10Time.elapsedTime > 90 && stage10Time.elapsedTime <= 100)
	{
		stage10Score.score = 600;
	}
	else if (stage10Time.elapsedTime > 100 && stage10Time.elapsedTime <= 110)
	{
		stage10Score.score = 500;
	}
	else if (stage10Time.elapsedTime > 110 && stage10Time.elapsedTime <= 120)
	{
		stage10Score.score = 400;
	}
	else if (stage10Time.elapsedTime > 120 && stage10Time.elapsedTime <= 140)
	{
		stage10Score.score = 300;
	}
	else if (stage10Time.elapsedTime > 140 && stage10Time.elapsedTime <= 160)
	{
		stage10Score.score = 200;
	}
	else if (stage10Time.elapsedTime > 160)
	{
		stage10Score.score = 100;
	}
	stage10Time.elapsedTimeNumber[0] = stage10Time.elapsedTime % 10;
	stage10Time.elapsedTimeNumber[1] = ((stage10Time.elapsedTime % 100) - stage10Time.elapsedTimeNumber[0]) / 10;
	stage10Time.elapsedTimeNumber[2] = ((stage10Time.elapsedTime % 1000) - stage10Time.elapsedTimeNumber[1]) / 100;
	stage10Time.elapsedTimeNumber[3] = ((stage10Time.elapsedTime % 10000) - stage10Time.elapsedTimeNumber[2]) / 1000;
	stage10Score.scoreNumber[0] = stage10Score.score % 10;
	stage10Score.scoreNumber[1] = ((stage10Score.score % 100) - stage10Score.scoreNumber[0]) / 10;
	stage10Score.scoreNumber[2] = ((stage10Score.score % 1000) - stage10Score.scoreNumber[1]) / 100;
	stage10Score.scoreNumber[3] = ((stage10Score.score % 10000) - stage10Score.scoreNumber[2]) / 1000;
	// 점수 총합
	stageTotalScore.score = stage1Score.score + stage2Score.score + stage3Score.score + stage4Score.score + stage5Score.score +
		stage6Score.score + stage7Score.score + stage8Score.score + stage9Score.score + stage10Score.score;
	stageTotalScore.scoreNumber[0] = stageTotalScore.score % 10;
	stageTotalScore.scoreNumber[1] = ((stageTotalScore.score % 100) - stageTotalScore.scoreNumber[0]) / 10;
	stageTotalScore.scoreNumber[2] = ((stageTotalScore.score % 1000) - stageTotalScore.scoreNumber[1]) / 100;
	stageTotalScore.scoreNumber[3] = ((stageTotalScore.score % 10000) - stageTotalScore.scoreNumber[2]) / 1000;
	stageTotalScore.scoreNumber[4] = ((stageTotalScore.score % 100000) - stageTotalScore.scoreNumber[3]) / 10000;

	// 숫자 이미지 찾기
	for (int i = 0; i < 4; i++)
	{
		stage1Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage2Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage3Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage4Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage5Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage6Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage7Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage8Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage9Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage10Time.elapsedTimeNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage1Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage2Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage3Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage4Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage5Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage6Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage7Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage8Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage9Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
		stage10Score.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
	}
	for (int i = 0; i < 5; i++)
	{
		stageTotalScore.scoreNumberImage[i] = IMAGEMANAGER->findImage("Result_Number");
	}

	// INI 데이터 저장
	// 점수 세이브
	int score1 = stage1Score.score;
	string str1_1 = to_string(score1);
	char* str1_2 = new char[str1_1.length() + 1];
	strcpy(str1_2, str1_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage1_Score", str1_2);
	INIDATA->saveINI("Save");
	int score2 = stage2Score.score;
	string str2_1 = to_string(score2);
	char* str2_2 = new char[str2_1.length() + 1];
	strcpy(str2_2, str2_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage2_Score", str2_2);
	INIDATA->saveINI("Save");
	int score3 = stage3Score.score;
	string str3_1 = to_string(score3);
	char* str3_2 = new char[str3_1.length() + 1];
	strcpy(str3_2, str3_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage3_Score", str3_2);
	INIDATA->saveINI("Save");
	int score4 = stage4Score.score;
	string str4_1 = to_string(score4);
	char* str4_2 = new char[str4_1.length() + 1];
	strcpy(str4_2, str4_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage4_Score", str4_2);
	INIDATA->saveINI("Save");
	int score5 = stage5Score.score;
	string str5_1 = to_string(score5);
	char* str5_2 = new char[str5_1.length() + 1];
	strcpy(str5_2, str5_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage5_Score", str5_2);
	INIDATA->saveINI("Save");
	int score6 = stage6Score.score;
	string str6_1 = to_string(score6);
	char* str6_2 = new char[str6_1.length() + 1];
	strcpy(str6_2, str6_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage6_Score", str6_2);
	INIDATA->saveINI("Save");
	int score7 = stage7Score.score;
	string str7_1 = to_string(score7);
	char* str7_2 = new char[str7_1.length() + 1];
	strcpy(str7_2, str7_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage7_Score", str7_2);
	INIDATA->saveINI("Save");
	int score8 = stage8Score.score;
	string str8_1 = to_string(score8);
	char* str8_2 = new char[str8_1.length() + 1];
	strcpy(str8_2, str8_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage8_Score", str8_2);
	INIDATA->saveINI("Save");
	int score9 = stage9Score.score;
	string str9_1 = to_string(score9);
	char* str9_2 = new char[str9_1.length() + 1];
	strcpy(str9_2, str9_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage9_Score", str9_2);
	INIDATA->saveINI("Save");
	int score10 = stage10Score.score;
	string str10_1 = to_string(score10);
	char* str10_2 = new char[str10_1.length() + 1];
	strcpy(str10_2, str10_1.c_str());
	INIDATA->addData("ScoreInfo", "Stage10_Score", str10_2);
	INIDATA->saveINI("Save");
	int totalScore = stageTotalScore.score;
	string strTotal1 = to_string(totalScore);
	char* strTotal2 = new char[strTotal1.length() + 1];
	strcpy(strTotal2, strTotal1.c_str());
	INIDATA->addData("ScoreInfo", "TotalScore", strTotal2);
	INIDATA->saveINI("Save");

	// 기타 텍스트 이미지 찾기
	setClearTime(IMAGEMANAGER->findImage("Result_ClearTime"));
	setStageScore(IMAGEMANAGER->findImage("Result_StageScore"));
	setTotalScore(IMAGEMANAGER->findImage("Result_TotalScore"));
	setMessage(IMAGEMANAGER->findImage("Result_Message"));

	// 기타 변수 초기화
	setBackgroundAlpha(0);
	setBackgroundAlphaBoolOnce(TRUE);
	setBackgroundAlphaBool(FALSE);
	setNumberAlpha(0);
	setNumberAlphaBool(TRUE);
	setStageAlpha(0);
	setStageAlphaBool(TRUE);
	setClearTimeAlpha(0);
	setClearTimeAlphaBool(TRUE);
	setStageScoreAlpha(0);
	setStageScoreAlphaBool(TRUE);
	setTotalScoreAlpha(0);
	setTotalScoreAlphaBool(TRUE);
	setReturnMenu(FALSE);

	// 초기화 종료
	return S_OK;
}

// 해제 (release)
void resultScene::release()
{
}

// 업데이트 (update)
void resultScene::update()
{
	// BGM 출력
	if (!SOUNDMANAGER->isPlaySound("Result"))
	{
		SOUNDMANAGER->play("Result");
	}

	// 메뉴 씬으로 전환
	if (INPUT->getKeyDown(VK_RETURN) && getBackgroundAlphaBoolOnce() == FALSE && getReturnMenu() == FALSE)
	{
		setReturnMenu(TRUE);
		SOUNDMANAGER->play("Create");
	}
	if (getReturnMenu() == TRUE &&
		(getBackgroundAlpha() <= 0 && getStageAlpha() <= 0 && getClearTimeAlpha() <= 0 && getStageScoreAlpha() <= 0 && getTotalScoreAlpha() <= 0))
	{
		SCENEMANAGER->loadScene("menuScene");
	}
}

// 렌더 (render)
void resultScene::render()
{
	// 백그라운드 이미지 출력
	getBackground()->alphaRender(getMemDC(), 0, 0, getBackgroundAlpha());

	// 숫자 이미지 출력
	// 스테이지 1
	for (int i = 0; i < 4; i++)
	{
		switch (stage1Time.elapsedTimeNumber[i])
		{
		case 0:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage1Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 80, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage1Score.scoreNumber[i])
		{
		case 0:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage1Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 80, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 2
	for (int i = 0; i < 4; i++)
	{
		switch (stage2Time.elapsedTimeNumber[i])
		{
		case 0:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage2Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 150, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage2Score.scoreNumber[i])
		{
		case 0:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage2Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 150, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 3
	for (int i = 0; i < 4; i++)
	{
		switch (stage3Time.elapsedTimeNumber[i])
		{
		case 0:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage3Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 220, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage3Score.scoreNumber[i])
		{
		case 0:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage3Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 220, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 4
	for (int i = 0; i < 4; i++)
	{
		switch (stage4Time.elapsedTimeNumber[i])
		{
		case 0:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage4Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 290, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage4Score.scoreNumber[i])
		{
		case 0:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage4Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 290, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 5
	for (int i = 0; i < 4; i++)
	{
		switch (stage5Time.elapsedTimeNumber[i])
		{
		case 0:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage5Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 360, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage5Score.scoreNumber[i])
		{
		case 0:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage5Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 360, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 6
	for (int i = 0; i < 4; i++)
	{
		switch (stage6Time.elapsedTimeNumber[i])
		{
		case 0:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage6Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 430, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage6Score.scoreNumber[i])
		{
		case 0:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage6Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 430, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 7
	for (int i = 0; i < 4; i++)
	{
		switch (stage7Time.elapsedTimeNumber[i])
		{
		case 0:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage7Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 500, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage7Score.scoreNumber[i])
		{
		case 0:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage7Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 500, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 8
	for (int i = 0; i < 4; i++)
	{
		switch (stage8Time.elapsedTimeNumber[i])
		{
		case 0:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage8Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 570, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage8Score.scoreNumber[i])
		{
		case 0:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage8Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 570, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 9
	for (int i = 0; i < 4; i++)
	{
		switch (stage9Time.elapsedTimeNumber[i])
		{
		case 0:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage9Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 640, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage9Score.scoreNumber[i])
		{
		case 0:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage9Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 640, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 스테이지 10
	for (int i = 0; i < 4; i++)
	{
		switch (stage10Time.elapsedTimeNumber[i])
		{
		case 0:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage10Time.elapsedTimeNumberImage[i]->alphaRender(getMemDC(), 690 - (40 * i), 710, 360, 0, 40, 50, getStageAlpha());
			break;
		}

		switch (stage10Score.scoreNumber[i])
		{
		case 0:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stage10Score.scoreNumberImage[i]->alphaRender(getMemDC(), 1060 - (40 * i), 710, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}
	// 토탈 스코어
	for (int i = 0; i < 5; i++)
	{
		switch (stageTotalScore.scoreNumber[i])
		{
		case 0:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 0, 0, 40, 50, getStageAlpha());
			break;
		case 1:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 40, 0, 40, 50, getStageAlpha());
			break;
		case 2:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 80, 0, 40, 50, getStageAlpha());
			break;
		case 3:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 120, 0, 40, 50, getStageAlpha());
			break;
		case 4:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 160, 0, 40, 50, getStageAlpha());
			break;
		case 5:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 200, 0, 40, 50, getStageAlpha());
			break;
		case 6:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 240, 0, 40, 50, getStageAlpha());
			break;
		case 7:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 280, 0, 40, 50, getStageAlpha());
			break;
		case 8:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 320, 0, 40, 50, getStageAlpha());
			break;
		case 9:
			stageTotalScore.scoreNumberImage[i]->alphaRender(getMemDC(), 880 - (40 * i), 793, 360, 0, 40, 50, getStageAlpha());
			break;
		}
	}

	// 스테이지 텍스트 이미지 출력
	getStage()->alphaRender(getMemDC(), 200, 66, getStageAlpha());

	// 기타 텍스트 이미지 출력
	getClearTime()->alphaRender(getMemDC(), 550, 10, getClearTimeAlpha());
	getStageScore()->alphaRender(getMemDC(), 900, 10, getStageScoreAlpha());
	getTotalScore()->alphaRender(getMemDC(), 400, 796, getTotalScoreAlpha());
	if (getBackgroundAlphaBoolOnce() == FALSE && getReturnMenu() == FALSE)
	{
		getMessage()->render(getMemDC(), 190, WINSIZEY - 100);
	}

	// 백그라운드 이미지 알파값
	if (getBackgroundAlphaBoolOnce() == FALSE)
	{
		if (getBackgroundAlphaBool() == TRUE)
		{
			setBackgroundAlpha(getBackgroundAlpha() + 2);

			if (getBackgroundAlpha() >= 255)
			{
				setBackgroundAlpha(255);
			}
		}
		else
		{
			setBackgroundAlpha(getBackgroundAlpha() - 2);

			if (getBackgroundAlpha() <= 0)
			{
				setBackgroundAlpha(0);
			}
		}
	}

	// 스테이지 텍스트 이미지 알파값
	if (getStageAlphaBool() == TRUE)
	{
		setStageAlpha(getStageAlpha() + 2);

		if (getStageAlpha() >= 255)
		{
			setStageAlpha(255);
		}
	}
	else
	{
		setStageAlpha(getStageAlpha() - 2);

		if (getStageAlpha() <= 0)
		{
			setStageAlpha(0);
		}
	}

	// 기타 텍스트 이미지 알파값
	if (getClearTimeAlphaBool() == TRUE)
	{
		setClearTimeAlpha(getClearTimeAlpha() + 2);

		if (getClearTimeAlpha() >= 255)
		{
			setClearTimeAlpha(255);
		}
	}
	else
	{
		setClearTimeAlpha(getClearTimeAlpha() - 2);

		if (getClearTimeAlpha() <= 0)
		{
			setClearTimeAlpha(0);
		}
	}
	if (getStageScoreAlphaBool() == TRUE)
	{
		setStageScoreAlpha(getStageScoreAlpha() + 2);

		if (getStageScoreAlpha() >= 255)
		{
			setStageScoreAlpha(255);
		}
	}
	else
	{
		setStageScoreAlpha(getStageScoreAlpha() - 2);

		if (getStageScoreAlpha() <= 0)
		{
			setStageScoreAlpha(0);
		}
	}
	if (getTotalScoreAlphaBool() == TRUE)
	{
		setTotalScoreAlpha(getTotalScoreAlpha() + 2);

		if (getTotalScoreAlpha() >= 255)
		{
			setTotalScoreAlpha(255);
		}
	}
	else
	{
		setTotalScoreAlpha(getTotalScoreAlpha() - 2);

		if (getTotalScoreAlpha() <= 0)
		{
			setTotalScoreAlpha(0);
		}
	}

	// 백그라운드 이미지 알파값 증감 전환
	if (getBackgroundAlphaBoolOnce() == TRUE)
	{
		setBackgroundAlpha(getBackgroundAlpha() + 2);

		if (getBackgroundAlpha() >= 180)
		{
			setBackgroundAlphaBoolOnce(FALSE);
			setBackgroundAlphaBool(TRUE);
		}
	}
	else
	{
		if (getReturnMenu() == FALSE)
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

	// 스테이지 텍스트 이미지 알파값 증감 전환
	if (getReturnMenu() == FALSE)
	{
		setStageAlphaBool(TRUE);
	}
	else
	{
		setStageAlphaBool(FALSE);
	}

	// 기타 텍스트 이미지 알파값 증감 전환
	if (getReturnMenu() == FALSE)
	{
		setClearTimeAlphaBool(TRUE);
		setStageScoreAlphaBool(TRUE);
		setTotalScoreAlphaBool(TRUE);
	}
	else
	{
		setClearTimeAlphaBool(FALSE);
		setStageScoreAlphaBool(FALSE);
		setTotalScoreAlphaBool(FALSE);
	}
}