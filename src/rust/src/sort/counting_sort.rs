pub fn counting_sort(seq: &mut [i32]) {
    let mut max_value = seq[0];
    let mut min_value = seq[0];
    for i in 1..seq.len() {
        if max_value < seq[i] {
            max_value = seq[i];
        }
        if min_value > seq[i] {
            min_value = seq[i];
        }
    }

    let mut counts = vec![0; ((max_value - min_value) as usize + 1) as usize];
    for i in 0..seq.len() {
        counts[(seq[i] - min_value) as usize] += 1;
    }

    let mut temp = 0;
    for i in 0..counts.len() {
        for _ in 0..counts[i] {
            seq[temp] = (i + min_value as usize) as i32;
            temp += 1;
        }
    }
}
