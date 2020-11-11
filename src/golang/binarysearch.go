package main

import "fmt"

func binarySearch(seq []int, query int) int {
	lo := 0
	hi := len(seq) - 1
	for lo <= hi {
		mid := (lo + hi) / 2
		if seq[mid] == query {
			return mid
		} else if seq[mid] < query {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return -1
}

func binarySearchTest() {
	seq := []int{2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65}

	fmt.Printf("Search result : %d\n", binarySearch(seq, 7))
	fmt.Printf("Missing query : %d\n", binarySearch(seq, 6))
	fmt.Printf("Empty sequence: %d\n", binarySearch([]int{}, 7))
}
