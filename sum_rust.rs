/*
 * sum_rust.rs
 * Copyright (C) k!M/pizslacker 2026
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
