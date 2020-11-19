const _merge = (seq: any[], lo: number, mid: number, hi: number): void => {
  let temp = [];
  let iLSeq = lo;
  let iRSeq = mid + 1;

  while ((iLSeq <= mid) && (iRSeq <= hi)) {
    if (seq[iLSeq] <= seq[iRSeq]) {
      temp.push(seq[iLSeq]);
      iLSeq++;
    } else {
      temp.push(seq[iRSeq]);
      iRSeq++;
    }
  }

  while (iLSeq <= mid) {
    temp.push(seq[iLSeq]);
    iLSeq++;
  }

  while (iRSeq <= hi) {
    temp.push(seq[iRSeq]);
    iRSeq++;
  }

  for (let i = lo; i <= hi; i++) {
    seq[i] = temp[i - lo];
  }
}


const _mergeSort = (seq: any[], lo: number, hi: number): void => {
  if (lo < hi) {
    let mid = Math.floor((lo + hi) / 2);
    _mergeSort(seq, lo, mid);
    _mergeSort(seq, mid + 1, hi);
    _merge(seq, lo, mid, hi);
  }
}


const mergeSort = (seq: any[]): void => {
  _mergeSort(seq, 0, seq.length - 1);
}


const mergeSortTest = () => {
  let seq1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq1Sorted = Object.assign([], seq1);
  let seq2 = [
    "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
  ];
  let seq2Sorted = Object.assign([], seq2);
  mergeSort(seq1Sorted);
  mergeSort(seq2Sorted);

  console.log(`seq1: ${seq1}\nseq1Sorted: ${seq1Sorted}`);
  console.log(`seq2: ${seq2}\nseq2Sorted: ${seq2Sorted}`);
}

mergeSortTest();
