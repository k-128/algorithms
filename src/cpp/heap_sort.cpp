#include <iostream>
#include <vector>
#include <string>


template <typename T>
void MaxHeapify(std::vector<T> &seq, size_t i_root, size_t heap_size) {
    size_t i_max   = i_root;
    size_t i_left  = i_root * 2 + 1;
    size_t i_right = i_root * 2 + 2;

    if ((i_left < heap_size) && (seq[i_left] > seq[i_max])) {
        i_max = i_left;
    }

    if ((i_right < heap_size) && (seq[i_right] > seq[i_max])) {
        i_max = i_right;
    }

    if (i_max != i_root) {
        std::swap(seq[i_max], seq[i_root]);
        MaxHeapify(seq, i_max, heap_size);
    }
}


template <typename T>
void BuildMaxHeap(std::vector<T> &seq, size_t heap_size) {
    for (size_t i = heap_size / 2; i > 0; --i) {
        MaxHeapify(seq, i-1, heap_size);
    }
}


template <typename T>
void HeapSort(std::vector<T> &seq) {
    size_t n = seq.size();
    BuildMaxHeap(seq, n);

    for (size_t i = n - 1; i > 0; --i) {
        std::swap(seq[0], seq[i]);
        MaxHeapify(seq, 0, i);
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
    HeapSort(seq_1_sorted);
    HeapSort(seq_2_sorted);

    std::cout << "seq_1: " << seq_1 << "\nseq_1_sorted: " << seq_1_sorted
        << "\nseq_2: " << seq_2 << "\nseq_2_sorted: " << seq_2_sorted
        << std::endl;

    return 0;
}
