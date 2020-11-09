#include <iostream>
#include <vector>


void SelectionSort(std::vector<int>& sequence) {
    for (unsigned int i = 0; i < sequence.size() - 1; ++i) {
        int i_lo_val = i + 1;
        for (unsigned int j = 0; j < sequence.size() - 1 - i; ++j) {
            if (sequence[i_lo_val] > sequence[j + i + 1]) {
                i_lo_val = j + i + 1;
            }
        }
        if (sequence[i] > sequence[i_lo_val]) {
            std::swap(sequence[i], sequence[i_lo_val]);
        }
    }
}


void PrintSequence(std::vector<int> v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted(seq);
    SelectionSort(seq_sorted);

    std::cout << "Initial sequence: ";
    PrintSequence(seq);
    std::cout << "\nSorted sequence : ";
    PrintSequence(seq_sorted);
    std::cout << "\n" << std::endl;

    return 0;
}
