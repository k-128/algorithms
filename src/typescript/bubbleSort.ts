const bubbleSort = (seq: number[]): void => {
  for (let i = 0; i < seq.length - 1; i++) {
    let isSorted = true
    for (let j = 0; j < seq.length - 1 - i; j++) {
      if (seq[j] > seq[j+1]) {
        isSorted = false;
        [seq[j], seq[j + 1]] = [seq[j + 1], seq[j]]
      }
    }
    if (isSorted) {
      break
    }
  }
}


const bubbleSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  bubbleSort(seq_sorted)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

bubbleSortTest()
