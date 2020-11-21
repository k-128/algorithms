package main

import "fmt"

func countingSort(seq []int) {
	if len(seq) == 0 {
		return
	}

	maxValue := seq[0]
	minValue := seq[0]
	for i := 1; i < len(seq); i++ {
		if maxValue < seq[i] {
			maxValue = seq[i]
		}
		if minValue > seq[i] {
			minValue = seq[i]
		}
	}

	counts := make([]int, maxValue-minValue+1)
	for i := 0; i < len(seq); i++ {
		counts[seq[i]-minValue] += 1
	}

	temp := 0
	for i := 0; i < len(counts); i++ {
		for j := 0; j < counts[i]; j++ {
			seq[temp] = i + minValue
			temp++
		}
	}
}

func countingSortTest() {
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
	countingSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +
	seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("test_int_1: ")
	countingSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -
	seq = []int{-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4}
	fmt.Printf("test_int_2: ")
	countingSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -, =
	seq = []int{1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4}
	fmt.Printf("test_int_3: ")
	countingSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}
}
