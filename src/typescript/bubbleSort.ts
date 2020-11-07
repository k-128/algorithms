const bubbleSort = (sequence: number[]): number[] => {
  let isSorted: boolean
  for (let i = 0; i < sequence.length - 1; i++) {
    isSorted = true
    for (let j = 0; j < sequence.length - 1 - i; j++) {
      if (sequence[j] > sequence[j+1]) {
        isSorted = false;
        [sequence[j], sequence[j + 1]] = [sequence[j + 1], sequence[j]]
      }
    }
    if (isSorted) {
      break
    }
  }
  return sequence
}


const bubbleSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${bubbleSort(seq)}`)
}

bubbleSortTest()
