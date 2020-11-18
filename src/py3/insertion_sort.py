from typing import List, Any


def insertion_sort(seq: List[Any]) -> None:
    for i in range(len(seq) - 1):
        i_insert = i
        key = seq[i + 1]
        while (i_insert >= 0) and (key < seq[i_insert]):
            seq[i_insert + 1] = seq[i_insert]
            i_insert -= 1

        seq[i_insert + 1] = key


if __name__ == "__main__":
    seq_1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    seq_1_sorted = seq_1.copy()
    seq_2 = ["p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"]
    seq_2_sorted = seq_2.copy()
    insertion_sort(seq_1_sorted)
    insertion_sort(seq_2_sorted)

    print(f"seq_1: {seq_1}\nseq_1_sorted: {seq_1_sorted}")
    print(f"seq_2: {seq_2}\nseq_2_sorted: {seq_2_sorted}")
