#include "Snake.h"

void FillRect(HDC hDC, const RECT* pRect, COLORREF color);
void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

class Game{

	private:
		Snake snake;
		bool gameover;
		int score;
		POINT food;
		Direction dir;
		std::queue<Direction> moves;
		unsigned int windowWidth;
		unsigned int windowHeight;
		
	public:
		Game();
		void DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC);
		void DrawFood(POINT food , HDC hDC);
		void eatFood();
		void checkGameover ( HWND hWnd);
		bool Initialize(HWND hWnd);
		bool OnKeyDown(WPARAM keyCode);
		void CALLBACK OnTimer(HWND hWnd, UINT Msg, UINT_PTR idTimer, DWORD dwTime);
		
};
