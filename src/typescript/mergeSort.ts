const mergeIntervals = (seqLeft: number[], seqRight: number[]): number[] => {
  let merged = []
  let kLSeq = 0
  let kRSeq = 0
  while ((kLSeq < seqLeft.length) && (kRSeq < seqRight.length)) {
    if (seqLeft[kLSeq] <= seqRight[kRSeq]) {
      merged.push(seqLeft[kLSeq])
      kLSeq++
    } else {
      merged.push(seqRight[kRSeq])
      kRSeq++
    }
  }

  while (kLSeq < seqLeft.length) {
    merged.push(seqLeft[kLSeq])
    kLSeq++
  }

  while (kRSeq < seqRight.length) {
    merged.push(seqRight[kRSeq])
    kRSeq++
  }

  return merged
}


const mergeSort = (sequence: number[]): number[] => {
  if (sequence.length < 2) {
    return sequence
  }

  let mid = Math.floor(sequence.length / 2)
  return mergeIntervals(
    mergeSort(sequence.slice(0, mid)),
    mergeSort(sequence.slice(mid, sequence.length))
  )
}


const mergeSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${mergeSort(seq)}`)
}

mergeSortTest()
