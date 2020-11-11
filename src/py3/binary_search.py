from typing import Sequence


def binary_search(seq: Sequence[int], query: int) -> int:
    lo = 0
    hi = len(seq) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if seq[mid] == query:
            return mid

        elif seq[mid] < query:
            lo = mid + 1

        else:
            hi = mid - 1

    return -1


if __name__ == "__main__":
    seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65]
    print(f"Search result : {binary_search(seq, 7)}")
    print(f"Missing query : {binary_search(seq, 6)}")
    print(f"Empty sequence: {binary_search([], 7)}")
