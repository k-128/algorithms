#include <iostream>
#include <vector>


std::vector<int> BubbleSort(std::vector<int> sequence) {
    for (unsigned int i = 0; i < sequence.size() - 1; i++) {
        bool isSorted = true;
        for (unsigned int j = 0; j < sequence.size() - 1 - i; j++) {
            if (sequence[j] > sequence[j + 1]) {
                isSorted = false;
                std::swap(sequence[j], sequence[j + 1]);
            }
        }
        if (isSorted) {
            break;
        }
    }
    return sequence;
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted = BubbleSort(seq);
    std::cout << "Initial sequence: ";
    for (unsigned int i = 0; i < seq.size(); i++) {
        std::cout << seq.at(i) << " ";
    }
    std::cout << "\nSorted sequence : ";
    for (unsigned int i = 0; i < seq_sorted.size(); i++) {
        std::cout << seq_sorted.at(i) << " ";
    }
    std::cout << "\n" << std::endl;

    return 0;
}
