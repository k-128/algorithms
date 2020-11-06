from typing import Sequence


def linear_search(sequence: Sequence[int], query: int) -> int:
    for i, val in enumerate(sequence):
        if val == query:
            return i

    return -1


if __name__ == "__main__":
    seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65]
    print(f"Search result : {linear_search(seq, 7)}")
    print(f"Missing query : {linear_search(seq, 6)}")
    print(f"Empty sequence: {linear_search([], 7)}")
