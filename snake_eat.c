#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLACK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snake_move(int y,int x);	
//get snake to move:dy=-1(move up),dy=1(move down);dx=-1(move left),dx=1(move right)
void put_food(void);
//put a food symbol randomly on a blank cell
void output_map(void);
//print the char matrix
int game_over(void);
//end the game when the snake hits itself

char map[12][13]={"************",
				  "*XXXXH     *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "************"};
//initialize the map

int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};		
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};		//the coordinate of the snake
int snake_length=5;
int flag=0;				//test if the snake has eaten the food
int foodX,foodY;

int main() {
	char single;
	int i;
	
	put_food();			//put food into the playground
	output_map();
	
	while(1) {
		scanf("%c",&single);
		getchar();
		
		if(flag) {
			for(i=snake_length;i>0;i--) {
				snakeX[i]=snakeX[i-1];
				snakeY[i]=snakeY[i-1];		//snake get longer equal to the snake went backward
			}
			
			snakeX[0]=foodX;
			snakeY[0]=foodY;		//the tail goes to the food position
			snake_length++;
			put_food();
		}
		
		switch(single) {
			case 'A':
				snake_move(0,-1);
				break;
			case 'D':
				snake_move(0,1);
				break;
			case 'W':
				snake_move(-1,0);
				break;
			case 'S':
				snake_move(1,0);
				break;
		}
		
		flag=0;			//initialize the flag
		
		if(snakeX[snake_length-1]==foodX&&snakeY[snake_length-1]==foodY) {
			flag=1;				//while the head of snake is at the position of food
		}
		
		output_map();
		
		if(game_over()) {
			printf("THE GAME IS OVER!\n");
			return 0;
		}
	}
	
	return 0;
}

void snake_move(int y,int x) {
	int i=0;
	int index1,index2;

	index1=snakeY[snake_length-1];
	index2=snakeX[snake_length-1];
	snakeX[snake_length-1]+=x;
	snakeY[snake_length-1]+=y;		//change the coordinate of the head
	map[snakeY[snake_length-1]][snakeX[snake_length-1]]=SNAKE_HEAD;
	map[snakeY[0]][snakeX[0]]=BLACK_CELL;
	
	
	for(i=0;i<snake_length-2;i++) {
		snakeX[i]=snakeX[i+1];		//move the snake on x axis
		snakeY[i]=snakeY[i+1];		//move the snake on y axis
		map[snakeY[i]][snakeX[i]]=SNAKE_BODY;		//get 'X' on the body of the snake
	}
	
	snakeY[snake_length-2]=index1;
	snakeX[snake_length-2]=index2;
	map[snakeY[snake_length-2]][snakeX[snake_length-2]]=SNAKE_BODY;
	
	return; 
}

void put_food(void) {
	srand((time(NULL)));		//to get more random coordinate of food
	foodX=rand()%10+2;
	foodY=rand()%10+2;
	
	while(map[foodY][foodX]!=BLACK_CELL) {
		foodX=rand()%10+2;
		foodY=rand()%10+2;
	}
	map[foodY][foodX]=SNAKE_FOOD;
}

int game_over(void) {
	int i=0;
	
	if(snakeY[snake_length-1]==11||snakeY[snake_length-1]==0) {
		return 1;		
	}
	if(snakeX[snake_length-1]==11||snakeX[snake_length-1]==0) {
		return 1;
	}							//snake bang on the wall
	for(i=0;i<snake_length-1;i++) {
		if(snakeX[snake_length-1]==snakeX[i]&&snakeY[snake_length-1]==snakeY[i]) {	
			return 1;
		}
	
	}						//snake bang on itself
	
	return 0;
}

void output_map() {
	int i;
	
	system("cls");
	
	for(i=0;i<12;i++) {
		printf("%s\n",map[i]);
	}
	
	return;
}
