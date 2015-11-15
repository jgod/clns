/*
The MIT License (MIT)

Copyright (c) 2015 Justin Godesky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef clns_h
#define clns_h

#include <vector>
#include <algorithm>
#include <functional>

namespace jgod { namespace clns {
  template <typename T>
  struct identity {typedef T type;}; // Used to coerce template arguments

#pragma mark - Searching
  /** Returns whether a vector of elements includes a certain element. */
  template <typename T>
  bool includes(const std::vector<T> &v, const typename identity<T>::type el) {
    return std::find_if(std::begin(v), std::end(v), [&](const T &i) {
      return i == el;
    }) != std::end(v);
  }

  /** Sorts and returns whether a vector of elements contain all of another vector. */
  template <typename T>
  bool includes(std::vector<T> &a, std::vector<T> &b) {
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));
    return std::includes(std::begin(a), std::end(a),
                         std::begin(b), std::end(b));
  }

#pragma mark - Modifying
  template <typename T>
  /** Removes falsy values from the vector. */
  void compact(std::vector<T> &v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](const T &t){return !t;}), v.end());
  }
  /** Removes falsy values from the vector. */
  inline void compact(std::vector<std::string> &v) {
    v.erase(std::remove(v.begin(), v.end(), ""), v.end());
  }

#pragma mark - Sets
  template <typename T>
  /** Returns a vector of all elements between two vectors of elements, sorting them first. */
  const std::vector<T> getUnion(std::vector<T> &a, std::vector<T> &b) {
    std::vector<T> un(a.size() + b.size());
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    typename std::vector<T>::iterator it;
    it = std::set_union(std::begin(a), std::end(a),
                        std::begin(b), std::end(b), std::begin(un));
    un.resize(it - un.begin());
    return un;
  }

  template <typename T>
  /** Returns a vector of matched elements between two vectors of elements, sorting them first. */
  const std::vector<T> getIntersection(std::vector<T> &a, std::vector<T> &b) {
    std::vector<T> xion(a.size() + b.size());
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    typename std::vector<T>::iterator it;
    it = std::set_intersection(std::begin(a), std::end(a),
                               std::begin(b), std::end(b),
                               xion.begin());
    xion.resize(it - xion.begin());
    return xion;
  }

  template <typename T>
  /** Returns a vector of diffed elements between two vectors of elements, sorting them first */
  const std::vector<T> getDifferences(std::vector<T> &a, std::vector<T> &b) {
    std::vector<T> diff(a.size() + b.size());
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    typename std::vector<T>::iterator it;
    it = std::set_symmetric_difference(std::begin(a), std::end(a),
                                       std::begin(b), std::end(b),
                                       diff.begin());
    diff.resize(it - diff.begin());
    return diff;
  }
}}
#endif /* clns_h */
