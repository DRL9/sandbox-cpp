// 防止重复定义原型的惯用手法
#ifndef COORD_H_
#define COORD_H_

// 函数外部的都是静态储存
// 静态储存， 外部可访问
// 静态变量， 如果没有显示初始化， 所有值都是0
struct Polar {
  double distance;
  double angle;
};

// 静态储存, 每个 #include 该源文件的， 都会生成独立的 DISTANCE 副本
static int DISTANCE = 10;

void printPoint();

void printOne();

#endif