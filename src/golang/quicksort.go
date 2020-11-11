package main

import "fmt"

func partition(seq []int, lo int, hi int) int {
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

func quickSort(seq []int, lo int, hi int) {
	if lo < hi {
		p := partition(seq, lo, hi)
		quickSort(seq, lo, p-1)
		quickSort(seq, p+1, hi)
	}
}

func quickSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	quickSort(seq, 0, len(seq)-1)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
