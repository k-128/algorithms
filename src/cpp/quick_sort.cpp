#include <iostream>
#include <vector>
#include <string>


template <typename T>
size_t Partition(std::vector<T> &seq, size_t lo, size_t hi) {
    size_t i = lo;

    for (size_t j = lo; j < hi; ++j) {
        if (seq[j] < seq[hi]) {
            std::swap(seq[i], seq[j]);
            ++i;
        }
    }

    std::swap(seq[i], seq[hi]);
    return i;
}


template <typename T>
void _QuickSort(std::vector<T> &seq, size_t lo, size_t hi) {
    if (lo < hi) {
        size_t p = Partition(seq, lo, hi);
        if (p) {
            _QuickSort(seq, lo, p-1);
        }
        _QuickSort(seq, p+1, hi);
    }
}


template <typename T>
void QuickSort(std::vector<T> &seq) {
    _QuickSort(seq, 0, seq.size() - 1);
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
    QuickSort(seq_1_sorted);
    QuickSort(seq_2_sorted);

    std::cout << "seq_1: " << seq_1 << "\nseq_1_sorted: " << seq_1_sorted
        << "\nseq_2: " << seq_2 << "\nseq_2_sorted: " << seq_2_sorted
        << std::endl;

    return 0;
}
