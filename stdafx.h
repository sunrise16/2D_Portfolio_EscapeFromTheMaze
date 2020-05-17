﻿#pragma once
#include <SDKDDKVer.h>

// GDI+ 사용
#pragma comment(lib, "Gdiplus.lib")
#include <Ole2.h>
#include <gdiplus.h>
using namespace Gdiplus;

// 거의 사용되지 않는 내용은 Windows 헤더에서 제외
#define WIN32_LEAN_AND_MEAN

// Windows 헤더 파일
#include <Windows.h>

// 디버깅용 콘솔창 (주석 처리할 경우 콘솔창이 사라짐)
// #pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// C 런타임 헤더 파일
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <math.h>

// C++ 런타임 헤더 파일
#include <iostream>
using namespace std;

// 자주 사용하는 STL
#include <string>
#include <vector>
#include <map>

// 직접 만든 헤더 파일
#include "commonMacroFunction.h"
#include "input.h"
#include "random.h"
#include "imageManager.h"
#include "utility.h"
#include "sceneManager.h"
#include "playerData.h"
#include "iniData.h"
#include "soundManager.h"
#include "timeManager.h"
using namespace MY_UTIL;

// singleton 정의
#define INPUT input::getSingleton()
#define RANDOM random::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define PLAYERDATA playerData::getSingleton()
#define INIDATA iniData::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()

// 윈도우 창 관련 정의
#define WINNAME (LPTSTR)(TEXT("이종석 2D 최종 포트폴리오 - Escape from the Maze"))
#define WINSTARTX	100
#define WINSTARTY	100
#define WINSIZEX		1280
#define WINSIZEY		960
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

// 매크로 함수
#define SAFE_DELETE(p)		{if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = NULL;}}

// 전역 변수
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;