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
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	heapSort(seq)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
