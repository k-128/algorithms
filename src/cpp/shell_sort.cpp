#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>


std::vector<size_t> _get_gaps(size_t size) {
  size_t temp = size / 2;
  std::vector<size_t> gaps = {temp};
  while (temp > 1) {
    temp = temp / 2;
    gaps.push_back(temp);
  }
  return gaps;
}


std::vector<size_t> _get_gaps_knuth(size_t size) {
  size_t temp = 1;
  std::vector<size_t> gaps = {temp};
  while (temp < size) {
    temp = temp * 3 + 1;
    gaps.push_back(temp);
  }
  std::reverse(gaps.begin(), gaps.end());
  return gaps;
}


std::vector<size_t> _get_gaps_ciura(size_t size) {
  size_t gaps_init[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
  size_t temp = 1;
  std::vector<size_t> gaps = {};
  for (size_t i = 0; temp < size; ++i) {
    if (temp >= 1750) {
      temp = std::floor(temp * 2.25);
    }
    else {
      temp = gaps_init[i];
    }
    gaps.push_back(temp);
  }
  std::reverse(gaps.begin(), gaps.end());
  return gaps;
}


template <typename T>
void shell_sort(std::vector<T> &seq) {
  if (seq.size() == 0) {
    return;
  }

  std::vector<size_t> gaps = _get_gaps_ciura(seq.size());

  for (size_t i = 0; i < gaps.size(); ++i) {
    size_t gap = gaps[i];
    for (size_t j = gap; j < seq.size(); ++j) {
      size_t i_insert = j;
      T key = seq[j];
      while ((i_insert >= gap) && (key < seq[i_insert - gap])) {
        seq[i_insert] = seq[i_insert - gap];
        i_insert = i_insert - gap;
      }
      seq[i_insert] = key;
    }
  }
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> v) {
  for (size_t i = 0; i < v.size(); ++i) {
    os << v.at(i) << " ";
  }
  return os;
}


template <typename T>
bool is_sorted(std::vector<T> v) {
  for (size_t i = 0; i < v.size() - 1; ++i) {
    if (v.at(i) > v.at(i+1)) {
      return false;
    }
  }
  return true;
}


void run_tests() {
  // Empty
  std::vector<int> v;
  std::cout << "test_empty... ";
  shell_sort(v);
  std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

  // +
  v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
  std::cout << "test_int_1... ";
  shell_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -
  v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
  std::cout << "test_int_2... ";
  shell_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -, =
  v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
  std::cout << "test_int_3... ";
  shell_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // string
  std::vector<std::string> vs;
  vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
  std::cout << "test_string.. ";
  shell_sort(vs);
  std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
  run_tests();
  return 0;
}
