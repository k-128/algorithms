pub fn counting_sort(seq: &mut Vec<i32>) {
    let mut max_value = seq[0];
    let mut min_value = seq[0];
    for i in 1..seq.len() {
        if max_value < seq[i] {
            max_value = seq[i];
        }
        if min_value > seq[i] {
            min_value = seq[i];
        }
    }

    let mut counts = vec![0; ((max_value - min_value) as usize + 1) as usize];
    for i in 0..seq.len() {
        counts[(seq[i] - min_value) as usize] += 1;
    }

    let mut temp = 0;
    for i in 0..counts.len() {
        for _ in 0..counts[i] {
            seq[temp] = (i + min_value as usize) as i32;
            temp += 1;
        }
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    fn get_vector_i32() -> Vec<i32> {
        vec![16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4]
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
        counting_sort(&mut v_i32);
        assert!(is_sorted(&v_i32));
    }
}
