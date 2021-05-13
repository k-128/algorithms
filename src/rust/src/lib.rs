pub mod search;
pub mod sort;


#[cfg(test)]
mod tests_search {
    use super::search::*;

    fn test_search_i32(f: fn(&[i32], i32) -> Option<usize>) {
        let v = vec![2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65];
        let r1 = f(&v, 7);
        let r2 = f(&v, 1);
        let r3 = f(&vec![], 1);
        assert_eq!(r1, Some(4));    // Sanity
        assert_eq!(r2, None);       // Missing & lower than 1 idx
        assert_eq!(r3, None);       // Empty
    }

    fn test_search_str<'a>(f: fn(&[&'a str], &'a str) -> Option<usize>) {
        let v = vec!["ab", "cd", "ef", "gh", "ij", "kl", "mn", "op"];
        let r1 = f(&v, &"op");
        let r2 = f(&v, &"_");
        let r3 = f(&vec![], &"a");
        assert_eq!(r1, Some(7));    // Sanity
        assert_eq!(r2, None);       // Missing & lower than 1 idx
        assert_eq!(r3, None);       // Empty
    }

    #[test]
    fn test_binary_search() {
        test_search_i32(binary_search);
        test_search_str(binary_search);
    }

    #[test]
    fn test_linear_search() {
        test_search_i32(linear_search);
        test_search_str(linear_search);
    }
}


#[cfg(test)]
mod tests_sort {
    use super::sort::*;

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

    fn test_sort_i32(f: fn(&mut [i32])) {
        let mut v = vec![16, 7, 9, 5, 65, 49, 37, 3, 28, 2, 21, 12, 4];
        f(&mut v);
        assert!(is_sorted(&v));    // Sanity
    }

    fn test_sort_str<'a>(f: fn(&mut [&'a str])) {
        let mut v = vec![
            "p", "g", "i", "j", "65", "W", "K", "c", "B", "b", "21", "l", "d"
        ];
        f(&mut v);
        assert!(is_sorted(&v));    // Sanity
    }

    #[test]
    fn test_bubble_sort() {
        test_sort_i32(bubble_sort);
        test_sort_str(bubble_sort);
    }

    #[test]
    fn test_counting_sort() {
        test_sort_i32(counting_sort);
    }

    #[test]
    fn test_heap_sort() {
        test_sort_i32(heap_sort);
        test_sort_str(heap_sort);
    }

    #[test]
    fn test_insertion_sort() {
        test_sort_i32(insertion_sort);
        test_sort_str(insertion_sort);
    }

    #[test]
    fn test_merge_sort() {
        test_sort_i32(merge_sort);
        test_sort_str(merge_sort);
    }

    #[test]
    fn test_quick_sort() {
        test_sort_i32(quick_sort);
        test_sort_str(quick_sort);
    }
    
    #[test]
    fn test_selection_sort() {
        test_sort_i32(selection_sort);
        test_sort_str(selection_sort);
    }

    #[test]
    fn test_shell_sort() {
        test_sort_i32(shell_sort);
        test_sort_str(shell_sort);
    }
}
