use std::cmp::PartialOrd;


fn _partition<T: PartialOrd>(seq: &mut [T], lo: usize, hi: usize) -> usize {
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


fn _quick_sort<T: PartialOrd>(seq: &mut [T], lo: usize, hi: usize) {
    if lo < hi {
        let p = _partition(seq, lo, hi);
        if p > 0 {
            _quick_sort(seq, lo, p - 1);
        }
        _quick_sort(seq, p + 1, hi);
    }
}


pub fn quick_sort<T: PartialOrd>(seq: &mut [T]) {
    _quick_sort(seq, 0, seq.len() - 1);
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
        quick_sort(&mut v_i32);
        quick_sort(&mut v_str);
        assert!(is_sorted(&v_i32));
        assert!(is_sorted(&v_str));
    }
}
