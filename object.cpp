#include "stdafx.h"
#include "object.h"
#include "player.h"
#include "clone.h"

// 초기화 (init)
HRESULT object::init(int _currentStage)
{
	// 구조체 초기화
	tagObject object;
	ZeroMemory(&object, sizeof(object));

	// 스테이지에 따라 오브젝트 정보 초기화
	switch (_currentStage)
	{
	case 1:
		// 메세지 오브젝트
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1088;
		object.createY = 1154;
		object.objectX = 1088;
		object.objectY = 1154;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_AutoGate");
		object.objectType = OBJECT_TYPE_AUTOGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1600;
		object.createY = 1154;
		object.objectX = 1600;
		object.objectY = 1154;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 2:
		// 장애물 오브젝트
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1120 + (64 * i);
			object.createY = 1328;
			object.objectX = 1120 + (64 * i);
			object.objectY = 1328;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 메세지 오브젝트 1
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 960;
		object.createY = 1216;
		object.objectX = 960;
		object.objectY = 1216;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 메세지 오브젝트 2
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1408;
		object.createY = 1088;
		object.objectX = 1408;
		object.objectY = 1088;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_AutoGate");
		object.objectType = OBJECT_TYPE_AUTOGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1664;
		object.createY = 960;
		object.objectX = 1664;
		object.objectY = 960;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 3:
		// 장애물 오브젝트
		for (int i = 0; i < 7; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1248 + (64 * i);
			object.createY = 1328;
			object.objectX = 1248 + (64 * i);
			object.objectY = 1328;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 928;
		object.createY = 1248;
		object.objectX = 928;
		object.objectY = 1248;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 메세지 오브젝트
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1088;
		object.createY = 1088;
		object.objectX = 1088;
		object.objectY = 1088;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1728;
		object.createY = 1088;
		object.objectX = 1728;
		object.objectY = 1088;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 4:
		// 타일 오브젝트
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1696;
			object.createY = 1056 + (64 * i);
			object.objectX = 1696;
			object.objectY = 1056 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1184;
			object.createY = 672 + (64 * i);
			object.objectX = 1184;
			object.objectY = 672 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트
		for (int i = 0; i < 5; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1376 + (64 * i);
			object.createY = 1328;
			object.objectX = 1376 + (64 * i);
			object.objectY = 1328;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1760;
		object.createY = 1184;
		object.objectX = 1760;
		object.objectY = 1184;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 864;
		object.createY = 1312;
		object.objectX = 864;
		object.objectY = 1312;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 초록색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GREEN;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 864;
		object.createY = 1120;
		object.objectX = 864;
		object.objectY = 1120;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 메세지 오브젝트
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1024;
		object.createY = 1280;
		object.objectX = 1024;
		object.objectY = 1280;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1664;
		object.createY = 896;
		object.objectX = 1664;
		object.objectY = 896;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 5:
		// 발판 오브젝트
		object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
		object.objectType = OBJECT_TYPE_LEDGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NORMAL;
		object.createX = 768;
		object.createY = 772;
		object.objectX = 768;
		object.objectY = 772;
		object.trigger = TRUE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
		_vObject.push_back(object);
		// 메세지 오브젝트 1
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 768;
		object.createY = 704;
		object.objectX = 768;
		object.objectY = 704;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 메세지 오브젝트 2
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1280;
		object.createY = 1344;
		object.objectX = 1280;
		object.objectY = 1344;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_AutoGate");
		object.objectType = OBJECT_TYPE_AUTOGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1792;
		object.createY = 896;
		object.objectX = 1792;
		object.objectY = 896;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 6:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 864 + (64 * i);
			object.createY = 800;
			object.objectX = 864 + (64 * i);
			object.objectY = 800;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1568 + (64 * i);
			object.createY = 800;
			object.objectX = 1568 + (64 * i);
			object.objectY = 800;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1696;
		object.createY = 736;
		object.objectX = 1696;
		object.objectY = 736;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 흰색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_WHITE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1696;
		object.createY = 1184;
		object.objectX = 1696;
		object.objectY = 1184;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 864;
		object.createY = 736;
		object.objectX = 864;
		object.objectY = 736;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 896;
		object.createY = 1152;
		object.objectX = 896;
		object.objectY = 1152;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 7:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 6; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 864 + (64 * (i % 3));
			object.createY = 736 + (448 * (i / 3));
			object.objectX = 864 + (64 * (i % 3));
			object.objectY = 736 + (448 * (i / 3));
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1504;
			object.createY = 608 + (64 * i);
			object.objectX = 1504;
			object.objectY = 608 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1376 + (64 * i);
			object.createY = 880;
			object.objectX = 1376 + (64 * i);
			object.objectY = 880;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1248 + (64 * (i % 2));
			object.createY = 1136 + (256 * (i / 2));
			object.objectX = 1248 + (64 * (i % 2));
			object.objectY = 1136 + (256 * (i / 2));
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치 1
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 928;
		object.createY = 1120;
		object.objectX = 928;
		object.objectY = 1120;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 게이트 스위치 2
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 928;
		object.createY = 1376;
		object.objectX = 928;
		object.objectY = 1376;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 흰색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_WHITE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1248;
		object.createY = 1248;
		object.objectX = 1248;
		object.objectY = 1248;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1504;
		object.createY = 1376;
		object.objectX = 1504;
		object.objectY = 1376;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 발판 오브젝트
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_SHORT;
			object.createX = 1696;
			object.createY = 708 + (192 * i);
			object.objectX = 1696;
			object.objectY = 708 + (192 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 8);
			_vObject.push_back(object);
		}
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1792;
		object.createY = 1344;
		object.objectX = 1792;
		object.objectY = 1344;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 8:
		// 타일 오브젝트
		// 흰색 타일 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1952;
			object.createY = 1184 + (64 * i);
			object.objectX = 1952;
			object.objectY = 1184 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 흰색 타일 2
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2784;
			object.createY = 608 + (64 * i);
			object.objectX = 2784;
			object.objectY = 608 + (64 * i);
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1312 + (64 * i);
			object.createY = 1120;
			object.objectX = 1312 + (64 * i);
			object.objectY = 1120;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1120;
			object.createY = 608 + (64 * i);
			object.objectX = 1120;
			object.objectY = 608 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1312 + (64 * i);
			object.createY = 1392;
			object.objectX = 1312 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1568 + (64 * i);
			object.createY = 1392;
			object.objectX = 1568 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 3
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1824 + (64 * i);
			object.createY = 1392;
			object.objectX = 1824 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 4
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2208 + (64 * i);
			object.createY = 1392;
			object.objectX = 2208 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 5
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1888 + (64 * i);
			object.createY = 816;
			object.objectX = 1888 + (64 * i);
			object.objectY = 816;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 6
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2144 + (64 * i);
			object.createY = 816;
			object.objectX = 2144 + (64 * i);
			object.objectY = 816;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2080;
		object.createY = 1248;
		object.objectX = 2080;
		object.objectY = 1248;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 흰색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_WHITE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1120;
		object.createY = 1248;
		object.objectX = 1120;
		object.objectY = 1248;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2720;
		object.createY = 672;
		object.objectX = 2720;
		object.objectY = 672;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 초록색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GREEN;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1376;
		object.createY = 1056;
		object.objectX = 1376;
		object.objectY = 1056;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NORMAL;
			object.createX = 1280 + (1152 * i);
			object.createY = 964;
			object.objectX = 1280 + (1152 * i);
			object.objectY = 964;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
			_vObject.push_back(object);
		}
		// 발판 오브젝트 2
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NORMAL;
			object.createX = 2752;
			object.createY = 1028 + (192 * i);
			object.objectX = 2752;
			object.objectY = 1028 + (192 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
			_vObject.push_back(object);
		}
		// 발판 오브젝트 3
		object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
		object.objectType = OBJECT_TYPE_LEDGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NORMAL;
		object.createX = 3008;
		object.createY = 836;
		object.objectX = 3008;
		object.objectY = 836;
		object.trigger = TRUE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
		_vObject.push_back(object);
		// 메세지 오브젝트
		object.objectImage = IMAGEMANAGER->findImage("Object_MessageObject");
		object.objectType = OBJECT_TYPE_MESSAGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 3008;
		object.createY = 768;
		object.objectX = 3008;
		object.objectY = 768;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 128);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 832;
		object.createY = 704;
		object.objectX = 832;
		object.objectY = 704;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 9:
		// 타일 오브젝트
		// 흰색 타일 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2400;
			object.createY = 864 + (64 * i);
			object.objectX = 2400;
			object.objectY = 864 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 흰색 타일 2
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1888;
			object.createY = 608 + (64 * i);
			object.objectX = 1888;
			object.objectY = 608 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일
		for (int i = 0; i < 9; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 864 + (64 * (i % 3));
			object.createY = 736 + (192 * (i / 3));
			object.objectX = 864 + (64 * (i % 3));
			object.objectY = 736 + (192 * (i / 3));
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 1
		for (int i = 0; i < 9; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 864 + (64 * (i % 3));
			object.createY = 800 + (192 * (i / 3));
			object.objectX = 864 + (64 * (i % 3));
			object.objectY = 800 + (192 * (i / 3));
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 2
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2144 + (64 * i);
			object.createY = 1056;
			object.objectX = 2144 + (64 * i);
			object.objectY = 1056;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 3
		object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
		object.objectType = OBJECT_TYPE_TILE;
		object.tileType = TILE_TYPE_GREEN;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1504;
		object.createY = 1120;
		object.objectX = 1504;
		object.objectY = 1120;
		object.trigger = TRUE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 초록색 타일 4
		object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
		object.objectType = OBJECT_TYPE_TILE;
		object.tileType = TILE_TYPE_GREEN;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2208;
		object.createY = 992;
		object.objectX = 2208;
		object.objectY = 992;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 파란색 타일 1
		for (int i = 0; i < 9; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_BLUE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 864 + (64 * (i % 3));
			object.createY = 864 + (192 * (i / 3));
			object.objectX = 864 + (64 * (i % 3));
			object.objectY = 864 + (192 * (i / 3));
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 파란색 타일 2
		object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
		object.objectType = OBJECT_TYPE_TILE;
		object.tileType = TILE_TYPE_BLUE;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1504;
		object.createY = 1248;
		object.objectX = 1504;
		object.objectY = 1248;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 장애물 오브젝트 1
		for (int i = 0; i < 8; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2016 + (64 * (i % 2)) + (256 * (i / 2));
			object.createY = 1328;
			object.objectX = 2016 + (64 * (i % 2)) + (256 * (i / 2));
			object.objectY = 1328;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1632 + (64 * i);
			object.createY = 752;
			object.objectX = 1632 + (64 * i);
			object.objectY = 752;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 흰색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_WHITE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2976;
		object.createY = 1312;
		object.objectX = 2976;
		object.objectY = 1312;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1504;
		object.createY = 1184;
		object.objectX = 1504;
		object.objectY = 1184;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 초록색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GREEN;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1568;
		object.createY = 672;
		object.objectX = 1568;
		object.objectY = 672;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 파란색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_BLUE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2208;
		object.createY = 928;
		object.objectX = 2208;
		object.objectY = 928;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NORMAL;
			object.createX = 1664 + (256 * i);
			object.createY = 1156;
			object.objectX = 1664 + (256 * i);
			object.objectY = 1156;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
			_vObject.push_back(object);
		}
		// 발판 오브젝트 2
		object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
		object.objectType = OBJECT_TYPE_LEDGE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NORMAL;
		object.createX = 1984;
		object.createY = 900;
		object.objectX = 1984;
		object.objectY = 900;
		object.trigger = TRUE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
		_vObject.push_back(object);
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_AutoGate");
		object.objectType = OBJECT_TYPE_AUTOGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 928;
		object.createY = 1344;
		object.objectX = 928;
		object.objectY = 1344;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	case 10:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2336 + (64 * i);
			object.createY = 1120;
			object.objectX = 2336 + (64 * i);
			object.objectY = 1120;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일 1
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1632 - (64 * (i % 2));
			object.createY = 992 + (128 * i);
			object.objectX = 1632 - (64 * (i % 2));
			object.objectY = 992 + (128 * i);
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일 2
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2080 + (64 * (i % 2));
			object.createY = 992 + (128 * i);
			object.objectX = 2080 + (64 * (i % 2));
			object.objectY = 992 + (128 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일 3
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1120;
			object.createY = 928 + (64 * i);
			object.objectX = 1120;
			object.objectY = 928 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 빨간색 타일 4
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_RED;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2336 + (64 * i);
			object.createY = 992;
			object.objectX = 2336 + (64 * i);
			object.objectY = 992;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 1
		for (int i = 0; i < 6; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2592 + (256 * (i / 3));
			object.createY = 736 + (64 * (i % 3));
			object.objectX = 2592 + (256 * (i / 3));
			object.objectY = 736 + (64 * (i % 3));
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 2
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2656 + (64 * (i % 3));
			object.createY = 864;
			object.objectX = 2656 + (64 * (i % 3));
			object.objectY = 864;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 초록색 타일 3
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_GREEN;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2656 + (64 * (i % 3));
			object.createY = 672;
			object.objectX = 2656 + (64 * (i % 3));
			object.objectY = 672;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 파란색 타일
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_BLUE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1312;
			object.createY = 608 + (64 * i);
			object.objectX = 1312;
			object.objectY = 608 + (64 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 736 + (64 * (i % 2)) + (256 * (i / 2));
			object.createY = 1392;
			object.objectX = 736 + (64 * (i % 2)) + (256 * (i / 2));
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 1120 + (64 * i);
			object.createY = 1200 - (128 * (i / 2));
			object.objectX = 1120 + (64 * i);
			object.objectY = 1200 - (128 * (i / 2));
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 3
		for (int i = 0; i < 3; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2592 + (64 * i);
			object.createY = 1392;
			object.objectX = 2592 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 장애물 오브젝트 4
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Obstacle");
			object.objectType = OBJECT_TYPE_OBSTACLE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 2912 + (64 * i);
			object.createY = 1392;
			object.objectX = 2912 + (64 * i);
			object.objectY = 1392;
			object.trigger = FALSE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 32);
			_vObject.push_back(object);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GATE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 1184;
		object.createY = 800;
		object.objectX = 1184;
		object.objectY = 800;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 흰색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_WHITE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2528;
		object.createY = 1376;
		object.objectX = 2528;
		object.objectY = 1376;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 빨간색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_RED;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2144;
		object.createY = 1376;
		object.objectX = 2144;
		object.objectY = 1376;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 초록색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_GREEN;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2368;
		object.createY = 1376;
		object.objectX = 2368;
		object.objectY = 1376;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 파란색 타일 스위치
		object.objectImage = IMAGEMANAGER->findImage("Object_Switch");
		object.objectType = OBJECT_TYPE_SWITCH;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_BLUE;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 2720;
		object.createY = 800;
		object.objectX = 2720;
		object.objectY = 800;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
		_vObject.push_back(object);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NORMAL;
			object.createX = 1600 + (384 * i);
			object.createY = 836;
			object.objectX = 1600 + (384 * i);
			object.objectY = 836;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
			_vObject.push_back(object);
		}
		// 발판 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			object.objectType = OBJECT_TYPE_LEDGE;
			object.tileType = TILE_TYPE_NULL;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NORMAL;
			object.createX = 3072;
			object.createY = 708 + (192 * i);
			object.objectX = 3072;
			object.objectY = 708 + (192 * i);
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 128, 8);
			_vObject.push_back(object);
		}
		// 게이트
		object.objectImage = IMAGEMANAGER->findImage("Object_CloseGate");
		object.objectType = OBJECT_TYPE_CLOSEGATE;
		object.tileType = TILE_TYPE_NULL;
		object.switchType = SWITCH_TYPE_NULL;
		object.ledgeType = LEDGE_TYPE_NULL;
		object.createX = 896;
		object.createY = 1092;
		object.objectX = 896;
		object.objectY = 1092;
		object.trigger = FALSE;
		object.switchOn = FALSE;
		object.switchOff = FALSE;
		object.switchSoundOutput = FALSE;
		object.switchOffDelay = 0;
		object.count = 0;
		object.index = 0;
		object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 128);
		_vObject.push_back(object);
		break;
	}

	// 기타 변수 초기화
	setAlpha(0);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);

	// 초기화 종료
	return S_OK;
}
HRESULT object::init(int _currentStage, int _alpha)
{
	// 스테이지에 따라 오브젝트 정보 초기화
	switch (_currentStage)
	{
	case 1:
		// 메세지 오브젝트
		_vObject[0].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[0].tileType = TILE_TYPE_NULL;
		_vObject[0].switchType = SWITCH_TYPE_NULL;
		_vObject[0].ledgeType = LEDGE_TYPE_NULL;
		_vObject[0].createX = 1088;
		_vObject[0].createY = 1154;
		_vObject[0].objectX = 1088;
		_vObject[0].objectY = 1154;
		_vObject[0].trigger = FALSE;
		_vObject[0].switchOn = FALSE;
		_vObject[0].switchOff = FALSE;
		_vObject[0].switchSoundOutput = FALSE;
		_vObject[0].switchOffDelay = 0;
		_vObject[0].count = 0;
		_vObject[0].index = 0;
		_vObject[0].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 128, 128);
		// 게이트
		_vObject[1].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[1].tileType = TILE_TYPE_NULL;
		_vObject[1].switchType = SWITCH_TYPE_NULL;
		_vObject[1].ledgeType = LEDGE_TYPE_NULL;
		_vObject[1].createX = 1600;
		_vObject[1].createY = 1154;
		_vObject[1].objectX = 1600;
		_vObject[1].objectY = 1154;
		_vObject[1].trigger = FALSE;
		_vObject[1].switchOn = FALSE;
		_vObject[1].switchOff = FALSE;
		_vObject[1].switchSoundOutput = FALSE;
		_vObject[1].switchOffDelay = 0;
		_vObject[1].count = 0;
		_vObject[1].index = 0;
		_vObject[1].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 64, 128);
		break;
	case 2:
		// 장애물 오브젝트
		for (int i = 0; i < 2; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i].tileType = TILE_TYPE_NULL;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 1120 + (64 * i);
			_vObject[i].createY = 1328;
			_vObject[i].objectX = 1120 + (64 * i);
			_vObject[i].objectY = 1328;
			_vObject[i].trigger = FALSE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 32);
		}
		// 메세지 오브젝트 1
		_vObject[2].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[2].tileType = TILE_TYPE_NULL;
		_vObject[2].switchType = SWITCH_TYPE_NULL;
		_vObject[2].ledgeType = LEDGE_TYPE_NULL;
		_vObject[2].createX = 960;
		_vObject[2].createY = 1216;
		_vObject[2].objectX = 960;
		_vObject[2].objectY = 1216;
		_vObject[2].trigger = FALSE;
		_vObject[2].switchOn = FALSE;
		_vObject[2].switchOff = FALSE;
		_vObject[2].switchSoundOutput = FALSE;
		_vObject[2].switchOffDelay = 0;
		_vObject[2].count = 0;
		_vObject[2].index = 0;
		_vObject[2].objectRect = RectMakeCenter(_vObject[2].objectX, _vObject[2].objectY, 128, 128);
		// 메세지 오브젝트 2
		_vObject[3].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[3].tileType = TILE_TYPE_NULL;
		_vObject[3].switchType = SWITCH_TYPE_NULL;
		_vObject[3].ledgeType = LEDGE_TYPE_NULL;
		_vObject[3].createX = 1408;
		_vObject[3].createY = 1088;
		_vObject[3].objectX = 1408;
		_vObject[3].objectY = 1088;
		_vObject[3].trigger = FALSE;
		_vObject[3].switchOn = FALSE;
		_vObject[3].switchOff = FALSE;
		_vObject[3].switchSoundOutput = FALSE;
		_vObject[3].switchOffDelay = 0;
		_vObject[3].count = 0;
		_vObject[3].index = 0;
		_vObject[3].objectRect = RectMakeCenter(_vObject[3].objectX, _vObject[3].objectY, 128, 128);
		// 게이트
		_vObject[4].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[4].tileType = TILE_TYPE_NULL;
		_vObject[4].switchType = SWITCH_TYPE_NULL;
		_vObject[4].ledgeType = LEDGE_TYPE_NULL;
		_vObject[4].createX = 1664;
		_vObject[4].createY = 960;
		_vObject[4].objectX = 1664;
		_vObject[4].objectY = 960;
		_vObject[4].trigger = FALSE;
		_vObject[4].switchOn = FALSE;
		_vObject[4].switchOff = FALSE;
		_vObject[4].switchSoundOutput = FALSE;
		_vObject[4].switchOffDelay = 0;
		_vObject[4].count = 0;
		_vObject[4].index = 0;
		_vObject[4].objectRect = RectMakeCenter(_vObject[4].objectX, _vObject[4].objectY, 64, 128);
		break;
	case 3:
		// 장애물 오브젝트
		for (int i = 0; i < 7; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i].tileType = TILE_TYPE_NULL;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 1248 + (64 * i);
			_vObject[i].createY = 1328;
			_vObject[i].objectX = 1248 + (64 * i);
			_vObject[i].objectY = 1328;
			_vObject[i].trigger = FALSE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		_vObject[7].objectType = OBJECT_TYPE_SWITCH;
		_vObject[7].tileType = TILE_TYPE_NULL;
		_vObject[7].switchType = SWITCH_TYPE_GATE;
		_vObject[7].ledgeType = LEDGE_TYPE_NULL;
		_vObject[7].createX = 928;
		_vObject[7].createY = 1248;
		_vObject[7].objectX = 928;
		_vObject[7].objectY = 1248;
		_vObject[7].trigger = FALSE;
		_vObject[7].switchOn = FALSE;
		_vObject[7].switchOff = FALSE;
		_vObject[7].switchSoundOutput = FALSE;
		_vObject[7].switchOffDelay = 0;
		_vObject[7].count = 0;
		_vObject[7].index = 0;
		_vObject[7].objectRect = RectMakeCenter(_vObject[7].objectX, _vObject[7].objectY, 64, 64);
		// 메세지 오브젝트
		_vObject[8].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[8].tileType = TILE_TYPE_NULL;
		_vObject[8].switchType = SWITCH_TYPE_NULL;
		_vObject[8].ledgeType = LEDGE_TYPE_NULL;
		_vObject[8].createX = 1088;
		_vObject[8].createY = 1088;
		_vObject[8].objectX = 1088;
		_vObject[8].objectY = 1088;
		_vObject[8].trigger = FALSE;
		_vObject[8].switchOn = FALSE;
		_vObject[8].switchOff = FALSE;
		_vObject[9].switchSoundOutput = FALSE;
		_vObject[8].switchOffDelay = 0;
		_vObject[8].count = 0;
		_vObject[8].index = 0;
		_vObject[8].objectRect = RectMakeCenter(_vObject[8].objectX, _vObject[8].objectY, 128, 128);
		// 게이트
		_vObject[9].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[9].tileType = TILE_TYPE_NULL;
		_vObject[9].switchType = SWITCH_TYPE_NULL;
		_vObject[9].ledgeType = LEDGE_TYPE_NULL;
		_vObject[9].createX = 1728;
		_vObject[9].createY = 1088;
		_vObject[9].objectX = 1728;
		_vObject[9].objectY = 1088;
		_vObject[9].trigger = FALSE;
		_vObject[9].switchOn = FALSE;
		_vObject[9].switchOff = FALSE;
		_vObject[9].switchSoundOutput = FALSE;
		_vObject[9].switchOffDelay = 0;
		_vObject[9].count = 0;
		_vObject[9].index = 0;
		_vObject[9].objectRect = RectMakeCenter(_vObject[9].objectX, _vObject[9].objectY, 64, 128);
		break;
	case 4:
		// 타일 오브젝트
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_RED;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 1696;
			_vObject[i].createY = 1056 + (64 * i);
			_vObject[i].objectX = 1696;
			_vObject[i].objectY = 1056 + (64 * i);
			_vObject[i].trigger = TRUE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 초록색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 3].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 3].tileType = TILE_TYPE_GREEN;
			_vObject[i + 3].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 3].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 3].createX = 1184;
			_vObject[i + 3].createY = 672 + (64 * i);
			_vObject[i + 3].objectX = 1184;
			_vObject[i + 3].objectY = 672 + (64 * i);
			_vObject[i + 3].trigger = TRUE;
			_vObject[i + 3].switchOn = FALSE;
			_vObject[i + 3].switchOff = FALSE;
			_vObject[i + 3].switchSoundOutput = FALSE;
			_vObject[i + 3].switchOffDelay = 0;
			_vObject[i + 3].count = 0;
			_vObject[i + 3].index = 0;
			_vObject[i + 3].objectRect = RectMakeCenter(_vObject[i + 3].objectX, _vObject[i + 3].objectY, 64, 64);
		}
		// 장애물 오브젝트
		for (int i = 0; i < 5; i++)
		{
			_vObject[i + 6].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 6].tileType = TILE_TYPE_NULL;
			_vObject[i + 6].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 6].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 6].createX = 1376 + (64 * i);
			_vObject[i + 6].createY = 1328;
			_vObject[i + 6].objectX = 1376 + (64 * i);
			_vObject[i + 6].objectY = 1328;
			_vObject[i + 6].trigger = FALSE;
			_vObject[i + 6].switchOn = FALSE;
			_vObject[i + 6].switchOff = FALSE;
			_vObject[i + 6].switchSoundOutput = FALSE;
			_vObject[i + 6].switchOffDelay = 0;
			_vObject[i + 6].count = 0;
			_vObject[i + 6].index = 0;
			_vObject[i + 6].objectRect = RectMakeCenter(_vObject[i + 6].objectX, _vObject[i + 6].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		_vObject[11].objectType = OBJECT_TYPE_SWITCH;
		_vObject[11].tileType = TILE_TYPE_NULL;
		_vObject[11].switchType = SWITCH_TYPE_GATE;
		_vObject[11].ledgeType = LEDGE_TYPE_NULL;
		_vObject[11].createX = 1760;
		_vObject[11].createY = 1184;
		_vObject[11].objectX = 1760;
		_vObject[11].objectY = 1184;
		_vObject[11].trigger = FALSE;
		_vObject[11].switchOn = FALSE;
		_vObject[11].switchOff = FALSE;
		_vObject[11].switchSoundOutput = FALSE;
		_vObject[11].switchOffDelay = 0;
		_vObject[11].count = 0;
		_vObject[11].index = 0;
		_vObject[11].objectRect = RectMakeCenter(_vObject[11].objectX, _vObject[11].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[12].objectType = OBJECT_TYPE_SWITCH;
		_vObject[12].tileType = TILE_TYPE_NULL;
		_vObject[12].switchType = SWITCH_TYPE_RED;
		_vObject[12].ledgeType = LEDGE_TYPE_NULL;
		_vObject[12].createX = 864;
		_vObject[12].createY = 1312;
		_vObject[12].objectX = 864;
		_vObject[12].objectY = 1312;
		_vObject[12].trigger = FALSE;
		_vObject[12].switchOn = FALSE;
		_vObject[12].switchOff = FALSE;
		_vObject[12].switchSoundOutput = FALSE;
		_vObject[12].switchOffDelay = 0;
		_vObject[12].count = 0;
		_vObject[12].index = 0;
		_vObject[12].objectRect = RectMakeCenter(_vObject[12].objectX, _vObject[12].objectY, 64, 64);
		// 초록색 타일 스위치
		_vObject[13].objectType = OBJECT_TYPE_SWITCH;
		_vObject[13].tileType = TILE_TYPE_NULL;
		_vObject[13].switchType = SWITCH_TYPE_GREEN;
		_vObject[13].ledgeType = LEDGE_TYPE_NULL;
		_vObject[13].createX = 864;
		_vObject[13].createY = 1120;
		_vObject[13].objectX = 864;
		_vObject[13].objectY = 1120;
		_vObject[13].trigger = FALSE;
		_vObject[13].switchOn = FALSE;
		_vObject[13].switchOff = FALSE;
		_vObject[13].switchSoundOutput = FALSE;
		_vObject[13].switchOffDelay = 0;
		_vObject[13].count = 0;
		_vObject[13].index = 0;
		_vObject[13].objectRect = RectMakeCenter(_vObject[13].objectX, _vObject[13].objectY, 64, 64);
		// 메세지 오브젝트
		_vObject[14].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[14].tileType = TILE_TYPE_NULL;
		_vObject[14].switchType = SWITCH_TYPE_NULL;
		_vObject[14].ledgeType = LEDGE_TYPE_NULL;
		_vObject[14].createX = 1024;
		_vObject[14].createY = 1280;
		_vObject[14].objectX = 1024;
		_vObject[14].objectY = 1280;
		_vObject[14].trigger = FALSE;
		_vObject[14].switchOn = FALSE;
		_vObject[14].switchOff = FALSE;
		_vObject[14].switchSoundOutput = FALSE;
		_vObject[14].switchOffDelay = 0;
		_vObject[14].count = 0;
		_vObject[14].index = 0;
		_vObject[14].objectRect = RectMakeCenter(_vObject[14].objectX, _vObject[14].objectY, 128, 128);
		// 게이트
		_vObject[15].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[15].tileType = TILE_TYPE_NULL;
		_vObject[15].switchType = SWITCH_TYPE_NULL;
		_vObject[15].ledgeType = LEDGE_TYPE_NULL;
		_vObject[15].createX = 1664;
		_vObject[15].createY = 896;
		_vObject[15].objectX = 1664;
		_vObject[15].objectY = 896;
		_vObject[15].trigger = FALSE;
		_vObject[15].switchOn = FALSE;
		_vObject[15].switchOff = FALSE;
		_vObject[15].switchSoundOutput = FALSE;
		_vObject[15].switchOffDelay = 0;
		_vObject[15].count = 0;
		_vObject[15].index = 0;
		_vObject[15].objectRect = RectMakeCenter(_vObject[15].objectX, _vObject[15].objectY, 64, 128);
		break;
	case 5:
		// 발판 오브젝트
		_vObject[0].objectType = OBJECT_TYPE_LEDGE;
		_vObject[0].tileType = TILE_TYPE_NULL;
		_vObject[0].switchType = SWITCH_TYPE_NULL;
		_vObject[0].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[0].createX = 768;
		_vObject[0].createY = 772;
		_vObject[0].objectX = 768;
		_vObject[0].objectY = 772;
		_vObject[0].trigger = TRUE;
		_vObject[0].switchOn = FALSE;
		_vObject[0].switchOff = FALSE;
		_vObject[0].switchSoundOutput = FALSE;
		_vObject[0].switchOffDelay = 0;
		_vObject[0].count = 0;
		_vObject[0].index = 0;
		_vObject[0].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 128, 8);
		// 메세지 오브젝트 1
		_vObject[1].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[1].tileType = TILE_TYPE_NULL;
		_vObject[1].switchType = SWITCH_TYPE_NULL;
		_vObject[1].ledgeType = LEDGE_TYPE_NULL;
		_vObject[1].createX = 768;
		_vObject[1].createY = 704;
		_vObject[1].objectX = 768;
		_vObject[1].objectY = 704;
		_vObject[1].trigger = FALSE;
		_vObject[1].switchOn = FALSE;
		_vObject[1].switchOff = FALSE;
		_vObject[1].switchSoundOutput = FALSE;
		_vObject[1].switchOffDelay = 0;
		_vObject[1].count = 0;
		_vObject[1].index = 0;
		_vObject[1].objectRect = RectMakeCenter(_vObject[1].objectX, _vObject[1].objectY, 128, 128);
		// 메세지 오브젝트 2
		_vObject[2].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[2].tileType = TILE_TYPE_NULL;
		_vObject[2].switchType = SWITCH_TYPE_NULL;
		_vObject[2].ledgeType = LEDGE_TYPE_NULL;
		_vObject[2].createX = 1280;
		_vObject[2].createY = 1344;
		_vObject[2].objectX = 1280;
		_vObject[2].objectY = 1344;
		_vObject[2].trigger = FALSE;
		_vObject[2].switchOn = FALSE;
		_vObject[2].switchOff = FALSE;
		_vObject[2].switchSoundOutput = FALSE;
		_vObject[2].switchOffDelay = 0;
		_vObject[2].count = 0;
		_vObject[2].index = 0;
		_vObject[2].objectRect = RectMakeCenter(_vObject[2].objectX, _vObject[2].objectY, 128, 128);
		// 게이트
		_vObject[3].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[3].tileType = TILE_TYPE_NULL;
		_vObject[3].switchType = SWITCH_TYPE_NULL;
		_vObject[3].ledgeType = LEDGE_TYPE_NULL;
		_vObject[3].createX = 1792;
		_vObject[3].createY = 896;
		_vObject[3].objectX = 1792;
		_vObject[3].objectY = 896;
		_vObject[3].trigger = FALSE;
		_vObject[3].switchOn = FALSE;
		_vObject[3].switchOff = FALSE;
		_vObject[3].switchSoundOutput = FALSE;
		_vObject[3].switchOffDelay = 0;
		_vObject[3].count = 0;
		_vObject[3].index = 0;
		_vObject[3].objectRect = RectMakeCenter(_vObject[3].objectX, _vObject[3].objectY, 64, 128);
		break;
	case 6:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_WHITE;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 864 + (64 * i);
			_vObject[i].createY = 800;
			_vObject[i].objectX = 864 + (64 * i);
			_vObject[i].objectY = 800;
			_vObject[i].trigger = FALSE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 3].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 3].tileType = TILE_TYPE_RED;
			_vObject[i + 3].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 3].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 3].createX = 1568 + (64 * i);
			_vObject[i + 3].createY = 800;
			_vObject[i + 3].objectX = 1568 + (64 * i);
			_vObject[i + 3].objectY = 800;
			_vObject[i + 3].trigger = FALSE;
			_vObject[i + 3].switchOn = FALSE;
			_vObject[i + 3].switchOff = FALSE;
			_vObject[i + 3].switchSoundOutput = FALSE;
			_vObject[i + 3].switchOffDelay = 0;
			_vObject[i + 3].count = 0;
			_vObject[i + 3].index = 0;
			_vObject[i + 3].objectRect = RectMakeCenter(_vObject[i + 3].objectX, _vObject[i + 3].objectY, 64, 64);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		_vObject[6].objectType = OBJECT_TYPE_SWITCH;
		_vObject[6].tileType = TILE_TYPE_NULL;
		_vObject[6].switchType = SWITCH_TYPE_GATE;
		_vObject[6].ledgeType = LEDGE_TYPE_NULL;
		_vObject[6].createX = 1696;
		_vObject[6].createY = 736;
		_vObject[6].objectX = 1696;
		_vObject[6].objectY = 736;
		_vObject[6].trigger = FALSE;
		_vObject[6].switchOn = FALSE;
		_vObject[6].switchOff = FALSE;
		_vObject[6].switchSoundOutput = FALSE;
		_vObject[6].switchOffDelay = 0;
		_vObject[6].count = 0;
		_vObject[6].index = 0;
		_vObject[6].objectRect = RectMakeCenter(_vObject[6].objectX, _vObject[6].objectY, 64, 64);
		// 흰색 타일 스위치
		_vObject[7].objectType = OBJECT_TYPE_SWITCH;
		_vObject[7].tileType = TILE_TYPE_NULL;
		_vObject[7].switchType = SWITCH_TYPE_WHITE;
		_vObject[7].ledgeType = LEDGE_TYPE_NULL;
		_vObject[7].createX = 1696;
		_vObject[7].createY = 1184;
		_vObject[7].objectX = 1696;
		_vObject[7].objectY = 1184;
		_vObject[7].trigger = FALSE;
		_vObject[7].switchOn = FALSE;
		_vObject[7].switchOff = FALSE;
		_vObject[7].switchSoundOutput = FALSE;
		_vObject[7].switchOffDelay = 0;
		_vObject[7].count = 0;
		_vObject[7].index = 0;
		_vObject[7].objectRect = RectMakeCenter(_vObject[7].objectX, _vObject[7].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[8].objectType = OBJECT_TYPE_SWITCH;
		_vObject[8].tileType = TILE_TYPE_NULL;
		_vObject[8].switchType = SWITCH_TYPE_RED;
		_vObject[8].ledgeType = LEDGE_TYPE_NULL;
		_vObject[8].createX = 864;
		_vObject[8].createY = 736;
		_vObject[8].objectX = 864;
		_vObject[8].objectY = 736;
		_vObject[8].trigger = FALSE;
		_vObject[8].switchOn = FALSE;
		_vObject[8].switchOff = FALSE;
		_vObject[8].switchSoundOutput = FALSE;
		_vObject[8].switchOffDelay = 0;
		_vObject[8].count = 0;
		_vObject[8].index = 0;
		_vObject[8].objectRect = RectMakeCenter(_vObject[8].objectX, _vObject[8].objectY, 64, 64);
		// 게이트
		_vObject[9].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[9].tileType = TILE_TYPE_NULL;
		_vObject[9].switchType = SWITCH_TYPE_NULL;
		_vObject[9].ledgeType = LEDGE_TYPE_NULL;
		_vObject[9].createX = 896;
		_vObject[9].createY = 1152;
		_vObject[9].objectX = 896;
		_vObject[9].objectY = 1152;
		_vObject[9].trigger = FALSE;
		_vObject[9].switchOn = FALSE;
		_vObject[9].switchOff = FALSE;
		_vObject[9].switchSoundOutput = FALSE;
		_vObject[9].switchOffDelay = 0;
		_vObject[9].count = 0;
		_vObject[9].index = 0;
		_vObject[9].objectRect = RectMakeCenter(_vObject[9].objectX, _vObject[9].objectY, 64, 128);
		break;
	case 7:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 6; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_WHITE;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 864 + (64 * (i % 3));
			_vObject[i].createY = 736 + (448 * (i / 3));
			_vObject[i].objectX = 864 + (64 * (i % 3));
			_vObject[i].objectY = 736 + (448 * (i / 3));
			_vObject[i].trigger = TRUE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 빨간색 타일
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 6].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 6].tileType = TILE_TYPE_RED;
			_vObject[i + 6].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 6].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 6].createX = 1504;
			_vObject[i + 6].createY = 608 + (64 * i);
			_vObject[i + 6].objectX = 1504;
			_vObject[i + 6].objectY = 608 + (64 * i);
			_vObject[i + 6].trigger = TRUE;
			_vObject[i + 6].switchOn = FALSE;
			_vObject[i + 6].switchOff = FALSE;
			_vObject[i + 6].switchSoundOutput = FALSE;
			_vObject[i + 6].switchOffDelay = 0;
			_vObject[i + 6].count = 0;
			_vObject[i + 6].index = 0;
			_vObject[i + 6].objectRect = RectMakeCenter(_vObject[i + 6].objectX, _vObject[i + 6].objectY, 64, 64);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 8].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 8].tileType = TILE_TYPE_NULL;
			_vObject[i + 8].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 8].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 8].createX = 1376 + (64 * i);
			_vObject[i + 8].createY = 880;
			_vObject[i + 8].objectX = 1376 + (64 * i);
			_vObject[i + 8].objectY = 880;
			_vObject[i + 8].trigger = FALSE;
			_vObject[i + 8].switchOn = FALSE;
			_vObject[i + 8].switchOff = FALSE;
			_vObject[i + 8].switchSoundOutput = FALSE;
			_vObject[i + 8].switchOffDelay = 0;
			_vObject[i + 8].count = 0;
			_vObject[i + 8].index = 0;
			_vObject[i + 8].objectRect = RectMakeCenter(_vObject[i + 8].objectX, _vObject[i + 8].objectY, 64, 32);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 10].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 10].tileType = TILE_TYPE_NULL;
			_vObject[i + 10].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 10].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 10].createX = 1248 + (64 * (i % 2));
			_vObject[i + 10].createY = 1136 + (256 * (i / 2));
			_vObject[i + 10].objectX = 1248 + (64 * (i % 2));
			_vObject[i + 10].objectY = 1136 + (256 * (i / 2));
			_vObject[i + 10].trigger = FALSE;
			_vObject[i + 10].switchOn = FALSE;
			_vObject[i + 10].switchOff = FALSE;
			_vObject[i + 10].switchSoundOutput = FALSE;
			_vObject[i + 10].switchOffDelay = 0;
			_vObject[i + 10].count = 0;
			_vObject[i + 10].index = 0;
			_vObject[i + 10].objectRect = RectMakeCenter(_vObject[i + 10].objectX, _vObject[i + 10].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 게이트 스위치 1
		_vObject[14].objectType = OBJECT_TYPE_SWITCH;
		_vObject[14].tileType = TILE_TYPE_NULL;
		_vObject[14].switchType = SWITCH_TYPE_GATE;
		_vObject[14].ledgeType = LEDGE_TYPE_NULL;
		_vObject[14].createX = 928;
		_vObject[14].createY = 1120;
		_vObject[14].objectX = 928;
		_vObject[14].objectY = 1120;
		_vObject[14].trigger = FALSE;
		_vObject[14].switchOn = FALSE;
		_vObject[14].switchOff = FALSE;
		_vObject[14].switchSoundOutput = FALSE;
		_vObject[14].switchOffDelay = 0;
		_vObject[14].count = 0;
		_vObject[14].index = 0;
		_vObject[14].objectRect = RectMakeCenter(_vObject[14].objectX, _vObject[14].objectY, 64, 64);
		// 게이트 스위치 2
		_vObject[15].objectType = OBJECT_TYPE_SWITCH;
		_vObject[15].tileType = TILE_TYPE_NULL;
		_vObject[15].switchType = SWITCH_TYPE_GATE;
		_vObject[15].ledgeType = LEDGE_TYPE_NULL;
		_vObject[15].createX = 928;
		_vObject[15].createY = 1376;
		_vObject[15].objectX = 928;
		_vObject[15].objectY = 1376;
		_vObject[15].trigger = FALSE;
		_vObject[15].switchOn = FALSE;
		_vObject[15].switchOff = FALSE;
		_vObject[15].switchSoundOutput = FALSE;
		_vObject[15].switchOffDelay = 0;
		_vObject[15].count = 0;
		_vObject[15].index = 0;
		_vObject[15].objectRect = RectMakeCenter(_vObject[15].objectX, _vObject[15].objectY, 64, 64);
		// 흰색 타일 스위치
		_vObject[16].objectType = OBJECT_TYPE_SWITCH;
		_vObject[16].tileType = TILE_TYPE_NULL;
		_vObject[16].switchType = SWITCH_TYPE_WHITE;
		_vObject[16].ledgeType = LEDGE_TYPE_NULL;
		_vObject[16].createX = 1248;
		_vObject[16].createY = 1248;
		_vObject[16].objectX = 1248;
		_vObject[16].objectY = 1248;
		_vObject[16].trigger = FALSE;
		_vObject[16].switchOn = FALSE;
		_vObject[16].switchOff = FALSE;
		_vObject[16].switchSoundOutput = FALSE;
		_vObject[16].switchOffDelay = 0;
		_vObject[16].count = 0;
		_vObject[16].index = 0;
		_vObject[16].objectRect = RectMakeCenter(_vObject[16].objectX, _vObject[16].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[17].objectType = OBJECT_TYPE_SWITCH;
		_vObject[17].tileType = TILE_TYPE_NULL;
		_vObject[17].switchType = SWITCH_TYPE_RED;
		_vObject[17].ledgeType = LEDGE_TYPE_NULL;
		_vObject[17].createX = 1504;
		_vObject[17].createY = 1376;
		_vObject[17].objectX = 1504;
		_vObject[17].objectY = 1376;
		_vObject[17].trigger = FALSE;
		_vObject[17].switchOn = FALSE;
		_vObject[17].switchOff = FALSE;
		_vObject[17].switchSoundOutput = FALSE;
		_vObject[17].switchOffDelay = 0;
		_vObject[17].count = 0;
		_vObject[17].index = 0;
		_vObject[17].objectRect = RectMakeCenter(_vObject[11].objectX, _vObject[11].objectY, 64, 64);
		// 발판 오브젝트
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 18].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 18].tileType = TILE_TYPE_NULL;
			_vObject[i + 18].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 18].ledgeType = LEDGE_TYPE_SHORT;
			_vObject[i + 18].createX = 1696;
			_vObject[i + 18].createY = 708 + (192 * i);
			_vObject[i + 18].objectX = 1696;
			_vObject[i + 18].objectY = 708 + (192 * i);
			_vObject[i + 18].trigger = TRUE;
			_vObject[i + 18].switchOn = FALSE;
			_vObject[i + 18].switchOff = FALSE;
			_vObject[i + 18].switchSoundOutput = FALSE;
			_vObject[i + 18].switchOffDelay = 0;
			_vObject[i + 18].count = 0;
			_vObject[i + 18].index = 0;
			_vObject[i + 18].objectRect = RectMakeCenter(_vObject[i + 18].objectX, _vObject[i + 18].objectY, 64, 8);
		}
		// 게이트
		_vObject[22].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[22].tileType = TILE_TYPE_NULL;
		_vObject[22].switchType = SWITCH_TYPE_NULL;
		_vObject[22].ledgeType = LEDGE_TYPE_NULL;
		_vObject[22].createX = 1792;
		_vObject[22].createY = 1344;
		_vObject[22].objectX = 1792;
		_vObject[22].objectY = 1344;
		_vObject[22].trigger = FALSE;
		_vObject[22].switchOn = FALSE;
		_vObject[22].switchOff = FALSE;
		_vObject[22].switchSoundOutput = FALSE;
		_vObject[22].switchOffDelay = 0;
		_vObject[22].count = 0;
		_vObject[22].index = 0;
		_vObject[22].objectRect = RectMakeCenter(_vObject[22].objectX, _vObject[22].objectY, 64, 128);
		break;
	case 8:
		// 타일 오브젝트
		// 흰색 타일 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_WHITE;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 1952;
			_vObject[i].createY = 1184 + (64 * i);
			_vObject[i].objectX = 1952;
			_vObject[i].objectY = 1184 + (64 * i);
			_vObject[i].trigger = TRUE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 흰색 타일 2
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 2].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 2].tileType = TILE_TYPE_WHITE;
			_vObject[i + 2].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 2].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 2].createX = 2784;
			_vObject[i + 2].createY = 608 + (64 * i);
			_vObject[i + 2].objectX = 2784;
			_vObject[i + 2].objectY = 608 + (64 * i);
			_vObject[i + 2].trigger = FALSE;
			_vObject[i + 2].switchOn = FALSE;
			_vObject[i + 2].switchOff = FALSE;
			_vObject[i + 2].switchSoundOutput = FALSE;
			_vObject[i + 2].switchOffDelay = 0;
			_vObject[i + 2].count = 0;
			_vObject[i + 2].index = 0;
			_vObject[i + 2].objectRect = RectMakeCenter(_vObject[i + 2].objectX, _vObject[i + 2].objectY, 64, 64);
		}
		// 빨간색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 4].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 4].tileType = TILE_TYPE_RED;
			_vObject[i + 4].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 4].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 4].createX = 1312 + (64 * i);
			_vObject[i + 4].createY = 1120;
			_vObject[i + 4].objectX = 1312 + (64 * i);
			_vObject[i + 4].objectY = 1120;
			_vObject[i + 4].trigger = FALSE;
			_vObject[i + 4].switchOn = FALSE;
			_vObject[i + 4].switchOff = FALSE;
			_vObject[i + 4].switchSoundOutput = FALSE;
			_vObject[i + 4].switchOffDelay = 0;
			_vObject[i + 4].count = 0;
			_vObject[i + 4].index = 0;
			_vObject[i + 4].objectRect = RectMakeCenter(_vObject[i + 4].objectX, _vObject[i + 4].objectY, 64, 64);
		}
		// 초록색 타일
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 7].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 7].tileType = TILE_TYPE_GREEN;
			_vObject[i + 7].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 7].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 7].createX = 1120;
			_vObject[i + 7].createY = 608 + (64 * i);
			_vObject[i + 7].objectX = 1120;
			_vObject[i + 7].objectY = 608 + (64 * i);
			_vObject[i + 7].trigger = TRUE;
			_vObject[i + 7].switchOn = FALSE;
			_vObject[i + 7].switchOff = FALSE;
			_vObject[i + 7].switchSoundOutput = FALSE;
			_vObject[i + 7].switchOffDelay = 0;
			_vObject[i + 7].count = 0;
			_vObject[i + 7].index = 0;
			_vObject[i + 7].objectRect = RectMakeCenter(_vObject[i + 7].objectX, _vObject[i + 7].objectY, 64, 64);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 10].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 10].tileType = TILE_TYPE_NULL;
			_vObject[i + 10].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 10].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 10].createX = 1312 + (64 * i);
			_vObject[i + 10].createY = 1392;
			_vObject[i + 10].objectX = 1312 + (64 * i);
			_vObject[i + 10].objectY = 1392;
			_vObject[i + 10].trigger = FALSE;
			_vObject[i + 10].switchOn = FALSE;
			_vObject[i + 10].switchOff = FALSE;
			_vObject[i + 10].switchSoundOutput = FALSE;
			_vObject[i + 10].switchOffDelay = 0;
			_vObject[i + 10].count = 0;
			_vObject[i + 10].index = 0;
			_vObject[i + 10].objectRect = RectMakeCenter(_vObject[i + 10].objectX, _vObject[i + 10].objectY, 64, 32);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 13].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 13].tileType = TILE_TYPE_NULL;
			_vObject[i + 13].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 13].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 13].createX = 1568 + (64 * i);
			_vObject[i + 13].createY = 1392;
			_vObject[i + 13].objectX = 1568 + (64 * i);
			_vObject[i + 13].objectY = 1392;
			_vObject[i + 13].trigger = FALSE;
			_vObject[i + 13].switchOn = FALSE;
			_vObject[i + 13].switchOff = FALSE;
			_vObject[i + 13].switchSoundOutput = FALSE;
			_vObject[i + 13].switchOffDelay = 0;
			_vObject[i + 13].count = 0;
			_vObject[i + 13].index = 0;
			_vObject[i + 13].objectRect = RectMakeCenter(_vObject[i + 13].objectX, _vObject[i + 13].objectY, 64, 32);
		}
		// 장애물 오브젝트 3
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 16].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 16].tileType = TILE_TYPE_NULL;
			_vObject[i + 16].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 16].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 16].createX = 1824 + (64 * i);
			_vObject[i + 16].createY = 1392;
			_vObject[i + 16].objectX = 1824 + (64 * i);
			_vObject[i + 16].objectY = 1392;
			_vObject[i + 16].trigger = FALSE;
			_vObject[i + 16].switchOn = FALSE;
			_vObject[i + 16].switchOff = FALSE;
			_vObject[i + 16].switchSoundOutput = FALSE;
			_vObject[i + 16].switchOffDelay = 0;
			_vObject[i + 16].count = 0;
			_vObject[i + 16].index = 0;
			_vObject[i + 16].objectRect = RectMakeCenter(_vObject[i + 16].objectX, _vObject[i + 16].objectY, 64, 32);
		}
		// 장애물 오브젝트 4
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 18].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 18].tileType = TILE_TYPE_NULL;
			_vObject[i + 18].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 18].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 18].createX = 2208 + (64 * i);
			_vObject[i + 18].createY = 1392;
			_vObject[i + 18].objectX = 2208 + (64 * i);
			_vObject[i + 18].objectY = 1392;
			_vObject[i + 18].trigger = FALSE;
			_vObject[i + 18].switchOn = FALSE;
			_vObject[i + 18].switchOff = FALSE;
			_vObject[i + 18].switchSoundOutput = FALSE;
			_vObject[i + 18].switchOffDelay = 0;
			_vObject[i + 18].count = 0;
			_vObject[i + 18].index = 0;
			_vObject[i + 18].objectRect = RectMakeCenter(_vObject[i + 18].objectX, _vObject[i + 18].objectY, 64, 32);
		}
		// 장애물 오브젝트 5
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 21].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 21].tileType = TILE_TYPE_NULL;
			_vObject[i + 21].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 21].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 21].createX = 1888 + (64 * i);
			_vObject[i + 21].createY = 816;
			_vObject[i + 21].objectX = 1888 + (64 * i);
			_vObject[i + 21].objectY = 816;
			_vObject[i + 21].trigger = FALSE;
			_vObject[i + 21].switchOn = FALSE;
			_vObject[i + 21].switchOff = FALSE;
			_vObject[i + 21].switchSoundOutput = FALSE;
			_vObject[i + 21].switchOffDelay = 0;
			_vObject[i + 21].count = 0;
			_vObject[i + 21].index = 0;
			_vObject[i + 21].objectRect = RectMakeCenter(_vObject[i + 21].objectX, _vObject[i + 21].objectY, 64, 32);
		}
		// 장애물 오브젝트 6
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 23].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 23].tileType = TILE_TYPE_NULL;
			_vObject[i + 23].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 23].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 23].createX = 2144 + (64 * i);
			_vObject[i + 23].createY = 816;
			_vObject[i + 23].objectX = 2144 + (64 * i);
			_vObject[i + 23].objectY = 816;
			_vObject[i + 23].trigger = FALSE;
			_vObject[i + 23].switchOn = FALSE;
			_vObject[i + 23].switchOff = FALSE;
			_vObject[i + 23].switchSoundOutput = FALSE;
			_vObject[i + 23].switchOffDelay = 0;
			_vObject[i + 23].count = 0;
			_vObject[i + 23].index = 0;
			_vObject[i + 23].objectRect = RectMakeCenter(_vObject[i + 23].objectX, _vObject[i + 23].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		_vObject[25].objectType = OBJECT_TYPE_SWITCH;
		_vObject[25].tileType = TILE_TYPE_NULL;
		_vObject[25].switchType = SWITCH_TYPE_GATE;
		_vObject[25].ledgeType = LEDGE_TYPE_NULL;
		_vObject[25].createX = 2080;
		_vObject[25].createY = 1248;
		_vObject[25].objectX = 2080;
		_vObject[25].objectY = 1248;
		_vObject[25].trigger = FALSE;
		_vObject[25].switchOn = FALSE;
		_vObject[25].switchOff = FALSE;
		_vObject[25].switchSoundOutput = FALSE;
		_vObject[25].switchOffDelay = 0;
		_vObject[25].count = 0;
		_vObject[25].index = 0;
		_vObject[25].objectRect = RectMakeCenter(_vObject[25].objectX, _vObject[25].objectY, 64, 64);
		// 흰색 타일 스위치
		_vObject[26].objectType = OBJECT_TYPE_SWITCH;
		_vObject[26].tileType = TILE_TYPE_NULL;
		_vObject[26].switchType = SWITCH_TYPE_WHITE;
		_vObject[26].ledgeType = LEDGE_TYPE_NULL;
		_vObject[26].createX = 1120;
		_vObject[26].createY = 1248;
		_vObject[26].objectX = 1120;
		_vObject[26].objectY = 1248;
		_vObject[26].trigger = FALSE;
		_vObject[26].switchOn = FALSE;
		_vObject[26].switchOff = FALSE;
		_vObject[26].switchSoundOutput = FALSE;
		_vObject[26].switchOffDelay = 0;
		_vObject[26].count = 0;
		_vObject[26].index = 0;
		_vObject[26].objectRect = RectMakeCenter(_vObject[26].objectX, _vObject[26].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[27].objectType = OBJECT_TYPE_SWITCH;
		_vObject[27].tileType = TILE_TYPE_NULL;
		_vObject[27].switchType = SWITCH_TYPE_RED;
		_vObject[27].ledgeType = LEDGE_TYPE_NULL;
		_vObject[27].createX = 2720;
		_vObject[27].createY = 672;
		_vObject[27].objectX = 2720;
		_vObject[27].objectY = 672;
		_vObject[27].trigger = FALSE;
		_vObject[27].switchOn = FALSE;
		_vObject[27].switchOff = FALSE;
		_vObject[27].switchSoundOutput = FALSE;
		_vObject[27].switchOffDelay = 0;
		_vObject[27].count = 0;
		_vObject[27].index = 0;
		_vObject[27].objectRect = RectMakeCenter(_vObject[27].objectX, _vObject[27].objectY, 64, 64);
		// 초록색 타일 스위치
		_vObject[28].objectType = OBJECT_TYPE_SWITCH;
		_vObject[28].tileType = TILE_TYPE_NULL;
		_vObject[28].switchType = SWITCH_TYPE_GREEN;
		_vObject[28].ledgeType = LEDGE_TYPE_NULL;
		_vObject[28].createX = 1376;
		_vObject[28].createY = 1056;
		_vObject[28].objectX = 1376;
		_vObject[28].objectY = 1056;
		_vObject[28].trigger = FALSE;
		_vObject[28].switchOn = FALSE;
		_vObject[28].switchOff = FALSE;
		_vObject[28].switchSoundOutput = FALSE;
		_vObject[28].switchOffDelay = 0;
		_vObject[28].count = 0;
		_vObject[28].index = 0;
		_vObject[28].objectRect = RectMakeCenter(_vObject[28].objectX, _vObject[28].objectY, 64, 64);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 29].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 29].tileType = TILE_TYPE_NULL;
			_vObject[i + 29].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 29].ledgeType = LEDGE_TYPE_NORMAL;
			_vObject[i + 29].createX = 1280 + (1152 * i);
			_vObject[i + 29].createY = 964;
			_vObject[i + 29].objectX = 1280 + (1152 * i);
			_vObject[i + 29].objectY = 964;
			_vObject[i + 29].trigger = TRUE;
			_vObject[i + 29].switchOn = FALSE;
			_vObject[i + 29].switchOff = FALSE;
			_vObject[i + 29].switchSoundOutput = FALSE;
			_vObject[i + 29].switchOffDelay = 0;
			_vObject[i + 29].count = 0;
			_vObject[i + 29].index = 0;
			_vObject[i + 29].objectRect = RectMakeCenter(_vObject[i + 29].objectX, _vObject[i + 29].objectY, 128, 8);
		}
		// 발판 오브젝트 2
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 31].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 31].tileType = TILE_TYPE_NULL;
			_vObject[i + 31].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 31].ledgeType = LEDGE_TYPE_NORMAL;
			_vObject[i + 31].createX = 2752;
			_vObject[i + 31].createY = 1028 + (192 * i);
			_vObject[i + 31].objectX = 2752;
			_vObject[i + 31].objectY = 1028 + (192 * i);
			_vObject[i + 31].trigger = TRUE;
			_vObject[i + 31].switchOn = FALSE;
			_vObject[i + 31].switchOff = FALSE;
			_vObject[i + 31].switchSoundOutput = FALSE;
			_vObject[i + 31].switchOffDelay = 0;
			_vObject[i + 31].count = 0;
			_vObject[i + 31].index = 0;
			_vObject[i + 31].objectRect = RectMakeCenter(_vObject[i + 31].objectX, _vObject[i + 31].objectY, 128, 8);
		}
		// 발판 오브젝트 3
		_vObject[33].objectType = OBJECT_TYPE_LEDGE;
		_vObject[33].tileType = TILE_TYPE_NULL;
		_vObject[33].switchType = SWITCH_TYPE_NULL;
		_vObject[33].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[33].createX = 3008;
		_vObject[33].createY = 836;
		_vObject[33].objectX = 3008;
		_vObject[33].objectY = 836;
		_vObject[33].trigger = TRUE;
		_vObject[33].switchOn = FALSE;
		_vObject[33].switchOff = FALSE;
		_vObject[33].switchSoundOutput = FALSE;
		_vObject[33].switchOffDelay = 0;
		_vObject[33].count = 0;
		_vObject[33].index = 0;
		_vObject[33].objectRect = RectMakeCenter(_vObject[33].objectX, _vObject[33].objectY, 128, 8);
		// 메세지 오브젝트
		_vObject[34].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[34].tileType = TILE_TYPE_NULL;
		_vObject[34].switchType = SWITCH_TYPE_NULL;
		_vObject[34].ledgeType = LEDGE_TYPE_NULL;
		_vObject[34].createX = 3008;
		_vObject[34].createY = 768;
		_vObject[34].objectX = 3008;
		_vObject[34].objectY = 768;
		_vObject[34].trigger = FALSE;
		_vObject[34].switchOn = FALSE;
		_vObject[34].switchOff = FALSE;
		_vObject[34].switchSoundOutput = FALSE;
		_vObject[34].switchOffDelay = 0;
		_vObject[34].count = 0;
		_vObject[34].index = 0;
		_vObject[34].objectRect = RectMakeCenter(_vObject[34].objectX, _vObject[34].objectY, 128, 128);
		// 게이트
		_vObject[35].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[35].tileType = TILE_TYPE_NULL;
		_vObject[35].switchType = SWITCH_TYPE_NULL;
		_vObject[35].ledgeType = LEDGE_TYPE_NULL;
		_vObject[35].createX = 832;
		_vObject[35].createY = 704;
		_vObject[35].objectX = 832;
		_vObject[35].objectY = 704;
		_vObject[35].trigger = FALSE;
		_vObject[35].switchOn = FALSE;
		_vObject[35].switchOff = FALSE;
		_vObject[35].switchSoundOutput = FALSE;
		_vObject[35].switchOffDelay = 0;
		_vObject[35].count = 0;
		_vObject[35].index = 0;
		_vObject[35].objectRect = RectMakeCenter(_vObject[35].objectX, _vObject[35].objectY, 64, 128);
		break;
	case 9:
		// 타일 오브젝트
		// 흰색 타일 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_WHITE;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 2400;
			_vObject[i].createY = 864 + (64 * i);
			_vObject[i].objectX = 2400;
			_vObject[i].objectY = 864 + (64 * i);
			_vObject[i].trigger = TRUE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 흰색 타일 2
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 2].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 2].tileType = TILE_TYPE_WHITE;
			_vObject[i + 2].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 2].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 2].createX = 1888;
			_vObject[i + 2].createY = 608 + (64 * i);
			_vObject[i + 2].objectX = 1888;
			_vObject[i + 2].objectY = 608 + (64 * i);
			_vObject[i + 2].trigger = TRUE;
			_vObject[i + 2].switchOn = FALSE;
			_vObject[i + 2].switchOff = FALSE;
			_vObject[i + 2].switchSoundOutput = FALSE;
			_vObject[i + 2].switchOffDelay = 0;
			_vObject[i + 2].count = 0;
			_vObject[i + 2].index = 0;
			_vObject[i + 2].objectRect = RectMakeCenter(_vObject[i + 2].objectX, _vObject[i + 2].objectY, 64, 64);
		}
		// 빨간색 타일
		for (int i = 0; i < 9; i++)
		{
			_vObject[i + 4].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 4].tileType = TILE_TYPE_RED;
			_vObject[i + 4].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 4].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 4].createX = 864 + (64 * (i % 3));
			_vObject[i + 4].createY = 736 + (192 * (i / 3));
			_vObject[i + 4].objectX = 864 + (64 * (i % 3));
			_vObject[i + 4].objectY = 736 + (192 * (i / 3));
			_vObject[i + 4].trigger = TRUE;
			_vObject[i + 4].switchOn = FALSE;
			_vObject[i + 4].switchOff = FALSE;
			_vObject[i + 4].switchSoundOutput = FALSE;
			_vObject[i + 4].switchOffDelay = 0;
			_vObject[i + 4].count = 0;
			_vObject[i + 4].index = 0;
			_vObject[i + 4].objectRect = RectMakeCenter(_vObject[i + 4].objectX, _vObject[i + 4].objectY, 64, 64);
		}
		// 초록색 타일 1
		for (int i = 0; i < 9; i++)
		{
			_vObject[i + 13].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 13].tileType = TILE_TYPE_GREEN;
			_vObject[i + 13].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 13].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 13].createX = 864 + (64 * (i % 3));
			_vObject[i + 13].createY = 800 + (192 * (i / 3));
			_vObject[i + 13].objectX = 864 + (64 * (i % 3));
			_vObject[i + 13].objectY = 800 + (192 * (i / 3));
			_vObject[i + 13].trigger = TRUE;
			_vObject[i + 13].switchOn = FALSE;
			_vObject[i + 13].switchOff = FALSE;
			_vObject[i + 13].switchSoundOutput = FALSE;
			_vObject[i + 13].switchOffDelay = 0;
			_vObject[i + 13].count = 0;
			_vObject[i + 13].index = 0;
			_vObject[i + 13].objectRect = RectMakeCenter(_vObject[i + 13].objectX, _vObject[i + 13].objectY, 64, 64);
		}
		// 초록색 타일 2
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 22].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 22].tileType = TILE_TYPE_GREEN;
			_vObject[i + 22].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 22].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 22].createX = 2144 + (64 * i);
			_vObject[i + 22].createY = 1056;
			_vObject[i + 22].objectX = 2144 + (64 * i);
			_vObject[i + 22].objectY = 1056;
			_vObject[i + 22].trigger = TRUE;
			_vObject[i + 22].switchOn = FALSE;
			_vObject[i + 22].switchOff = FALSE;
			_vObject[i + 22].switchSoundOutput = FALSE;
			_vObject[i + 22].switchOffDelay = 0;
			_vObject[i + 22].count = 0;
			_vObject[i + 22].index = 0;
			_vObject[i + 22].objectRect = RectMakeCenter(_vObject[i + 22].objectX, _vObject[i + 22].objectY, 64, 64);
		}
		// 초록색 타일 3
		_vObject[25].objectType = OBJECT_TYPE_TILE;
		_vObject[25].tileType = TILE_TYPE_GREEN;
		_vObject[25].switchType = SWITCH_TYPE_NULL;
		_vObject[25].ledgeType = LEDGE_TYPE_NULL;
		_vObject[25].createX = 1504;
		_vObject[25].createY = 1120;
		_vObject[25].objectX = 1504;
		_vObject[25].objectY = 1120;
		_vObject[25].trigger = TRUE;
		_vObject[25].switchOn = FALSE;
		_vObject[25].switchOff = FALSE;
		_vObject[25].switchSoundOutput = FALSE;
		_vObject[25].switchOffDelay = 0;
		_vObject[25].count = 0;
		_vObject[25].index = 0;
		_vObject[25].objectRect = RectMakeCenter(_vObject[25].objectX, _vObject[25].objectY, 64, 64);
		// 초록색 타일 4
		_vObject[26].objectType = OBJECT_TYPE_TILE;
		_vObject[26].tileType = TILE_TYPE_GREEN;
		_vObject[26].switchType = SWITCH_TYPE_NULL;
		_vObject[26].ledgeType = LEDGE_TYPE_NULL;
		_vObject[26].createX = 2208;
		_vObject[26].createY = 992;
		_vObject[26].objectX = 2208;
		_vObject[26].objectY = 992;
		_vObject[26].trigger = FALSE;
		_vObject[26].switchOn = FALSE;
		_vObject[26].switchOff = FALSE;
		_vObject[26].switchSoundOutput = FALSE;
		_vObject[26].switchOffDelay = 0;
		_vObject[26].count = 0;
		_vObject[26].index = 0;
		_vObject[26].objectRect = RectMakeCenter(_vObject[26].objectX, _vObject[26].objectY, 64, 64);
		// 파란색 타일 1
		for (int i = 0; i < 9; i++)
		{
			_vObject[i + 27].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 27].tileType = TILE_TYPE_BLUE;
			_vObject[i + 27].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 27].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 27].createX = 864 + (64 * (i % 3));
			_vObject[i + 27].createY = 864 + (192 * (i / 3));
			_vObject[i + 27].objectX = 864 + (64 * (i % 3));
			_vObject[i + 27].objectY = 864 + (192 * (i / 3));
			_vObject[i + 27].trigger = TRUE;
			_vObject[i + 27].switchOn = FALSE;
			_vObject[i + 27].switchOff = FALSE;
			_vObject[i + 27].switchSoundOutput = FALSE;
			_vObject[i + 27].switchOffDelay = 0;
			_vObject[i + 27].count = 0;
			_vObject[i + 27].index = 0;
			_vObject[i + 27].objectRect = RectMakeCenter(_vObject[i + 27].objectX, _vObject[i + 27].objectY, 64, 64);
		}
		// 파란색 타일 2
		_vObject[36].objectType = OBJECT_TYPE_TILE;
		_vObject[36].tileType = TILE_TYPE_BLUE;
		_vObject[36].switchType = SWITCH_TYPE_NULL;
		_vObject[36].ledgeType = LEDGE_TYPE_NULL;
		_vObject[36].createX = 1504;
		_vObject[36].createY = 1248;
		_vObject[36].objectX = 1504;
		_vObject[36].objectY = 1248;
		_vObject[36].trigger = FALSE;
		_vObject[36].switchOn = FALSE;
		_vObject[36].switchOff = FALSE;
		_vObject[36].switchSoundOutput = FALSE;
		_vObject[36].switchOffDelay = 0;
		_vObject[36].count = 0;
		_vObject[36].index = 0;
		_vObject[36].objectRect = RectMakeCenter(_vObject[36].objectX, _vObject[36].objectY, 64, 64);
		// 장애물 오브젝트 1
		for (int i = 0; i < 8; i++)
		{
			_vObject[i + 37].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 37].tileType = TILE_TYPE_NULL;
			_vObject[i + 37].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 37].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 37].createX = 2016 + (64 * (i % 2)) + (256 * (i / 2));
			_vObject[i + 37].createY = 1328;
			_vObject[i + 37].objectX = 2016 + (64 * (i % 2)) + (256 * (i / 2));
			_vObject[i + 37].objectY = 1328;
			_vObject[i + 37].trigger = FALSE;
			_vObject[i + 37].switchOn = FALSE;
			_vObject[i + 37].switchOff = FALSE;
			_vObject[i + 37].switchSoundOutput = FALSE;
			_vObject[i + 37].switchOffDelay = 0;
			_vObject[i + 37].count = 0;
			_vObject[i + 37].index = 0;
			_vObject[i + 37].objectRect = RectMakeCenter(_vObject[i + 37].objectX, _vObject[i + 37].objectY, 64, 32);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 45].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 45].tileType = TILE_TYPE_NULL;
			_vObject[i + 45].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 45].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 45].createX = 1632 + (64 * i);
			_vObject[i + 45].createY = 752;
			_vObject[i + 45].objectX = 1632 + (64 * i);
			_vObject[i + 45].objectY = 752;
			_vObject[i + 45].trigger = FALSE;
			_vObject[i + 45].switchOn = FALSE;
			_vObject[i + 45].switchOff = FALSE;
			_vObject[i + 45].switchSoundOutput = FALSE;
			_vObject[i + 45].switchOffDelay = 0;
			_vObject[i + 45].count = 0;
			_vObject[i + 45].index = 0;
			_vObject[i + 45].objectRect = RectMakeCenter(_vObject[i + 45].objectX, _vObject[i + 45].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 흰색 타일 스위치
		_vObject[48].objectType = OBJECT_TYPE_SWITCH;
		_vObject[48].tileType = TILE_TYPE_NULL;
		_vObject[48].switchType = SWITCH_TYPE_WHITE;
		_vObject[48].ledgeType = LEDGE_TYPE_NULL;
		_vObject[48].createX = 2976;
		_vObject[48].createY = 1312;
		_vObject[48].objectX = 2976;
		_vObject[48].objectY = 1312;
		_vObject[48].trigger = FALSE;
		_vObject[48].switchOn = FALSE;
		_vObject[48].switchOff = FALSE;
		_vObject[48].switchSoundOutput = FALSE;
		_vObject[48].switchOffDelay = 0;
		_vObject[48].count = 0;
		_vObject[48].index = 0;
		_vObject[48].objectRect = RectMakeCenter(_vObject[48].objectX, _vObject[48].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[49].objectType = OBJECT_TYPE_SWITCH;
		_vObject[49].tileType = TILE_TYPE_NULL;
		_vObject[49].switchType = SWITCH_TYPE_RED;
		_vObject[49].ledgeType = LEDGE_TYPE_NULL;
		_vObject[49].createX = 1504;
		_vObject[49].createY = 1184;
		_vObject[49].objectX = 1504;
		_vObject[49].objectY = 1184;
		_vObject[49].trigger = FALSE;
		_vObject[49].switchOn = FALSE;
		_vObject[49].switchOff = FALSE;
		_vObject[49].switchSoundOutput = FALSE;
		_vObject[49].switchOffDelay = 0;
		_vObject[49].count = 0;
		_vObject[49].index = 0;
		_vObject[49].objectRect = RectMakeCenter(_vObject[49].objectX, _vObject[49].objectY, 64, 64);
		// 초록색 타일 스위치
		_vObject[50].objectType = OBJECT_TYPE_SWITCH;
		_vObject[50].tileType = TILE_TYPE_NULL;
		_vObject[50].switchType = SWITCH_TYPE_GREEN;
		_vObject[50].ledgeType = LEDGE_TYPE_NULL;
		_vObject[50].createX = 1568;
		_vObject[50].createY = 672;
		_vObject[50].objectX = 1568;
		_vObject[50].objectY = 672;
		_vObject[50].trigger = FALSE;
		_vObject[50].switchOn = FALSE;
		_vObject[50].switchOff = FALSE;
		_vObject[50].switchSoundOutput = FALSE;
		_vObject[50].switchOffDelay = 0;
		_vObject[50].count = 0;
		_vObject[50].index = 0;
		_vObject[50].objectRect = RectMakeCenter(_vObject[50].objectX, _vObject[50].objectY, 64, 64);
		// 파란색 타일 스위치
		_vObject[51].objectType = OBJECT_TYPE_SWITCH;
		_vObject[51].tileType = TILE_TYPE_NULL;
		_vObject[51].switchType = SWITCH_TYPE_BLUE;
		_vObject[51].ledgeType = LEDGE_TYPE_NULL;
		_vObject[51].createX = 2208;
		_vObject[51].createY = 928;
		_vObject[51].objectX = 2208;
		_vObject[51].objectY = 928;
		_vObject[51].trigger = FALSE;
		_vObject[51].switchOn = FALSE;
		_vObject[51].switchOff = FALSE;
		_vObject[51].switchSoundOutput = FALSE;
		_vObject[51].switchOffDelay = 0;
		_vObject[51].count = 0;
		_vObject[51].index = 0;
		_vObject[51].objectRect = RectMakeCenter(_vObject[51].objectX, _vObject[51].objectY, 64, 64);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 52].objectImage = IMAGEMANAGER->findImage("Object_Ledge");
			_vObject[i + 52].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 52].tileType = TILE_TYPE_NULL;
			_vObject[i + 52].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 52].ledgeType = LEDGE_TYPE_NORMAL;
			_vObject[i + 52].createX = 1664 + (256 * i);
			_vObject[i + 52].createY = 1156;
			_vObject[i + 52].objectX = 1664 + (256 * i);
			_vObject[i + 52].objectY = 1156;
			_vObject[i + 52].trigger = TRUE;
			_vObject[i + 52].switchOn = FALSE;
			_vObject[i + 52].switchOff = FALSE;
			_vObject[i + 52].switchSoundOutput = FALSE;
			_vObject[i + 52].switchOffDelay = 0;
			_vObject[i + 52].count = 0;
			_vObject[i + 52].index = 0;
			_vObject[i + 52].objectRect = RectMakeCenter(_vObject[i + 52].objectX, _vObject[i + 52].objectY, 128, 8);
		}
		// 발판 오브젝트 2
		_vObject[54].objectType = OBJECT_TYPE_LEDGE;
		_vObject[54].tileType = TILE_TYPE_NULL;
		_vObject[54].switchType = SWITCH_TYPE_NULL;
		_vObject[54].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[54].createX = 1984;
		_vObject[54].createY = 900;
		_vObject[54].objectX = 1984;
		_vObject[54].objectY = 900;
		_vObject[54].trigger = TRUE;
		_vObject[54].switchOn = FALSE;
		_vObject[54].switchOff = FALSE;
		_vObject[54].switchSoundOutput = FALSE;
		_vObject[54].switchOffDelay = 0;
		_vObject[54].count = 0;
		_vObject[54].index = 0;
		_vObject[54].objectRect = RectMakeCenter(_vObject[54].objectX, _vObject[54].objectY, 128, 8);
		// 게이트
		_vObject[55].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[55].tileType = TILE_TYPE_NULL;
		_vObject[55].switchType = SWITCH_TYPE_NULL;
		_vObject[55].ledgeType = LEDGE_TYPE_NULL;
		_vObject[55].createX = 928;
		_vObject[55].createY = 1344;
		_vObject[55].objectX = 928;
		_vObject[55].objectY = 1344;
		_vObject[55].trigger = FALSE;
		_vObject[55].switchOn = FALSE;
		_vObject[55].switchOff = FALSE;
		_vObject[55].switchSoundOutput = FALSE;
		_vObject[55].switchOffDelay = 0;
		_vObject[55].count = 0;
		_vObject[55].index = 0;
		_vObject[55].objectRect = RectMakeCenter(_vObject[55].objectX, _vObject[55].objectY, 64, 128);
		break;
	case 10:
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 2; i++)
		{
			_vObject[i].objectType = OBJECT_TYPE_TILE;
			_vObject[i].tileType = TILE_TYPE_WHITE;
			_vObject[i].switchType = SWITCH_TYPE_NULL;
			_vObject[i].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i].createX = 2336 + (64 * i);
			_vObject[i].createY = 1120;
			_vObject[i].objectX = 2336 + (64 * i);
			_vObject[i].objectY = 1120;
			_vObject[i].trigger = TRUE;
			_vObject[i].switchOn = FALSE;
			_vObject[i].switchOff = FALSE;
			_vObject[i].switchSoundOutput = FALSE;
			_vObject[i].switchOffDelay = 0;
			_vObject[i].count = 0;
			_vObject[i].index = 0;
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		// 빨간색 타일 1
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 2].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 2].tileType = TILE_TYPE_RED;
			_vObject[i + 2].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 2].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 2].createX = 1632 - (64 * (i % 2));
			_vObject[i + 2].createY = 992 + (128 * i);
			_vObject[i + 2].objectX = 1632 - (64 * (i % 2));
			_vObject[i + 2].objectY = 992 + (128 * i);
			_vObject[i + 2].trigger = FALSE;
			_vObject[i + 2].switchOn = FALSE;
			_vObject[i + 2].switchOff = FALSE;
			_vObject[i + 2].switchSoundOutput = FALSE;
			_vObject[i + 2].switchOffDelay = 0;
			_vObject[i + 2].count = 0;
			_vObject[i + 2].index = 0;
			_vObject[i + 2].objectRect = RectMakeCenter(_vObject[i + 2].objectX, _vObject[i + 2].objectY, 64, 64);
		}
		// 빨간색 타일 2
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 5].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 5].tileType = TILE_TYPE_RED;
			_vObject[i + 5].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 5].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 5].createX = 2080 + (64 * (i % 2));
			_vObject[i + 5].createY = 992 + (128 * i);
			_vObject[i + 5].objectX = 2080 + (64 * (i % 2));
			_vObject[i + 5].objectY = 992 + (128 * i);
			_vObject[i + 5].trigger = TRUE;
			_vObject[i + 5].switchOn = FALSE;
			_vObject[i + 5].switchOff = FALSE;
			_vObject[i + 5].switchSoundOutput = FALSE;
			_vObject[i + 5].switchOffDelay = 0;
			_vObject[i + 5].count = 0;
			_vObject[i + 5].index = 0;
			_vObject[i + 5].objectRect = RectMakeCenter(_vObject[i + 5].objectX, _vObject[i + 5].objectY, 64, 64);
		}
		// 빨간색 타일 3
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 8].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 8].tileType = TILE_TYPE_RED;
			_vObject[i + 8].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 8].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 8].createX = 1120;
			_vObject[i + 8].createY = 928 + (64 * i);
			_vObject[i + 8].objectX = 1120;
			_vObject[i + 8].objectY = 928 + (64 * i);
			_vObject[i + 8].trigger = TRUE;
			_vObject[i + 8].switchOn = FALSE;
			_vObject[i + 8].switchOff = FALSE;
			_vObject[i + 8].switchSoundOutput = FALSE;
			_vObject[i + 8].switchOffDelay = 0;
			_vObject[i + 8].count = 0;
			_vObject[i + 8].index = 0;
			_vObject[i + 8].objectRect = RectMakeCenter(_vObject[i + 8].objectX, _vObject[i + 8].objectY, 64, 64);
		}
		// 빨간색 타일 5
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 12].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 12].tileType = TILE_TYPE_RED;
			_vObject[i + 12].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 12].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 12].createX = 2336 + (64 * i);
			_vObject[i + 12].createY = 992;
			_vObject[i + 12].objectX = 2336 + (64 * i);
			_vObject[i + 12].objectY = 992;
			_vObject[i + 12].trigger = TRUE;
			_vObject[i + 12].switchOn = FALSE;
			_vObject[i + 12].switchOff = FALSE;
			_vObject[i + 12].switchSoundOutput = FALSE;
			_vObject[i + 12].switchOffDelay = 0;
			_vObject[i + 12].count = 0;
			_vObject[i + 12].index = 0;
			_vObject[i + 12].objectRect = RectMakeCenter(_vObject[i + 12].objectX, _vObject[i + 12].objectY, 64, 64);
		}
		// 초록색 타일 1
		for (int i = 0; i < 6; i++)
		{
			_vObject[i + 14].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 14].tileType = TILE_TYPE_GREEN;
			_vObject[i + 14].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 14].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 14].createX = 2592 + (256 * (i / 3));
			_vObject[i + 14].createY = 736 + (64 * (i % 3));
			_vObject[i + 14].objectX = 2592 + (256 * (i / 3));
			_vObject[i + 14].objectY = 736 + (64 * (i % 3));
			_vObject[i + 14].trigger = FALSE;
			_vObject[i + 14].switchOn = FALSE;
			_vObject[i + 14].switchOff = FALSE;
			_vObject[i + 14].switchSoundOutput = FALSE;
			_vObject[i + 14].switchOffDelay = 0;
			_vObject[i + 14].count = 0;
			_vObject[i + 14].index = 0;
			_vObject[i + 14].objectRect = RectMakeCenter(_vObject[i + 14].objectX, _vObject[i + 14].objectY, 64, 64);
		}
		// 초록색 타일 2
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 20].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 20].tileType = TILE_TYPE_GREEN;
			_vObject[i + 20].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 20].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 20].createX = 2656 + (64 * (i % 3));
			_vObject[i + 20].createY = 864;
			_vObject[i + 20].objectX = 2656 + (64 * (i % 3));
			_vObject[i + 20].objectY = 864;
			_vObject[i + 20].trigger = FALSE;
			_vObject[i + 20].switchOn = FALSE;
			_vObject[i + 20].switchOff = FALSE;
			_vObject[i + 20].switchSoundOutput = FALSE;
			_vObject[i + 20].switchOffDelay = 0;
			_vObject[i + 20].count = 0;
			_vObject[i + 20].index = 0;
			_vObject[i + 20].objectRect = RectMakeCenter(_vObject[i + 20].objectX, _vObject[i + 20].objectY, 64, 64);
		}
		// 초록색 타일 3
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 23].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 23].tileType = TILE_TYPE_GREEN;
			_vObject[i + 23].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 23].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 23].createX = 2656 + (64 * (i % 3));
			_vObject[i + 23].createY = 672;
			_vObject[i + 23].objectX = 2656 + (64 * (i % 3));
			_vObject[i + 23].objectY = 672;
			_vObject[i + 23].trigger = TRUE;
			_vObject[i + 23].switchOn = FALSE;
			_vObject[i + 23].switchOff = FALSE;
			_vObject[i + 23].switchSoundOutput = FALSE;
			_vObject[i + 23].switchOffDelay = 0;
			_vObject[i + 23].count = 0;
			_vObject[i + 23].index = 0;
			_vObject[i + 23].objectRect = RectMakeCenter(_vObject[i + 23].objectX, _vObject[i + 23].objectY, 64, 64);
		}
		// 파란색 타일
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 26].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 26].tileType = TILE_TYPE_BLUE;
			_vObject[i + 26].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 26].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 26].createX = 1312;
			_vObject[i + 26].createY = 608 + (64 * i);
			_vObject[i + 26].objectX = 1312;
			_vObject[i + 26].objectY = 608 + (64 * i);
			_vObject[i + 26].trigger = TRUE;
			_vObject[i + 26].switchOn = FALSE;
			_vObject[i + 26].switchOff = FALSE;
			_vObject[i + 26].switchSoundOutput = FALSE;
			_vObject[i + 26].switchOffDelay = 0;
			_vObject[i + 26].count = 0;
			_vObject[i + 26].index = 0;
			_vObject[i + 26].objectRect = RectMakeCenter(_vObject[i + 26].objectX, _vObject[i + 26].objectY, 64, 64);
		}
		// 장애물 오브젝트 1
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 30].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 30].tileType = TILE_TYPE_NULL;
			_vObject[i + 30].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 30].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 30].createX = 736 + (64 * (i % 2)) + (256 * (i / 2));
			_vObject[i + 30].createY = 1392;
			_vObject[i + 30].objectX = 736 + (64 * (i % 2)) + (256 * (i / 2));
			_vObject[i + 30].objectY = 1392;
			_vObject[i + 30].trigger = FALSE;
			_vObject[i + 30].switchOn = FALSE;
			_vObject[i + 30].switchOff = FALSE;
			_vObject[i + 30].switchSoundOutput = FALSE;
			_vObject[i + 30].switchOffDelay = 0;
			_vObject[i + 30].count = 0;
			_vObject[i + 30].index = 0;
			_vObject[i + 30].objectRect = RectMakeCenter(_vObject[i + 30].objectX, _vObject[i + 30].objectY, 64, 32);
		}
		// 장애물 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 34].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 34].tileType = TILE_TYPE_NULL;
			_vObject[i + 34].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 34].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 34].createX = 1120 + (64 * i);
			_vObject[i + 34].createY = 1200 - (128 * (i / 2));
			_vObject[i + 34].objectX = 1120 + (64 * i);
			_vObject[i + 34].objectY = 1200 - (128 * (i / 2));
			_vObject[i + 34].trigger = FALSE;
			_vObject[i + 34].switchOn = FALSE;
			_vObject[i + 34].switchOff = FALSE;
			_vObject[i + 34].switchSoundOutput = FALSE;
			_vObject[i + 34].switchOffDelay = 0;
			_vObject[i + 34].count = 0;
			_vObject[i + 34].index = 0;
			_vObject[i + 34].objectRect = RectMakeCenter(_vObject[i + 34].objectX, _vObject[i + 34].objectY, 64, 32);
		}
		// 장애물 오브젝트 3
		for (int i = 0; i < 3; i++)
		{
			_vObject[i + 38].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 38].tileType = TILE_TYPE_NULL;
			_vObject[i + 38].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 38].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 38].createX = 2592 + (64 * i);
			_vObject[i + 38].createY = 1392;
			_vObject[i + 38].objectX = 2592 + (64 * i);
			_vObject[i + 38].objectY = 1392;
			_vObject[i + 38].trigger = FALSE;
			_vObject[i + 38].switchOn = FALSE;
			_vObject[i + 38].switchOff = FALSE;
			_vObject[i + 38].switchSoundOutput = FALSE;
			_vObject[i + 38].switchOffDelay = 0;
			_vObject[i + 38].count = 0;
			_vObject[i + 38].index = 0;
			_vObject[i + 38].objectRect = RectMakeCenter(_vObject[i + 38].objectX, _vObject[i + 38].objectY, 64, 32);
		}
		// 장애물 오브젝트 4
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 41].objectType = OBJECT_TYPE_OBSTACLE;
			_vObject[i + 41].tileType = TILE_TYPE_NULL;
			_vObject[i + 41].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 41].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 41].createX = 2912 + (64 * i);
			_vObject[i + 41].createY = 1392;
			_vObject[i + 41].objectX = 2912 + (64 * i);
			_vObject[i + 41].objectY = 1392;
			_vObject[i + 41].trigger = FALSE;
			_vObject[i + 41].switchOn = FALSE;
			_vObject[i + 41].switchOff = FALSE;
			_vObject[i + 41].switchSoundOutput = FALSE;
			_vObject[i + 41].switchOffDelay = 0;
			_vObject[i + 41].count = 0;
			_vObject[i + 41].index = 0;
			_vObject[i + 41].objectRect = RectMakeCenter(_vObject[i + 41].objectX, _vObject[i + 41].objectY, 64, 32);
		}
		// 스위치 오브젝트
		// 게이트 스위치
		_vObject[43].objectType = OBJECT_TYPE_SWITCH;
		_vObject[43].tileType = TILE_TYPE_NULL;
		_vObject[43].switchType = SWITCH_TYPE_GATE;
		_vObject[43].ledgeType = LEDGE_TYPE_NULL;
		_vObject[43].createX = 1184;
		_vObject[43].createY = 800;
		_vObject[43].objectX = 1184;
		_vObject[43].objectY = 800;
		_vObject[43].trigger = FALSE;
		_vObject[43].switchOn = FALSE;
		_vObject[43].switchOff = FALSE;
		_vObject[43].switchSoundOutput = FALSE;
		_vObject[43].switchOffDelay = 0;
		_vObject[43].count = 0;
		_vObject[43].index = 0;
		_vObject[43].objectRect = RectMakeCenter(_vObject[43].objectX, _vObject[43].objectY, 64, 64);
		// 흰색 타일 스위치
		_vObject[44].objectType = OBJECT_TYPE_SWITCH;
		_vObject[44].tileType = TILE_TYPE_NULL;
		_vObject[44].switchType = SWITCH_TYPE_WHITE;
		_vObject[44].ledgeType = LEDGE_TYPE_NULL;
		_vObject[44].createX = 2528;
		_vObject[44].createY = 1376;
		_vObject[44].objectX = 2528;
		_vObject[44].objectY = 1376;
		_vObject[44].trigger = FALSE;
		_vObject[44].switchOn = FALSE;
		_vObject[44].switchOff = FALSE;
		_vObject[44].switchSoundOutput = FALSE;
		_vObject[44].switchOffDelay = 0;
		_vObject[44].count = 0;
		_vObject[44].index = 0;
		_vObject[44].objectRect = RectMakeCenter(_vObject[44].objectX, _vObject[44].objectY, 64, 64);
		// 빨간색 타일 스위치
		_vObject[45].objectType = OBJECT_TYPE_SWITCH;
		_vObject[45].tileType = TILE_TYPE_NULL;
		_vObject[45].switchType = SWITCH_TYPE_RED;
		_vObject[45].ledgeType = LEDGE_TYPE_NULL;
		_vObject[45].createX = 2144;
		_vObject[45].createY = 1376;
		_vObject[45].objectX = 2144;
		_vObject[45].objectY = 1376;
		_vObject[45].trigger = FALSE;
		_vObject[45].switchOn = FALSE;
		_vObject[45].switchOff = FALSE;
		_vObject[45].switchSoundOutput = FALSE;
		_vObject[45].switchOffDelay = 0;
		_vObject[45].count = 0;
		_vObject[45].index = 0;
		_vObject[45].objectRect = RectMakeCenter(_vObject[45].objectX, _vObject[45].objectY, 64, 64);
		// 초록색 타일 스위치
		_vObject[46].objectType = OBJECT_TYPE_SWITCH;
		_vObject[46].tileType = TILE_TYPE_NULL;
		_vObject[46].switchType = SWITCH_TYPE_GREEN;
		_vObject[46].ledgeType = LEDGE_TYPE_NULL;
		_vObject[46].createX = 2368;
		_vObject[46].createY = 1376;
		_vObject[46].objectX = 2368;
		_vObject[46].objectY = 1376;
		_vObject[46].trigger = FALSE;
		_vObject[46].switchOn = FALSE;
		_vObject[46].switchOff = FALSE;
		_vObject[46].switchSoundOutput = FALSE;
		_vObject[46].switchOffDelay = 0;
		_vObject[46].count = 0;
		_vObject[46].index = 0;
		_vObject[46].objectRect = RectMakeCenter(_vObject[46].objectX, _vObject[46].objectY, 64, 64);
		// 파란색 타일 스위치
		_vObject[47].objectType = OBJECT_TYPE_SWITCH;
		_vObject[47].tileType = TILE_TYPE_NULL;
		_vObject[47].switchType = SWITCH_TYPE_BLUE;
		_vObject[47].ledgeType = LEDGE_TYPE_NULL;
		_vObject[47].createX = 2720;
		_vObject[47].createY = 800;
		_vObject[47].objectX = 2720;
		_vObject[47].objectY = 800;
		_vObject[47].trigger = FALSE;
		_vObject[47].switchOn = FALSE;
		_vObject[47].switchOff = FALSE;
		_vObject[47].switchSoundOutput = FALSE;
		_vObject[47].switchOffDelay = 0;
		_vObject[47].count = 0;
		_vObject[47].index = 0;
		_vObject[47].objectRect = RectMakeCenter(_vObject[47].objectX, _vObject[47].objectY, 64, 64);
		// 발판 오브젝트 1
		for (int i = 0; i < 2; i++)
		{
			_vObject[i + 48].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 48].tileType = TILE_TYPE_NULL;
			_vObject[i + 48].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 48].ledgeType = LEDGE_TYPE_NORMAL;
			_vObject[i + 48].createX = 1600 + (384 * i);
			_vObject[i + 48].createY = 836;
			_vObject[i + 48].objectX = 1600 + (384 * i);
			_vObject[i + 48].objectY = 836;
			_vObject[i + 48].trigger = TRUE;
			_vObject[i + 48].switchOn = FALSE;
			_vObject[i + 48].switchOff = FALSE;
			_vObject[i + 48].switchSoundOutput = FALSE;
			_vObject[i + 48].switchOffDelay = 0;
			_vObject[i + 48].count = 0;
			_vObject[i + 48].index = 0;
			_vObject[i + 48].objectRect = RectMakeCenter(_vObject[i + 48].objectX, _vObject[i + 48].objectY, 128, 8);
		}
		// 발판 오브젝트 2
		for (int i = 0; i < 4; i++)
		{
			_vObject[i + 50].objectType = OBJECT_TYPE_LEDGE;
			_vObject[i + 50].tileType = TILE_TYPE_NULL;
			_vObject[i + 50].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 50].ledgeType = LEDGE_TYPE_NORMAL;
			_vObject[i + 50].createX = 3072;
			_vObject[i + 50].createY = 708 + (192 * i);
			_vObject[i + 50].objectX = 3072;
			_vObject[i + 50].objectY = 708 + (192 * i);
			_vObject[i + 50].trigger = TRUE;
			_vObject[i + 50].switchOn = FALSE;
			_vObject[i + 50].switchOff = FALSE;
			_vObject[i + 50].switchSoundOutput = FALSE;
			_vObject[i + 50].switchOffDelay = 0;
			_vObject[i + 50].count = 0;
			_vObject[i + 50].index = 0;
			_vObject[i + 50].objectRect = RectMakeCenter(_vObject[i + 50].objectX, _vObject[i + 50].objectY, 128, 8);
		}
		// 게이트
		_vObject[54].objectType = OBJECT_TYPE_CLOSEGATE;
		_vObject[54].tileType = TILE_TYPE_NULL;
		_vObject[54].switchType = SWITCH_TYPE_NULL;
		_vObject[54].ledgeType = LEDGE_TYPE_NULL;
		_vObject[54].createX = 896;
		_vObject[54].createY = 1092;
		_vObject[54].objectX = 896;
		_vObject[54].objectY = 1092;
		_vObject[54].trigger = FALSE;
		_vObject[54].switchOn = FALSE;
		_vObject[54].switchOff = FALSE;
		_vObject[54].switchSoundOutput = FALSE;
		_vObject[54].switchOffDelay = 0;
		_vObject[54].count = 0;
		_vObject[54].index = 0;
		_vObject[54].objectRect = RectMakeCenter(_vObject[54].objectX, _vObject[54].objectY, 64, 128);
		break;
	}

	// 기타 변수 초기화
	setAlpha(_alpha);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);

	// 초기화 종료
	return S_OK;
}

// 스테이지 5 전용 재초기화 (initStage5)
HRESULT object::initStage5(int _initCount, int _alpha)
{
	if (_initCount == 0)
	{
		// 발판 오브젝트
		_vObject[0].objectType = OBJECT_TYPE_LEDGE;
		_vObject[0].tileType = TILE_TYPE_NULL;
		_vObject[0].switchType = SWITCH_TYPE_NULL;
		_vObject[0].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[0].createX = 768;
		_vObject[0].createY = 772;
		_vObject[0].objectX = 768;
		_vObject[0].objectY = 772;
		_vObject[0].trigger = TRUE;
		_vObject[0].switchOn = FALSE;
		_vObject[0].switchOff = FALSE;
		_vObject[0].switchSoundOutput = FALSE;
		_vObject[0].switchOffDelay = 0;
		_vObject[0].count = 0;
		_vObject[0].index = 0;
		_vObject[0].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 128, 8);
		// 메세지 오브젝트 1
		_vObject[1].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[1].tileType = TILE_TYPE_NULL;
		_vObject[1].switchType = SWITCH_TYPE_NULL;
		_vObject[1].ledgeType = LEDGE_TYPE_NULL;
		_vObject[1].createX = 768;
		_vObject[1].createY = 704;
		_vObject[1].objectX = 768;
		_vObject[1].objectY = 704;
		_vObject[1].trigger = FALSE;
		_vObject[1].switchOn = FALSE;
		_vObject[1].switchOff = FALSE;
		_vObject[1].switchSoundOutput = FALSE;
		_vObject[1].switchOffDelay = 0;
		_vObject[1].count = 0;
		_vObject[1].index = 0;
		_vObject[1].objectRect = RectMakeCenter(_vObject[1].objectX, _vObject[1].objectY, 128, 128);
		// 메세지 오브젝트 2
		_vObject[2].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[2].tileType = TILE_TYPE_NULL;
		_vObject[2].switchType = SWITCH_TYPE_NULL;
		_vObject[2].ledgeType = LEDGE_TYPE_NULL;
		_vObject[2].createX = 1280;
		_vObject[2].createY = 1344;
		_vObject[2].objectX = 1280;
		_vObject[2].objectY = 1344;
		_vObject[2].trigger = FALSE;
		_vObject[2].switchOn = FALSE;
		_vObject[2].switchOff = FALSE;
		_vObject[2].switchSoundOutput = FALSE;
		_vObject[2].switchOffDelay = 0;
		_vObject[2].count = 0;
		_vObject[2].index = 0;
		_vObject[2].objectRect = RectMakeCenter(_vObject[2].objectX, _vObject[2].objectY, 128, 128);
		// 게이트
		_vObject[3].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[3].tileType = TILE_TYPE_NULL;
		_vObject[3].switchType = SWITCH_TYPE_NULL;
		_vObject[3].ledgeType = LEDGE_TYPE_NULL;
		_vObject[3].createX = 1792;
		_vObject[3].createY = 896;
		_vObject[3].objectX = 1792;
		_vObject[3].objectY = 896;
		_vObject[3].trigger = FALSE;
		_vObject[3].switchOn = FALSE;
		_vObject[3].switchOff = FALSE;
		_vObject[3].switchSoundOutput = FALSE;
		_vObject[3].switchOffDelay = 0;
		_vObject[3].count = 0;
		_vObject[3].index = 0;
		_vObject[3].objectRect = RectMakeCenter(_vObject[3].objectX, _vObject[3].objectY, 64, 128);
	}
	else if (_initCount == 1)
	{
		// 발판 오브젝트
		_vObject[0].objectType = OBJECT_TYPE_LEDGE;
		_vObject[0].tileType = TILE_TYPE_NULL;
		_vObject[0].switchType = SWITCH_TYPE_NULL;
		_vObject[0].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[0].createX = 768;
		_vObject[0].createY = 772;
		_vObject[0].objectX = 768;
		_vObject[0].objectY = 772;
		_vObject[0].trigger = TRUE;
		_vObject[0].switchOn = FALSE;
		_vObject[0].switchOff = FALSE;
		_vObject[0].switchSoundOutput = FALSE;
		_vObject[0].switchOffDelay = 0;
		_vObject[0].count = 0;
		_vObject[0].index = 0;
		_vObject[0].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 128, 8);
		// 메세지 오브젝트 1
		_vObject[1].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[1].tileType = TILE_TYPE_NULL;
		_vObject[1].switchType = SWITCH_TYPE_NULL;
		_vObject[1].ledgeType = LEDGE_TYPE_NULL;
		_vObject[1].createX = 768;
		_vObject[1].createY = 704;
		_vObject[1].objectX = 768;
		_vObject[1].objectY = 704;
		_vObject[1].trigger = FALSE;
		_vObject[1].switchOn = FALSE;
		_vObject[1].switchOff = FALSE;
		_vObject[1].switchSoundOutput = FALSE;
		_vObject[1].switchOffDelay = 0;
		_vObject[1].count = 0;
		_vObject[1].index = 0;
		_vObject[1].objectRect = RectMakeCenter(_vObject[1].objectX, _vObject[1].objectY, 128, 128);
		// 메세지 오브젝트 2
		_vObject[2].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[2].tileType = TILE_TYPE_NULL;
		_vObject[2].switchType = SWITCH_TYPE_NULL;
		_vObject[2].ledgeType = LEDGE_TYPE_NULL;
		_vObject[2].createX = 1280;
		_vObject[2].createY = 1344;
		_vObject[2].objectX = 1280;
		_vObject[2].objectY = 1344;
		_vObject[2].trigger = FALSE;
		_vObject[2].switchOn = FALSE;
		_vObject[2].switchOff = FALSE;
		_vObject[2].switchSoundOutput = FALSE;
		_vObject[2].switchOffDelay = 0;
		_vObject[2].count = 0;
		_vObject[2].index = 0;
		_vObject[2].objectRect = RectMakeCenter(_vObject[2].objectX, _vObject[2].objectY, 128, 128);
		// 게이트
		_vObject[3].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[3].tileType = TILE_TYPE_NULL;
		_vObject[3].switchType = SWITCH_TYPE_NULL;
		_vObject[3].ledgeType = LEDGE_TYPE_NULL;
		_vObject[3].createX = 1792;
		_vObject[3].createY = 896;
		_vObject[3].objectX = 1792;
		_vObject[3].objectY = 896;
		_vObject[3].trigger = FALSE;
		_vObject[3].switchOn = FALSE;
		_vObject[3].switchOff = FALSE;
		_vObject[3].switchSoundOutput = FALSE;
		_vObject[3].switchOffDelay = 0;
		_vObject[3].count = 0;
		_vObject[3].index = 0;
		_vObject[3].objectRect = RectMakeCenter(_vObject[3].objectX, _vObject[3].objectY, 64, 128);

		// 구조체 초기화
		tagObject object;
		ZeroMemory(&object, sizeof(object));

		// 흰색 타일
		for (int i = 0; i < 10; i++)
		{
			object.objectImage = IMAGEMANAGER->findImage("Object_SwitchTile");
			object.objectType = OBJECT_TYPE_TILE;
			object.tileType = TILE_TYPE_WHITE;
			object.switchType = SWITCH_TYPE_NULL;
			object.ledgeType = LEDGE_TYPE_NULL;
			object.createX = 992 + (64 * i);
			object.createY = 992;
			object.objectX = 992 + (64 * i);
			object.objectY = 992;
			object.trigger = TRUE;
			object.switchOn = FALSE;
			object.switchOff = FALSE;
			object.switchSoundOutput = FALSE;
			object.switchOffDelay = 0;
			object.count = 0;
			object.index = 0;
			object.objectRect = RectMakeCenter(object.objectX, object.objectY, 64, 64);
			_vObject.push_back(object);
		}
	}
	else
	{
		// 발판 오브젝트
		_vObject[0].objectType = OBJECT_TYPE_LEDGE;
		_vObject[0].tileType = TILE_TYPE_NULL;
		_vObject[0].switchType = SWITCH_TYPE_NULL;
		_vObject[0].ledgeType = LEDGE_TYPE_NORMAL;
		_vObject[0].createX = 768;
		_vObject[0].createY = 772;
		_vObject[0].objectX = 768;
		_vObject[0].objectY = 772;
		_vObject[0].trigger = TRUE;
		_vObject[0].switchOn = FALSE;
		_vObject[0].switchOff = FALSE;
		_vObject[0].switchSoundOutput = FALSE;
		_vObject[0].switchOffDelay = 0;
		_vObject[0].count = 0;
		_vObject[0].index = 0;
		_vObject[0].objectRect = RectMakeCenter(_vObject[0].objectX, _vObject[0].objectY, 128, 8);
		// 메세지 오브젝트 1
		_vObject[1].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[1].tileType = TILE_TYPE_NULL;
		_vObject[1].switchType = SWITCH_TYPE_NULL;
		_vObject[1].ledgeType = LEDGE_TYPE_NULL;
		_vObject[1].createX = 768;
		_vObject[1].createY = 704;
		_vObject[1].objectX = 768;
		_vObject[1].objectY = 704;
		_vObject[1].trigger = FALSE;
		_vObject[1].switchOn = FALSE;
		_vObject[1].switchOff = FALSE;
		_vObject[1].switchSoundOutput = FALSE;
		_vObject[1].switchOffDelay = 0;
		_vObject[1].count = 0;
		_vObject[1].index = 0;
		_vObject[1].objectRect = RectMakeCenter(_vObject[1].objectX, _vObject[1].objectY, 128, 128);
		// 메세지 오브젝트 2
		_vObject[2].objectType = OBJECT_TYPE_MESSAGE;
		_vObject[2].tileType = TILE_TYPE_NULL;
		_vObject[2].switchType = SWITCH_TYPE_NULL;
		_vObject[2].ledgeType = LEDGE_TYPE_NULL;
		_vObject[2].createX = 1280;
		_vObject[2].createY = 1344;
		_vObject[2].objectX = 1280;
		_vObject[2].objectY = 1344;
		_vObject[2].trigger = FALSE;
		_vObject[2].switchOn = FALSE;
		_vObject[2].switchOff = FALSE;
		_vObject[2].switchSoundOutput = FALSE;
		_vObject[2].switchOffDelay = 0;
		_vObject[2].count = 0;
		_vObject[2].index = 0;
		_vObject[2].objectRect = RectMakeCenter(_vObject[2].objectX, _vObject[2].objectY, 128, 128);
		// 게이트
		_vObject[3].objectType = OBJECT_TYPE_AUTOGATE;
		_vObject[3].tileType = TILE_TYPE_NULL;
		_vObject[3].switchType = SWITCH_TYPE_NULL;
		_vObject[3].ledgeType = LEDGE_TYPE_NULL;
		_vObject[3].createX = 1792;
		_vObject[3].createY = 896;
		_vObject[3].objectX = 1792;
		_vObject[3].objectY = 896;
		_vObject[3].trigger = FALSE;
		_vObject[3].switchOn = FALSE;
		_vObject[3].switchOff = FALSE;
		_vObject[3].switchSoundOutput = FALSE;
		_vObject[3].switchOffDelay = 0;
		_vObject[3].count = 0;
		_vObject[3].index = 0;
		_vObject[3].objectRect = RectMakeCenter(_vObject[3].objectX, _vObject[3].objectY, 64, 128);
		// 타일 오브젝트
		// 흰색 타일
		for (int i = 0; i < 10; i++)
		{
			_vObject[i + 4].objectType = OBJECT_TYPE_TILE;
			_vObject[i + 4].tileType = TILE_TYPE_WHITE;
			_vObject[i + 4].switchType = SWITCH_TYPE_NULL;
			_vObject[i + 4].ledgeType = LEDGE_TYPE_NULL;
			_vObject[i + 4].createX = 992 + (64 * i);
			_vObject[i + 4].createY = 992;
			_vObject[i + 4].objectX = 992 + (64 * i);
			_vObject[i + 4].objectY = 992;
			_vObject[i + 4].trigger = TRUE;
			_vObject[i + 4].switchOn = FALSE;
			_vObject[i + 4].switchOff = FALSE;
			_vObject[i + 4].switchSoundOutput = FALSE;
			_vObject[i + 4].switchOffDelay = 0;
			_vObject[i + 4].count = 0;
			_vObject[i + 4].index = 0;
			_vObject[i + 4].objectRect = RectMakeCenter(_vObject[i + 4].objectX, _vObject[i + 4].objectY, 64, 64);
		}
	}

	// 기타 변수 초기화
	setAlpha(_alpha);
	setCurrentStage(0);
	setCurrentStageWidth(0);
	setCurrentStageHeight(0);
	setStageStart(TRUE);
	setStageCleared(FALSE);

	return S_OK;
}

// 해제 (release)
void object::release()
{
}

// 업데이트 (update)
void object::update()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		// 플레이어의 위치에 따른 지형물 좌표값 갱신
		if (getPlayerAdress()->getMapX() >= (WINSIZEX / 2) && getPlayerAdress()->getMapX() <= getCurrentStageWidth() - (WINSIZEX / 2))
		{
			_vObject[i].objectX = _vObject[i].createX - (getPlayerAdress()->getMapX() - (WINSIZEX / 2));
		}
		if (getPlayerAdress()->getMapY() >= (WINSIZEY / 2) && getPlayerAdress()->getMapY() <= getCurrentStageHeight() - (WINSIZEY / 2))
		{
			_vObject[i].objectY = _vObject[i].createY - (getPlayerAdress()->getMapY() - (WINSIZEY / 2));
		}

		// 지형물 RECT 생성
		if (_vObject[i].objectType == OBJECT_TYPE_TILE || _vObject[i].objectType == OBJECT_TYPE_SWITCH)
		{
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 64);
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_OBSTACLE)
		{
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 32);
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_MESSAGE)
		{
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 128, 128);
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_AUTOGATE || _vObject[i].objectType == OBJECT_TYPE_CLOSEGATE)
		{
			_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 128);
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_LEDGE)
		{
			switch (_vObject[i].ledgeType)
			{
			case LEDGE_TYPE_SHORT:
				_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 64, 8);
				break;
			case LEDGE_TYPE_NORMAL:
				_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 128, 8);
				break;
			case LEDGE_TYPE_LONG:
				_vObject[i].objectRect = RectMakeCenter(_vObject[i].objectX, _vObject[i].objectY, 192, 8);
				break;
			}
		}

		// 스위치 OFF 딜레이 증가
		if (_vObject[i].switchOff == TRUE)
		{
			_vObject[i].switchOffDelay++;
		}
		else
		{
			_vObject[i].switchOffDelay = 0;
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

	// 애니메이션 출력
	this->animation();
}

// 렌더 (render)
void object::render()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		if (_vObject[i].objectType == OBJECT_TYPE_TILE)
		{
			switch (_vObject[i].tileType)
			{
			case TILE_TYPE_WHITE:
				if (_vObject[i].trigger == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 0, 64, 64, getAlpha());
				}
				else if (_vObject[i].trigger == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 0, 64, 64, getAlpha());
				}
				break;
			case TILE_TYPE_RED:
				if (_vObject[i].trigger == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 64, 64, 64, getAlpha());
				}
				else if (_vObject[i].trigger == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 64, 64, 64, getAlpha());
				}
				break;
			case TILE_TYPE_GREEN:
				if (_vObject[i].trigger == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 128, 64, 64, getAlpha());
				}
				else if (_vObject[i].trigger == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 128, 64, 64, getAlpha());
				}
				break;
			case TILE_TYPE_BLUE:
				if (_vObject[i].trigger == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 192, 64, 64, getAlpha());
				}
				else if (_vObject[i].trigger == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 192, 64, 64, getAlpha());
				}
				break;
			}
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_SWITCH)
		{
			switch (_vObject[i].switchType)
			{
			case SWITCH_TYPE_GATE:
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 0, 64, 64, getAlpha());
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 0, 64, 64, getAlpha());
				}
				break;
			case SWITCH_TYPE_WHITE:
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 64, 64, 64, getAlpha());
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 64, 64, 64, getAlpha());
				}
				break;
			case SWITCH_TYPE_RED:
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 128, 64, 64, getAlpha());
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 128, 64, 64, getAlpha());
				}
				break;
			case SWITCH_TYPE_GREEN:
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 192, 64, 64, getAlpha());
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 192, 64, 64, getAlpha());
				}
				break;
			case SWITCH_TYPE_BLUE:
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 256, 64, 64, getAlpha());
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 64, 256, 64, 64, getAlpha());
				}
				break;
			}
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_LEDGE)
		{
			switch (_vObject[i].ledgeType)
			{
			case LEDGE_TYPE_SHORT:
				_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 0, 64, 8, getAlpha());
				break;
			case LEDGE_TYPE_NORMAL:
				_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 8, 128, 8, getAlpha());
				break;
			case LEDGE_TYPE_LONG:
				_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 16, 192, 8, getAlpha());
				break;
			}
			Rectangle(getMemDC(), _vObject[i].objectRect);
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_OBSTACLE)
		{
			_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top - 32, getAlpha());
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_MESSAGE)
		{
			_vObject[i].objectImage->frameAlphaRender(getMemDC(), _vObject[i].objectRect.left, _vObject[i].objectRect.top, 0, 0, 128, 128, 18, 1, getAlpha());
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_AUTOGATE)
		{
			_vObject[i].objectImage->alphaRender(getMemDC(), _vObject[i].objectRect.left - 32, _vObject[i].objectRect.top, getAlpha());
		}
		else if (_vObject[i].objectType == OBJECT_TYPE_CLOSEGATE)
		{
			_vObject[i].objectImage->frameAlphaRender(getMemDC(), _vObject[i].objectRect.left - 32, _vObject[i].objectRect.top, 0, 0, 128, 128, 6, 1, getAlpha());
		}
	}
}

// 애니메이션 (animation)
void object::animation()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		switch (_vObject[i].objectType)
		{
		case OBJECT_TYPE_TILE: case OBJECT_TYPE_OBSTACLE: case OBJECT_TYPE_SWITCH: case OBJECT_TYPE_AUTOGATE:
			_vObject[i].objectImage->setFrameY(0);
			_vObject[i].objectImage->setFrameX(0);
			break;
		case OBJECT_TYPE_MESSAGE:
			_vObject[i].count += 1;
			_vObject[i].objectImage->setFrameY(0);
			if (_vObject[i].count % 3 == 0)
			{
				_vObject[i].index += 1;
				if (_vObject[i].index > 17)
				{
					_vObject[i].index = 0;
				}
				_vObject[i].objectImage->setFrameX(_vObject[i].index);
			}
			break;
		case OBJECT_TYPE_CLOSEGATE:
			_vObject[i].count += 1;
			_vObject[i].objectImage->setFrameY(0);
			if (_vObject[i].count % 3 == 0)
			{
				if (_vObject[i].switchOn == FALSE)
				{
					_vObject[i].index -= 1;
					if (_vObject[i].index < 0)
					{
						_vObject[i].index = 0;
					}
				}
				else if (_vObject[i].switchOn == TRUE)
				{
					_vObject[i].index += 1;
					if (_vObject[i].index > 5)
					{
						_vObject[i].index = 5;
					}
				}
				_vObject[i].objectImage->setFrameX(_vObject[i].index);
			}
			break;
		}
	}
}

// 트리거 작동
void object::setTrigger(int objectNumber, bool trigger)
{
	_vObject[objectNumber].trigger = trigger;
}

// 스위치 ON
void object::setSwitchOn(int objectNumber, bool switchOn)
{
	_vObject[objectNumber].switchOn = switchOn;
}

// 스위치 OFF
void object::setSwitchOff(int objectNumber, bool switchOff)
{
	_vObject[objectNumber].switchOff = switchOff;
}

// 스위치 사운드 출력 조정
void object::setSwitchSoundOutput(int objectNumber, bool switchSoundOutput)
{
	_vObject[objectNumber].switchSoundOutput = switchSoundOutput;
}