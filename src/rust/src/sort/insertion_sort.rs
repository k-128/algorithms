pub fn insertion_sort<T>(seq: &mut [T])
where
    T: PartialOrd + Copy
{
    for i in 0..seq.len() - 1 {
        let mut i_temp = i + 1;
        let key = seq[i + 1];
        while (i_temp >= 1) && (key < seq[i_temp - 1]) {
            seq[i_temp] = seq[i_temp - 1];
            i_temp -= 1;
        }
        seq[i_temp] = key;
    }
}
