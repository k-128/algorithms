from typing import List


def partition(seq: List[int], lo: int, hi: int) -> int:
    i = lo
    for j in range(lo, hi):
        if seq[j] < seq[hi]:
            seq[i], seq[j] = seq[j], seq[i]
            i += 1

    seq[i], seq[hi] = seq[hi], seq[i]
    return i


def quick_sort(seq: List[int], lo: int, hi: int) -> None:
    if (lo < hi):
        p = partition(seq, lo, hi)
        quick_sort(seq, lo, p-1)
        quick_sort(seq, p+1, hi)


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    quick_sort(seq_sorted, 0, len(seq_sorted) - 1)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
