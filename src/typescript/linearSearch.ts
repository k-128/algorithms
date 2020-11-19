const linearSearch = (seq: number[], query: number): number => {
  for (let i = 0; i < seq.length; i++) {
    if (seq[i] == query) {
      return i;
    }
  }
  return -1;
}


const linearSearchTest = () => {
  const seq = [2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65];

  console.log(`Search result : ${linearSearch(seq, 7)}`);
  console.log(`Missing query : ${linearSearch(seq, 6)}`);
  console.log(`Empty sequence: ${linearSearch([], 7)}`);
}

linearSearchTest();
