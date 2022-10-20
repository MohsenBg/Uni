#include "c_time.h"
#include "factorial.h"
#include "input.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

int main() {
  cout << "\n";

  unsigned long long number =
      input_handler::get_input<unsigned int>("Enter number:");
  auto recursive_res =
      time_handler::calcuate_time<unsigned long long>(&recursive_fac, number);
  auto linear_res =
      time_handler::calcuate_time<unsigned long long>(&iteration_fac, number);

  cout << "\nname_function\t\t time\t\tresult \n";
  cout << "===============================================\n";

  cout << "iteration_fac\t\t " << linear_res.run_time.count() << "ns"
       << "\t\t" << linear_res.value << endl;

  cout << "recursive_fac \t\t " << recursive_res.run_time.count() << "ns"
       << "\t\t" << recursive_res.value << endl;

  cout << "\n";
  return 0;
}
