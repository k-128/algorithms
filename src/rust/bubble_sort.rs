use std::cmp::PartialOrd;


pub fn bubble_sort<T: PartialOrd>(seq: &mut [T]) {
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
        bubble_sort(&mut v_i32);
        bubble_sort(&mut v_str);
        assert!(is_sorted(&v_i32));
        assert!(is_sorted(&v_str));
    }
}
