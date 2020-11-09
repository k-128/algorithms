#include <iostream>
#include <vector>


void Merge(
    std::vector<int>& sequence,
    unsigned int i_front,
    unsigned int i_mid,
    unsigned int i_end
) {
    std::vector<int> merged;
    unsigned int i_lseq = i_front;
    unsigned int i_rseq = i_mid + 1;

    while (i_lseq <= i_mid && i_rseq <= i_end) {
        if (sequence[i_lseq] <= sequence[i_rseq]) {
            merged.push_back(sequence[i_lseq]);
            ++i_lseq;
        }
        else {
            merged.push_back(sequence[i_rseq]);
            ++i_rseq;
        }
    }

    while (i_lseq <= i_mid) {
        merged.push_back(sequence[i_lseq]);
        ++i_lseq;
    }

    while (i_rseq <= i_end) {
        merged.push_back(sequence[i_rseq]);
        ++i_rseq;
    }

    for (unsigned int i = i_front; i <= i_end; ++i) {
        sequence[i] = merged[i - i_front];
    }
}


void MergeSort(
    std::vector<int>& sequence,
    unsigned int i_front,
    unsigned int i_end
) {
    if (i_front < i_end) {
        unsigned int i_mid = (i_front + i_end) / 2;
        MergeSort(sequence, i_front, i_mid);
        MergeSort(sequence, i_mid + 1, i_end);
        Merge(sequence, i_front, i_mid, i_end);
    }
}


void PrintSequence(std::vector<int> v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted(seq);
    MergeSort(seq_sorted, 0, seq_sorted.size() - 1);

    std::cout << "Initial sequence: ";
    PrintSequence(seq);
    std::cout << "\nSorted sequence : ";
    PrintSequence(seq_sorted);
    std::cout << "\n" << std::endl;

    return 0;
}
