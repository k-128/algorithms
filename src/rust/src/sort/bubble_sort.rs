pub fn bubble_sort<T>(seq: &mut [T])
where
    T: PartialOrd
{
    for i in 0..seq.len() {
        let mut is_sorted = true;
        for j in 0..seq.len() - 1 - i {
            if seq[j] > seq[j + 1] {
                is_sorted = false;
                seq.swap(j, j + 1);
            }
        }
        if is_sorted {
            break;
        }
    }
}
