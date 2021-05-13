#include <iostream>
#include <vector>
#include <string>


template <typename T>
void _merge(std::vector<T> &seq, size_t lo, size_t mid, size_t hi) {
  std::vector<T> temp;
  size_t i_lseq = lo;
  size_t i_rseq = mid + 1;

  while (i_lseq <= mid && i_rseq <= hi) {
    if (seq[i_lseq] <= seq[i_rseq]) {
      temp.push_back(seq[i_lseq]);
      ++i_lseq;
    }
    else {
      temp.push_back(seq[i_rseq]);
      ++i_rseq;
    }
  }

  while (i_lseq <= mid) {
    temp.push_back(seq[i_lseq]);
    ++i_lseq;
  }

  while (i_rseq <= hi) {
    temp.push_back(seq[i_rseq]);
    ++i_rseq;
  }

  for (size_t i = lo; i <= hi; ++i) {
    seq[i] = temp[i - lo];
  }
}


template <typename T>
void _merge_sort(std::vector<T> &seq, size_t lo, size_t hi) {
  if (lo < hi) {
    size_t mid = (lo + hi) / 2;
    _merge_sort(seq, lo, mid);
    _merge_sort(seq, mid + 1, hi);
    _merge(seq, lo, mid, hi);
  }
}


template <typename T>
void merge_sort(std::vector<T> &seq) {
  if (seq.size() == 0) {
    return;
  }

  _merge_sort(seq, 0, seq.size() -1);
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
  merge_sort(v);
  std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

  // +
  v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
  std::cout << "test_int_1... ";
  merge_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -
  v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
  std::cout << "test_int_2... ";
  merge_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -, =
  v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
  std::cout << "test_int_3... ";
  merge_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // string
  std::vector<std::string> vs;
  vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
  std::cout << "test_string.. ";
  merge_sort(vs);
  std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
  run_tests();
  return 0;
}
