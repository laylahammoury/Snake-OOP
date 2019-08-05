#pragma once
# include "resource.h"

# include <time.h>  
# include <map>  
# include <queue>
# include <Windows.h>
# include <vector>
# include <string>
# include <ColorDlg.h>

enum Direction{up, down, left, right, stop};

class Snake{

	private:
		int size ;
		int padding ;
		std::vector<POINT> body;
		POINT tail , headToBe ;	//temporary POINTS used for movement
		
	public:
		Snake( int square_size = 20);
		void MoveSnake( Direction direction);
		void increaseSnake();
		void killSnake();
		const std::vector<POINT>& getSnakeBody()const {return body; }// constant function and returns const vector of points
		/*
		const std::vector<POINT>& snakeBody = snake.getBody();
		*/
		int getSize() const { return size;}// constant function
		int getPadding() const {return padding ;}// constant function
		POINT getHead() const {return body[0] ;}// constant function
		POINT getHeadToBe() const {return headToBe;}// constant function

};