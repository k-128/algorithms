#include <iostream>
#include <vector>


std::vector<int> InsertionSort(std::vector<int> sequence) {
    int i_insert;
    int key;
    for (unsigned int i = 0; i < sequence.size() - 1; i++) {
        i_insert = i;
        key = sequence[i + 1];
        while ((i_insert >= 0) && (key < sequence[i_insert])) {
            sequence[i_insert + 1] = sequence[i_insert];
            i_insert--;
        }
        sequence[i_insert + 1] = key;
    }
    return sequence;
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted = InsertionSort(seq);
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
