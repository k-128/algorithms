#include <iostream>
#include <vector>


void SelectionSort(std::vector<int> &seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        int i_lo_val = i + 1;
        for (size_t j = 0; j < seq.size() - 1 - i; ++j) {
            if (seq[i_lo_val] > seq[j + i + 1]) {
                i_lo_val = j + i + 1;
            }
        }
        if (seq[i] > seq[i_lo_val]) {
            std::swap(seq[i], seq[i_lo_val]);
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


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted(seq);
    SelectionSort(seq_sorted);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
