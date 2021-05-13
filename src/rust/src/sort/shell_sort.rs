fn _get_gaps(size: usize) -> Vec<usize> {
    let mut temp = size / 2;
    let mut gaps = vec![temp];
    while temp > 1 {
        temp = temp / 2;
        gaps.push(temp);
    }
    gaps
}


fn _get_gaps_knuth(size: usize) -> Vec<usize> {
    let mut temp = 1;
    let mut gaps = vec![temp];
    while temp < size {
        temp = temp * 3 + 1;
        gaps.push(temp);
    }
    gaps.reverse();
    gaps
}


fn _get_gaps_ciura(size: usize) -> Vec<usize> {
    let gaps_init = vec![1, 4, 10, 23, 57, 132, 301, 701, 1750];
    let mut temp = 1;
    let mut gaps = Vec::new();
    let mut i = 0;
    while temp < size {
        if temp >= 1750 {
            temp = ((temp as f64 * 2.22).floor()) as usize;
        } else {
            temp = gaps_init[i];
        }
        gaps.push(temp);
        i += 1;
    }
    gaps.reverse();
    gaps
}


pub fn shell_sort<T>(seq: &mut [T])
where
    T: PartialOrd + Copy
{
    let gaps = _get_gaps_ciura(seq.len());

    for i in 0..gaps.len() {
        let gap = gaps[i];
        for j in gap..seq.len() {
            let mut i_insert = j;
            let key = seq[j];
            while (i_insert >= gap) && (key < seq[i_insert - gap]) {
                seq[i_insert] = seq[i_insert - gap];
                i_insert = i_insert - gap;
            }
            seq[i_insert] = key;
        }
    }
}
