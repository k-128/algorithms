fn partition<T>(seq: &mut [T], lo: usize, hi: usize) -> usize
where
    T: PartialOrd
{
    let mut i = lo;

    for j in lo..hi + 1 {
        if seq[j] < seq[hi] {
            seq.swap(i, j);
            i += 1;
        }
    }

    seq.swap(i, hi);
    i
}


fn quick_sort_f<T>(seq: &mut [T], lo: usize, hi: usize)
where
    T: PartialOrd
{
    if lo < hi {
        let p = partition(seq, lo, hi);
        if p > 0 {
            quick_sort_f(seq, lo, p - 1);
        }
        quick_sort_f(seq, p + 1, hi);
    }
}


pub fn quick_sort<T>(seq: &mut [T])
where
    T: PartialOrd
{
    quick_sort_f(seq, 0, seq.len() - 1);
}
