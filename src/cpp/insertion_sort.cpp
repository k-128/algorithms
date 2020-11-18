#include <iostream>
#include <vector>
#include <string>


template <typename T>
void InsertionSort(std::vector<T> &seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        size_t i_insert = i;
        T key = seq[i + 1];
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
    std::vector<int> seq_1 = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_1_sorted(seq_1);
    std::vector<std::string> seq_2 = {
        "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
    };
    std::vector<std::string> seq_2_sorted(seq_2);
    InsertionSort(seq_1_sorted);
    InsertionSort(seq_2_sorted);

    std::cout << "seq_1: " << seq_1 << "\nseq_1_sorted: " << seq_1_sorted
        << "\nseq_2: " << seq_2 << "\nseq_2_sorted: " << seq_2_sorted
        << std::endl;

    return 0;
}
