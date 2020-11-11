const partition = (seq: number[], lo: number, hi: number): number => {
  let i = lo

  for (let j = lo; j < hi; j++) {
      if (seq[j] < seq[hi]) {
          [seq[i], seq[j]] = [seq[j], seq[i]]
          i++
      }
  }

  [seq[i], seq[hi]] = [seq[hi], seq[i]]
  return i
}


const quickSort = (seq: number[], lo: number, hi: number): void => {
    if (lo < hi) {
        let p = partition(seq, lo, hi)
        quickSort(seq, lo, p-1)
        quickSort(seq, p+1, hi)
    }
}


const quickSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  quickSort(seq_sorted, 0, seq_sorted.length - 1)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

quickSortTest()
