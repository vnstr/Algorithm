//
// Created by Vostrilov Ivan 7/04/21.
//

#pragma once

#include <iterator>

namespace gdr {

/*!
 * Find item between [first, last).
 * @tparam RandomAccessIterator
 * @param first first initial position.
 * @param last final position.
 * @tparam item type.
 * @param item searched item.
 * @return iterator to item or last if not found.
 * Complexity:
 *  worst case O(logn).
 */

template <class RandomAccessIterator, class T>
RandomAccessIterator BinarySearch(RandomAccessIterator first,
                                  RandomAccessIterator last, T item) {
	RandomAccessIterator ret;
	RandomAccessIterator half;
	auto len = last - first;

	if (len < 2) {
		return *first == item ? first : last;
	}
	ret = half = first + len / 2 + (len % 2);
	if (item < *half) {
		ret = BinarySearch(first, half, item);
		return ret == half ? last : ret;
	} else if (item > *half) {
		ret = BinarySearch(half, last, item);
	}
	return ret;
}
}
