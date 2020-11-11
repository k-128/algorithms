package main

import "fmt"

func insertionSort(seq []int) {
	for i := 0; i < len(seq)-1; i++ {
		iInsert := i
		key := seq[i+1]
		for (iInsert >= 0) && (key < seq[iInsert]) {
			seq[iInsert+1] = seq[iInsert]
			iInsert--
		}
		seq[iInsert+1] = key
	}
}

func insertionSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	insertionSort(seq)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
