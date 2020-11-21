const countingSort = (seq: number[]): void => {
  let maxValue = seq[0];
  let minValue = seq[0];
  for (let i = 1; i < seq.length; i++) {
    if (maxValue < seq[i]) {
      maxValue = seq[i];
    }
    if (minValue > seq[i]) {
      minValue = seq[i];
    }
  }

  let counts = new Array(maxValue - minValue + 1).fill(0);
  for (let i = 0; i < seq.length; i++) {
    counts[i + minValue] += 1;
  }

  let temp = 0
  for (let i = 0; i < counts.length; i++) {
    for (let j = 0; j < counts[i]; j++) {
      seq[temp] = i + minValue;
      temp += 1;
    }
  }
}


const countingSortTest = () => {
  let seq1 = [16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
  let seq1Sorted = Object.assign([], seq1);
  countingSort(seq1Sorted);

  console.log(`seq1: ${seq1}\nseq1Sorted: ${seq1Sorted}`);
}

countingSortTest();
