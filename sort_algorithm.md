---
**基本排序算法的原理及C语言具体实现**
---

# 1.选择排序 #

比如我们给定一个序列{5,9,7,8,2}。

选择排序每次都选择在剩下的元素中最小的值，并且将这个数值和还未排序的第一个元素交换，然后依次对剩下的还未排序的元素采取相同操作，直到未排序的元素变成1为止。

为了思路更清晰，我们先写出这种算法的伪代码：

```

FOR i from 0 to list.length-2 DO

	Find the index of smallest number in list[i,length-1]

	IF index<>i THEN
	
	swap(i,index)

	END IF

END FOR

```

也就是说，如果有n个元素，那么我们进行n-1次排序就可以了，最后的一个元素一定是有序的。并且同时还要考虑到如果为排序的第一个数刚好就是最小的那个数的话，就没有必要再进行数值的交换了，因此加上了一个条件的判断。

下面我们继续展开找出最小数下标的伪代码：

```

FOR j from i to length-1

	if(list[j]<list[j+1]) THEN

		index=j

	END IF

END FOR

```

值得注意的是条件中各种边界的控制，比如因为要遍历剩下的所有元素，所以j的取值就是从i到length-1。而在比较两个数的大小时，还要考虑如果有两个相等的数的情况，发现只要一个小于号条件就足够了。

下面，我尝试用C语言写出了这个算法的具体实现：

```C

#include<stdio.h>

int find_small(const int*numbers,int i,int length);
void swap(int index,int i,int*numbers);

int main() {
	int numbers[10];
	int length,index;
	int i;
	
	scanf("%d",&length);	//输入数组的长度 
	
	for(i=0;i<length;i++) {
		scanf("%d",&numbers[i]);		//输入待排序的元素 
	}
	
	for(i=0;i<length-1;i++) {
		index=find_small(numbers,i,length);
		
		if(index!=i) {
			swap(index,i,numbers);
		}
	} 
	
	for(i=0;i<length;i++) {
		printf("%d ",numbers[i]);
	}
}

int find_small(const int*numbers,int i,int length) {
	int index=i;
	int min=numbers[i];
	int j;
	
	for(j=i;j<length-1;j++) {

		if(min>numbers[j+1]) {
			min=numbers[j+1];
			index=j+1;
		}
		
	}
	
	return index;
}

void swap(int index,int i,int*numbers) {
	int middle;
	
	middle=numbers[i];
	numbers[i]=numbers[index];
	numbers[index]=middle;
	
	return;
}

```
	
其实在一开始的程序中，我有一个小小的错误，那就是在寻找最小数的下标时，虽然伪代码中的条件给的很简单，但其实每次比较都是上一次比较的较小值继续与之后的元素进行比较，而不是仅仅的相邻两个元素的比较。

所以，如果一开始写成了

```

if(numbers[j]<numbers[j+1]) {
	index=j;
}

```

程序是无法正确排序的。

同时，如果条件中是j<length,就会在下标j+1处越界。

最后，附上程序结果的截图：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/selection_sort.png?raw=true)

# 2.冒泡排序 #

冒泡排序其实是很形象的一种排序名称，每次依次交换两个数使得最小的数能够想气泡一样浮上去。

比如给定一个序列{2,5,4,7,3,0}，那么从最后的元素开始，0不断被交换到前一个数的位置，从而依次使得小数在前，大数同时就自动排在了后面。

同样，先把冒泡排序的伪代码写出来：

```

FOR i from 0 to list.len-2 
	FOR j=list.len-1 DOWNTO i+1
		IF(list[j]<list[j-1]) 
			swap(j,j-1)
		END IF
	END FOR
END FOR

```

下面是我写的代码：

```C

#include<stdio.h>

void bubble_sort(int*numbers,int length);

int main() {
	int numbers[10]={0};
	int length;
	int i;
	
	scanf("%d",&length);
	
	for(i=0;i<length;i++)  {
		scanf("%d",&numbers[i]);
	}
	
	bubble_sort(numbers,length);
	
	for(i=0;i<length;i++) {
		printf("%d ",numbers[i]);
	}
	
	return 0;
}

void bubble_sort(int*numbers,int length) {
	int middle;
	int i,j;
	
	for(i=0;i<length-1;i++) {
		
		for(j=length-1;j>0;j--) {
			
			if(numbers[j]<numbers[j-1]) {
				middle=numbers[j];
				numbers[j]=numbers[j-1];
				numbers[j-1]=middle;
			}
		}
	}
}

```

下面是程序运行截图：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/bubble_sort.png?raw=true)

# 3.插入排序 #

插入排序就像是打扑克牌是每摸到一张牌后把它按顺序插到已有的牌中，前提是已有的牌是已经是有序的排列了。

先写出它的伪代码：

```

FOR i from 1 to list.len-1 
	insert list[i] to list[0,i-1]
END FOR

```

insert的伪代码：

```
SET j to i
SET value to list[j]

WHILE value<list[j-1] AND j>0
	j decrease by one
	index=j
END WHILE

move list[index,i] backward 
list[index]=value

```

写到这里，看着这些"<""j-1"头都大了……

这个时候，不妨稍微举几个简单的例子带进去，看看是不是取对了。

比如，用序列{53,27,36}为例。

第一次循环中j=1，value的值就是第一个要插入排序的元素，27。因为27<53并且j>0，所以j自减一变为0，记录下标index=0。这个时候循环条件不满足退出了，向后移动一个位置后，27排在了53的前面。同理，当插入第二个元素36时检验也符合。

下面是C的代码：

```C

#include<stdio.h>

void insert_sort(int*numbers,int length,int i);


int main() {
	int numbers[20];
	int length;
	int i;
	
	scanf("%d",&length);
	
	for(i=0;i<length;i++) {
		scanf("%d",&numbers[i]);
	}
	
	for(i=1;i<length;i++) {
		insert_sort(numbers,length,i);
	}
	
	for(i=0;i<length;i++) {
		printf("%d ",numbers[i]);
	}
	
	return 0;
}

void insert_sort(int*numbers,int length,int i) {
	int value=numbers[i];
	int j=i,k;
	
	if(value>=numbers[j-1]) {
		return;
	}
	else {
		while(value<numbers[j-1]&&j>0) {
			j--;
		}
		
		for(k=i-1;k>=j;k--) {
			numbers[k+1]=numbers[k];
		}
		
		numbers[j]=value;
	}
	
}

```

下面是程序运行截图：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/insert__sort.png?raw=true)

值得注意的是，再进行待排元素的插入时，要将数组的元素从要插入的位置移动到待排元素的位置都向后移动一个单位，但是一定不是移动到序列末尾！！一开始因为写成了k=length-1导致排序出的结果一直不对……

# 4.简单桶排序 #

桶排序就是将数据间变化不大的数据分别放在几个桶里，然后再各自对桶进行排序。

最简单的桶排序应该就是每个桶只放单一值的排序了。

下面是伪代码：

```

FOR i from 0 to list.len-1
	get i into the bucket
END FOR

get the number of item in each bucket

```

几乎不用动脑子就可以写出这种桶排序：

```C

#include<stdio.h>

int main() {
	int length,index;
	int numbers[10]={0};
	int buckets[11]={0};
	int i,j;
	
	scanf("%d",&length);
	
	for(i=0;i<length;i++) {
		scanf("%d",&numbers[i]);
	}
	
	for(i=0;i<length;i++) {
		index=numbers[i];
		buckets[index]++;
	}
	
	for(i=0;i<length+1;i++) {
		j=buckets[i];
		while(j--) {
			printf("%d ",i);
		}
	}
	
	return 0;
} 

```

值得注意的是，桶的数组一定要经过初始化，并且桶的大小要比输入数据的最大值要大一，因为数组的下标是从零开始的。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/bucket_sort.png?raw=true)

# 5.快速排序 #

想要能够自己写出快速排序的程序，就必须真正弄懂快速排序的原理。

这种算法将一个大问题分解成许多小问题，首先选定一个基准值，通常可以选定第一个元素值。如果待排序的元素小于等于基准值，就移动到基准值的左边，否则就移动到基准值的右边。注意，不要忘记考虑相等的情况！

我想了一个晚上……还是没有想明白双指针的移动和那些大于等于、小于等于号……

后来从网上搜到一张图，稍微明白了一点点……

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/quick_sort.png?raw=true)

这种算法可能要再花几天想一想，等想明白了再写代码吧。

