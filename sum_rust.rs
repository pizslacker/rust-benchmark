use std::slice;

#[no_mangle]
pub extern "C" fn sum_rust(arr: *const i64, size: usize) -> i64 {
    // Safety check for null pointers
    if arr.is_null() || size == 0 {
        return 0;
    }

    // Unsafe block is required to turn a raw C pointer into a safe Rust slice
    let slice = unsafe { slice::from_raw_parts(arr, size) };
    
    // Idiomatic Rust: using an iterator to sum the slice
    slice.iter().sum()
}