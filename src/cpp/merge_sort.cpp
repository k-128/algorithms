#include <iostream>
#include <vector>
#include <string>


template <typename T>
void Merge(std::vector<T> &seq, size_t lo, size_t mid, size_t hi) {
    std::vector<T> temp;
    size_t i_lseq = lo;
    size_t i_rseq = mid + 1;

    while (i_lseq <= mid && i_rseq <= hi) {
        if (seq[i_lseq] <= seq[i_rseq]) {
            temp.push_back(seq[i_lseq]);
            ++i_lseq;
        }
        else {
            temp.push_back(seq[i_rseq]);
            ++i_rseq;
        }
    }

    while (i_lseq <= mid) {
        temp.push_back(seq[i_lseq]);
        ++i_lseq;
    }

    while (i_rseq <= hi) {
        temp.push_back(seq[i_rseq]);
        ++i_rseq;
    }

    for (size_t i = lo; i <= hi; ++i) {
        seq[i] = temp[i - lo];
    }
}


template <typename T>
void _MergeSort(std::vector<T> &seq, size_t lo, size_t hi) {
    if (lo < hi) {
        size_t mid = (lo + hi) / 2;
        _MergeSort(seq, lo, mid);
        _MergeSort(seq, mid + 1, hi);
        Merge(seq, lo, mid, hi);
    }
}


template <typename T>
void MergeSort(std::vector<T> &seq) {
    _MergeSort(seq, 0, seq.size() -1);
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
    MergeSort(seq_1_sorted);
    MergeSort(seq_2_sorted);

    std::cout << "seq_1: " << seq_1 << "\nseq_1_sorted: " << seq_1_sorted
        << "\nseq_2: " << seq_2 << "\nseq_2_sorted: " << seq_2_sorted
        << std::endl;

    return 0;
}
