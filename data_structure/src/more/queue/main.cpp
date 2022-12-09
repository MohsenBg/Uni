#include "./queue.h"
#include "iostream"
using namespace std;

int main() {
  queue myQueue = queue(5);

  cout << "\nadd(12)" << endl;
  myQueue.add(12);
  myQueue.log();

  cout << "\nadd(15)" << endl;
  myQueue.add(15);
  myQueue.log();

  cout << "\nadd(16)" << endl;
  myQueue.add(16);
  myQueue.log();

  cout << "\nadd(25)" << endl;
  myQueue.add(25);
  myQueue.log();

  cout << "\nadd(41)" << endl;
  myQueue.add(41);
  myQueue.log();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.log();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.log();

  cout << "\nadd(51)" << endl;
  myQueue.add(51);
  myQueue.log();

  return 0;
}
