#include <iostream>
#include <vector>


void BubbleSort(std::vector<int>& sequence) {
    for (unsigned int i = 0; i < sequence.size() - 1; ++i) {
        bool is_sorted = true;
        for (unsigned int j = 0; j < sequence.size() - 1 - i; ++j) {
            if (sequence[j] > sequence[j + 1]) {
                is_sorted = false;
                std::swap(sequence[j], sequence[j + 1]);
            }
        }
        if (is_sorted) {
            break;
        }
    }
}


void PrintSequence(std::vector<int> v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << "\n";
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted(seq);
    BubbleSort(seq_sorted);

    std::cout << "Initial sequence: ";
    PrintSequence(seq);
    std::cout << "\nSorted sequence : ";
    PrintSequence(seq_sorted);

    return 0;
}
