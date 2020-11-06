package main

import "fmt"

func linearSearch(sequence []int, query int) int {
	for i, val := range sequence {
		if val == query {
			return i
		}
	}
	return -1
}

func linearSearchTest() {
	seq := []int{2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65}
	fmt.Printf("Search result : %d\n", linearSearch(seq, 7))
	fmt.Printf("Missing query : %d\n", linearSearch(seq, 6))
	fmt.Printf("Empty sequence: %d\n", linearSearch([]int{}, 7))
}
