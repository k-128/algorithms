#include <iostream>
#include <vector>


void InsertionSort(std::vector<int>& sequence) {
    for (unsigned int i = 0; i < sequence.size() - 1; ++i) {
        int i_insert = i;
        int key = sequence[i + 1];
        while ((i_insert >= 0) && (key < sequence[i_insert])) {
            sequence[i_insert + 1] = sequence[i_insert];
            --i_insert;
        }
        sequence[i_insert + 1] = key;
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
    InsertionSort(seq_sorted);

    std::cout << "Initial sequence: ";
    PrintSequence(seq);
    std::cout << "Sorted sequence : ";
    PrintSequence(seq_sorted);

    return 0;
}
