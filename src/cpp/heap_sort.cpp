#include <iostream>
#include <vector>
#include <string>


template <typename T>
void max_heapify(std::vector<T> &seq, size_t i_root, size_t heap_size) {
  size_t i_max   = i_root;
  size_t i_left  = i_root * 2 + 1;
  size_t i_right = i_root * 2 + 2;

  if ((i_left < heap_size) && (seq[i_left] > seq[i_max])) {
    i_max = i_left;
  }

  if ((i_right < heap_size) && (seq[i_right] > seq[i_max])) {
    i_max = i_right;
  }

  if (i_max != i_root) {
    std::swap(seq[i_max], seq[i_root]);
    max_heapify(seq, i_max, heap_size);
  }
}


template <typename T>
void build_max_heap(std::vector<T> &seq, size_t heap_size) {
  for (size_t i = heap_size / 2; i > 0; --i) {
    max_heapify(seq, i-1, heap_size);
  }
}


template <typename T>
void heap_sort(std::vector<T> &seq) {
  if (seq.size() == 0) {
    return;
  }

  size_t n = seq.size();
  build_max_heap(seq, n);

  for (size_t i = n - 1; i > 0; --i) {
    std::swap(seq[0], seq[i]);
    max_heapify(seq, 0, i);
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
  heap_sort(v);
  std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

  // +
  v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
  std::cout << "test_int_1... ";
  heap_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -
  v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
  std::cout << "test_int_2... ";
  heap_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -, =
  v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
  std::cout << "test_int_3... ";
  heap_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // string
  std::vector<std::string> vs;
  vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
  std::cout << "test_string.. ";
  heap_sort(vs);
  std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
  run_tests();
  return 0;
}
