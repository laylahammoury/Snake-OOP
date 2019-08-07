#include "Snake.h"

void FillRect(HDC hDC, const RECT* pRect, COLORREF color);
void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

# define PADDING 2
# define BOX_SIZE 20
# define INITIAL_LENGTH 20


inline const char* get_name() { return "adel"; }

class Game
{
	Snake snake;
	bool gameover;
	int score;
	POINT food;
	Direction dir;
	std::queue<Direction> moves;
	unsigned int windowWidth;
	unsigned int windowHeight;
		
public:
	Game(): snake(BOX_SIZE)
	{ }

	void drawSnake(HDC hDC);
	void drawPoint(POINT food , HDC hDC, COLORREF color);
	// Checks if head intersects food, if so, generates a new food position and grows the snake.
	void eatFood();
	void checkGameover ( HWND hWnd);
	bool Initialize(HWND hWnd);
	bool OnKeyDown(WPARAM keyCode);
	void OnTimer(HWND hWnd);
		
};
