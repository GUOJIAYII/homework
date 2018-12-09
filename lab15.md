---
**智能蛇实验报告**
---

# 一.实验目的 #

1.了解算法与“智能”的关系

2.通过算法赋予蛇智能

3.了解 Linux IO 设计的控制

# 二.实验环境 #

使用了linux的虚拟机，Unbutu版本。

# 三.控制输入/输出设备 #


## 1、VT 100 终端标准 ##

通过介绍稍微明白一点VT100控制码，是一个终端类型定义，可以在终端扩展显示的代码，并且均以'\033'开头。

首先，尝试在Linux的环境下编译sindemo.c的文件：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/sindemo.gif?raw=true)

## 2、实现 kbhit() ##

kbhit函数可以检测是否有键盘的输入，但是不会阻止while循环的进行，这样蛇就可以动了。

只要将自己写好的智能蛇代码放到相应的位置上就好了！


# 四.编写智能算法 #

要实现蛇的智能算法，就是需要蛇来自己判断该如何到达食物的距离最小，然后自动行走。

在具体实现之前，先写出这个函数的伪代码：

```

Hx,Hy: the position of the head
Fx,Fy: the position of the head

fun Where_To_Go(Hx,Hy,Fx,Fy) {

	moveable[3]={'A','S','D','W'} is the direction that the snake can go
	distance[3]={0,0,0,0} is the distance between the food and the snake

	calculate the distance from the head to the food separately
	IF Hx-1!=BLANK or Hy!=BLANK THEN
		distance=9999
	ELSE 
		distance=|Fx – (Hx-1)| + |Fy – Hy|

	return the index of the smallest number of distance
	return moveable[p]

}

```

因为这是一个智能蛇，所以不需要像上一次的字符蛇一样每一次都输入一个字符，人工控制它的移动，只要蛇没有死，每一次都自己计算怎样走才能使距离最小，然后返回相应的方向，自己进行移动就好了。

所以这次的主控程序是这样的：

```

output the map

WHILE the game is not over DO

	wait (time) 
		ch=Where_To_Go(Hx,Hy,Fx,Fy)

		CASE ch DO 
		'a': move left
			 break
		's': move down
			 break
		'd' :move right
			 break
		'w' :move up
			 break
		END CASE
		
		output the map

END WHILE

output the game is over!

```

写出该部分的函数实现：

```C

char where_to_move(int Hx,int Hy,int Fx,int Fy) {
	char moveable[4]={'A','S','D','W'};
	int distance[4]={0,0,0,0};
	int index=0;
	
	if (map[Hy][Hx-1]==BLACK_CELL) {
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

```

这是完整的源代码：[https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/smart_snake.cpp](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/smart_snake.cpp)

这是非常简陋的运行效果：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/stupid_snake.gif?raw=true)

这条可怜的蛇看起来一点都不智能，效果也很不好……

如果放置一个长度为5的障碍物，若是放在地图正中央，可能会使这条蛇被自己困死，但如果放在围墙周围，影响就不大了。

# 实验反思 #

说实话，其实这周的软导作业对我来说最大的难点在于如何在Linux环境下完成编译与运行……

在我看来，这条智能蛇之所以能够自己判断选择路径，也不过是因为我们人为写了一个判断方向的函数，本质还是最基础的字符蛇的实现，也就是通过函数一步步将大问题分解，实现自顶向下的问题求解方法，进而更容易将问题解决。

后来经过查找资料，发现还可以加上图片和背景、让蛇吃的越多跑的越快、让蛇自己判断食物是否安全（即吃下食物是否会死亡）等更高级的玩法，以后有时间也可以再尝试一下。