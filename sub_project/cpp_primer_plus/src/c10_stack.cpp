#include "./c10_stack.h"

bool Stack::pop(Item& item) {
  if (top == 0) {
    return false;
  }
  item = items[--top];
  return true;
}

bool Stack::push(const Item& item) {
  if (top == MAX) {
    return false;
  }
  items[top++] = item;
  return true;
}

bool Stack::is_empty() const {
  return top == 0;
}

bool Stack::is_full() const {
  return top == MAX;
}

Stack::Stack() {}