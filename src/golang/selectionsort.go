package main

import "fmt"

func selectionSort(seq []int) {
	for i := 0; i < len(seq)-1; i++ {
		iLoVal := i + 1
		for j := 0; j < len(seq)-1-i; j++ {
			if seq[iLoVal] > seq[j+i+1] {
				iLoVal = j + i + 1
			}
		}
		if seq[i] > seq[iLoVal] {
			seq[i], seq[iLoVal] = seq[iLoVal], seq[i]
		}
	}
}

func selectionSortTest() {
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
	selectionSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +
	seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("test_int_1: ")
	selectionSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -
	seq = []int{-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4}
	fmt.Printf("test_int_2: ")
	selectionSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -, =
	seq = []int{1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4}
	fmt.Printf("test_int_3: ")
	selectionSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}
}
