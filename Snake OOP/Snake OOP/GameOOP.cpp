#include "Game.h"

void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

// Use this to fill a rectangle of the hDC with a specific color.
void FillRect(HDC hDC, const RECT* pRect, COLORREF color)
{
	COLORREF oldColor = SetBkColor(hDC, color);
	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, pRect, TEXT(""), 0, 0);
	SetBkColor(hDC, oldColor);
}

void Game::eatFood(){


	if (food.x == pointbody[0].x && food.y == pointbody[0].y)
		{
			food.x  = (rand()% foodRandomizing )* size;
			food.y  = (rand() % foodRandomizing )* size;
			snake.increaseSnake();
			score += 10; 
			
		} 
}
void Snake::DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC)
	{
		RECT temp ;
		int green = 255;
		for (int i = Snakbody.size()-1; i >= 0; i--)
			{
				temp.top = Snakbody[i].x ;
				temp.left = Snakbody[i].y ;
				temp.bottom = temp.top + (size-padding);
				temp.right = temp.left + (size-padding);
				if(green > 105)
					green-=15;
				if (i == 0)
					FillRect(hDC, &temp, RGB(255, 77, 50)); //Draw a red square.
				else
					FillRect(hDC, &temp, RGB(50, green, 50)); //Draw a green square.
			}
	}
