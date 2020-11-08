const insertionSort = (sequence: number[]): number[] => {
  for (let i = 0; i < sequence.length - 1; i++) {
    let iInsert = i
    let key = sequence[i + 1]
    while ((iInsert >= 0) && (key < sequence[iInsert])) {
      sequence[iInsert + 1] = sequence[iInsert]
      iInsert--
    }
    sequence[iInsert + 1] = key
  }
  return sequence
}


const insertionSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${insertionSort(seq)}`)
}

insertionSortTest()
