#pragma once

template <class T>
class Queue {
 private:
  //  嵌套类
  class Node {
    // 外层是不能访问私有内容的
   public:
    T val;
    Node* next;
    explicit Node(T v) : val(v) {};
  };
  Node* node = nullptr;

 public:
  ~Queue();
  bool enqueue(const T& item);
  bool dequeue(T& item);
  bool isEmpty() const;
};

template <class T>
Queue<T>::~Queue() {
  Node* n = node;
  while (n) {
    auto tmp = n;
    n = n->next;
    delete tmp;
  }
}

template <class T>
bool Queue<T>::isEmpty() const {
  return node == nullptr;
}
template <class T>
bool Queue<T>::enqueue(const T& item) {
  Node* cur = new Node(item);
  if (node == nullptr) {
    node = cur;
  } else {
    node->next = cur;
  }

  return true;
}
template <class T>
bool Queue<T>::dequeue(T& item) {
  if (isEmpty()) {
    return false;
  }
  Node* prev = node;
  Node* last = node;
  while (last->next) {
    prev = last;
    last = last->next;
  }
  item = last->val;
  if (prev == last) {
    node = nullptr;
  } else {
    prev->next = nullptr;
  }

  return true;
}