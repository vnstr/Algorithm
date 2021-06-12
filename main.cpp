#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdint>

#include "sorting/sorting.h"

#define MAX 10

template<class T>
void print_vector(const std::vector<T> &v) {
  std::cout << " ";
  for (auto &i : v) {
   std::cout << i << " ";
  }
}

uint32_t gen() {
  static std::vector<int> reminder;
  int val = rand() % MAX;
  auto found = std::find(reminder.begin(), reminder.end(), val);

  while (found != reminder.end()) {
    val = rand() % MAX;
    found = std::find(reminder.begin(), reminder.end(), val);
  }
  reminder.emplace_back(val);
  return val;
}

int main() {
  srand(time(nullptr));
  std::cout << "Hello, World!" << std::endl;
  std::vector<int> vector(10);

  std::generate(vector.begin(), vector.end(), gen);

  std::cout << "Before:\n[";
  print_vector(vector);
  std::cout << "]" << std::endl;

  gdr::QuickSort(vector.begin(), vector.end());

  std::cout << "After:\n[";
  print_vector(vector);
  std::cout << "]" << std::endl;
  return 0;
}
