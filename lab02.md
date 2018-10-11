---
**不会JavaScript、CSS？新手小白一样可以制作自己的第一个网页游戏！**
---

&#8195;要想完成网页游戏的设计，我们需要一个HTML5游戏快速开发工具。借助它们，我们不需要很高深的技术就可以开发出优秀、好玩的游戏！

&#8195;首先，先来推荐几款适合入门级的新手所使用的游戏开发工具吧！

1.**GameMaker**

![](https://images0.cnblogs.com/blog/36987/201310/31152417-acb0dc8b7a674c58bccfa86e2a31442a.png)

&#8195;GameMaker 既适合入门级的新手，也同样适合经验丰富的游戏开发人员，帮助他们创建跨平台的游戏。

&#8195;GameMaker 除了使比普通开发模式快 80% 以外，开发人员还可以创建功能全面的原型，在短短几个小时内或者一个星期内，创建一个完整的游戏。

[https://www.yoyogames.com/gamemaker](https://www.yoyogames.com/gamemaker)

2.**Construct 2** 

![](https://images0.cnblogs.com/blog/36987/201310/31152810-7ec0e16e6d2c4e60bc24dfe19d450cf2.jpg)

&#8195;功能强大的 HTML5 游戏开发工具，借助可视化开发界面，开发者无需编写任何代码就可以创建游戏。拥有强大的事件系统，灵活的行为以及很炫的视觉效果。

[https://www.scirra.com/construct2](https://www.scirra.com/construct2)

下面我们以Construct 2为例，详细讲述一款最基本的网页游戏制作。

以下是我们会用到的图片素材，单击右键将它们保存到本地。

![](https://img.heypik.com/background/20180814/heypik-taobao-vector-cartoons-swallows-summer-outskirts-blue-sky-posters-background_28303607.jpg?x-oss-process=image/watermark,image_c2h1aXlpbl9uZXcucG5n,g_center)

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQL08xcv5lb3kKZ_sVd8Yv_QSNJ5RWMoQdfuehSFrIYDpOdVRegfA)

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSi2OS9hJNETSpmc4wfURerdaGcncLvhkS65OqikFo4hGSoqja3bA)

![](http://pic.90sjimg.com/design/00/64/37/06/592d664554553.png)

![](http://img2.3png.com/86c683fa6ad80fa53a09d035cc14a55cda2c.png)

首先，新建一个项目。点击File，然后选择New。

![](https://www.scirra.com/images/articles/newprojdialog65.png)


选择第一个默认设置即可，点击Open。

让我们先把画布背景加进去。双击layout1空白处或是单击右键选择insert new object均会弹出如下的对话框。

我们选择插入Tiled Background，点击insert。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/2.jpg?raw=true)

注意，这个时候你的鼠标已经变成了一个十字准线。在布局的中间位置单击左键，就会弹出一个如下的小窗口。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/3.jpg?raw=true)

点击红色部分圈出的区域，选择本地的图片，将刚刚保存的背景图插入。关闭小窗口后，你就可以在布局中看到背景图片了！

咦！好像背景图片的大小不太对？没关系，我们可以调整它而使它覆盖整个布局。单击布局，左侧就会出现其属性栏，如图，可以在size中调整它的大小。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/6.jpg?raw=true)

将Tiled Background的大小改成和layout的大小参数相同，再通过鼠标的拖拉，即可将布局填满。

同时，按住control键鼠标向下滚动即可缩小，向上滚动即可放大。


为了避免之后添加更多对象时会不小心选中背景，我们需要将它锁上。在右边的任务栏中选择layers。


我们的背景层被命名为了Layer 0，当我们还需要新建其他图层时，容易引起混淆，并不能给我们提供有用的信息。因此建议将它重命名位Background。点击前面的小锁图标就可以将该图层锁上，这样我们就不会在操作其他图层时不小心选中背景层了。（如果之后想对背景层进行改动，单击小锁图标即可解锁。）同时，点击上方的添加符号，新建一个图层，将它重命名位Main。

相信你也已经注意到了，Construct 2从零开始计数，这样的编程效果更好！

回到布局，我们再按之前的插入过程插入两个新对象，keyboard和mouse。（确保你现在处于Main图层！）

看起来似乎没有什么变化？不要担心，这些对象不需要放置在布局中，它们是隐蔽的，并自动在项目范围内工作。你可以在右边的projects中找到他们。这样，我们项目中的所有布局都可以接受鼠标和键盘的输入。

到了该插入游戏对象的时候了！对于每个游戏对象，我们都将使用sprite类型。它只显示一个结构，我们可以对它进行移动、旋转、调整大小等操作。

按照之前插入对象的流程完成插入后，有没有感觉哪里不对劲？？

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/8.jpg?raw=true)

**这个图片好像还带着背景边框呢！**这样大大降低了游戏的美观性，看起来有些奇怪，对吧？

别着急，通过一些巧妙的处理过后我们最终得到了背景为透明色的游戏对象。处理方法会在本文的最后介绍给大家。

重新插入后，看起来是这样的：

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/9.jpg?raw=true)

另一种插入游戏对象的快捷方法是直接将图像从Windows拖放到布局区域。值得注意的是，一次只能拖动一个图像！！如果你一次拖动了四个图像，Construct 2会生成一个带有四个动画帧的sprite。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/10.jpg?raw=true)

现在，将小石子和爆炸移动到布局边缘，我们并不像在游戏的一开始就看到它们。就像刚才重命名图层一样，在每个sprite的属性栏中更改他们的名字为player,worm,stone,explosion。

如果你现在已经有些迫不及待，可以点击界面左上角的run图标，就可以在新打开的网页中看到游戏的雏形了。美中不足的是，这个游戏的所有对象还都只是静态的呢。为了让sprite能够动起来，我们需要对它们添加相应的行为。

在此之前，我们先简单了解一下Construct 2都有哪些行为：

&#8195;1.**8 direction**：我们可以通过箭头键来移动对象；

&#8195;2.**Bullet**：即以当前角度以某种速度向前移动一个物体；

&#8195;3.**Scroll to**:屏幕在对象移动时会自动跟随；

&#8195;4.**Bound to layout**:阻止一个物体离开布局区域，使玩家不能在布局区域以外游荡。

&#8195;5.**Destroy outside layout**:当一个物体离开布局区域时摧毁它。否则，我们的小石块将永远飞离屏幕，占用内存和处理能力。

&#8195;6.**Fade**:物体逐渐淡出。

下面我们开始对sprite对象增加行为。

点击要添加行为的对象，在左侧的属性栏中找到Behaviors，在弹出的窗口中点击新建的按钮。（11）


选择要增加的行为，点击add。

这是你要分别增加的行为：

1.player：8 Direction,Scroll to,Bound to layout;

2.worm：Bullet Movement;

3.stone:Bullet Movement,Destroy outside layout;

4.explosion:Fade.

点击预览。

有没有感觉小虫子的速度有点快？单击worm，在左侧的属性栏中调整它的速度大小，为了降低难度，可以适当降低它的速度。


![](https://www.scirra.com/images/articles/bulletproperties.png)

同样，将小石头的速度适当增加，并且也可以修改爆炸时的淡出时间。

回想一下你平时玩过的小游戏，只有一个敌人会不会太少了？如果想要增加更多的敌人，难道真的需要一个一个的添加sprite再一一设置行为吗？

尝试按住control，单击小虫子，对它进行拖拽。看看会发生什么？

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/12.jpg?raw=true)

点开看看这些对象的属性，也都跟我们刚刚设置过的相同。这样大大提高了游戏设计的效率。

注意多个虫子的放置位置，不要让它太靠近玩家，以免直接造成游戏结束。


现在，让我们点开event sheet 1。

你现在可以看到，Construct 2每秒都会按照从上到下的顺序会运行60次事件列表，每一次都会重新刷新屏幕。在事件运行之前，需要先判断所有的条件是否都满足。如果都满足了，就开始运行事件，否则就跳到下一个事件，不执行任何的子事件。


现在让我们加入第一个事件。增加了这个事件后，我们可以让player一直面向鼠标。

单击add event，选择system，将条件设为every tick，双击它。

现在，点击右侧的add action。因为我们的事件要求player一直面向鼠标，因此它是我们的操作对象。

在行为列表中选择set angle toward position。

![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/14.jpg?raw=true)

Construct 2需要知道x,y的坐标以确定player朝向的位置。分别输入Mouse.X和Mouse.Y作为行为的参数。(如果有提示Mouse不是一个对象名，是因为之前在布局没有插入mouse的对象）

完成之后尝试运行游戏。

![](https://github.com/GUOJIAYII/swi-homework/raw/gh-pages/images/1.gif)

让我们继续添加其他操作：

&#8195;条件:Mouse - > On click - >left（默认值）

&#8195;操作：player - >spawn another project - >stone,layer 1,image point 0。


为了让玩家单击左键能够发射石子，我们还要添加以下事件：

&#8195;条件: Mouse -> On click -> Left clicked（默认） 

&#8195;操作：Player -> Spawn another object -> stone，layer1 

为了让石子能够击杀小虫子，添加以下事件：

&#8195;条件: stone -> On collision with another object ->worm 

&#8195;操作: worm -> Destroy

&#8195;操作: stone -> Spawn another object -> Explosion, layer 1

&#8195;操作: stone -> Destroy

预览游戏的时候，小虫子只向着单一的方向运动，是不是有些枯燥乏味呢？别担心，我们可以添加新事件来使他们向任意方向运动，如果还想要更刺激的游戏体验，甚至可以向着玩家的方向前进！

&#8195;条件: System -> On start of Layout

&#8195;操作: worm -> Set angle -> random(360)

条件: worm -> Is outside layout

操作: worm -> Set angle toward position -> For X, Player.X - for Y, Player.Y.

![](https://github.com/GUOJIAYII/swi-homework/raw/gh-pages/images/2.gif)

如果你觉得虫子被击中一次后就死掉太没意思了，我们也可以通过左侧属性栏中的instance variables来设定每只虫子的生命值。每击中一次生命值减一，当生命值小于等于零时，虫子被摧毁。

在左侧的属性栏中新建一个instance variables，命名为Life，并赋予其初始值为9。

进一步，我们需要修改之前的事件将 worm -> Destroy依次改成下图所示：

![](https://www.scirra.com/images/articles/sub1fromhealth.png)

当生命值小于等于0时，虫子被摧毁：

![](https://www.scirra.com/images/articles/monsternohealth.png)

下面，我们还要进一步优化一下这个游戏。比如，我们仍然需要一个变量来显示玩家的得分。但是注意，这次我们并不能像之前的生命值一样，选择instance variables的类型。这种类型的变量都是存储在游戏对象中的，如果玩家被击杀，游戏结束，那这个变量也将不复存在。

相对应，我们采取全局变量的形式。在空白处单击右键新建一个全局变量命名为Score。

在虫子得到生命值小于等于0的条件下，新增一个行为system ->add 1 to Score。

为了显示玩家的得分，我们需要新建一个HUD图层。

值得注意的是，当我们玩游戏的时候，并不希望这些显示的信息也跟着一起移动，我们希望它能一直保持在原地。但是默认情况下，图层会进行滚动。因此为了保持相对静止，我们可以将视差设为0。

在左侧的属性栏中将HUD的Parallax属性设置为0,0。插入Text对象，为了使效果更明显，在属性栏中设为粗体，也可以改变字号和颜色。

回到event sheet，在第一个事件中增加行为 Text -> Set text->"Score: " & Score。

为了增加游戏难度，我们使小虫子可以“自我繁殖”，每3秒在布局中随机出现一只虫子，并且玩家与虫子相碰时，玩家死亡，游戏结束。

创建一个新事件：

&#8195;条件: System -> Every X seconds -> 3

&#8195;操作: System -> Create object -> worm, layer 1, 1400 (for X), random(1024) (for Y)

&#8195;条件: worm -> On collision with another object -> Player

&#8195;操作: Player -> Destroy

游戏终于制作好了！快玩玩看吧！



![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/3.gif?raw=true)

# 如何简单的将图片的背景透明化 #

还记得我们当初插入的带有边框背景的游戏对象吗？一开始为了能去掉它还费了很大的劲，尝试过在线去背景的各种网站，甚至想重新下载Photoshop进行抠图......但是后来从网上的教程里学到了一分钟就能将背景透明化的技巧！

首先，新建一个Powerpoint。新添加一张幻灯片后，将背景的颜色设置为与所需要图片的背景相差较大的颜色。

插入要调整的图片后，在格式中选择将图片的背景透明化。


![](https://github.com/GUOJIAYII/swi-homework/blob/gh-pages/images/15.jpg?raw=true)

即可得到背景透明的图片。

**注意：**不要将图片另存为后插入到布局中，这样还是有白色的背景！！！只要复制粘贴即可！