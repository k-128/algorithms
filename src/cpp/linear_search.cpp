#include <iostream>
#include <vector>


template <typename T>
int LinearSearch(std::vector<T> seq, int query) {
    for (size_t i = 0; i < seq.size(); ++i) {
        if (seq[i] == query) {
            return i;
        }
    }
    return -1;
}


int main() {
    std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};

    std::cout << "Search result : " << LinearSearch(seq, 7) << "\n";
    std::cout << "Missing query : " << LinearSearch(seq, 6) << "\n";
    std::cout << "Empty sequence: " << LinearSearch(std::vector<int> {}, 7)
        << std::endl;

    return 0;
}
