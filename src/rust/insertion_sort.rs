use std::cmp::PartialOrd;
use std::marker::Copy;


pub fn insertion_sort<T: PartialOrd + Copy>(seq: &mut [T]) {
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
        insertion_sort(&mut v_i32);
        insertion_sort(&mut v_str);
        assert!(is_sorted(&v_i32));
        assert!(is_sorted(&v_str));
    }
}
