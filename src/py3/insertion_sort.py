from typing import List


def insertion_sort(sequence: List[int]) -> List[int]:
    for i in range(len(sequence) - 1):
        i_insert = i
        key = sequence[i + 1]
        while key < sequence[i_insert] and i_insert >= 0:
            sequence[i_insert + 1] = sequence[i_insert]
            i_insert -= 1

        if i != i_insert:
            sequence[i_insert + 1] = key

    return sequence


if __name__ == "__main__": 
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {insertion_sort(seq)}")
