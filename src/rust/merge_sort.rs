use std::cmp::PartialOrd;
use std::marker::Copy;


fn _merge<T: PartialOrd + Copy>(seq: &mut [T], lo: usize, mid: usize, hi: usize) {
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


fn _merge_sort<T: PartialOrd + Copy>(seq: &mut [T], lo: usize, hi: usize) {
    if lo < hi {
        let mid = (lo + hi) / 2;
        _merge_sort(seq, lo, mid);
        _merge_sort(seq, mid + 1, hi);
        _merge(seq, lo, mid, hi);
    }
}


pub fn merge_sort<T: PartialOrd + Copy>(seq: &mut [T]) {
    _merge_sort(seq, 0, seq.len() - 1);
}


#[cfg(test)]
mod tests {
    use super::*;

    fn get_vector_i32() -> Vec<i32> {
        vec![16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
    }

    fn get_vector_str() -> Vec<&'static str> {
        vec!["p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"]
    }

    fn is_sorted<T: PartialOrd>(seq: &[T]) -> bool {
        let mut prev = &seq[0];
        for elem in seq.iter().skip(1) {
            if prev > elem {
                return false;
            }
            prev = elem;
        }
        true
    }

    #[test]
    fn test_sanity() {
        let mut v_i32 = get_vector_i32();
        let mut v_str = get_vector_str();
        merge_sort(&mut v_i32);
        merge_sort(&mut v_str);
        assert!(is_sorted(&v_i32));
        assert!(is_sorted(&v_str));
    }
}
