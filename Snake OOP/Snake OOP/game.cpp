#include "Game.h"
//#include<vector>

void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);

// Use this to fill a rectangle of the hDC with a specific color.
//void FillRect(HDC hDC, const RECT* pRect, COLORREF color)
//{
//	COLORREF oldColor = SetBkColor(hDC, color);
//	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, pRect, TEXT(""), 0, 0);
//	SetBkColor(hDC, oldColor);
//}


Game::Game(){
	
}
// This is called when the application is launched.
	bool Game::Initialize(HWND hWnd)
	{
		RECT rClient;
		GetClientRect(hWnd, &rClient);
		windowWidth = rClient.right - rClient.left; // rClient.top and rClient.left are always 0.
		windowHeight = rClient.bottom - rClient.top;
		gameover = false;
		snake.killSnake();//used to initialize the snake
		dir = stop;
		score = 0;
		srand (time(NULL));
		OutputDebugStringA("My game has been initialized. This text should be shown in the 'output' window in VS");
		snake.initSquares(windowHeight , windowWidth);//fill the snake to start with 3 squares

		//initialize the food place
		food.x = snake.getHead().x ;
		food.y = snake.getHead().y + (2 * snake.getSize());

		return true;
	}


void Game::eatFood(){
	
	const POINT head = snake.getHead();
	if (food.x == head.x && food.y == head.y)
		{
			food.x  = (rand()% windowWidth/snake.getSize()) * snake.getSize();
			food.y  = (rand() % windowWidth/snake.getSize()) * snake.getSize();
			snake.increaseSnake();
			score += 10; 
			
		} 
}
void Game::DrawFood(POINT food ,HDC hDC){
	RECT foodTemp;
		foodTemp.top = food.x ;
		foodTemp.left = food.y ;
		foodTemp.bottom = foodTemp.top + (snake.getSize - snake.getPadding());
		foodTemp.right= foodTemp.left+ (snake.getSize - snake.getPadding());
		FillRect(hDC, &foodTemp, RGB(255, 255, 77)); //Draw a food square.

}
void Game::DrawSnake(const std::vector<POINT>& Snakbody , HDC hDC)
	{
		RECT temp ;
		int green = 255;
		for (int i = Snakbody.size()-1; i >= 0; i--)
			{
				temp.top = Snakbody[i].x ;
				temp.left = Snakbody[i].y ;
				temp.bottom = temp.top + (snake.getSize() - snake.getPadding());
				temp.right = temp.left + (snake.getSize() - snake.getPadding());
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
		const std::vector<POINT> snakeBody = snake.getSnakeBody();
		const POINT headToBe = snake.getHeadToBe();
		const POINT head = snake.getHead();
		for (int i = 1; i < snakeBody.size()-1; i++)
		{
			if(headToBe.x ==  snakeBody[i].x && headToBe.y == snakeBody[i].y)
				{
					gameover = true;
					MessageBox(0,TEXT("You ate yourself :P "), TEXT("GAMEOVER !!!!"), MB_OK);
					Initialize(hWnd);
				}
			
		}
		
		if( (head.y + snake.getSize()) > windowWidth ||  head.y  < 0 ||  (head.x + snake.getSize()) > windowHeight ||  head.x  < 0)//Gameover states
			{
				gameover = true;
				MessageBox(0,TEXT("Try again :O "), TEXT("GAMEOVER !!!!"), MB_OK);
				Initialize(hWnd);
			}
	}
void CALLBACK Game::OnTimer(HWND hWnd, UINT Msg, UINT_PTR idTimer, DWORD dwTime)
	{
		
		HDC hDC = GetDC(hWnd);
		RECT rClient;
		GetClientRect(hWnd, &rClient);
		FillRect(hDC, &rClient, RGB(0, 0, 0)); // Clear the window to blackness.
		char text[256] = { 0 };
		sprintf_s(text, " Score : %d", score);
		RECT rText = { 0, 0, rClient.right, 15 };
		DrawTextLine(hWnd, hDC, text, &rText, RGB(120, 120, 120));

		if( moves.size() >=1 )
		{
			dir = moves.front();
			moves.pop();
		}
		
		
		if ( gameover )
		{
			DrawSnake(snake.getSnakeBody(), hDC);//to draw it and see how you died
			return ;
		}

		snake.MoveSnake( dir);
		eatFood();
		
		DrawFood(food , hDC);
		

		DrawSnake(snake.getSnakeBody() , hDC);
		checkGameover ( hWnd);

	
	}//end of OnTimer

