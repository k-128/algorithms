const insertionSort = (seq: any[]): void => {
  for (let i = 0; i < seq.length - 1; i++) {
    let iInsert = i;
    let key = seq[i + 1];
    while ((iInsert >= 0) && (key < seq[iInsert])) {
      seq[iInsert + 1] = seq[iInsert];
      iInsert--;
    }
    seq[iInsert + 1] = key;
  }
}


const insertionSortTest = () => {
  let seq1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq1Sorted = Object.assign([], seq1);
  let seq2 = [
    "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
  ];
  let seq2Sorted = Object.assign([], seq2);
  insertionSort(seq1Sorted);
  insertionSort(seq2Sorted);

  console.log(`seq1: ${seq1}\nseq1Sorted: ${seq1Sorted}`);
  console.log(`seq2: ${seq2}\nseq2Sorted: ${seq2Sorted}`);
}

insertionSortTest();
