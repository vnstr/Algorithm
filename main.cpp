#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdint>

#include "sorting/sorting.h"
#include "BinarySearch/binary_search.h"

#define GEN_MAX 1000

template<class T>
void PrintVector(const std::vector<T> &v) {
  std::cout << " ";
  for (auto &i : v) {
   std::cout << i << " ";
  }
}

uint32_t Gen() {
  static std::vector<int> reminder;
  int val = rand() % GEN_MAX;
  auto found = std::find(reminder.begin(), reminder.end(), val);

  while (found != reminder.end()) {
    val = rand() % GEN_MAX;
    found = std::find(reminder.begin(), reminder.end(), val);
  }
  reminder.emplace_back(val);
  return val;
}

void SortingTest() {
	std::cout << "SortingTest" << std::endl;
  std::vector<uint32_t> vector(10);

  std::generate(vector.begin(), vector.end(), Gen);

  std::cout << "Before:\n[";
  PrintVector(vector);
  std::cout << "]" << std::endl;

  gdr::QuickSort(vector.begin(), vector.end());

  std::cout << "After:\n[";
  PrintVector(vector);
  std::cout << "]" << std::endl;
	std::cout << "-----------" << std::endl;
}

void BinarySearchTest() {
	std::cout << "BinarySearchTest" << std::endl;
	const int size = 100;
	std::vector<uint32_t> nums;

	nums.reserve(size);
	for (int i = 0; i < size; i++) {
		nums.emplace_back(Gen());
	}
	std::sort(nums.begin(), nums.end());
	auto item = nums.at(rand() % size);
	auto found = gdr::BinarySearch(nums.begin(), nums.end(), item);
	auto not_found = gdr::BinarySearch(nums.begin(), nums.end(),
	                                                 uint32_t(GEN_MAX + 1));

	std::cout << "found:     " << (*found == item ? "OK" : "FAIL") << std::endl;
	std::cout << "not_found: " << (not_found == nums.end() ? "OK" : "FAIL")
	          << std::endl;
	std::cout << "----------------" << std::endl;
}

int main() {
  srand(time(nullptr));
	SortingTest();
	BinarySearchTest();
  return 0;
}
