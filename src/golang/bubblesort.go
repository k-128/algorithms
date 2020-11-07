package main

import "fmt"

func bubbleSort(sequence []int) []int {
	for i := 0; i < len(sequence)-1; i++ {
		var isSorted = true
		for j := 0; j < len(sequence)-1-i; j++ {
			if sequence[j] > sequence[j+1] {
				isSorted = false
				sequence[j], sequence[j+1] = sequence[j+1], sequence[j]
			}
		}
		if isSorted {
			break
		}
	}
	return sequence
}

func bubbleSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("Initial sequence: %v\n", seq)
	fmt.Printf("Sorted sequence : %v\n", bubbleSort(seq))
}
