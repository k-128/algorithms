from typing import List, Any


def selection_sort(seq: List[Any]) -> None:
    for i in range(len(seq) - 1):
        i_lo_val = i + 1
        for j in range(len(seq) - 1 - i):
            if seq[i_lo_val] > seq[j + i + 1]:
                i_lo_val = j + i + 1

        if seq[i] > seq[i_lo_val]:
            seq[i], seq[i_lo_val] = seq[i_lo_val], seq[i]


if __name__ == "__main__":
    sorting_fn = selection_sort

    def is_sorted(seq: List[Any]) -> bool:
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

    # string
    seq = ["p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"]
    sorting_fn(seq)
    print(f"test_str: {'passed' if is_sorted(seq) else 'failed'}.")
