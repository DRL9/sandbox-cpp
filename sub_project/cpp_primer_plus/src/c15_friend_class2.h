#pragma once

// 要有前置声明， Remote 才知道 Tv 是一个 class
class Tv;
class Remote {
 public:
  void set_channel(Tv& tv, int channel);
};

class Tv {
 public:
  //  友元成员函数
  friend void Remote::set_channel(Tv&, int);

 private:
  int channel;
};

// 在头文件中， 应该用内联方法， 不然就放在源文件中
inline void Remote::set_channel(Tv& tv, int channel) {
  tv.channel = channel;
}