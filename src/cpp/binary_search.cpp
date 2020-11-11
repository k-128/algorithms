#include <iostream>
#include <vector>


template <typename T>
int BinarySearch(std::vector<T> seq, int query) {
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


int main() {
    std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};

    std::cout << "Search result : " << BinarySearch(seq, 7) << "\n";
    std::cout << "Missing query : " << BinarySearch(seq, 6) << "\n";
    std::cout << "Empty sequence: " << BinarySearch(std::vector<int> {}, 7)
        << std::endl;

    return 0;
}
