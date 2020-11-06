from typing import List


def bubble_sort(sequence: List[int]) -> List[int]:
    for i in range(len(sequence) - 1):
        is_sorted = True
        for j in range(len(sequence) - 1 - i):
            if sequence[j] > sequence[j + 1]:
                is_sorted = False
                sequence[j], sequence[j + 1] = sequence[j + 1], sequence[j]

        if is_sorted:
            break

    return sequence


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {bubble_sort(seq)}")
