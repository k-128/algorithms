#ifndef INCLUDED_ALGO_H
#define INCLUDED_ALGO_H

#include <algorithm>
#include <ranges>
#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>


namespace algo
{
namespace
{
template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<typename T>
concept Container = requires(T ctnr)
{
    ctnr.size();
    requires std::ranges::contiguous_range<T>;
};

template<typename T>
concept SortedContainer = requires(T ctnr)
{
    ctnr.size();
    requires std::ranges::contiguous_range<T>;
    requires std::totally_ordered<T>;
};

template<typename T>
concept SortableContainer = requires(T ctnr)
{
    ctnr.size();
    requires std::ranges::contiguous_range<T>;
    requires std::is_integral_v<typename T::value_type>
        || std::is_floating_point_v<typename T::value_type>;
};
} // namespace


namespace search
{
inline int Binary(const SortedContainer auto &seq, Arithmetic auto query)
{
    int lo = 0;
    int hi = seq.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (seq[mid] == query)
        {
            return mid;
        }
        else if (seq[mid] < query)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}


inline int Linear(const Container auto &seq, Arithmetic auto query)
{
    int idx = 0;
    for (const auto &e : seq)
    {
        if (e == query) return idx;
        ++idx;
    }
    return -1;
}
} // namespace search


namespace sort
{
inline void Bubble(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    bool is_sorted;
    for (size_t i = 0; i < seq_size - 1; ++i)
    {
        is_sorted = true;
        for (size_t j = 0; j < seq_size - 1 - i; ++j)
        {
            if (seq[j] > seq[j + 1])
            {
                is_sorted = false;
                std::swap(seq[j], seq[j + 1]);
            }
        }
        if (is_sorted)
        {
            break;
        }
    }
}


inline void Counting(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    auto min_value = seq[0];
    auto max_value = seq[0];
    for (const auto &e : seq)
    {
        if (min_value > e) min_value = e;
        if (max_value < e) max_value = e;
    }

    const size_t counts_size = max_value - min_value + 1;
    std::vector<int> counts(counts_size, 0);
    for (const auto &e : seq)
    {
        counts[e - min_value] += 1;
    }

    int tmp = 0;
    for (size_t i = 0; i < counts_size; ++i)
    {
        for (size_t j = 0; j < counts[i]; ++j)
        {
            seq[tmp] = i + min_value;
            ++tmp;
        }
    }
}


namespace
{
void MaxHeapify(SortableContainer auto &seq, size_t i_root, size_t heap_size)
{
    size_t i_max    = i_root;
    size_t i_left   = i_root * 2 + 1;
    size_t i_right  = i_root * 2 + 2;

    if ( i_left < heap_size &&  seq[i_left] > seq[i_max]) i_max = i_left;
    if (i_right < heap_size && seq[i_right] > seq[i_max]) i_max = i_right;

    if (i_max != i_root)
    {
        std::swap(seq[i_max], seq[i_root]);
        MaxHeapify(seq, i_max, heap_size);
    }
}


void BuildMaxHeap(SortableContainer auto &seq, size_t heap_size)
{
    for (size_t i = heap_size / 2; i > 0; --i)
    {
        MaxHeapify(seq, i - 1, heap_size);
    }
}
} // namespace


inline void Heap(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    BuildMaxHeap(seq, seq_size);
    for (size_t i = seq_size - 1; i > 0; --i)
    {
        std::swap(seq[0], seq[i]);
        MaxHeapify(seq, 0, i);
    }
}


inline void Insertion(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    for (size_t i = 0; i < seq_size - 1; ++i)
    {
        int i_insert = i;
        auto key = seq[i + i];

        while (i_insert >= 0 && key < seq[i_insert])
        {
            seq[i_insert + 1] = seq[i_insert];
            --i_insert;
        }
        seq[i_insert + 1] = key;
    }
}


namespace
{
template<SortableContainer C>
void MergeFinal(C &seq, size_t lo, size_t mid, size_t hi)
{
    C temp;
    size_t i_lseq = lo;
    size_t i_rseq = mid + 1;

    while (i_lseq <= mid && i_rseq <= hi)
    {
        if (seq[i_lseq] <= seq[i_rseq])
        {
            temp.push_back(seq[i_lseq]);
            ++i_lseq;
        }
        else
        {
            temp.push_back(seq[i_rseq]);
            ++i_rseq;
        }
    }

    while (i_lseq <= mid)
    {
        temp.push_back(seq[i_lseq]);
        ++i_lseq;
    }

    while (i_rseq <= hi)
    {
        temp.push_back(seq[i_rseq]);
        ++i_rseq;
    }

    for (size_t i = lo; i <= hi; ++i)
    {
        seq[i] = temp[i - lo];
    }
}


void MergeRecursive(SortableContainer auto &seq, size_t lo, size_t hi)
{
    if (lo < hi)
    {
        size_t mid = (lo + hi) / 2;
        MergeRecursive(seq, lo, mid);
        MergeRecursive(seq, mid + 1, hi);
        MergeFinal(seq, lo, mid, hi);
    }
}
} // namespace


inline void Merge(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }
    MergeRecursive(seq, 0, seq_size - 1);
}


namespace
{
size_t QuickPartition(SortableContainer auto &seq, size_t lo, size_t hi)
{
    size_t i = lo;

    for (size_t j = lo; j < hi; ++j)
    {
        if (seq[j] <= seq[hi])
        {
            std::swap(seq[i], seq[j]);
            ++i;
        }
    }

    std::swap(seq[i], seq[hi]);
    return i;
}


void QuickRecursive(SortableContainer auto &seq, size_t lo, size_t hi)
{
    if (lo < hi)
    {
        size_t p = QuickPartition(seq, lo, hi);
        if (p)
        {
            QuickRecursive(seq, lo, p - 1);
        }
        QuickRecursive(seq, p + 1, hi);
    }
}
} // namespace


inline void Quick(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }
    QuickRecursive(seq, 0, seq_size - 1);
}


inline void Selection(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    for (size_t i = 0; i < seq_size - 1; ++i)
    {
        size_t i_lo_val = i + 1;
        for (size_t j = 0; j < seq_size - 1 - i; ++j)
        {
            if (seq[i_lo_val] > seq[j + i + 1])
            {
                i_lo_val = j + i + 1;
            }
        }

        if (seq[i] > seq[i_lo_val])
        {
            std::swap(seq[i], seq[i_lo_val]);
        }
    }
}


namespace
{
std::vector<size_t> ShellGetGaps(size_t seq_size)
{
    size_t temp = seq_size / 2;
    std::vector<size_t> gaps = {temp};
    while (temp > 1)
    {
        temp = temp / 2;
        gaps.push_back(temp);
    }
    return gaps;
}


std::vector<size_t> ShellGetGapsKnuth(size_t seq_size)
{
    size_t temp = 1;
    std::vector<size_t> gaps = {temp};
    while (temp < seq_size)
    {
        temp = temp * 3 + 1;
        gaps.push_back(temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}


std::vector<size_t> ShellGetGapsCiura(size_t seq_size)
{
    std::array<size_t, 9> gaps_init{1, 4, 10, 23, 57, 132, 301, 701, 1750};
    size_t temp = 1;
    std::vector<size_t> gaps = {};
    for (size_t i = 0; temp < seq_size; ++i)
    {
        if (temp >= 1750)
        {
            temp = std::floor(temp * 2.25);
        }
        else
        {
            temp = gaps_init[i];
        }
        gaps.push_back(temp);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}
} // namespace


inline void Shell(SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    if (seq_size == 0)
    {
        return;
    }

    std::vector<size_t> gaps = ShellGetGapsCiura(seq_size);
    const size_t gaps_size = gaps.size();

    for (size_t i = 0; i < gaps_size; ++i)
    {
        size_t gap = gaps[i];
        for (size_t j = gap; j < seq_size; ++j)
        {
            size_t i_insert = j;
            auto key = seq[j];
            while ((i_insert >= gap) && (key < seq[i_insert - gap]))
            {
                seq[i_insert] = seq[i_insert - gap];
                i_insert = i_insert - gap;
            }
            seq[i_insert] = key;
        }
    }
}
} // namespace sort


namespace test
{
namespace
{
template<typename T>
auto &operator << (std::ostream &os, const std::vector<T> v)
{
    os << '{';
    for (const auto& x : v) os << x << ", ";
    os << '}';
    return os;
}


bool IsSorted(const SortableContainer auto &seq)
{
    const size_t seq_size = seq.size();
    for (size_t i = 1; i < seq_size; ++i)
    {
        if (seq.at(i-1) > seq.at(i))
        {
            return false;
        }
    }
    return true;
}


template<typename F>
void TestSearchFn(const F&& fn, const char* fn_name)
{
    std::cout << "init test searching fn: " << fn_name << '\n';

    std::vector<int>     vin{};
    std::vector<int>     vec{2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};
    std::array<int, 13>  arr{2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65};
    std::array<float, 8> arf{2.0f, 3.1f, 4.2f, 5.3f, 7.4f, 9.5f, 12.6f, 16.7f};
    std::string str{"123456789"};

    std::cout << "- std::vector<int> empty";
    assert(fn(vin, 6) == -1 && fn_name);
    std::cout << std::string(5, ' ') << "[x]" << '\n';

    std::cout << "- std::vector<int>";
    assert(fn(vec, 7) == 4 && fn_name);
    assert(fn(vec, 6) == -1 && fn_name);
    std::cout << std::string(11, ' ') << "[x]" << '\n';

    std::cout << "- std::array<int, 13>";
    assert(fn(arr, 7) == 4 && fn_name);
    assert(fn(arr, 6) == -1 && fn_name);
    std::cout << std::string(8, ' ') << "[x]" << '\n';

    std::cout << "- std::array<float, 7>";
    assert(fn(arf, 7.4f) == 4 && fn_name);
    assert(fn(arf, 6.0f) == -1 && fn_name);
    std::cout << std::string(7, ' ') << "[x]" << '\n';

    std::cout << "- std::string";
    assert(fn(str, '7') == 6 && fn_name);
    assert(fn(str, '0') == -1 && fn_name);
    std::cout << std::string(16, ' ') << "[x]" << '\n';

    std::cout << '\n';
}


template<typename F>
void TestSortFn(const F&& fn, const char* fn_name)
{
    std::cout << "init test sorting fn: " << fn_name << '\n';
    std::vector<int> v;
    std::cout << "- std::vector<int> empty";
    fn(v);
    assert(v.size() == 0 && fn_name);
    std::cout << std::string(5, ' ') << "[x]" << '\n';

    v = {16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4};
    std::cout << "- std::vector<int> +";
    fn(v);
    assert(IsSorted(v) && fn_name);
    std::cout << std::string(9, ' ') << "[x]" << '\n';

    v = {-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4};
    std::cout << "- std::vector<int> +, -";
    fn(v);
    assert(IsSorted(v) && fn_name);
    std::cout << std::string(6, ' ') << "[x]" << '\n';

    v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
    std::cout << "- std::vector<int> +, -, =";
    fn(v);
    assert(IsSorted(v) && fn_name);
    std::cout << std::string(3, ' ') << "[x]" << '\n';

    v = {1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4};
    std::cout << "- std::vector<int> +, -, =";
    fn(v);
    assert(IsSorted(v) && fn_name);
    std::cout << std::string(3, ' ') << "[x]" << '\n';

    std::vector<float> vf = {
        1.1f, 2.2f, -4.4f, -7.7f, 1.1f, 9.9f, -7.7f, 2.2f, 2.2f, 6.6f, 1.1f
    };
    std::cout << "- std::vector<float> +, -, =";
    fn(vf);
    assert(IsSorted(vf) && fn_name);
    std::cout << std::string(1, ' ') << "[x]" << '\n';

    std::string str{"pgij65WKcBb21ld"};
    std::cout << "- std::string";
    fn(str);
    assert(IsSorted(str) && fn_name);
    std::cout << std::string(16, ' ') << "[x]" << '\n';

    std::cout << '\n';
}
} // namespace


inline void CheckFns()
{
    TestSearchFn([](auto&& s, auto&& q) { return algo::search::Binary(s, q); },
        "algo::search::Binary");
    TestSearchFn([](auto&& s, auto&& q) { return algo::search::Linear(s, q); },
        "algo::search::Linear");

    TestSortFn([](auto&& s) { return algo::sort::Bubble(s); },
        "algo::sort::Bubble");
    TestSortFn([](auto&& s) { return algo::sort::Counting(s); },
        "algo::sort::Counting");
    TestSortFn([](auto&& s) { return algo::sort::Heap(s); },
        "algo::sort::Heap");
    TestSortFn([](auto&& s) { return algo::sort::Insertion(s); },
        "algo::sort::Insertion");
    TestSortFn([](auto&& s) { return algo::sort::Merge(s); },
        "algo::sort::Merge");
    TestSortFn([](auto&& s) { return algo::sort::Quick(s); },
        "algo::sort::Quick");
    TestSortFn([](auto&& s) { return algo::sort::Selection(s); },
        "algo::sort::Selection");
    TestSortFn([](auto&& s) { return algo::sort::Shell(s); },
        "algo::sort::Shell");

    std::cout << "Tests successful.\n";
}
} // namespace test
} // namespace algo


int main()
{
    algo::test::CheckFns();
}


#endif // INCLUDED_ALGO_H
