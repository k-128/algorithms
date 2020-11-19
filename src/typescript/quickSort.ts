const partition = (seq: any[], lo: number, hi: number): number => {
  let i = lo;

  for (let j = lo; j < hi; j++) {
    if (seq[j] < seq[hi]) {
      [seq[i], seq[j]] = [seq[j], seq[i]];
      i++;
    }
  }

  [seq[i], seq[hi]] = [seq[hi], seq[i]];
  return i;
}


const _quickSort = (seq: any[], lo: number, hi: number): void => {
  if (lo < hi) {
    let p = partition(seq, lo, hi);
    _quickSort(seq, lo, p-1);
    _quickSort(seq, p+1, hi);
  }
}


const quickSort = (seq: any[]): void => {
  _quickSort(seq, 0, seq.length - 1);
}


const quickSortTest = () => {
  let seq1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq1Sorted = Object.assign([], seq1);
  let seq2 = [
    "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
  ];
  let seq2Sorted = Object.assign([], seq2);
  quickSort(seq1Sorted);
  quickSort(seq2Sorted);

  console.log(`seq1: ${seq1}\nseq1Sorted: ${seq1Sorted}`);
  console.log(`seq2: ${seq2}\nseq2Sorted: ${seq2Sorted}`);
}

quickSortTest();
