package main

import "fmt"

func insertionSort(sequence []int) []int {
	for i := 0; i < len(sequence)-1; i++ {
		var iInsert = i
		var key = sequence[i+1]
		for (iInsert >= 0) && (key < sequence[iInsert]) {
			sequence[iInsert+1] = sequence[iInsert]
			iInsert--
		}
		sequence[iInsert+1] = key
	}
	return sequence
}

func insertionSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	fmt.Printf("Initial sequence: %v\n", seq)
	fmt.Printf("Sorted sequence : %v\n", insertionSort(seq))
}
