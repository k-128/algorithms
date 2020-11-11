package main

import "fmt"

func bubbleSort(seq []int) {
	for i := 0; i < len(seq)-1; i++ {
		isSorted := true
		for j := 0; j < len(seq)-1-i; j++ {
			if seq[j] > seq[j+1] {
				isSorted = false
				seq[j], seq[j+1] = seq[j+1], seq[j]
			}
		}
		if isSorted {
			break
		}
	}
}

func bubbleSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	bubbleSort(seq)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
