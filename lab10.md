---
**Python**
---

# 高数作业 #

利用Python可以十分容易地进行求导、求极限、求定积分或不定积分、微分方程等计算。

比如，我们先进行一次**求函数极限**：

$$\lim_{x\to +\infty} {(1-\frac{1}{n})}^{n^2} $$ 

说实话，如何证明这个极限是0还花了我挺长时间的.....

但是使用python，简单输入这一行式子，就可以得到：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E6%9E%81%E9%99%901.png?raw=true)

 再换一个难一点的函数极限：

$$\lim_{x\to 0} \frac{\sqrt[3]{1+3x}-\sqrt[3]{1-2x}}{x+x^2} $$

如果使用夹逼定理，不好把握放缩的程度，但是使用python...

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E6%9E%81%E9%99%902.png?raw=true)

再尝试**对函数求导**：

$$ y=\frac{x}{2}\sqrt{x^2+a^2}+\frac{a^2}{2}arcsin\frac{x}{a} $$

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E5%AF%BC.png?raw=true)

现在，尝试利用python进行**积分**的计算：

这是定积分的计算：

$$ \int_{0}^{1} \sqrt{2+x-x^2}dx  $$

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E5%AE%9A%E7%A7%AF%E5%88%86.png?raw=true)

这是不定积分的计算：



# 线性代数 #


利用python**解线性方程组**：

 x + 2y + z = 7

2x - y + 3z = 7

3x + y + 2z = 18

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E8%A7%A3%E7%BA%BF%E6%80%A7%E6%96%B9%E7%A8%8B%E7%BB%84.png?raw=true)

利用python求**矩阵的逆**

先看一个2&times;2的矩阵：

$$ \begin{bmatrix} 1 & 2 \\ 4 & 7 \\ \end{bmatrix} $$

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E7%9F%A9%E9%98%B5%E7%9A%84%E9%80%86.png?raw=true)

在判断矩阵的det不为0之后，就可以计算矩阵的逆了。

然后，再看一个3&times;3的矩阵：

$$ \begin{bmatrix} 1 & -2 & 1 \\ 4 & -7 & 3 \\ -2 & 6 & -4\\ \end{bmatrix} $$

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/python%E6%B1%82%E7%9F%A9%E9%98%B5%E7%9A%84%E9%80%863.png?raw=true)



