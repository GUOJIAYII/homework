---
**常见的排序算法**
---

# （直接）插入排序 #

就像打扑克牌一样，插入排序的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

比如：

Input: {5 2 4 6 1 3}。

首先拿起第一张牌, 手上有 {5}。

拿起第二张牌 2, 把 2 insert 到手上的牌 {5}, 得到 {2 5}。

拿起第三张牌 4, 把 4 insert 到手上的牌 {2 5}, 得到 {2 4 5}。

以此类推。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F.gif?raw=true)

也就是说，拿起第一张牌的时候，我们可以认为这个牌**已经排序了**，然后依次取出下一个元素，在已经排序的元素序列中从后向前扫描，如果该元素（已排序）大于新元素，将该元素移到下一位置，直到找到已排序的元素小于或者等于新元素的位置。

根据自己的理解，我用C语言写了一个插入排序的程序：

```C


#include<stdio.h>

void insertion_sort(const int*numbers,int*sorted,int length);
int get_movelen(const int*numbers,const int*sorted,int i);
void move_len(int*sorted,int index,int i);

int main() {
	int length;
	int numbers[100]={0},sorted[100]={0};
	int i;
	
	scanf("%d",&length);
	
	for(i=0;i<length;i++) {
		scanf("%d",&numbers[i]);
	}
	
	insertion_sort(numbers,sorted,length);
	
	for(i=0;i<length;i++) {
		printf("%d\n",sorted[i]);
	}
	
	return 0;
}

void insertion_sort(const int*numbers,int*sorted,int length) {
	int i=0,j=0;
	int index=0;
	
	sorted[i]=numbers[i];	//拿出numbers中的第一个元素并且认为已经排序
	
	for(i=1;i<length;i++) {		//进行length-1轮插入
		if(numbers[i]>=sorted[i-1]) {
			sorted[i]=numbers[i];
		}
		
		else {
			
			index=get_movelen(numbers,sorted,i);	//得到要插入数据要移动的数组长度 
			move_len(sorted,index,i);					//从下标为index开始移动movelen个长度单位 
			sorted[index]=numbers[i];
			
		}
	}
	
	return;
}

int get_movelen(const int*numbers,const int*sorted,int i) {
	int j=i;
	
	while(numbers[j]<sorted[i-1]&&i>=0) {
		i--;
	}
	
	return i;

}

void move_len(int*sorted,int index,int i) {
	int j;
	
	for(j=i-1;j>=index;j--) {
		sorted[j+1]=sorted[j];
	}
}

```

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/additional.png?raw=true)

明明感觉算法挺好理解的……但是居然写了这么一大堆……

后来到网上搜索，发现根本没有必要先计算出要移动多长的长度再依次移动数组中的元素，也没有必要再新建一个数组进行操作，直接在原数组的基础上进行操作就可以了！

即：

```C

void Insertion_Sort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=a[i];

        for(j=i;j>0&&a[j-1]>temp;--j) {
			   a[j]=a[j-1];
}
           
        a[j]=temp;
    }
}

```


# 快速排序 #

快速排序使用分治法来把一个串分为两个子串。具体算法描述如下：

从数列中挑出一个元素，称为 “基准”（pivot）；

重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；

**递归地（recursive）**把小于基准值元素的子数列和大于基准值元素的子数列排序。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/quicksort.gif?raw=true)

也就是说，通过一趟排序将要排序的数据分割成独立的两部分，**其中一部分的所有数据都比另外一部分的所有数据都要小**，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

一开始我也想自己写一个代码……后来想了一个多小时也没有写出来……

后来借鉴网上的代码，写出来如下的版本：

```C

#include <stdio.h>

void quick_sort(int*numbers,int begin,int end); 
void swap(int*num1,int*num2);

int main() {
	int maxlen=0;
    int numbers[100]={0};
    int i=0;

    scanf("%d",&maxlen);
    
	for(i=0;i<maxlen;i++) {
 		scanf("%d",&numbers[i]);
	}
    
    quick_sort(numbers,0,maxlen-1); 

    for(i=0;i<maxlen;i++) {
    	printf("%d ",numbers[i]);
	}
	printf("\n");
    
    return 0;
}


void swap(int*num1,int*num2) {
    int temp;
 
    temp=*num1;
    *num1=*num2;
    *num2=temp;
 
    return ;
}
 

void quick_sort(int*numbers,int begin,int end)
{
    int i=0,j=0;
 
    if(begin<end)
    {
        i=begin+1; 
        j=end;        
          
        while(i<j)
        {
            if(numbers[i]>numbers[begin])  
            {
                swap(&numbers[i], &numbers[j]);  
                j--;
            }
            else
            {
                i++;  
            }
        }

 
        if(numbers[i]>=numbers[begin]) {
            i--;
        }
 
        swap(&numbers[begin],&numbers[i]); 
        
        quick_sort(numbers,begin,i);
        quick_sort(numbers,j,end);
        
    }
}

```

写完代码后，对快速排序的认识就更深刻了，比如，begin的值一定要小于end，因为要排序的对象里至少要有一个数；每一次while语句的退出条件都是在i=j的条件下，也就是此时数组被分割成了两个部分，[begin+1]--[i-1]和[i+1]--[end]，其中前一块的元素都比基准值要小，后一块的元素都比基准值大。

