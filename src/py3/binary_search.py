from typing import Sequence


def binary_search(sequence: Sequence[int], query: int) -> int:
    low = 0
    high = len(sequence) - 1
    while low <= high:
        mid = (low + high) // 2
        if sequence[mid] == query:
            return mid

        elif sequence[mid] < query:
            low = mid + 1

        else:
            high = mid - 1

    return -1


if __name__ == "__main__":
    seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65]
    print(f"Search result : {binary_search(seq, 7)}")
    print(f"Missing query : {binary_search(seq, 6)}")
    print(f"Empty sequence: {binary_search([], 7)}")
