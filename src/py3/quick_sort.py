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
    seq_1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_1_sorted = seq_1.copy()
    seq_2 = ["p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"]
    seq_2_sorted = seq_2.copy()
    quick_sort(seq_1_sorted)
    quick_sort(seq_2_sorted)

    print(f"seq_1: {seq_1}\nseq_1_sorted: {seq_1_sorted}")
    print(f"seq_2: {seq_2}\nseq_2_sorted: {seq_2_sorted}")
