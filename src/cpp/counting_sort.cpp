#include <iostream>
#include <vector>


void counting_sort(std::vector<int> &seq) {
  if (seq.size() == 0) {
    return;
  }

  int max_value = seq[0];
  int min_value = seq[0];
  for (size_t i = 1; i < seq.size(); ++i) {
    if (max_value < seq[i]) {
      max_value = seq[i];
    }
    if (min_value > seq[i]) {
      min_value = seq[i];
    }
  }

  std::vector<int> counts(max_value - min_value + 1, 0);
  for (size_t i = 0; i < seq.size(); ++i) {
    counts[seq[i] - min_value] += 1;
  }

  int temp = 0;
  for (size_t i = 0; i < counts.size(); ++i) {
    for (int j = 0; j < counts[i]; ++j) {
      seq[temp] = i + min_value;
      temp++;
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
  counting_sort(v);
  std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

  // +
  v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
  std::cout << "test_int_1... ";
  counting_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -
  v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
  std::cout << "test_int_2... ";
  counting_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

  // +, -, =
  v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
  std::cout << "test_int_3... ";
  counting_sort(v);
  std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";
}


int main() {
  run_tests();
  return 0;
}
