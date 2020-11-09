#include <iostream>
#include <vector>


int BinarySearch(std::vector<int> sequence, int query) {
    int low = 0;
    int high = sequence.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sequence[mid] == query) {
            return mid;
        }
        else if (sequence[mid] < query) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}


int main() {
    std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};

    std::cout << "Search result : " << BinarySearch(seq, 7) << "\n";
    std::cout << "Missing query : " << BinarySearch(seq, 6) << "\n";
    std::cout << "Empty sequence: " << BinarySearch({}, 7) << std::endl;

    return 0;
}
