package main

import "fmt"

func mergeIntervals(seqLeft []int, seqRight []int) []int {
	var merged []int
	var kLSeq int
	var kRSeq int
	for (kLSeq < len(seqLeft)) && (kRSeq < len(seqRight)) {
		if seqLeft[kLSeq] < seqRight[kRSeq] {
			merged = append(merged, seqLeft[kLSeq])
			kLSeq++
		} else {
			merged = append(merged, seqRight[kRSeq])
			kRSeq++
		}
	}

	for kLSeq < len(seqLeft) {
		merged = append(merged, seqLeft[kLSeq])
		kLSeq++
	}

	for kRSeq < len(seqRight) {
		merged = append(merged, seqRight[kRSeq])
		kRSeq++
	}

	return merged
}

func mergeSort(sequence []int) []int {
	if len(sequence) < 2 {
		return sequence
	}

	mid := len(sequence) / 2
	return mergeIntervals(
		mergeSort(sequence[:mid]),
		mergeSort(sequence[mid:]))
}

func mergeSortTest() {
	var seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("Initial sequence: %v\n", seq)
	fmt.Printf("Sorted sequence : %v\n", mergeSort(seq))
}
