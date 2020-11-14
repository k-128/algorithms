use std::cmp::PartialEq;


pub fn linear_search<T: PartialEq>(seq: &[T], query: &T) -> Option<usize> {
    for (i, val) in seq.iter().enumerate() {
        if val == query {
            return Some(i)
        }
    }

    None
}


#[cfg(test)]
mod tests {
    use super::*;

    fn get_vector_i32() -> Vec<i32> {
        vec![2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65]
    }

    fn get_vector_str() -> Vec<&'static str> {
        vec!["ab", "cd", "ef", "gh", "ij", "kl", "mn", "op"]
    }

    #[test]
    fn test_exists() {
        let i1 = linear_search(&get_vector_i32(), &7);
        let i2 = linear_search(&get_vector_str(), &"op");
        assert_eq!(i1, Some(4));
        assert_eq!(i2, Some(7));
    }

    #[test]
    fn test_missing() {
        let i1 = linear_search(&get_vector_i32(), &6);
        let i2 = linear_search(&get_vector_str(), &"e");
        assert_eq!(i1, None);
        assert_eq!(i2, None);
    }

    #[test]
    fn test_empty() {
        assert_eq!(linear_search(&vec![], &6), None);
    }
}
