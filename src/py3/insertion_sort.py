from typing import List


def insertion_sort(seq: List[int]) -> None:
    for i in range(len(seq) - 1):
        i_insert = i
        key = seq[i + 1]
        while (i_insert >= 0) and (key < seq[i_insert]):
            seq[i_insert + 1] = seq[i_insert]
            i_insert -= 1

        seq[i_insert + 1] = key


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    insertion_sort(seq_sorted)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
