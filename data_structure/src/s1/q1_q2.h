#ifndef Q1_Q2_H
#define Q1_Q2_H
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

template <typename A> struct RES_CAL_TIME {
  A value;
  duration<long, ratio<1, 1000000000>> run_time;
  RES_CAL_TIME(A _value, duration<long, ratio<1, 1000000000>> _run_time) {
    value = _value;
    run_time = _run_time;
  }
};

// check overflow
unsigned long long safe_multiply(unsigned long long num1,
                                 unsigned long long num2) {

  // check formol overflow on multiply
  // num1 * num2 = res
  // res / num2 = num1
  long long res = num1 * num2;
  long long check_div = res / num2;

  // check over flow  if overflow happend app panic and exit with code 1
  if (check_div != num1) {
    cout << "panic cause:overflow multiply "
         << "'" << num1 << "'"
         << " * "
         << "'" << num2 << "'" << endl;
    exit(1);
  }
  return res;
}

template <typename T> T get_input(string msg) {
  T input;

  // Make sure user Enter valid type input.
  // App panic when user Enter negetive number
  while (cout << msg && !(cin >> input)) {
    // remove cin error flag
    cin.clear();
    // empty buffer
    cin.ignore();
    cout << "invaild input Try Again\n";
  }
  return input;
}

unsigned long long recursive_fac(unsigned long long num) {
  if (num <= 1)
    return 1;

  return safe_multiply(num, recursive_fac(num - 1));
}

unsigned long long iteration_fac(unsigned long long num) {
  long long result = num;

  if (result == 0)
    result += 1;

  while (num > 2) {
    num -= 1;
    result = safe_multiply(num, result);
  }

  return result;
}

template <typename A> RES_CAL_TIME<A> calcuate_time(A (*func)(A), A arg) {
  // save Start Time
  auto start_time = high_resolution_clock::now();
  unsigned long long res = func(arg);
  // save End Time
  auto end_time = high_resolution_clock::now();
  // calcuate time
  auto time = duration_cast<nanoseconds>(end_time - start_time);

  // return Struc
  //  value: factoral result
  //  time:  total time function execute
  return RES_CAL_TIME<A>(res, time);
}
#endif //