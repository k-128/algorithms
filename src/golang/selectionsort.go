package main

import "fmt"

func selectionSort(sequence []int) []int {
	for i := 0; i < len(sequence)-1; i++ {
		var i_lo_val = i + 1
		for j := 0; j < len(sequence)-1-i; j++ {
			if sequence[i_lo_val] > sequence[j+i+1] {
				i_lo_val = j + i + 1
			}
		}
		if sequence[i] > sequence[i_lo_val] {
			sequence[i], sequence[i_lo_val] = sequence[i_lo_val], sequence[i]
		}
	}
	return sequence
}

func selectionSortTest() {
	var seq = []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("Initial sequence: %v\n", seq)
	fmt.Printf("Sorted sequence : %v\n", selectionSort(seq))
}
