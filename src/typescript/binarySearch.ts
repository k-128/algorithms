const binarySearch = (seq: number[], query: number): number => {
  let lo = 0;
  let hi = seq.length - 1;
  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2);
    if (seq[mid] == query) {
      return mid;
    } else if (seq[mid] < query) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}


const binarySearchTest = () => {
  const seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65];

  console.log(`Search result : ${binarySearch(seq, 7)}`);
  console.log(`Missing query : ${binarySearch(seq, 6)}`);
  console.log(`Empty sequence: ${binarySearch([], 7)}`);
}

binarySearchTest();
