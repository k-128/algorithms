#include <iostream>
#include <vector>
#include <string>


template <typename T>
void selection_sort(std::vector<T> &seq) {
    if (seq.size() == 0) {
        return;
    }

    for (size_t i = 0; i < seq.size() - 1; ++i) {
        size_t i_lo_val = i + 1;
        for (size_t j = 0; j < seq.size() - 1 - i; ++j) {
            if (seq[i_lo_val] > seq[j + i + 1]) {
                i_lo_val = j + i + 1;
            }
        }
        if (seq[i] > seq[i_lo_val]) {
            std::swap(seq[i], seq[i_lo_val]);
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
    selection_sort(v);
    std::cout << (v.size() == 0 ? "passed" : "failed") << "." << "\n";

    // +
    v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::cout << "test_int_1... ";
    selection_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // +, -
    v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
    std::cout << "test_int_2... ";
    selection_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // +, -, =
    v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
    std::cout << "test_int_3... ";
    selection_sort(v);
    std::cout << (is_sorted(v) ? "passed" : "failed") << ": " << v << "\n";

    // string
    std::vector<std::string> vs;
    vs = {"p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"};
    std::cout << "test_string.. ";
    selection_sort(vs);
    std::cout << (is_sorted(vs) ? "passed" : "failed") << ": " << vs << "\n";
}


int main() {
    run_tests();
    return 0;
}
