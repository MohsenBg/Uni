#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
using namespace std;

template <typename T> class Hash_Table {
private:
  unsigned _count = 0;
  unsigned _collision_count = 0;
  unsigned _size;

  bool is_type_number() { return is_arithmetic<T>::value; };

  // convert value in to index
  unsigned long hash(string key) {
    unsigned long hash = 5381;
    for (int i = 0; i < key.length(); i++) {
      hash = hash * 33 + key[i];
    }
    return hash % (_size / 2);
  }

  // handle collision
  void handle_collision(T value) {
    unsigned last_index = _size / 2 + _collision_count;

    storage[last_index] = new T(value);

    for (int i = last_index; i > _size / 2 && Get(i) < Get(i - 1); i--) {
      swap(storage[i], storage[i - 1]);
    }
    _collision_count += 1;
  }

public:
  T **storage;

  Hash_Table(unsigned size) {
    _size = size * 2;
    storage = new T *[_size];
  }

  // Return number of element[s] in Hash_Table
  unsigned Count() { return _count; }

  // Return size of the Hash_Table (array)
  unsigned Copacity() { return _size; }

  // Return value in storage with index
  // Warning: if index >= Size of storage => geting Error
  T Get(unsigned index) { return *storage[index]; }

  // Add_Element
  void Add(T value) {

    // if Hash_Table Full end function;
    if (Count() >= Copacity())
      return;

    string key = to_string(value);
    unsigned index = hash(key);
    if (storage[index] == nullptr)
      storage[index] = new T(value);
    else
      handle_collision(value);
  }

  void Debug_Log() {
    cout << "index"
         << "\t"
         << "value"
         << "\t\t"
         << "hash" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < _size; i++) {
      if (storage[i] != nullptr) {
        unsigned hash_value = hash(to_string(Get(i)));
        cout << i << "\t" << Get(i) << "\t\t" << hash_value << endl;

      } else {
        cout << i << "\t"
             << "nullptr"
             << "\t\t"
             << "-" << endl;
      }
    }
  }
};
#endif
