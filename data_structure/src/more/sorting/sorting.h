#ifndef SORTING_H
#define SORTING_H
#include "./exception_handler.h"
#include <iostream>

using namespace std;

class sotring {
private:
  template <typename T> static void print_array(T array[], int start, int end) {
    cout << "[";
    for (int i = start; i < end; i++) {
      cout << array[i];
      if (i != end - 1)
        cout << ",";
    }
    cout << "]\n";
  }

  template <typename T> struct Array_Info {
    T *array;
    int size;
    Array_Info(T *_array, int _size) {
      array = _array;
      size = _size;
    }
  };

  template <typename T> static bool is_type_number() {
    return is_arithmetic<T>::value;
  };

  template <typename T> static void_t<T> handle_type() {
    try {
      if (!is_type_number<T>())
        throw Excpetion("error:invalid_data_type");

    } catch (const Excpetion &ex) {
      cout << ex.what() << endl;
      exit(1);
    }
  }

  template <typename T>
  static unsigned find_middle(T array[], int low, int hight) {
    T a1 = array[low];
    T a2 = array[(hight - low) / 2];
    T a3 = array[hight];

    if (a1 > a2 && a1 < a3)
      return low;

    if (a2 > a1 && a2 < a3)
      return (hight - low) / 2;

    return hight;
  }

  template <typename T> static int partition(T array[], int low, int hight) {

    int pivot_index = hight;
    T pivot = array[pivot_index];
    int i = low - 1;

    for (int j = low; j < hight; j++) {
      if (pivot > array[j]) {
        i++;
        swap(array[i], array[j]);
      }
    }

    int new_pivot_postion = i + 1;
    swap(array[new_pivot_postion], array[pivot_index]);
    return new_pivot_postion;
  }

  template <typename T> static void _quick_sort(T array[], int low, int hight) {
    if (hight > low) {
      int ptr = partition(array, low, hight);
      _quick_sort(array, low, ptr - 1);
      _quick_sort(array, ptr + 1, hight);
    }
  }

  template <typename T>
  static void merge(Array_Info<T> main, Array_Info<T> left,
                    Array_Info<T> right) {
    int main_counter = 0;
    int left_counter = 0;
    int right_counter = 0;

    while (left_counter < left.size && right_counter < right.size) {
      if (right.array[right_counter] > left.array[left_counter]) {
        main.array[main_counter] = left.array[left_counter];
        left_counter++;
      } else {
        main.array[main_counter] = right.array[right_counter];
        right_counter++;
      }
      main_counter++;
    }

    while (left_counter < left.size) {
      main.array[main_counter] = left.array[left_counter];
      left_counter++;
      main_counter++;
    }

    while (right_counter < right.size) {
      main.array[main_counter] = right.array[right_counter];
      right_counter++;
      main_counter++;
    }
  }

  template <typename T> static void _merge_sort(T array[], int size) {
    if (size < 2)
      return;

    int mid = size / 2;
    int right_size = size - mid;

    // Make two array
    T *left_array = new T[mid];
    T *right_array = new T[right_size];

    // copy element to each array
    for (int i = 0; i < mid; i++) {
      left_array[i] = array[i];
    }

    for (int j = mid; j < size; j++) {
      right_array[j - mid] = array[j];
    }
    Array_Info<T> left = Array_Info<T>(left_array, mid);
    Array_Info<T> right = Array_Info<T>(right_array, right_size);
    Array_Info<T> main_array = Array_Info<T>(array, size);
    // return;

    _merge_sort(left_array, mid);
    _merge_sort(right_array, right_size);

    // merge
    merge(main_array, left, right);
    delete[] right_array;
    delete[] left_array;
  }

public:
  // INFO: Bubble_Sort
  //  WARNING: user should deallocated sorted array retrun
  template <typename T> static T *bubble_sort(T array[], int array_size) {
    handle_type<T>();
    T *sorted_array = new T[array_size];
    copy(array, array + array_size, sorted_array);

    for (int i = 0; i < array_size; i++) {
      bool does_swapped = false;
      for (int j = 0; j < array_size - i - 1; j++) {
        if (sorted_array[j] > sorted_array[j + 1]) {
          swap(sorted_array[j], sorted_array[j + 1]);
          does_swapped = true;
        }
      }
      if (!does_swapped)
        break;
    }

    return sorted_array;
  }

  // INFO: Insertion_Sort
  //  WARNING: user should deallocated sorted array retrun
  template <typename T> static T *insertion_sort(T array[], int array_size) {
    handle_type<T>();
    T *sorted_array = new T[array_size];
    copy(array, array + array_size, sorted_array);

    for (int i = 1; i < array_size; i++) {
      T current = sorted_array[i];
      int j = i - 1;
      while (j >= 0 && sorted_array[j] > current) {
        sorted_array[j + 1] = sorted_array[j];
        j--;
      }
      sorted_array[j + 1] = current;
    }

    return sorted_array;
  }

  // INFO: Selection_Sort
  //  WARNING: user should deallocated sorted array retrun
  template <typename T> static T *selection_sort(T array[], int array_size) {
    handle_type<T>();
    T *sorted_array = new T[array_size];
    copy(array, array + array_size, sorted_array);

    for (int i = 0; i < array_size; i++) {
      int min_index = i;
      for (int j = i + 1; j < array_size; j++) {
        if (sorted_array[j] < sorted_array[min_index])
          min_index = j;
      }
      swap(sorted_array[min_index], sorted_array[i]);
    }

    return sorted_array;
  }

  // INFO: Quick_Sort
  //  WARNING: user should deallocated sorted array retrun
  template <typename T> static T *quick_sort(T array[], int array_size) {
    handle_type<T>();
    T *sorted_array = new T[array_size];
    copy(array, array + array_size, sorted_array);

    if (array_size <= 1) {
      return sorted_array;
    }

    _quick_sort(sorted_array, 0, array_size - 1);

    return sorted_array;
  }

  // INFO: Merge_Sort
  //  WARNING: user should deallocated sorted array retrun
  template <typename T> static T *merge_sort(T array[], int array_size) {
    handle_type<T>();
    T *sorted_array = new T[array_size];
    copy(array, array + array_size, sorted_array);

    if (array_size <= 1) {
      return sorted_array;
    }

    _merge_sort(sorted_array, array_size);
    return sorted_array;
  }
};
#endif
