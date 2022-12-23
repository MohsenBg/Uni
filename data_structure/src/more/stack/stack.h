#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
class CustomStack {
private:
  int copacity;
  int len;
  int *storage;
  void OutRangeError() {
    cout << "Error: Out of Range Index" << endl;
    exit(1);
  };

public:
  CustomStack(int size) {
    this->copacity = size;
    len = 0;
    storage = new int[size];
  }

  void Push(int value) {
    if (this->IsStackFUll())
      this->OutRangeError();
    this->storage[len] = value;
    len++;
  }

  int pop() {
    if (this->IsStackEmpty())
      this->OutRangeError();
    len--;
    return this->storage[len];
  }

  bool IsStackEmpty() { return len == 0; }
  bool IsStackFUll() { return len == copacity; }
  int Capacity() { return this->copacity; }
  int Length() { return this->len; }
};

#endif
