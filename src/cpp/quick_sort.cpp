#include <iostream>
#include <vector>


template <typename T>
int Partition(std::vector<T> &seq, int lo, int hi) {
    int i = lo;

    for (int j = lo; j < hi; ++j) {
        if (seq[j] < seq[hi]) {
            std::swap(seq[i], seq[j]);
            ++i;
        }
    }

    std::swap(seq[i], seq[hi]);
    return i;
}


template <typename T>
void QuickSort(std::vector<T> &seq, int lo, int hi) {
    if (lo < hi) {
        int p = Partition(seq, lo, hi);
        QuickSort(seq, lo, p-1);
        QuickSort(seq, p+1, hi);
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
    QuickSort(seq_sorted, 0, seq_sorted.size() - 1);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
