> 地址：https://www.bilibili.com/video/BV1nb4y1Q7gg

---

QWidget是不带菜单栏的，QMainWindow是带菜单栏的。

---



## 关于qt中的信号

QT中自定义信号
在实际的项目开发中，大多数时候是直接将组建中预定义的信号连接到槽函数；信号发射时槽函数被调用。

问题：信号是怎么来的？又是如何发射的？

**Qt中信号（SIGNAL）的本质**
**信号指示一个特殊的成员函数声明**

**函数的返回值是void类型**
**函数只能声明不能定义**
**信号必须使用signals关键字进行声明**
**函数的访问属性自动被设置为protected**
**只能通过emit关键字调用函数（发射信号）**
————————————————
版权声明：本文为CSDN博主「食梦少年」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/small_prince_/article/details/96106202





可以通过信号--->槽函数---->发布信号来修改发出的信号。

也就是这样：

```cpp
// 连接信号与槽函数
connect(b1,QPushButton::clicked,this,SubWidget::sendSlot);

// 槽函数定义，发送信号
void SubWidget::sendSlot()
{
    emit my_signal();
    emit my_signal(250,"我是小弟，请求切换到大哥\n");
}

```



---



