from typing import List, Any


def max_heapify(seq: List[Any], i_root: int, heap_size: int) -> None:
    i_max   = i_root
    i_left  = i_root * 2 + 1
    i_right = i_root * 2 + 2

    if (i_left < heap_size) and seq[i_left] > seq[i_max]:
        i_max = i_left

    if (i_right < heap_size) and seq[i_right] > seq[i_max]:
        i_max = i_right

    if i_max != i_root:
        seq[i_root], seq[i_max] = seq[i_max], seq[i_root]
        max_heapify(seq, i_max, heap_size)


def build_max_heap(seq: List[Any], heap_size: int) -> None:
    for i in range(heap_size // 2, 0, -1):
        max_heapify(seq, i-1, heap_size)


def heap_sort(seq: List[Any]) -> None:
    n = len(seq)
    build_max_heap(seq, n)
    for i in range(n - 1, 0, -1):
        seq[0], seq[i] = seq[i], seq[0]
        max_heapify(seq, 0, i)


if __name__ == "__main__":
    sorting_fn = heap_sort

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
