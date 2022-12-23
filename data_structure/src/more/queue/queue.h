#ifndef QUEUE_H
#define QUEUE_H
#include "tabulate.hpp"
#include <iostream>
#include <vector>
using namespace tabulate;
using namespace std;

class queue {
private:
  int *storage;
  int copacity;
  int len;
  int front;
  int rear;

  void addfront() {
    if (front >= copacity - 1)
      this->front = 0;
    else
      this->front++;
  }

  void addrear() {
    if (rear >= copacity - 1)
      this->rear = 0;
    else
      this->rear++;
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

    storage[this->front] = value;
    this->len++;
    this->addfront();
  }

  int remove() {
    this->len--;
    int oldValue = storage[this->rear];
    this->addrear();
    return oldValue;
  }

  void logStorage() {
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

  void logQueue() {
    Table result;
    Table::Row_t row;

    int index = this->rear;
    int hlep = this->length();
    while (hlep != 0) {
      if (index >= this->copacity)
        index = 0;

      row.push_back(to_string(storage[index]));
      index++;
      hlep--;
    }

    result.add_row(row);
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
