#include "./stack.h"
#include <iostream>
using namespace std;
int main() {
  const int size = 5;
  int nums[size] = {1, 2, 3, 4, 5};
  CustomStack myStack = CustomStack(size);

  for (int i = 0; i < size; i++) {
    cout << "--------------------------\n";
    cout << "Push => " << nums[i] << endl;
    myStack.Push(nums[i]);
    cout << "len:" << myStack.Length() << endl;
  }

  for (int i = 0; i < size; i++) {
    cout << "--------------------------\n";
    cout << "Pop => " << myStack.pop() << endl;
    cout << "len:" << myStack.Length() << endl;
  }

  return 0;
}
