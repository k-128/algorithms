package main

import (
	"fmt"
	"math"
	"sort"
)

func getGaps(size int) []int {
	temp := size / 2
	gaps := []int{temp}
	for temp > 1 {
		temp = temp / 2
		gaps = append(gaps, temp)
	}
	return gaps
}

func getGapsKnuth(size int) []int {
	temp := 1
	gaps := []int{temp}
	for temp < size {
		temp = temp*3 + 1
		gaps = append(gaps, temp)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(gaps)))
	return gaps
}

func getGapsCiura(size int) []int {
	gapsInit := []int{1, 4, 10, 23, 57, 132, 301, 701, 1750}
	temp := 1
	gaps := []int{}
	for i := 0; temp < size; i++ {
		if temp >= 1750 {
			temp = int(math.Floor(float64(temp) * 2.25))
		} else {
			temp = gapsInit[i]
		}
		gaps = append(gaps, temp)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(gaps)))
	return gaps
}

func shellSort(seq []int) {
	for _, gap := range getGapsCiura(len(seq)) {
		for i := gap; i < len(seq); i++ {
			iInsert := i
			key := seq[i]
			for (iInsert >= gap) && (key < seq[iInsert-gap]) {
				seq[iInsert] = seq[iInsert-gap]
				iInsert = iInsert - gap
			}
			seq[iInsert] = key
		}
	}
}

func shellSortTest() {
	seq := []int{16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4}
	shellSort(seq)

	fmt.Printf("Sorted sequence : %v\n", seq)
}
