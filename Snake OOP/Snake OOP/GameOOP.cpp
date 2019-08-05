#include "Game.h"
//#include<vector>

void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

// Use this to fill a rectangle of the hDC with a specific color.
void FillRect(HDC hDC, const RECT* pRect, COLORREF color)
{
	COLORREF oldColor = SetBkColor(hDC, color);
	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, pRect, TEXT(""), 0, 0);
	SetBkColor(hDC, oldColor);
}


Game::Game(){
	snakeBody = snake.getSnakeBody();
	snakeSize = snake.getSize();
	snakePadding = snake.getPadding();
}



void Game::eatFood(){
	
	if (food.x == snakeBody[0].x && food.y == snakeBody[0].y)
		{
			food.x  = (rand()% foodRandomizing )* snakeSize;
			food.y  = (rand() % foodRandomizing )* snakeSize;
			snake.increaseSnake();
			score += 10; 
			
		} 
}
void Game::DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC)
	{
		RECT temp ;
		int green = 255;
		for (int i = Snakbody.size()-1; i >= 0; i--)
			{
				temp.top = Snakbody[i].x ;
				temp.left = Snakbody[i].y ;
				temp.bottom = temp.top + (snakeSize-snakePadding);
				temp.right = temp.left + (snakeSize-snakePadding);
				if(green > 105)
					green-=15;
				if (i == 0)
					FillRect(hDC, &temp, RGB(255, 77, 50)); //Draw a red square.
				else
					FillRect(hDC, &temp, RGB(50, green, 50)); //Draw a green square.
			}
	}

void Game::checkGameover ( HWND hWnd)
	{

		for (int i = 1; i < snakeBody.size()-1; i++)
		{
			if(head.x ==  snakeBody[i].x && head.y == snakeBody[i].y)
				{
					gameover = true;
					MessageBox(0,TEXT("You ate yourself :P "), TEXT("GAMEOVER !!!!"), MB_OK);
					Initialize(hWnd);
				}
			
		}
		
		if( (snakeBody[0].y + snakeSize) > windowWidth ||  snakeBody[0].y  < 0 ||  (snakeBody[0].x + snakeSize) > windowHeight ||  snakeBody[0].x  < 0)//Gameover states
			{
				gameover = true;
				MessageBox(0,TEXT("Try again :O "), TEXT("GAMEOVER !!!!"), MB_OK);
				Initialize(hWnd);
			}
	}
