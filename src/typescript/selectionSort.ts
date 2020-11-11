const selectionSort = (seq: number[]): void => {
  for (let i = 0; i < seq.length - 1; i++) {
    let iLoVal = i + 1
    for (let j = 0; j < seq.length - 1 - i; j++) {
      if (seq[iLoVal] > seq[j + i + 1]) {
        iLoVal = j + i + 1
      }
    }
    if (seq[i] > seq[iLoVal]) {
      [seq[i], seq[iLoVal]] = [seq[iLoVal], seq[i]]
    }
  }
}


const selectionSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  selectionSort(seq_sorted)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

selectionSortTest()
