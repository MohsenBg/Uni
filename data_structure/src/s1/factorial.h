#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <iostream>
using namespace std;
// extern keyword for sharing that function with rust for testing
//  check overflow
extern "C++" unsigned long long safe_multiply(unsigned long long num1,
                                              unsigned long long num2) {

  // check formol overflow on multiply
  // num1 * num2 = res
  // res / num2 = num1
  unsigned long long res = num1 * num2;
  unsigned long long check_div = res / num2;

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

extern "C++" unsigned long long recursive_fac(unsigned long long num) {
  if (num <= 1)
    return 1;

  return safe_multiply(num, recursive_fac(num - 1));
}

extern "C++" unsigned long long iteration_fac(unsigned long long num) {
  unsigned long long result = num;

  if (result == 0)
    result += 1;

  while (num > 2) {
    num -= 1;
    result = safe_multiply(num, result);
  }

  return result;
}

#endif //
