#include <iostream>
#include <vector>


template <typename T>
int linear_search(std::vector<T> seq, int query) {
  for (size_t i = 0; i < seq.size(); ++i) {
    if (seq[i] == query) {
      return i;
    }
  }
  return -1;
}


void run_tests() {
  std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};

  std::cout << "Search result : " << linear_search(seq, 7) << "\n";
  std::cout << "Missing query : " << linear_search(seq, 6) << "\n";
  std::cout << "Empty sequence: " << linear_search(std::vector<int> {}, 7)
    << std::endl;
}


int main() {
  run_tests();
  return 0;
}
