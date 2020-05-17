#pragma once
#include "gameNode.h"

// �޴��� ���Ź�
enum MENU
{
	MENU_GAMESTART = 0,
	MENU_GAMELOAD = 1,
	MENU_QUIT = 2,
	MENU_NULL = 3
};

// menuScene Ŭ����
class menuScene : public gameNode
{
private:
	// �̹��� ����
	// ��׶���
	image* background;					// ��׶��� �̹���
	int backgroundAlpha;				// ��׶��� �̹��� ���İ�
	bool backgroundAlphaBoolOnce;		// ��׶��� �̹��� ���İ� ���� ��ȯ (���� 1ȸ��)
	bool backgroundAlphaBool;			// ��׶��� �̹��� ���İ� ���� ��ȯ
	// Ÿ��Ʋ
	image* title;						// Ÿ��Ʋ �̹���
	int titleAlpha;						// Ÿ��Ʋ �̹��� ���İ�
	bool titleAlphaBool;				// Ÿ��Ʋ �̹��� ���İ� ���� ��ȯ
	// �ɺ�
	image* symbol;						// �ɺ� �̹���
	int symbolAlpha;					// �ɺ� �̹��� ���İ�
	bool symbolAlphaBool;				// �ɺ� �̹��� ���İ� ���� ��ȯ
	// ���� �޴�
	image* gameStart;					// ���� ���� �̹���
	int gameStartAlpha;					// ���� ���� �̹��� ���İ�
	image* gameLoad;					// ���� �ε� �̹���
	int gameLoadAlpha;					// ���� �ε� �̹��� ���İ�
	image* quit;						// ���� ���� �̹���
	int quitAlpha;						// ���� ���� �̹��� ���İ�
	image* gameStartMessage;			// ���� ���� �޴� �޼��� �̹���
	image* gameLoadMessage;				// ���� �ε� �޴� �޼��� �̹���
	image* quitMessage;					// ���� ���� �޴� �޼��� �̹���
	image* pointer;						// �� ��� ������ �̹���
	int pointerX;						// �� ��� ������ X��ǥ ��
	bool pointerXBool;					// �� ��� ������ X��ǥ �� ���� ��ȯ

	// ���� ����
	bool menuSelect;					// �޴� ����Ʈ
	MENU currentMenu;					// ���� �������� �޴�
	int currentMenuValue;				// ���� �������� �޴���
	int selectMenuValue;				// �޴� ���� �Ϸ����� ���� �޴��� ����
	bool selectMenuComplete;			// �޴� ���� �Ϸ�

public:
	// GET, SET �Լ�
	// �̹��� ����
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
	// ��Ÿ ���� ����
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

	// �ʱ�ȭ ó��
	HRESULT init();

	// ���� ó��
	void release();

	// ���� ó��
	void update();

	// ȭ�� ��� ó��
	void render();

	// ������, �Ҹ���
	menuScene() {}
	~menuScene() {}
};