---
**用伪代码表示洗衣机控制程序**
---
1）请使用伪代码分解“正常洗衣”程序的大步骤。包括注水、浸泡等：

```

	pour water
	soak clothes
	wash clothes
	rinse clothes
	dehydrate clothes
	discharge water

```

2）进一步用基本操作、控制语句（IF、FOR、WHILE等）、变量与表达式,写出每个步骤的伪代码:

```

	SET standard_water_volume=n
	SET soak_time=time1
	SET standard_wash_time=time2

	WHILE get_water_volume() <n
		water_in_switch(open)
	ENDWHILE
	water_in_switch(close)		//注水到指定高度

	WHILE time_counter()<time1
		wait
	ENDWHILE				//在指定的时间浸泡衣物
	
	time_counter()=0		//将时间计数清零
	
	WHILE time_counter()<time2
		motor_run(left)
	ENDWHIE				
	
	time_counter()=0	
	
	WHILE time_counter()<time2
		motor_run(right)
	ENDWHILE
	
	time_counter()=0		//按照指定的时间洗涤衣服

	WHILE get_water_volume()>0
		water_out_switch(open)
	ENDWHILE
	water_out_switch(close)			//将洗衣机中的水排出

	WHILE time_counter()<time2
		motor_run(left)
	ENDWHIE				
	
	time_counter()=0	
	
	WHILE time_counter()<time2
		motor_run(right)
	ENDWHILE
	
	time_counter()=0		//按照指定的时间清洗衣服

	WHILE get_water_volume()>0
		water_out_switch(open)
	ENDWHILE
	water_out_switch(close)			//将洗衣机中的水排出

	WHILE time_counter()<time2
		motor_run(left)
	ENDWHIE				
	
	time_counter()=0	
	
	WHILE time_counter()<time2
		motor_run(right)
	ENDWHILE
	
	time_counter()=0			//将衣服脱水甩干

	halt(returncode)		//洗衣完成


```

3）根据你的实践，请分析“正常洗衣”与“快速洗衣”在用户目标和程序上的异同。你认为是否存在改进（创新）空间，简单说明你的改进意见？

我认为“正常洗衣”大多用于家用，对洗衣的时间长度没有太高的要求，比较要求衣服的清洗干净的程度，因此这种模式的程序会将洗衣时间设置的长一点，并且可以多次进行清洗，而不只是简单的一次洗涤和漂洗。
	
与之相对，“快速洗衣”模式更适合独自使用，比如男生打球运动后需要清洗衣服，但又不能花太长的时间去等待；或者外出在宾馆中有衣物需要清洗，这就需要能够减少洗衣时间，尽快洗好。这种情况下并不过多要求衣服洗得特别干净，因此这种模式的程序会在能够洗干净衣服的前提下，将洗衣时间设置的尽可能短，并且洗衣次数也会尽可能的减少。

从上面伪代码的编写程序中，我们可以很明显的体会出来其实洗衣机的程序无非就是加水、转动清洗、排水、转动脱水几部组成，但是因为这几部分没有单独提炼出来，导致程序很复杂，不能让人一眼就看明白。所以不妨将这几部分作为子程序，以简化这个程序。同时，可以适当的对这些模块添加一些参数，使之更简单易读。

4）通过步骤3），提取一些共性功能模块（函数），简化“正常洗衣”程序，使程序
变得更利于人类理解和修改维护。


我们可以将这些功能模块分为：

1.注水到指定高度&#8195;2.浸泡时等待一段时间&#8195;3.洗衣机向某个方向进行转动一段时间&#8195;4.排水
	
理清这些共有的功能模块后，我们发现伪代码流程会大大简化！

比如，注水到指定高度，只要设置好一个参数，那么这个函数块不仅在“正常洗衣”的模式中可以应用，在其他模式中也可以使用这个功能块！同时，只要通过设置好的参数告诉洗衣机向哪个方向转动、转动多长时间，那么洗涤、漂洗和脱水的流程都只需要调用这个函数即可！

先写好这些功能模块：


```

pour_water (standard _ water _ volume)

	WHILE get_water_volume() <standard _water _ volume
		water_in_switch(open)
	ENDWHILE
	water_in_switch(close)		//注水到指定高度
	
```

```

wait(time)

	WHILE time_counter()<time
		
	ENDWHILE		

```

```

motor_run(direction,time)
		
	WHILE time_counter()<time
		motor_run(direction)
	ENDWHILE

```

```

discharge_water()

	WHILE get_water_volume() > 0
		water_out_switch(open)
	ENDWHILE
	water_out_switch(close)

```

然后，在这个基础上，我们之前的伪代码可以化简成如下：

```
pour_water(standard _water _ volume)

wait(time1)				//浸泡

motor_run(left,time2)

motor_run(right,time2)		//洗涤

discharge_water()

pour_water(standard _water _ volume)

motor_run(left,time2)

motor_run(right,time2)			//清洗

discharge_water()

motor_run(left,time2)

motor_run(right,time2)			//脱水

```

