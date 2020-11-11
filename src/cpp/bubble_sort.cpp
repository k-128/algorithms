#include <iostream>
#include <vector>


template <typename T>
void BubbleSort(std::vector<T> &seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        bool is_sorted = true;
        for (size_t j = 0; j < seq.size() - 1 - i; ++j) {
            if (seq[j] > seq[j + 1]) {
                is_sorted = false;
                std::swap(seq[j], seq[j + 1]);
            }
        }
        if (is_sorted) {
            break;
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
    BubbleSort(seq_sorted);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
