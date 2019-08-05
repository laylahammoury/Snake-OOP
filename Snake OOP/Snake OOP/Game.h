#include "Snake.h"

void FillRect(HDC hDC, const RECT* pRect, COLORREF color);
void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

class Game{

	private:
		Snake snake;
		bool gameover;
		int score;
		POINT food;
		std::queue<Direction> moves;
		static int foodRandomizing;
		unsigned int windowWidth;
		unsigned int windowHeight;
		std::vector<POINT> snakeBody;
		int snakeSize  , snakePadding;
	public:
		Game();
		void DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC);
		void eatFood();
		bool Initialize(HWND hWnd);
		bool OnKeyDown(WPARAM keyCode);


};
