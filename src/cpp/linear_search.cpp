#include <iostream>
#include <vector>


int LinearSearch(std::vector<int> sequence, int query ) {
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == query) {
            return i;
        }
    }
    return -1;
}


int main() {
    std::vector<int> seq = {2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};
    std::cout << "Search result :" << LinearSearch(seq, 7) << "\n";
    std::cout << "Missing query :" << LinearSearch(seq, 6) << "\n";
    std::cout << "Empty sequence:" << LinearSearch({}, 7) << "\n"
        << std::endl;

    return 0;
}
