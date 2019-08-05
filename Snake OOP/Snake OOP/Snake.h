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
		POINT tail , head ;	//temporary POINTS used for movement
		
	public:
		Snake( int square_size = 20);
		void MoveSnake( Direction direction);
		void increaseSnake();
		void killSnake();
		std::vector<POINT> getSnakeBody();
		const std::vector<POINT>& getBody() const { return body; }

		const std::vector<POINT>& snakeBody = snake.getBody();
		snakeBody.push_back();

		int getSize() const;
		int getPadding() const;

};