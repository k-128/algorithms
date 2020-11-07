const binarySearch = (sequence: number[], query: number): number => {
  let low = 0
  let high = sequence.length - 1
  while (low <= high) {
    let mid = Math.floor((low + high) / 2)
    if (sequence[mid] == query) {
      return mid
    } else if (sequence[mid] < query) {
      low = mid + 1
    } else {
      high = mid - 1
    }
  }
  return -1
}


const binarySearchTest = () => {
  const seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65]
  console.log(`Search result : ${binarySearch(seq, 7)}`)
  console.log(`Missing query : ${binarySearch(seq, 6)}`)
  console.log(`Empty sequence: ${binarySearch([], 7)}`)
}

binarySearchTest()
