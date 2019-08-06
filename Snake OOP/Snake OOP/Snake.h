#pragma once

# include <time.h>  
# include <map>  
# include <queue>
# include <Windows.h>
# include <vector>
# include <string>
# include <ColorDlg.h>

enum Direction{up, down, left, right, stop};

//int add(int x, int y);


class Snake
{
	private:
		int size ; // The size of each square
		std::vector<POINT> body;
		POINT tail , headToBe ;	//temporary POINTS used for movement
		
	public:
		
		Snake( int square_size = 20 );
		void MoveSnake( Direction direction);
		void increaseSnake();
		void clearSnake();
		const std::vector<POINT>& getSnakeBody()const {return body; } // constant function and returns const vector of points
		int getSize() const { return size;} // constant function
		POINT getHead() const { return body[0]; } 
		POINT getHeadToBe() const {return headToBe;} 
		void initSquares(int windowHeight , int windowWidth , int length);

};