from typing import List, Any


def _partition(seq: List[Any], lo: int, hi: int) -> int:
    i = lo
    for j in range(lo, hi):
        if seq[j] < seq[hi]:
            seq[i], seq[j] = seq[j], seq[i]
            i += 1

    seq[i], seq[hi] = seq[hi], seq[i]
    return i


def _quick_sort(seq: List[Any], lo: int, hi: int) -> None:
    if (lo < hi):
        p = _partition(seq, lo, hi)
        _quick_sort(seq, lo, p-1)
        _quick_sort(seq, p+1, hi)


def quick_sort(seq: List[Any]) -> None:
    _quick_sort(seq, 0, len(seq) - 1)


if __name__ == "__main__":
    sorting_fn = quick_sort

    def is_sorted(seq: List[Any]) -> bool:
        for i in range(len(seq)-1):
            if seq[i] > seq[i+1]:
                return False
        return True

    # empty
    seq = []
    sorting_fn(seq)
    print(f"test_empty: {'passed' if is_sorted(seq) else 'failed'}.")

    # +
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    sorting_fn(seq)
    print(f"test_int_1: {'passed' if is_sorted(seq) else 'failed'}.")

    # +, -
    seq = [-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4]
    sorting_fn(seq)
    print(f"test_int_2: {'passed' if is_sorted(seq) else 'failed'}.")

    # +, -, =
    seq = [1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4]
    sorting_fn(seq)
    print(f"test_int_3: {'passed' if is_sorted(seq) else 'failed'}.")

    # string
    seq = ["p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"]
    sorting_fn(seq)
    print(f"test_str: {'passed' if is_sorted(seq) else 'failed'}.")
