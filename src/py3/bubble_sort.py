from typing import List


def bubble_sort(seq: List[int]) -> None:
    for i in range(len(seq) - 1):
        is_sorted = True
        for j in range(len(seq) - 1 - i):
            if seq[j] > seq[j + 1]:
                is_sorted = False
                seq[j], seq[j + 1] = seq[j + 1], seq[j]

        if is_sorted:
            break


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    bubble_sort(seq_sorted)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
