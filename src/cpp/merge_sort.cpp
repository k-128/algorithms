#include <iostream>
#include <vector>


template <typename T>
void Merge(std::vector<T> &seq, int lo, int mid, int hi) {
    std::vector<T> temp;
    int i_lseq = lo;
    int i_rseq = mid + 1;

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

    for (int i = lo; i <= hi; ++i) {
        seq[i] = temp[i - lo];
    }
}


template <typename T>
void MergeSort(std::vector<T> &seq, int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        MergeSort(seq, lo, mid);
        MergeSort(seq, mid + 1, hi);
        Merge(seq, lo, mid, hi);
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
    MergeSort(seq_sorted, 0, seq_sorted.size() - 1);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
