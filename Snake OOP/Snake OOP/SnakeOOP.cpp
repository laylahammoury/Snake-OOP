# include "Snake.h"
# include "Game.h"

Snake::Snake(){
	//*this.size = 20;
	size = 20;
	padding = 2;
}

void Snake::MoveSnake( Direction direction){

		int newTop = pointbody[0].x;
		int newLeft = pointbody[0].y;
		switch (direction)
		{	
		case up:
			newTop -= (size);
			break;

		case down:
			newTop += (size);
			break;

		case left:
			newLeft -= (size);
			break;

		case right:
			newLeft += (size);
			break;

		}
		
		head.x = newTop;
		head.y = newLeft;
	
		if (direction != stop){
			pointbody.insert(pointbody.begin(), head);
			tail = pointbody[pointbody.size()-1];
			pointbody.erase(pointbody.end()-1);
	
		}
	}
void Snake::increaseSnake(){
	pointbody.push_back(tail);
}

void Snake::killSnake(){
	pointbody.clear();
}
