package main

import "fmt"

func _merge(seq []int, lo int, mid int, hi int) {
	var temp []int
	iLSeq := lo
	iRSeq := mid + 1

	for (iLSeq <= mid) && (iRSeq <= hi) {
		if seq[iLSeq] <= seq[iRSeq] {
			temp = append(temp, seq[iLSeq])
			iLSeq++
		} else {
			temp = append(temp, seq[iRSeq])
			iRSeq++
		}
	}

	for iLSeq <= mid {
		temp = append(temp, seq[iLSeq])
		iLSeq++
	}

	for iRSeq <= hi {
		temp = append(temp, seq[iRSeq])
		iRSeq++
	}

	for i := lo; i <= hi; i++ {
		seq[i] = temp[i-lo]
	}
}

func _mergeSort(seq []int, lo int, hi int) {
	if lo < hi {
		mid := (lo + hi) / 2
		_mergeSort(seq, lo, mid)
		_mergeSort(seq, mid+1, hi)
		_merge(seq, lo, mid, hi)
	}
}

func mergeSort(seq []int) {
	_mergeSort(seq, 0, len(seq)-1)
}

func mergeSortTest() {
	isSorted := func(seq []int) bool {
		for i := 0; i < len(seq)-1; i++ {
			if seq[i] > seq[i+1] {
				return false
			}
		}
		return true
	}

	// Empty
	seq := []int{}
	fmt.Printf("test_empty: ")
	mergeSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +
	seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("test_int_1: ")
	mergeSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -
	seq = []int{-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4}
	fmt.Printf("test_int_2: ")
	mergeSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -, =
	seq = []int{1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4}
	fmt.Printf("test_int_3: ")
	mergeSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}
}
