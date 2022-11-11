#include "./sorting.h"
#include <iostream>
#include <random>

template <typename T> void print_array(T array[], unsigned size);

int main(int argc, char *argv[]) {
  const unsigned size_arr = 10;
  int numbers[size_arr];

  srand(time(NULL));

  for (int i = 0; i < size_arr; i++) {
    int number = 1 + (rand() % 1000);
    numbers[i] = number;
  }

  {
    cout << "Bubble_Sort" << endl;
    int *sorted = sotring::bubble_sort<int>(numbers, size_arr);
    print_array(sorted, size_arr);
    cout << "\n";
    delete[] sorted;
  }
  {
    cout << "Selection_Sort" << endl;
    int *sorted = sotring::selection_sort<int>(numbers, size_arr);
    print_array(sorted, size_arr);
    cout << "\n";
    delete[] sorted;
  }
  {
    cout << "insertion_Sort" << endl;
    int *sorted = sotring::insertion_sort<int>(numbers, size_arr);
    print_array(sorted, size_arr);
    cout << "\n";
    delete[] sorted;
  }
  {
    cout << "Quick_Sort" << endl;
    int *sorted = sotring::quick_sort<int>(numbers, size_arr);
    print_array(sorted, size_arr);
    cout << "\n";
    delete[] sorted;
  }
  cout << "Marge_Sort" << endl;
  int *sorted = sotring::merge_sort<int>(numbers, size_arr);
  print_array(sorted, size_arr);
  delete[] sorted;
  return 0;
}

template <typename T> void print_array(T array[], unsigned size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    cout << array[i];
    if (i != size - 1)
      cout << ",";
  }
  cout << "]\n";
}
