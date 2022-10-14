#include "q1_q2.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

int main() {
  cout << "\n";
  unsigned long long number = get_input<unsigned int>("Enter number:");
  auto recursive_res =
      calcuate_time<unsigned long long>(&recursive_fac, number);
  auto linear_res = calcuate_time<unsigned long long>(&iteration_fac, number);

  cout << "\nname_function\t\t time\t\tresult \n";
  cout << "===============================================\n";

  cout << "iteration_fac\t\t " << linear_res.run_time.count() << "ns"
       << "\t\t" << linear_res.value << endl;

  cout << "recursive_fac \t\t " << recursive_res.run_time.count() << "ns"
       << "\t\t" << recursive_res.value << endl;

  cout << "\n";
  return 0;
}
