#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


std::vector<int> GetGaps(int size) {
    int temp = size / 2;
    std::vector<int> gaps = {temp};
    while (temp > 1) {
        temp = temp / 2;
        gaps.insert(gaps.end(), temp);
    }
    return gaps;
}


std::vector<int> GetGapsKnuth(int size) {
    int temp = 1;
    std::vector<int> gaps = {temp};
    while (temp < size) {
        temp = temp * 3 + 1;
        gaps.insert(gaps.end(), temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}


std::vector<int> GetGapsCiura(int size) {
    int gaps_init[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int temp = 1;
    std::vector<int> gaps = {};
    for (unsigned int i = 0; temp < size; i++) {
        if (temp >= 1750) {
            temp = std::floor(temp * 2.25);
        }
        else {
            temp = gaps_init[i];
        }
        gaps.insert(gaps.end(), temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}


std::vector<int> ShellSort(std::vector<int> sequence) {
    std::vector<int> gaps = GetGapsCiura(sequence.size());
    for (unsigned int i = 0; i < gaps.size(); i++) {
        int gap = gaps[i];
        for (unsigned int j = gap; j < sequence.size(); j++) {
            int i_insert = j;
            int key = sequence[j];
            while ((i_insert >= gap) && (key < sequence[i_insert - gap])) {
                sequence[i_insert] = sequence[i_insert - gap];
                i_insert = i_insert - gap;
            }
            sequence[i_insert] = key;
        }
    }
    return sequence;
}


int main() {
    std::vector<int> seq = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::vector<int> seq_sorted = ShellSort(seq);
    std::cout << "Initial sequence: ";
    for (unsigned int i = 0; i < seq.size(); i++) {
        std::cout << seq.at(i) << " ";
    }
    std::cout << "\nSorted sequence : ";
    for (unsigned int i = 0; i < seq_sorted.size(); i++) {
        std::cout << seq_sorted.at(i) << " ";
    }
    std::cout << "\n" << std::endl;

    return 0;
}
