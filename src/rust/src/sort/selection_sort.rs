pub fn selection_sort<T>(seq: &mut [T])
where
    T: PartialOrd
{
    for i in 0..seq.len() - 1 {
        let mut i_lo_val = i + 1;
        for j in 0..seq.len() - 1 - i {
            if seq[i_lo_val] > seq[j + i + 1] {
                i_lo_val = j + i + 1;
            }
        }
        if seq[i] > seq[i_lo_val] {
            seq.swap(i, i_lo_val);
        }
    }
}
