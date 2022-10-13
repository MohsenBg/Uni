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

template <typename T> T get_input(string msg);
unsigned long int safe_multiply(unsigned long int num1, unsigned long int num2);
unsigned long int recursive_fac(unsigned long int num);
unsigned long int linear_fac(unsigned long int num);
template <typename A> RES_CAL_TIME<A> calcuate_time(A (*func)(A), A arg);

int main() {
  cout << "\n";
  unsigned long int number = get_input<long int>("Enter number:");

  auto recursive_res = calcuate_time<unsigned long int>(&recursive_fac, number);
  auto linear_res = calcuate_time<unsigned long int>(&linear_fac, number);

  cout << "\nname_function\t\t time\t\tresult \n";
  cout << "===============================================\n";

  cout << "linear_fac\t\t " << linear_res.run_time.count() << "ns"
       << "\t\t" << linear_res.value << endl;

  cout << "recursive_fac \t\t " << recursive_res.run_time.count() << "ns"
       << "\t\t" << recursive_res.value << endl;

  cout << "\n\n";
  return 0;
}

// check overflow
unsigned long int safe_multiply(unsigned long int num1,
                                unsigned long int num2) {

  // check formol overflow on multiply
  // num1 * num2 = res
  // res / num2 = num1
  long int res = num1 * num2;
  long int check_div = res / num2;

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

unsigned long int recursive_fac(unsigned long int num) {
  if (num <= 1)
    return num;

  return safe_multiply(num, recursive_fac(num - 1));
}

unsigned long int linear_fac(unsigned long int num) {
  if (num <= 1)
    return num;
  long int res = 1;
  for (long int i = num; i > 1; i--) {
    res = safe_multiply(i, res);
  }
  return res;
}

template <typename A> RES_CAL_TIME<A> calcuate_time(A (*func)(A), A arg) {
  // save Start Time
  auto start_time = high_resolution_clock::now();
  unsigned long int res = func(arg);
  // save End Time
  auto end_time = high_resolution_clock::now();
  // calcuate time
  auto time = duration_cast<nanoseconds>(end_time - start_time);

  // return Struc
  //  value: factoral result
  //  time:  total time function execute
  return RES_CAL_TIME<A>(res, time);
}
