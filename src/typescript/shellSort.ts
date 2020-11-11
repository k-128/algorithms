const getGaps = (size: number): number[] => {
  let temp = Math.floor(size / 2)
  let gaps = [temp]
  while (temp > 1) {
    temp = Math.floor(temp / 2)
    gaps.push(temp)
  }
  return gaps
}


const getGapsKnuth = (size: number): number[] => {
  let temp = 1
  let gaps = [temp]
  while (temp < size) {
    temp = temp * 3 + 1
    gaps.push(temp)
  }
  return gaps.reverse()
}


const getGapsCiura = (size: number): number[] => {
  let gapsInit = [1, 4, 10, 23, 57, 132, 301, 701, 1750]
  let temp = 1
  let gaps = []
  for (let i = 0; temp < size; i++) {
    temp = temp >= 1750 ? Math.floor(temp * 2.25) : gapsInit[i]
    gaps.push(temp)
  }
  return gaps.reverse()
}


const shellSort = (seq: number[]): void => {
  let gaps = getGapsCiura(seq.length)

  for (let i=0; i < gaps.length; i++) {
    let gap = gaps[i]
    for (let j=gap; j < seq.length; j++) {
      let iInsert = j
      let key = seq[j]
      while ((iInsert >= gap) && (key < seq[iInsert - gap])) {
        seq[iInsert] = seq[iInsert - gap]
        iInsert = iInsert - gap
      }
      seq[iInsert] = key
    }
  }
}


const shellSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  let seq_sorted = Object.assign([], seq)
  shellSort(seq_sorted)

  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${seq_sorted}`)
}

shellSortTest()
