# include <time.h>  
# include <map>  
# include<queue>
# include <Windows.h>
# include <vector>
# include <string>
# include<ColorDlg.h>
#include<iostream>
#include "Game.h"
using namespace std;
/*
Welcome to the Snake game programming challenge. You are required to add code to the following three functions to implement the Snake game.
You can of course write any code that you need to outside of these functions as well.
The functions are:

Initialize()
OnTimer()
OnKeyDown()


The file shows you how to draw rectangles with specific colors and how to draw text if you need to.
You should not need anything else because we are looking to create a visually-simple Snake game, so flat squared should be good enough.

Good luck!

* Exceptions
* classes (constructors, destructors, copy constructors, operator overloading, virtual methods, abstract classes)
* Templates (template functions and classes).

std::vector<RECT> snake;


CVs and interviews:
techlead: top resume mistakes
Deniz Sasal: very useful discussions about intervies, CVs... etc. (white background)
*/


// COLORREF is a Windows data type. It is used by the API to represent 32-bit colors.
// Create a COLORREF value using the RGB() macro:
// COLORREF myColor = RGB(red, green, blue);
// where red, green, and blue are integers from 0-255.

// Another Windows data type is RECT. It represents a rectangle. It has the members:
// top, left, right, bottom.


// Use this to fill a rectangle of the hDC with a specific color.
void FillRect(HDC hDC, const RECT* pRect, COLORREF color)
{
	COLORREF oldColor = SetBkColor(hDC, color);
	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, pRect, TEXT(""), 0, 0);
	SetBkColor(hDC, oldColor);
}

//This is used to make a point and initialize it
//POINT MakePoint(int x, int y ) { POINT pt = {x, y}; return pt; }



// Use this to draw text if you need to.
void DrawTextLine(HWND hWnd, HDC hDC, const char* sText, RECT* prText, COLORREF clr);


namespace game
{
	Snake snake =  Snake(20 , 2);
	Game gamePlay = Game(snake);
// This is called when the application is launched.
bool Initialize(HWND hWnd )
	{
		cout<<"init has been calld"<<endl;
		gamePlay.Initialize(hWnd);
		return true;

	}

// This is called periodically. Use it to update your game state and draw to the window.
	void CALLBACK OnTimer(HWND hWnd, UINT Msg, UINT_PTR idTimer, DWORD dwTime )
	{
		gamePlay.OnTimer( hWnd,  Msg,  idTimer,  dwTime);
	}

	// This is called when the user presses a key on the keyboard.
	// Use this to change the direction of your snake.
	bool OnKeyDown(WPARAM keyCode )
	{
		gamePlay.OnKeyDown( keyCode);
		return true;
	}
	int main()
	{
		
		//cout<<"main has been called"<<endl;
		/*Snake snake =  Snake(20 , 2);
		gamePlay = Game(snake);*/
		HWND hWnd;
		Initialize(hWnd );
		UINT Msg ; UINT_PTR idTimer ; DWORD dwTime; 
		OnTimer(hWnd , Msg , idTimer , dwTime );
		WPARAM keyCode;
		OnKeyDown(keyCode );	
		
		
	
	return 0;
	}//end of main
}//end of namespace game
