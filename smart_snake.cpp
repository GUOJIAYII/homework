#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
char where_to_move(int Hx,int Hy,int Fx,int Fy);
// get the best direction to move 
int get_min(const int*distance);

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

static struct termios ori_attr, cur_attr;

static __inline 
int tty_reset(void)
{
        if (tcsetattr(STDIN_FILENO, TCSANOW, &ori_attr) != 0)
                return -1;

        return 0;
}


static __inline
int tty_set(void)
{
        
        if ( tcgetattr(STDIN_FILENO, &ori_attr) )
                return -1;
        
        memcpy(&cur_attr, &ori_attr, sizeof(cur_attr) );
        cur_attr.c_lflag &= ~ICANON;
//        cur_attr.c_lflag |= ECHO;
        cur_attr.c_lflag &= ~ECHO;
        cur_attr.c_cc[VMIN] = 1;
        cur_attr.c_cc[VTIME] = 0;

        if (tcsetattr(STDIN_FILENO, TCSANOW, &cur_attr) != 0)
                return -1;

        return 0;
}

static __inline
int kbhit(void) 
{
                   
        fd_set rfds;
        struct timeval tv;
        int retval;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        /* Wait up to five seconds. */
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

        if (retval == -1) {
                perror("select()");
                return 0;
        } else if (retval)
                return 1;
        /* FD_ISSET(0, &rfds) will be true. */
        else
                return 0;
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

char where_to_move(int Hx,int Hy,int Fx,int Fy) {
	char moveable[4]={'A','S','D','W'};
	int distance[4]={0,0,0,0};
	int index=0;
	
	if(map[Hy][Hx-1]==BLACK_CELL) {
		distance[0]=abs((Fx-(Hx-1)))+abs((Fy-Hy));
	}
	else {
		distance[0]=999;
	}
	
	if(map[Hy+1][Hx]==BLACK_CELL) {
		distance[1]=abs(Fx-Hx)+abs(Fy-(Hy+1));
	} 
	else {
		distance[1]=999;
	}
	if(map[Hy][Hx+1]==BLACK_CELL) {
		distance[2]=abs(Fx-(Hx+1))+abs(Fy-Hy);
	}
	else {
		distance[2]=999;
	}
	if(map[Hy-1][Hx]==BLACK_CELL) {
		distance[3]=abs(Fx-Hx)+abs(Fy-(Hy-1));
	}
	else {
		distance[3]=999;
	}

	
	index=get_min(distance);
	
	return moveable[index];
}

int get_min(const int*distance) {
	int i=0;
	int min=distance[0];
	int index=0;
	
	for(i=1;i<4;i++) {
		if(min>distance[i]&&distance[i]!=999) {
			min=distance[i];
			index=i;
		}
	}
	
	return index;
}

int main()
{
  	
    int tty_set_flag;
    tty_set_flag = tty_set();
    
    char single;
	int i;
	
	put_food();			//put food into the playground
	output_map();
	
	while(1) {
		single=where_to_move(snakeX[0],snakeY[0],foodX,foodY);
		
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
        printf("pressed `q` to quit!\n");
        while(1) {

                if( kbhit() ) {
                        const int key = getchar();
                        printf("%c pressed\n", key);
                        if(key == 'q')
                                break;
                } else {
                       ;// fprintf(stderr, "<no key detected>\n");
                }
        }

        //ª÷∏¥÷’∂À…Ë÷√
        if(tty_set_flag == 0) 
                tty_reset();
        return 0;
}




