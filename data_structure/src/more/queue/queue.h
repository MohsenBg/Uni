#ifndef QUEUE_H
#define QUEUE_H
#include "tabulate.hpp"
#include <iostream>
using namespace tabulate;
using namespace std;

class queue {
private:
  int *storage;
  int copacity;
  int len;
  int front;
  int rear;
  int getIndex() {
    int tmp = this->front;
    if (this->front == copacity - 1)
      this->front = -1;
    return tmp;
  }

public:
  queue(int copacity) {
    this->storage = new int[copacity];
    this->copacity = copacity;
    this->len = 0;
    this->rear = 0;
    this->front = 0;
  }

  void add(int value) {
    if (this->isFull())
      return;

    int index = getIndex();
    storage[index] = value;
    this->len++;
    this->front++;
  }

  int remove() {
    this->len--;
    this->rear++;

    if (this->rear >= copacity)
      this->rear = 0;

    return storage[rear];
  }

  void log() {
    Table result;
    result.add_row({"index", "value", "status"});
    for (int i = 0; i < this->copacity; i++) {
      if (this->rear == i && this->front == i) {
        result.add_row({to_string(i), to_string(storage[i]), "rear/front"});
        continue;
      }
      if (this->rear == i) {
        result.add_row({to_string(i), to_string(storage[i]), "rear"});
        continue;
      }
      if (this->front == i) {
        result.add_row({to_string(i), to_string(storage[i]), "front"});
        continue;
      }
      result.add_row({to_string(i), to_string(storage[i])});
    }

    result.format().padding_right(2).padding_left(2).font_align(
        FontAlign::center);
    result.print(cout);
    cout << endl;
  }

  bool isFull() { return this->len == copacity; }
  bool isEmpty() { return this->len == 0; }
  int length() { return this->len; }
};
#endif
