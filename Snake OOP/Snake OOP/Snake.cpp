# include "Snake.h"
# include "Game.h"


//int Snake::size = 20;

Snake::Snake( int square_size){
	//*this.size = 20;
	size = square_size;
	padding = 2;
}

void Snake::MoveSnake( Direction direction){

		int newTop = body[0].x;
		int newLeft = body[0].y;
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
			body.insert(body.begin(), head);
			tail = body[body.size()-1];
			body.erase(body.end()-1);
	
		}
	}
void Snake::increaseSnake(){
	body.push_back(tail);
}

void Snake::killSnake(){
	body.clear();
}

//getters
std::vector<POINT> Snake::getSnakeBody(){
	return body;

}

int Snake::getSize(){
	return size;
}
int Snake::getPadding(){
	return padding;
}