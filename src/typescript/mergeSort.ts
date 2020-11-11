const merge = (seq: number[], lo: number, mid: number, hi: number): void => {
  let temp = []
  let iLSeq = lo
  let iRSeq = mid + 1

  while ((iLSeq <= mid) && (iRSeq <= hi)) {
    if (seq[iLSeq] <= seq[iRSeq]) {
      temp.push(seq[iLSeq])
      iLSeq++
    } else {
      temp.push(seq[iRSeq])
      iRSeq++
    }
  }

  while (iLSeq <= mid) {
    temp.push(seq[iLSeq])
    iLSeq++
  }

  while (iRSeq <= hi) {
    temp.push(seq[iRSeq])
    iRSeq++
  }

  for (let i = lo; i <= hi; i++) {
    seq[i] = temp[i - lo]
  }
}


const mergeSort = (seq: number[], lo: number, hi: number): void => {
  if (lo < hi) {
    let mid = Math.floor((lo + hi) / 2)
    mergeSort(seq, lo, mid)
    mergeSort(seq, mid + 1, hi)
    merge(seq, lo, mid, hi)
  }
}


const mergeSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  mergeSort(seq_sorted, 0, seq_sorted.length - 1)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

mergeSortTest()
