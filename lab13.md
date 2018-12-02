---
**字符蛇游戏实验报告**
---

**一.实验目的**

1.了解字符游戏的表示

2.体验自顶向下的设计方法实现问题求解

3.使用伪代码表示算法

4.使用函数抽象过程

**二.实验内容**

1.任务一：会动的蛇

首先根据游戏的设计写出伪代码，即只要蛇还没有死，就等待输入移动指令，进行移动，重新打印出字符矩阵。

```

WHILE the game is not over 
	get ch from keyboard

	CASE ch DO

		'W':move up,break;
		'A':move left,break;
		'S':move down,break;
		'D':move right,break;
	END CASE

	print the char matrix

END WHILE

print the game is over

```

根据伪代码，先写好程序的总控代码：

```C

#include<stdio.h>
#include<stdlib.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLACK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snake_move(int y,int x);	
//get snake to move:dy=-1(move up),dy=1(move down);dx=-1(move left),dx=1(move right)
void put_food(void)
//put a food symbol randomly on a blank cell
void output_map(void)
//print the char matrix
void game_over(void)
//end the game when the snake hits itself

char map[12][13]={"************",
				  "*XXXXH     *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "*          *"
				  "************"};
//initialize the map

int snakeX={1,2,3,4,5};		
int snakeY={1,1,1,1,1};		//the coordinate of the snake
int snake_length=5;

```

写好大致框架后，逐步将函数实现：

主要的困难在于如何实现蛇的移动，蛇的移动是全身的,也就是蛇身的每一个坐标都要进行相应的增减变化！

也就是说，必须要想明白不管蛇头怎么移动，他全身的移动是连续的，可以通过不断的坐标之间的赋值实现！而原先蛇尾出的坐标设为BLACK_CELL就好了！

同时值得注意的是因为使用二维数组所以坐标由习惯的（x,y）变化成了（y,x），注意好对应关系。

终于，蛇可以正常移动了！

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/snake_move.gif?raw=true)

不知道为什么，之前每次移动后打印都会打印两次，检查了好久，才发现问题可能出在回车键会对scanf函数造成影响，在后面加了一个getchar()就可以正常输出了。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/output_once.png?raw=true)

这是最终完成的完整代码~

[https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/snake_move.c](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/snake_move.c)

2.任务二：会吃的蛇

要实现吃到食物后蛇的长度可以增加，其实也就是蛇头的位置不变，蛇身向后退了一步，这个函数也可以通过坐标的赋值来实现！而最后的尾巴的坐标可以让它指向生成的食物的坐标，但其实虽然此时的坐标是snakeX[0],snakeY[0],但这其实是实际的蛇头的坐标。

同时，此时要对snake_move中的函数稍加修改，因为snake_length是一个可以不断增加的变量了。


为了保证投放食物的位置具有较好的随机性，在用rand函数产生随机数的基础上，可以使用srand(time(NULL))，即/用系统当前时间设置rand()随机序列种子，保证每次运行随机序列不一样。（这里需要添加库<time.h>）。rand()函数可以随机产生20-90的整数，为了数组不越界，可以选择合数的数来取余。比如，选择10。但是这样下标最大也就是9，可以再加上一个数字，比如2，使得食物可以在整个区域内出现。

并且投放食物的同时还要考虑到可能会出现生成的坐标正好就是边界或是蛇本身，此时就要重新生成一组新的坐标，直至它出现在BLACK_CELL中。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/snake_eat.gif?raw=true)

这是这部分的完整代码：

[https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/snake_eat.c](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/snake_eat.c)

**三.实验总结**

自顶向下逐步分解是一种非常实用的方法，现有一个解决问题的大体框架之后，在逐步去落实每一步究竟如何完成，就会是使问题简单很多。本来没有想到一个下午就能写出这个字符蛇的小游戏，但是就是因为能顾将问题不断分解从而降低了难度，做起来也就容易很多了。


