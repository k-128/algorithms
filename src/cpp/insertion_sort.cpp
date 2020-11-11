#include <iostream>
#include <vector>


template <typename T>
void InsertionSort(std::vector<T> &seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        int i_insert = i;
        int key = seq[i + 1];
        while ((i_insert >= 0) && (key < seq[i_insert])) {
            seq[i_insert + 1] = seq[i_insert];
            --i_insert;
        }
        seq[i_insert + 1] = key;
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
    InsertionSort(seq_sorted);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
