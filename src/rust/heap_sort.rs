use std::cmp::PartialOrd;


fn heapify<T: PartialOrd>(seq: &mut [T], i_root: usize, heap_size: usize) {
    let mut i_max = i_root;
    let i_left  = i_root * 2 + 1;
    let i_right = i_root * 2 + 2;

    if (i_left < heap_size) && (seq[i_left] > seq[i_max]) {
        i_max = i_left;
    }

    if (i_right < heap_size) && (seq[i_right] > seq[i_max]) {
        i_max = i_right;
    }

    if i_max != i_root {
        seq.swap(i_max, i_root);
        heapify(seq, i_max, heap_size);
    }
}


fn build_max_heap<T: PartialOrd>(seq: &mut [T], heap_size: usize) {
    for i in (0..heap_size / 2).rev() {
        heapify(seq, i, heap_size);
    }
}   


pub fn heap_sort<T: PartialOrd>(seq: &mut [T]) {
    let n = seq.len();
    build_max_heap(seq, n);

    for i in (1..n).rev() {
        seq.swap(0, i);
        heapify(seq, 0, i);
    }
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
        heap_sort(&mut v_i32);
        heap_sort(&mut v_str);
        assert!(is_sorted(&v_i32));
        assert!(is_sorted(&v_str));
    }
}
