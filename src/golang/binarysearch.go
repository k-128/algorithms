package main

import "fmt"

func binarySearch(sequence []int, query int) int {
	low := 0
	high := len(sequence) - 1
	for low <= high {
		mid := (low + high) / 2
		if sequence[mid] == query {
			return mid
		} else if sequence[mid] < query {
			low = mid + 1
		} else {
			high = mid - 1
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
