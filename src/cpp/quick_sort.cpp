#include <iostream>
#include <vector>
#include <string>


template <typename T>
size_t _partition(std::vector<T> &seq, size_t lo, size_t hi) {
  size_t i = lo;

  for (size_t j = lo; j < hi; ++j) {
    if (seq[j] <= seq[hi]) {
      std::swap(seq[i], seq[j]);
      ++i;
    }
  }

  std::swap(seq[i], seq[hi]);
  return i;
}


template <typename T>
void _quick_sort(std::vector<T> &seq, size_t lo, size_t hi) {
  if (lo < hi) {
    size_t p = _partition(seq, lo, hi);
    if (p) {
      _quick_sort(seq, lo, p-1);
    }
    _quick_sort(seq, p+1, hi);
  }
}


template <typename T>
void quick_sort(std::vector<T> &seq) {
  if (seq.size() == 0) {
    return;
  }

  _quick_sort(seq, 0, seq.size() - 1);
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
  quick_sort(v);
  std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

  // +
  v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
  std::cout << "test_int_1... ";
  quick_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -
  v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
  std::cout << "test_int_2... ";
  quick_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -, =
  v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
  std::cout << "test_int_3... ";
  quick_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // string
  std::vector<std::string> vs;
  vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
  std::cout << "test_string.. ";
  quick_sort(vs);
  std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
  run_tests();
  return 0;
}
