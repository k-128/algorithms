from typing import List


def counting_sort(seq: List[int]) -> None:
    if not seq:
        return

    maxValue = seq[0]
    minValue = seq[0]
    for i in range(len(seq) - 1):
        if maxValue < seq[i]:
            maxValue = seq[i]

        if minValue > seq[i]:
            minValue = seq[i]

    counts = [0 for _ in range(maxValue - minValue + 1)]
    for val in seq:
        counts[val - minValue] += 1

    temp = 0
    for i, val in enumerate(counts):
        for _ in range(val):
            seq[temp] = i + minValue
            temp += 1


if __name__ == "__main__":
    sorting_fn = counting_sort

    def is_sorted(seq: List[int]) -> bool:
        for i in range(len(seq)-1):
            if seq[i] > seq[i+1]:
                return False
        return True

    # empty
    seq = []
    sorting_fn(seq)
    print(f"test_empty: {'passed' if is_sorted(seq) else 'failed'}.")

    # +
    seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    sorting_fn(seq)
    print(f"test_int_1: {'passed' if is_sorted(seq) else 'failed'}.")

    # +, -
    seq = [-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4]
    sorting_fn(seq)
    print(f"test_int_2: {'passed' if is_sorted(seq) else 'failed'}.")

    # +, -, =
    seq = [1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4]
    sorting_fn(seq)
    print(f"test_int_3: {'passed' if is_sorted(seq) else 'failed'}.")
