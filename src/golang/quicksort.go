package main

import "fmt"

func _partition(seq []int, lo int, hi int) int {
	i := lo

	for j := lo; j < hi; j++ {
		if seq[j] < seq[hi] {
			seq[i], seq[j] = seq[j], seq[i]
			i++
		}
	}

	seq[i], seq[hi] = seq[hi], seq[i]
	return i
}

func _quickSort(seq []int, lo int, hi int) {
	if lo < hi {
		p := _partition(seq, lo, hi)
		_quickSort(seq, lo, p-1)
		_quickSort(seq, p+1, hi)
	}
}

func quickSort(seq []int) {
	_quickSort(seq, 0, len(seq)-1)
}

func quickSortTest() {
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
	quickSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +
	seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("test_int_1: ")
	quickSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -
	seq = []int{-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4}
	fmt.Printf("test_int_2: ")
	quickSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -, =
	seq = []int{1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4}
	fmt.Printf("test_int_3: ")
	quickSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}
}
