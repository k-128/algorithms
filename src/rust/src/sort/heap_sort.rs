fn heapify<T>(seq: &mut [T], i_root: usize, heap_size: usize)
where
    T: PartialOrd
{
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


fn build_max_heap<T>(seq: &mut [T], heap_size: usize)
where
    T: PartialOrd
{
    for i in (0..heap_size / 2).rev() {
        heapify(seq, i, heap_size);
    }
}   


pub fn heap_sort<T>(seq: &mut [T])
where
    T: PartialOrd
{
    let n = seq.len();
    build_max_heap(seq, n);

    for i in (1..n).rev() {
        seq.swap(0, i);
        heapify(seq, 0, i);
    }
}
