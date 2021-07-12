//
// Created by Vostrilov Ivan 6/12/21.
//

#pragma once

#include <cstdint>
#include <iterator>
#include <utility>

namespace gdr {

/*!
 * Rotates the order of the elements in the range [first,last),
 * in such a way that the element pointed by middle becomes
 * the new first element.
 * @tparam ForwardIterator
 * @param first first initial position.
 * @param middle element wich becomes first.
 * @param last final position.
 * @return none
 * Complexity:
 *  worst case O(n).
 */

template <class ForwardIterator>
void RotateToLeft(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last) {
	ForwardIterator next = middle;

	while (first != next) {
		std::swap(*first, *next);
		++first;
		++next;
		if (next == last) {
			next = middle;
		} else if (first == middle) {
			middle = next;
		}
	}
}

/*!
 * Sorts items between [first, last).
 * @tparam RandomAccessIterator
 * @param first first initial position.
 * @param last final position.
 * @return none
 * Complexity:
 *  average n * log(n);
 *  worst case O(n^2).
 */

template <class RandomAccessIterator>
void QuickSort(RandomAccessIterator first, RandomAccessIterator last) {
	if (last - first < 2) {
		return;
	}
	auto left_border  = first - 1;
	auto base = first;

	++first;
	while (first != last) {
		if (*first < *base) {
			auto save = *first;
			auto it = first - 1;

			while (it != left_border) {
				*(it + 1) = *it;
				--it;
			}
			*(it + 1) = save;
			++base;
		}
		++first;
	}
	QuickSort(left_border + 1, base);
	QuickSort(base + 1, last);
}

/*!
 * Concatenates two adjacent parts of an array with sorting
 * @tparam RandomAccessIterator
 * @param first1 initial position 1
 * @param last1 final position 2
 * @param first2 initial position 2
 * @param last2 final position 2
 * @return none
 * Complexity:
 *  worst case O(n).
 */

template<class RandomAccessIterator>
void Merge(RandomAccessIterator first1, RandomAccessIterator last1,
           RandomAccessIterator first2, RandomAccessIterator last2) {
	using value_type = typename std::iterator_traits<
		RandomAccessIterator>::value_type;

	auto begin = first1;
	auto len = (last1 - first1) + (last2 - first2);
	std::vector<value_type> b;

	b.reserve(len);
	while (first1 != last1 && first2 != last2) {
		if (*first2 < *first1) {
			b.emplace_back(*first2);
			++first2;
		} else {
			b.emplace_back(*first1);
			++first1;
		}
	}
	while (first1 != last1) {
		b.emplace_back(*first1);
		++first1;
	}
	while (first2 != last2) {
		b.emplace_back(*first2);
		++first2;
	}
	for (auto &i : b) {
		*begin = i;
		++begin;
	}
}

/*!
 * Sorts items between [first, last).
 * @tparam RandomAccessIterator
 * @param first initial position.
 * @param last final position.
 * @return none
 * Complexity:
 *  average n * log(n);
 *  worst case O(n * log(n)).
 */

template<class RandomAccessIterator>
void MergeSort(RandomAccessIterator first, RandomAccessIterator last) {
	auto len = last - first;

	if (len < 2) {
		return;
	}
	auto half = first + len / 2 + (len % 2);
	MergeSort(first, half);
	MergeSort(half, last);
	Merge(first, half, half, last);
}
}
