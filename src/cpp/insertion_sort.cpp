#include <iostream>
#include <vector>
#include <string>


template <typename T>
void insertion_sort(std::vector<T> &seq) {
    if (seq.size() == 0) {
        return;
    }

    for (size_t i = 0; i < seq.size() - 1; ++i) {
        int i_insert = i;
        T key = seq[i + 1];
        while ((i_insert >= 0) && (key < seq[i_insert])) {
            seq[i_insert + 1] = seq[i_insert];
            --i_insert;
        }
        seq[i_insert + 1] = key;
    }
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v.at(i) << " ";
    }
    return os;
}


template <typename T>
bool is_sorted(std::vector<T> v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
        if (v.at(i) > v.at(i+1)) {
            return false;
        }
    }
    return true;
}


void run_tests() {
    // Empty
    std::vector<int> v;
    std::cout << "test_empty... ";
    insertion_sort(v);
    std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

    // +
    v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::cout << "test_int_1... ";
    insertion_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // +, -
    v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
    std::cout << "test_int_2... ";
    insertion_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // +, -, =
    v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
    std::cout << "test_int_3... ";
    insertion_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // string
    std::vector<std::string> vs;
    vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
    std::cout << "test_string.. ";
    insertion_sort(vs);
    std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
    run_tests();
    return 0;
}
