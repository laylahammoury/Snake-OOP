# include "Snake.h"
# include "Game.h"


//int Snake::size = 20;

Snake::Snake( int square_size , int square_padding){
	size = square_size;
	padding = square_padding;
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
		
		headToBe.x = newTop;
		headToBe.y = newLeft;
	
		if (direction != stop){
			body.insert(body.begin(), headToBe);
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
void Snake::initSquares(int windowHeight , int windowWidth){

	POINT initArray[3];
		int initX = windowWidth /2;
		int initY = windowHeight/2;

		for (int i = 0; i < 3; i++)
		{
			initArray[i].x = initX ;
			initArray[i].y = initY - (i * size);
			body.push_back(initArray[i]);
		}

}
