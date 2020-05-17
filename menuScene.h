#pragma once
#include "gameNode.h"

// 메뉴값 열거문
enum MENU
{
	MENU_GAMESTART = 0,
	MENU_GAMELOAD = 1,
	MENU_QUIT = 2,
	MENU_NULL = 3
};

// menuScene 클래스
class menuScene : public gameNode
{
private:
	// 이미지 관련
	// 백그라운드
	image* background;					// 백그라운드 이미지
	int backgroundAlpha;				// 백그라운드 이미지 알파값
	bool backgroundAlphaBoolOnce;		// 백그라운드 이미지 알파값 증감 전환 (최초 1회만)
	bool backgroundAlphaBool;			// 백그라운드 이미지 알파값 증감 전환
	// 타이틀
	image* title;						// 타이틀 이미지
	int titleAlpha;						// 타이틀 이미지 알파값
	bool titleAlphaBool;				// 타이틀 이미지 알파값 증감 전환
	// 심볼
	image* symbol;						// 심볼 이미지
	int symbolAlpha;					// 심볼 이미지 알파값
	bool symbolAlphaBool;				// 심볼 이미지 알파값 증감 전환
	// 선택 메뉴
	image* gameStart;					// 게임 시작 이미지
	int gameStartAlpha;					// 게임 시작 이미지 알파값
	image* gameLoad;					// 게임 로드 이미지
	int gameLoadAlpha;					// 게임 로드 이미지 알파값
	image* quit;						// 게임 종료 이미지
	int quitAlpha;						// 게임 종료 이미지 알파값
	image* gameStartMessage;			// 게임 시작 메뉴 메세지 이미지
	image* gameLoadMessage;				// 게임 로드 메뉴 메세지 이미지
	image* quitMessage;					// 게임 종료 메뉴 메세지 이미지
	image* pointer;						// 손 모양 포인터 이미지
	int pointerX;						// 손 모양 포인터 X좌표 값
	bool pointerXBool;					// 손 모양 포인터 X좌표 값 증감 전환

	// 변수 관련
	bool menuSelect;					// 메뉴 셀렉트
	MENU currentMenu;					// 현재 선택중인 메뉴
	int currentMenuValue;				// 현재 선택중인 메뉴값
	int selectMenuValue;				// 메뉴 선택 완료했을 때의 메뉴값 설정
	bool selectMenuComplete;			// 메뉴 선택 완료

public:
	// GET, SET 함수
	// 이미지 관련
	image* getBackground() { return background; }
	void setBackground(image* _background) { background = _background; }
	int getBackgroundAlpha() { return backgroundAlpha; }
	void setBackgroundAlpha(int _backgroundAlpha) { backgroundAlpha = _backgroundAlpha; }
	bool getBackgroundAlphaBoolOnce() { return backgroundAlphaBoolOnce; }
	void setBackgroundAlphaBoolOnce(bool _backgroundAlphaBoolOnce) { backgroundAlphaBoolOnce = _backgroundAlphaBoolOnce; }
	bool getBackgroundAlphaBool() { return backgroundAlphaBool; }
	void setBackgroundAlphaBool(bool _backgroundAlphaBool) { backgroundAlphaBool = _backgroundAlphaBool; }
	image* getTitle() { return title; }
	void setTitle(image* _title) { title = _title; }
	int getTitleAlpha() { return titleAlpha; }
	void setTitleAlpha(int _titleAlpha) { titleAlpha = _titleAlpha; }
	bool getTitleAlphaBool() { return titleAlphaBool; }
	void setTitleAlphaBool(bool _titleAlphaBool) { titleAlphaBool = _titleAlphaBool; }
	image* getSymbol() { return symbol; }
	void setSymbol(image* _symbol) { symbol = _symbol; }
	int getSymbolAlpha() { return symbolAlpha; }
	void setSymbolAlpha(int _symbolAlpha) { symbolAlpha = _symbolAlpha; }
	bool getSymbolAlphaBool() { return symbolAlphaBool; }
	void setSymbolAlphaBool(bool _symbolAlphaBool) { symbolAlphaBool = _symbolAlphaBool; }
	image* getGameStart() { return gameStart; }
	void setGameStart(image* _gameStart) { gameStart = _gameStart; }
	int getGameStartAlpha() { return gameStartAlpha; }
	void setGameStartAlpha(int _gameStartAlpha) { gameStartAlpha = _gameStartAlpha; }
	image* getGameLoad() { return gameLoad; }
	void setGameLoad(image* _gameLoad) { gameLoad = _gameLoad; }
	int getGameLoadAlpha() { return gameLoadAlpha; }
	void setGameLoadAlpha(int _gameLoadAlpha) { gameLoadAlpha = _gameLoadAlpha; }
	image* getQuit() { return quit; }
	void setQuit(image* _quit) { quit = _quit; }
	int getQuitAlpha() { return quitAlpha; }
	void setQuitAlpha(int _quitAlpha) { quitAlpha = _quitAlpha; }
	image* getGameStartMessage() { return gameStartMessage; }
	void setGameStartMessage(image* _gameStartMessage) { gameStartMessage = _gameStartMessage; }
	image* getGameLoadMessage() { return gameLoadMessage; }
	void setGameLoadMessage(image* _gameLoadMessage) { gameLoadMessage = _gameLoadMessage; }
	image* getQuitMessage() { return quitMessage; }
	void setQuitMessage(image* _quitMessage) { quitMessage = _quitMessage; }
	image* getPointer() { return pointer; }
	void setPointer(image* _pointer) { pointer = _pointer; }
	int getPointerX() { return pointerX; }
	void setPointerX(int _pointerX) { pointerX = _pointerX; }
	bool getPointerXBool() { return pointerXBool; }
	void setPointerXBool(bool _pointerXBool) { pointerXBool = _pointerXBool; }
	// 기타 변수 관련
	bool getMenuSelect() { return menuSelect; }
	void setMenuSelect(bool _menuSelect) { menuSelect = _menuSelect; }
	MENU getCurrentMenu() { return currentMenu; }
	void setCurrentMenu(MENU _currentMenu) { currentMenu = _currentMenu; }
	int getCurrentMenuValue() { return currentMenuValue; }
	void setCurrentMenuValue(int _currentMenuValue) { currentMenuValue = _currentMenuValue; }
	int getSelectMenuValue() { return selectMenuValue; }
	void setSelectMenuValue(int _selectMenuValue) { selectMenuValue = _selectMenuValue; }
	bool getSelectMenuComplete() { return selectMenuComplete; }
	void setSelectMenuComplete(bool _selectMenuComplete) { selectMenuComplete = _selectMenuComplete; }

	// 초기화 처리
	HRESULT init();

	// 해제 처리
	void release();

	// 계산식 처리
	void update();

	// 화면 출력 처리
	void render();

	// 생성자, 소멸자
	menuScene() {}
	~menuScene() {}
};