from typing import List


def selection_sort(sequence: List[int]) -> List[int]:
    for i in range(len(sequence) - 1):
        i_lo_val = i + 1
        for j in range(len(sequence) - 1 - i):
            if sequence[i_lo_val] > sequence[j + i + 1]:
                i_lo_val = j + i + 1

        if sequence[i] > sequence[i_lo_val]:
            sequence[i], sequence[i_lo_val] = sequence[i_lo_val], sequence[i]

    return sequence


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {selection_sort(seq)}")
