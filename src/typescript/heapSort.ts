const heapify = (seq: number[], iRoot: number, heapSize: number): void => {
  let iMax   = iRoot;
  let iLeft  = iRoot * 2 + 1;
  let iRight = iRoot * 2 + 2;

  if ((iLeft < heapSize) && (seq[iLeft] > seq[iMax])) {
    iMax = iLeft;
  }

  if ((iRight < heapSize) && (seq[iRight] > seq[iMax])) {
    iMax = iRight;
  }

  if (iMax !== iRoot) {
    [seq[iRoot], seq[iMax]] = [seq[iMax], seq[iRoot]];
    heapify(seq, iMax, heapSize);
  }
}


const buildMaxHeap = (seq: number[], heapSize: number): void => {
  for (let i = Math.floor(heapSize / 2); i > 0; i--) {
    heapify(seq, i - 1, heapSize);
  }
}


const heapSort = (seq: any[]): void => {
  let n = seq.length;
  buildMaxHeap(seq, n);

  for (let i = n - 1; i > 0; i--) {
    [seq[0], seq[i]] = [seq[i], seq[0]];
    heapify(seq, 0, i);
  }
}


const heapSortTest = () => {
  let seq = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq_sorted = Object.assign([], seq);
  heapSort(seq_sorted);

  console.log(`Initial sequence: ${seq}`);
  console.log(`Sorted sequence : ${seq_sorted}`);
}

heapSortTest();
