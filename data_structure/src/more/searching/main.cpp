#include "./hash_table.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  const unsigned size = 10;
  Hash_Table<int> hash_table = Hash_Table<int>(size);
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    int input = 1 + (rand() % 100);
    hash_table.Add(input);
  }

  hash_table.Debug_Log();

  return 0;
}
