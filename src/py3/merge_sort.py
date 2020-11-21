from typing import List, Any


def _merge(seq: List[Any], lo: int, mid: int, hi: int) -> None:
    temp = []
    i_lseq = lo
    i_rseq = mid + 1

    while (i_lseq <= mid and i_rseq <= hi):
        if (seq[i_lseq] <= seq[i_rseq]):
            temp.append(seq[i_lseq])
            i_lseq += 1

        else:
            temp.append(seq[i_rseq])
            i_rseq += 1

    while (i_lseq <= mid):
        temp.append(seq[i_lseq])
        i_lseq +=1

    while (i_rseq <= hi):
        temp.append(seq[i_rseq])
        i_rseq += 1

    for i in range(lo, hi + 1):
        seq[i] = temp[i - lo]


def _merge_sort(seq: List[Any], lo: int, hi: int) -> None:
    if (lo < hi):
        mid = (lo + hi) // 2
        _merge_sort(seq, lo, mid)
        _merge_sort(seq, mid + 1, hi)
        _merge(seq, lo, mid, hi)


def merge_sort(seq: List[Any]) -> None:
    _merge_sort(seq, 0, len(seq) - 1)


if __name__ == "__main__":
    sorting_fn = merge_sort

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
