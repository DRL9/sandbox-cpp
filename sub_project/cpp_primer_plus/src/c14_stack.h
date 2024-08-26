#pragma once

template <class T>
class Stack {
 private:
  T* items;
  int stack_size;
  int top;

 public:
  explicit Stack(int s = 10);
  Stack(const Stack& s);
  ~Stack() { delete[] items; };
  bool is_full() const { return top >= stack_size; }
  bool push(const T&);
  bool pop(T&);
  Stack<T> operator=(Stack<T>& s);
};

template <class T>
Stack<T>::Stack(int s) : stack_size(s), top(0) {
  items = new T[stack_size];
}

template <class T>
Stack<T>::Stack(const Stack& s) {
  stack_size = s.stack_size;
  items = new T[stack_size];
  for (int i = 0; i < stack_size; i++) {
    items[i] = s.items[i];
  }
  top = 0;
}

template <class T>
bool Stack<T>::push(const T& item) {
  if (top >= stack_size) {
    return false;
  }
  items[top++] = item;
  return true;
}

template <class T>
bool Stack<T>::pop(T& item) {
  if (top == 0) {
    return false;
  }
  item = items[--top];
  return true;
}

template <class T>
Stack<T> Stack<T>::operator=(Stack<T>& s) {
  if (&s == this) {
    return *this;
  }
  delete[] items;
  stack_size = s.stack_size;
  top = s.top;
  items = new T[stack_size];
  for (int i = 0; i < stack_size; i++) {
    items[i] = s.items[i];
  }

  return *this;
}