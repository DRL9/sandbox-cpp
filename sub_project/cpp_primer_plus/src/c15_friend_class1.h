#pragma once

class Tv {
 public:
  // 友元类, 可以访问自身的私有字段
  friend class Remote;

 private:
  int channel;
};

class Remote {
 public:
  void set_channel(Tv& tv, int channel) { tv.channel = channel; };
};