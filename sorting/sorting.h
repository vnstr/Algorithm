//
// Created by Vostrilov Ivan 6/12/21.
//

#pragma once

#include <iterator>
#include <utility>

namespace gdr {

/*!
 * Sorts items between [first, last).
 * \param[in] first initial position.
 * \param[in] last final position.
 * \return none
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
  auto base_it = first;
  auto base    = *first;

  ++first;
  while (first != last) {
    if (*first < base) {
      auto save = *first;
      auto it = first - 1;

      while (it != left_border) {
        *(it + 1) = *it;
        --it;
      }
      *(it + 1) = save;
      ++base_it;
    }
    ++first;
  }
  QuickSort(left_border + 1, base_it);
  QuickSort(base_it + 1, last);
}
}
