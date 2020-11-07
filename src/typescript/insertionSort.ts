const insertionSort = (sequence: number[]): number[] => {
  for (let i = 0; i < sequence.length - 1; i++) {
    let i_insert = i
    let key = sequence[i + 1]
    while ((i_insert >= 0) && (key < sequence[i_insert])) {
      sequence[i_insert + 1] = sequence[i_insert]
      i_insert--
    }
    sequence[i_insert + 1] = key
  }
  return sequence
}


const insertionSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${insertionSort(seq)}`)
}

insertionSortTest()
