const selectionSort = (sequence: number[]): number[] => {
  for (let i = 0; i < sequence.length - 1; i++) {
    let iLoVal = i + 1
    for (let j = 0; j < sequence.length - 1 - i; j++) {
      if (sequence[iLoVal] > sequence[j + i + 1]) {
        iLoVal = j + i + 1
      }
    }
    if (sequence[i] > sequence[iLoVal]) {
      [sequence[i], sequence[iLoVal]] = [sequence[iLoVal], sequence[i]]
    }
  }
  return sequence
}


const selectionSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${selectionSort(seq)}`)
}

selectionSortTest()
