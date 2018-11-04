---
**逻辑电路设计与运算**
---

&#8195;因为作业中的网址失效，这次作业在辗转了几个网站后终于完成了。但是因为网站的变化，这次作业的内容会与作业中原来的要求有所不同......

在老师的帮助下，我终于会自己连一个基本的逻辑电路了！

比如，我们先连一个最简单的not gate:

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/refined1.jpg?raw=true)

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/refined2.jpg?raw=true)

电阻值的选取是很重要的哦！（其实把电压设为5V完全足够了，但是我觉得它不够亮，为了效果更明显，我设置成了11.7V）

当然了，如果电路涉及到更多的逻辑电路时，用晶体管一个个搭建再加上各种复杂的串并联会把人逼疯的。

比如，我们考虑一下两个三级管并联所形成的NOR gate。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/QQ%E5%9B%BE%E7%89%8720181104110834.jpg?raw=true)

是不是很让人头大？？

这种时候，不妨利用一下软件中自带的逻辑电路原件吧！

首先，我们尝试一下添加 and gate 的演示：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/real%20and%20gate.gif?raw=true)

很容易看出，当两个logic source均为1的时候，小灯泡才会亮，只要有一个logic source变成了0，小灯泡就会熄灭。虽然此时仍有很微弱的电流通过，但是无法让灯泡发光。

因此容易得出 and gate 的真值表如下：

	| IN A | IN B | OUT |
	| 0 | 0 | 0 |
	| 0 | 1 | 0 |
	| 1 | 0 | 0 |
	| 1 | 1 | 1 |

**任务一：建立一个简单电路**

（1）建立非门功能(O = A’)验证电路：

虽然circuit.io上并没有给出not gate,但是......

Everycircuit上的逻辑门很！全！哦！

所以非常简单：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/notgate.gif?raw=true)

很明显，当输入为0的时候小灯泡会发光，当输入为1的时候小灯泡是不亮的。

（2）填写表格：

因此得出真值表：

	| INPUT | OUTPUT |
	| 0 | 1 |
	| 1 | 0 |

（3）选做题：

**如何用 XOR 门作非门:**

考虑到异或门是在两数相同是输出0，两数不同时输出1，而非门只能有一个输入，因此不妨将异或门中的其中一个输入固定为1，只变化另一个输入。因此可知当输入为0时，两数不同，输出1；当输入为1时，两数相同，输出0。

如下：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/xor%20gate%20notgate.gif?raw=true)

很显然，当可变的 logic source 为0的时候小灯泡发光，为1的时候小灯泡熄灭。因此这样就将一个异或门转成了一个非门。

**串联、并联三极管，结果是什么门？**

显然，当串联三极管时，只有当两个三级管全导通时输出才会是0，否则就是1。

画出真值表：

	| IN A | IN B | X |
	| 0 | 0 | 1 |
	| 0 | 1 | 1 |
	| 1 | 0 | 1 |
	| 1 | 1 | 0 |

很显然，这是一个NAND GATE。


同样，当三极管并联时，只要有一个三极管导通，输出就是0，只有两个三极管都不通时，才会输出1。

画出真值表：

	| IN A | IN B | X |
	| 0 | 0 | 1 |
	| 0 | 1 | 0 |
	| 1 | 0 | 0 |
	| 1 | 1 | 0 |

显然，这是一个NOR GATE。

**任务 2：验证电路等价**

（1）分别建立电路 A（B+C）和 AB+AC 在一个界面上。

如图：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/%E8%BF%90%E7%AE%97.png?raw=true)

通过在模拟电路时改变三个 logic source 的输入，可以得到如下的真值表。

（2）并枚举所有可能输入，用真值表记录结果。

	| A | B | C | O1 | O2 |
	| 0 | 0 | 0 | 0 | 0 |
	| 0 | 0 | 1 | 0 | 0 |
	| 0 | 1 | 0 | 0 | 0 |
	| 1 | 0 | 0 | 0 | 0 |
	| 1 | 0 | 1 | 1 | 1 |
	| 1 | 1 | 0 | 1 | 1 |
	| 0 | 1 | 1 | 0 | 0 |
	| 1 | 1 | 1 | 1 | 1 |

由真值表可知，两个电路是完全等价的。

**任务 3：理解存储电路**

（1）按课件 S-R latch 搭建电路：

根据S-R latch的原理图，连接起S-R latch的电路图：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/refined3.jpg?raw=true)

（2）顺序按Set，Reset，并填写以下表格:

同样，模拟电路时改变 logic source，可以看到两盏灯的亮灭情况。

写出真值表：   

	|~SET | ~RESET | Q(X) | ~Q(Y) |
	| 1 | 1 | 0 | 1 |
	| 0 | 1 | 1 | 0 |
	| 1 | 1 | 0 | 1 |
	| 1 | 0 | 0 | 1 |
	| 1 | 1 | 0 | 1 |


**任务 4：设计全加电路**

（1） 画出一位的全加电路:

由全加器的电路图可以很容易的连接出如下的电路图：

 ![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/full%20adder1.png?raw=true)

（2） 画出二位的全加电路:

两位的全加电路原理与一位的电路相同，只需要将第一位输出的C<sub>next</sub>当作下一位中C<sub>in</sub>的输入即可。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/full%20adder2.png?raw=true)
