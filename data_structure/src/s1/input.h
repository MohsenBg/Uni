#ifndef INPUT_H
#define INPUT_H
#include <iostream>
using namespace std;

class input_handler {
public:
  template <typename T> static T get_input(string msg) {
    T input;

    // Make sure user Enter valid type input.
    while (cout << msg && !(cin >> input)) {
      reset_cin();
      cout << "invaild input Try Again\n";
    }
    return input;
  }
  static void reset_cin() {
    // remove cin error flag
    cin.clear();
    // empty buffer
    cin.ignore();
  }
};
#endif
