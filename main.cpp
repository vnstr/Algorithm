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
	return rand() % GEN_MAX;
}

void SortingTest() {
	std::cout << "SortingTest" << std::endl;
	std::vector<uint32_t> vector(10);

	std::generate(vector.begin(), vector.end(), Gen);
	std::vector<uint32_t> copy(vector);

	std::cout << "Before:\n[";
	PrintVector(vector);
	std::cout << "]" << std::endl;

	gdr::QuickSort(vector.begin(), vector.end());
	gdr::MergeSort(copy.begin(), copy.end());

	std::cout << "After QuickSort:\n[";
	PrintVector(vector);
	std::cout << "]" << std::endl;	std::cout << "-----------" << std::endl;

	std::cout << "After MergeSort:\n[";
	PrintVector(copy);
	std::cout << "]" << std::endl;	std::cout << "-----------" << std::endl;
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

void RotateToLeftTest() {
	const int size  = 5;
	int       diffs = 0;
	for (int i = 0; i < 3; ++i) {
		std::vector<int> mouse;
		std::vector<int> copy;

		for (int i = 0; i < size; ++i) {
			int val = Gen();
			mouse.emplace_back(val);
			copy.emplace_back(val);
		}
		int middle = Gen() % size;
		std::rotate(mouse.begin(), mouse.begin() + middle, mouse.end());
		gdr::RotateToLeft(copy.begin(), copy.begin() + middle, copy.end());

		for (int i = 0; i < size; ++i) {
			if (mouse[i] != copy[i]) {
				++diffs;
			}
		}
	}
	if (diffs) {
		std::cout << "RotateToLeftTest: FAILED" << std::endl;
	} else {
		std::cout << "RotateToLeftTest: OK" << std::endl;
	}
}

int main() {
	srand(time(nullptr));
	SortingTest();
	BinarySearchTest();
	RotateToLeftTest();
	return 0;
}
