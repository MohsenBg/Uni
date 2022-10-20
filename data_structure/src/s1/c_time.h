#ifndef C_TIME_H
#define C_TIME_H
#include <chrono>
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

class time_handler {
public:
  template <typename A>
  static RES_CAL_TIME<A> calcuate_time(A (*func)(A), A arg) {
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
};
#endif
