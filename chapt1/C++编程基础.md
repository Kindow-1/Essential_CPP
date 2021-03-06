## C++编程基础

### 1.1 如何撰写 C++程序

###### 对一个完整的C++程序的逐句解释。

##### 1_01.cpp

std是标准库所驻之**命名空间**的名称，标准库所提供的任何事物（例如string class以及cout、cin这两个iostream类对象）都被封装在命名空间std内。

**命名空间**是一种将库名称封装起来的方法。通过这种方法可以避免和应用程序发生命名冲突的问题。命名空间就像是在众多名称的可见范围之间竖起的一道道围墙。

若要使用cin、cout这两个iostream类对象，我们不仅需要包含<iostream>头文件，还得让命名空间std内的名称曝光。而所谓的using directive：

```c++
using namespace std;
```

便是让命名空间中的名称曝光的最简单方法。

### 1.2 对象的定义与初始化

###### 合法赋值（数据类型和对象名称）、各种关键字，两种初始化语法

##### 1_02.cpp

合法的对象名称：

- 大小字母有所区分

- 不能以数字开头
- 不能和关键字完全一致

初始化语法：

1.使用=运算符

```c++
int num_tries = 0;
```

2.构造函数语法

```c++
#include <complex>
complex<double> purei(0, 7); //多值初始化
int num_tries(0); //单值初始化
```

