#include<string>
#include "Snake.h"

void FillRect(HDC hDC, const RECT* pRect, COLORREF color);

class Game{

	private:
		Snake snake;
		bool gameover;
		int score;
		std::queue<Direction> moves;
		static int foodRandomizing;
		unsigned int windowWidth;
		unsigned int windowHeight;
	
	public:
		void DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC);
		void eatFood();
		bool Initialize(HWND hWnd);
		void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);
		bool OnKeyDown(WPARAM keyCode);


};
