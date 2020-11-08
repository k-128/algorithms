#include <iostream>
#include <vector>


void Merge(
    std::vector<int>& sequence,
    unsigned int i_front,
    unsigned int i_mid,
    unsigned int i_end
) {
    std::vector<int> merged;
    unsigned int k_lseq = i_front;
    unsigned int k_rseq = i_mid + 1;

    while (k_lseq <= i_mid && k_rseq <= i_end) {
        if (sequence[k_lseq] <= sequence[k_rseq]) {
            merged.push_back(sequence[k_lseq]);
            ++k_lseq;
        }
        else {
            merged.push_back(sequence[k_rseq]);
            ++k_rseq;
        }
    }

    while (k_lseq <= i_mid) {
        merged.push_back(sequence[k_lseq]);
        ++k_lseq;
    }

    while (k_rseq <= i_end) {
        merged.push_back(sequence[k_rseq]);
        ++k_rseq;
    }

    for (unsigned int i = i_front; i <= i_end; ++i) {
        sequence[i] = merged[i - i_front];
    }
}


void MergeSort(
    std::vector<int>& sequence,
    unsigned int front,
    unsigned int end
) {
    if (front < end) {
        unsigned int mid = (front + end) / 2;
        MergeSort(sequence, front, mid);
        MergeSort(sequence, mid + 1, end);
        Merge(sequence, front, mid, end);
    }
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted(seq);
    MergeSort(seq_sorted, 0, seq_sorted.size() - 1);

    std::cout << "Initial sequence: ";
    for (unsigned int i = 0; i < seq.size(); ++i) {
        std::cout << seq.at(i) << " ";
    }
    MergeSort(seq, 0, seq.size() - 1);
    std::cout << "\nSorted sequence : ";
    for (unsigned int i = 0; i < seq.size(); ++i) {
        std::cout << seq.at(i) << " ";
    }
    std::cout << "\n" << std::endl;

    return 0;
}
