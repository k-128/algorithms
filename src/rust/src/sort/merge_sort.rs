fn merge<T>(seq: &mut [T], lo: usize, mid: usize, hi: usize)
where
    T: PartialOrd + Copy
{
    let mut temp = Vec::new();
    let mut i_lseq = lo;
    let mut i_rseq = mid + 1;

    while (i_lseq <= mid) && (i_rseq <= hi) {
        if seq[i_lseq] <= seq[i_rseq] {
            temp.push(seq[i_lseq]);
            i_lseq += 1;
        } else {
            temp.push(seq[i_rseq]);
            i_rseq += 1;
        }
    }

    while i_lseq <= mid {
        temp.push(seq[i_lseq]);
        i_lseq += 1;
    }

    while i_rseq <= hi {
        temp.push(seq[i_rseq]);
        i_rseq += 1;
    }

    for i in lo..hi + 1 {
        seq[i] = temp[i - lo];
    }
}


fn merge_sort_f<T>(seq: &mut [T], lo: usize, hi: usize)
where
    T: PartialOrd + Copy
{
    if lo < hi {
        let mid = (lo + hi) / 2;
        merge_sort_f(seq, lo, mid);
        merge_sort_f(seq, mid + 1, hi);
        merge(seq, lo, mid, hi);
    }
}


pub fn merge_sort<T>(seq: &mut [T])
where
    T: PartialOrd + Copy
{
    merge_sort_f(seq, 0, seq.len() - 1);
}
