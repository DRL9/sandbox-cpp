// 用来防止重复声明头文件 ， 更为现代的做法
#pragma once

namespace jack {
// 对于变量， 在头文件只是声明， 而在源文件中初始化， 不然会报错： duplicate
// symbols
extern int pos;
// 嵌套名称空间
namespace foo {
// 也可以声明为内部链接性， 这样子每个引用该头文件的， 使用的是独立的 book_size
// 副本
static int book_size = 1;
}  // namespace foo

void hello();

}  // namespace jack
