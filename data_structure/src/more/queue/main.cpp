#include "./queue.h"
#include "iostream"
using namespace std;

int main() {
  queue myQueue = queue(5);

  cout << "\nadd(12)" << endl;
  myQueue.add(12);
  myQueue.logQueue();

  cout << "\nadd(15)" << endl;
  myQueue.add(15);
  myQueue.logQueue();

  cout << "\nadd(16)" << endl;
  myQueue.add(16);
  myQueue.logQueue();

  cout << "\nadd(25)" << endl;
  myQueue.add(25);
  myQueue.logQueue();

  cout << "\nadd(41)" << endl;
  myQueue.add(41);
  myQueue.logQueue();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.logQueue();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.logQueue();

  cout << "\nadd(51)" << endl;
  myQueue.add(51);
  myQueue.logQueue();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.logQueue();

  cout << "\nremove()" << endl;
  myQueue.remove();
  myQueue.logQueue();

  cout << "\nadd(12)" << endl;
  myQueue.add(12);
  myQueue.logQueue();

  cout << "\nadd(15)" << endl;
  myQueue.add(15);
  myQueue.logQueue();

  return 0;
}
