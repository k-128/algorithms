from math import floor
from typing import List


def get_gaps(size: int) -> List[int]:
    temp = size // 2
    gaps = [temp]
    while temp > 1:
        temp = temp // 2
        gaps.append(temp)

    return gaps


def get_gaps_knuth(size: int) -> List[int]:
    temp = 1
    gaps = [temp]
    while temp < size:
        temp = temp * 3 + 1
        gaps.append(temp)

    return gaps[::-1]


def get_gaps_ciura(size: int) -> List[int]:
    gaps_init = [1, 4, 10, 23, 57, 132, 301, 701, 1750]
    temp = 1
    gaps = []
    i = 0
    while temp < size:
        temp = floor(temp * 2.25) if temp >= 1750 else gaps_init[i]
        gaps.append(temp)
        i += 1

    return gaps[::-1]


def shell_sort(seq: List[int]) -> None:
    for gap in get_gaps_ciura(len(seq)):
        for i in range(gap, len(seq)):
            i_insert = i
            key = seq[i]
            while (i_insert >= gap) and (key < seq[i_insert - gap]):
                seq[i_insert] = seq[i_insert - gap]
                i_insert -= gap

            seq[i_insert] = key


if __name__ == "__main__":
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_sorted = seq.copy()
    shell_sort(seq_sorted)

    print(f"Initial sequence: {seq}")
    print(f"Sorted sequence : {seq_sorted}")
