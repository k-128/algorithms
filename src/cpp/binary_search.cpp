#include <iostream>
#include <vector>


template <typename T>
int binary_search(std::vector<T> seq, int query) {
  int lo = 0;
  int hi = seq.size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (seq[mid] == query) {
      return mid;
    }
    else if (seq[mid] < query) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }
  return -1;
}


void run_tests() {
  std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};

  std::cout << "Search result : " << binary_search(seq, 7) << "\n";
  std::cout << "Missing query : " << binary_search(seq, 6) << "\n";
  std::cout << "Empty sequence: " << binary_search(std::vector<int> {}, 7)
    << std::endl;
}


int main() {
  run_tests();
  return 0;
}
