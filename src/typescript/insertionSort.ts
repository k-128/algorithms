const insertionSort = (seq: number[]): void => {
  for (let i = 0; i < seq.length - 1; i++) {
    let iInsert = i
    let key = seq[i + 1]
    while ((iInsert >= 0) && (key < seq[iInsert])) {
      seq[iInsert + 1] = seq[iInsert]
      iInsert--
    }
    seq[iInsert + 1] = key
  }
}


const insertionSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  insertionSort(seq_sorted)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

insertionSortTest()
