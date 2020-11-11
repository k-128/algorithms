#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


std::vector<int> GetGaps(int size) {
    int temp = size / 2;
    std::vector<int> gaps = {temp};
    while (temp > 1) {
        temp = temp / 2;
        gaps.push_back(temp);
    }
    return gaps;
}


std::vector<int> GetGapsKnuth(int size) {
    int temp = 1;
    std::vector<int> gaps = {temp};
    while (temp < size) {
        temp = temp * 3 + 1;
        gaps.push_back(temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}


std::vector<int> GetGapsCiura(int size) {
    int gaps_init[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int temp = 1;
    std::vector<int> gaps = {};
    for (size_t i = 0; temp < size; ++i) {
        if (temp >= 1750) {
            temp = std::floor(temp * 2.25);
        }
        else {
            temp = gaps_init[i];
        }
        gaps.push_back(temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}


template <typename T>
void ShellSort(std::vector<T> &seq) {
    std::vector<int> gaps = GetGapsCiura(seq.size());

    for (size_t i = 0; i < gaps.size(); ++i) {
        int gap = gaps[i];
        for (size_t j = gap; j < seq.size(); ++j) {
            int i_insert = j;
            int key = seq[j];
            while ((i_insert >= gap) && (key < seq[i_insert - gap])) {
                seq[i_insert] = seq[i_insert - gap];
                i_insert = i_insert - gap;
            }
            seq[i_insert] = key;
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
    ShellSort(seq_sorted);

    std::cout << "Initial sequence: " << seq << "\n";
    std::cout << "Sorted sequence : " << seq_sorted << std::endl;

    return 0;
}
