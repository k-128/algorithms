from typing import List


def merge(seq: List[int], lo: int, mid: int, hi: int) -> None:
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


def merge_sort(seq: List[int], lo: int, hi: int) -> None:
    if (lo < hi):
        mid = (lo + hi) // 2
        merge_sort(seq, lo, mid)
        merge_sort(seq, mid + 1, hi)
        merge(seq, lo, mid, hi)


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    merge_sort(seq_sorted, 0, len(seq_sorted) - 1)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
