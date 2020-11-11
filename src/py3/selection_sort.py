from typing import List


def selection_sort(seq: List[int]) -> None:
    for i in range(len(seq) - 1):
        i_lo_val = i + 1
        for j in range(len(seq) - 1 - i):
            if seq[i_lo_val] > seq[j + i + 1]:
                i_lo_val = j + i + 1

        if seq[i] > seq[i_lo_val]:
            seq[i], seq[i_lo_val] = seq[i_lo_val], seq[i]


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    selection_sort(seq_sorted)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
