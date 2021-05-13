pub fn binary_search<T>(seq: &[T], query: T) -> Option<usize>
where
    T: PartialOrd + Sized
{
    if seq.is_empty() || query < seq[0] {
        return None;
    }

    let mut lo  = 0;
    let mut hi  = seq.len() - 1;

    while lo <= hi {
        let mid = (lo + hi) / 2;

        if seq[mid] == query {
            return Some(mid);
        } else if seq[mid] < query {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    // // Get closest idx
    // if query > seq[mid] {
    //     mid += 1;
    // }
    // Some(mid)

    None
}


pub fn linear_search<T>(seq: &[T], query: T) -> Option<usize>
where
    T: PartialEq + Sized
{
    for (i, val) in seq.iter().enumerate() {
        if val == &query {
            return Some(i);
        }
    }

    None
}
