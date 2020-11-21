package main

import "fmt"

func heapify(seq []int, iRoot int, heapSize int) {
	iMax := iRoot
	iLeft := iRoot*2 + 1
	iRight := iRoot*2 + 2

	if (iLeft < heapSize) && (seq[iLeft] > seq[iMax]) {
		iMax = iLeft
	}

	if (iRight < heapSize) && (seq[iRight] > seq[iMax]) {
		iMax = iRight
	}

	if iMax != iRoot {
		seq[iRoot], seq[iMax] = seq[iMax], seq[iRoot]
		heapify(seq, iMax, heapSize)
	}
}

func buildMaxHeap(seq []int, heapSize int) {
	for i := heapSize / 2; i > 0; i-- {
		heapify(seq, i-1, heapSize)
	}
}

func heapSort(seq []int) {
	n := len(seq)
	buildMaxHeap(seq, n)

	for i := n - 1; i > 0; i-- {
		seq[0], seq[i] = seq[i], seq[0]
		heapify(seq, 0, i)
	}
}

func heapSortTest() {
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
	heapSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +
	seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("test_int_1: ")
	heapSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -
	seq = []int{-16, 7, -9, 5, -65, 49, -37, 3, -28, 2, -21, 12, -4}
	fmt.Printf("test_int_2: ")
	heapSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}

	// +, -, =
	seq = []int{1, 2, -4, -7, 1, 9, -7, 2, 2, 6, 1, 12, 4}
	fmt.Printf("test_int_3: ")
	heapSort(seq)
	if isSorted(seq) {
		fmt.Printf("passed: %v\n", seq)
	}
}
