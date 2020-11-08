from typing import List


def merge(seq_left: List[int], seq_right: List[int]) -> List[int]:
    merged = []
    k_lseq = 0
    k_rseq = 0
    while (k_lseq < len(seq_left)) and (k_rseq < len(seq_right)):
        if seq_left[k_lseq] <= seq_right[k_rseq]:
            merged.append(seq_left[k_lseq])
            k_lseq += 1

        else:
            merged.append(seq_right[k_rseq])
            k_rseq += 1

    while k_lseq < len(seq_left):
        merged.append(seq_left[k_lseq])
        k_lseq += 1

    while k_rseq < len(seq_right):
        merged.append(seq_right[k_rseq])
        k_rseq += 1

    return merged


def merge_sort(sequence: List[int]) -> List[int]:
    if len(sequence) < 2:
        return sequence

    mid = len(sequence) // 2
    return merge(
        merge_sort(sequence[:mid]),
        merge_sort(sequence[mid:])
    )


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {merge_sort(seq)}")
