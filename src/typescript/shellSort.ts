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
  let gaps_init = [1, 4, 10, 23, 57, 132, 301, 701, 1750]
  let temp = 1
  let gaps = []
  for (let i = 0; temp < size; i++) {
    temp = temp >= 1750 ? Math.floor(temp * 2.25) : gaps_init[i]
    gaps.push(temp)
  }
  return gaps.reverse()
}


const shellSort = (sequence: number[]): number[] => {
  let gaps = getGapsCiura(sequence.length)
  for (let i=0; i < gaps.length; i++) {
    let gap = gaps[i]
    for (let j=gap; j < sequence.length; j++) {
      let i_insert = j
      let key = sequence[j]
      while ((i_insert >= gap) && (key < sequence[i_insert - gap])) {
        sequence[i_insert] = sequence[i_insert - gap]
        i_insert = i_insert - gap
      }
      sequence[i_insert] = key
    }
  }
  return sequence
}


const shellSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
  console.log(`Initial sequence: ${seq}`)
  console.log(`Sorted sequence : ${shellSort(seq)}`)
}

shellSortTest()
