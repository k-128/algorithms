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
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	selectionSort(seq)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
