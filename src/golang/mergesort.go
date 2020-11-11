package main

import "fmt"

func merge(seq []int, lo int, mid int, hi int) {
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

func mergeSort(seq []int, lo int, hi int) {
	if lo < hi {
		mid := (lo + hi) / 2
		mergeSort(seq, lo, mid)
		mergeSort(seq, mid+1, hi)
		merge(seq, lo, mid, hi)
	}
}

func mergeSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	mergeSort(seq, 0, len(seq)-1)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
