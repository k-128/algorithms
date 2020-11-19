const bubbleSort = (seq: any[]): void => {
  for (let i = 0; i < seq.length - 1; i++) {
    let isSorted = true;
    for (let j = 0; j < seq.length - 1 - i; j++) {
      if (seq[j] > seq[j+1]) {
        isSorted = false;
        [seq[j], seq[j + 1]] = [seq[j + 1], seq[j]];
      }
    }
    if (isSorted) {
      break;
    }
  }
}


const bubbleSortTest = () => {
  let seq1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq1Sorted = Object.assign([], seq1);
  let seq2 = [
    "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
  ];
  let seq2Sorted = Object.assign([], seq2);
  bubbleSort(seq1Sorted);
  bubbleSort(seq2Sorted);

  console.log(`seq1: ${seq1}\nseq1Sorted: ${seq1Sorted}`);
  console.log(`seq2: ${seq2}\nseq2Sorted: ${seq2Sorted}`);
}

bubbleSortTest();
