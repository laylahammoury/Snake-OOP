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
		static int size ;
		int padding ;
		std::vector<POINT> pointbody;
		static POINT tail , head ;	//temporary POINTS used for movement

	public:
		Snake();
		void MoveSnake( Direction direction);
		void increaseSnake();
		void killSnake();

	friend class Game;

};