#pragma once

typedef unsigned long Item;
class Stack {
 private:
  const static int MAX = 10;
  Item items[MAX];
  int top = 0;

 public:
  Stack();
  //   按引用传递
  bool pop(Item&);
  bool push(const Item&);
  bool is_full() const;
  bool is_empty() const;
};