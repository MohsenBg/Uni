mod ffi {
    include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
}

pub use ffi::bubble_sort_f32;
pub use ffi::bubble_sort_f64;
pub use ffi::bubble_sort_i16;
pub use ffi::bubble_sort_i32;
pub use ffi::bubble_sort_i64;
pub use ffi::bubble_sort_u16;
pub use ffi::bubble_sort_u32;
pub use ffi::bubble_sort_u64;
pub use ffi::insertion_sort_f32;
pub use ffi::insertion_sort_f64;
pub use ffi::insertion_sort_i16;
pub use ffi::insertion_sort_i32;
pub use ffi::insertion_sort_i64;
pub use ffi::insertion_sort_u16;
pub use ffi::insertion_sort_u32;
pub use ffi::insertion_sort_u64;
pub use ffi::merge_sort_f32;
pub use ffi::merge_sort_f64;
pub use ffi::merge_sort_i16;
pub use ffi::merge_sort_i32;
pub use ffi::merge_sort_i64;
pub use ffi::merge_sort_u16;
pub use ffi::merge_sort_u32;
pub use ffi::merge_sort_u64;
pub use ffi::quick_sort_f32;
pub use ffi::quick_sort_f64;
pub use ffi::quick_sort_i16;
pub use ffi::quick_sort_i32;
pub use ffi::quick_sort_i64;
pub use ffi::quick_sort_u16;
pub use ffi::quick_sort_u32;
pub use ffi::quick_sort_u64;
pub use ffi::selection_sort_f32;
pub use ffi::selection_sort_f64;
pub use ffi::selection_sort_i16;
pub use ffi::selection_sort_i32;
pub use ffi::selection_sort_i64;
pub use ffi::selection_sort_u16;
pub use ffi::selection_sort_u32;
pub use ffi::selection_sort_u64;

#[cfg(test)]
mod tests {
    use super::*;
    use rand::distributions::Standard;
    use rand::prelude::Distribution;
    use rand::{self, Rng};

    fn get_random_number<T>(count: usize) -> Vec<T>
    where
        Standard: Distribution<T>,
    {
        let mut result: Vec<T> = Vec::new();
        let mut rng = rand::thread_rng();
        for _ in 0..count {
            result.push(rng.gen::<T>());
        }
        result
    }

    #[test]
    fn test_bubble_sort_i16() {
        for i in 0..10 {
            let mut input: Vec<i16> = get_random_number(i);
            let res = unsafe { bubble_sort_i16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_i32() {
        for i in 0..10 {
            let mut input: Vec<i32> = get_random_number(i);
            let res = unsafe { bubble_sort_i32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_i64() {
        for i in 0..10 {
            let mut input: Vec<i64> = get_random_number(i);
            let res = unsafe { bubble_sort_i64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_u16() {
        for i in 0..10 {
            let mut input: Vec<u16> = get_random_number(i);
            let res = unsafe { bubble_sort_u16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_u32() {
        for i in 0..10 {
            let mut input: Vec<u32> = get_random_number(i);
            let res = unsafe { bubble_sort_u32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_u64() {
        for i in 0..10 {
            let mut input: Vec<u64> = get_random_number(i);
            let res = unsafe { bubble_sort_u64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_f32() {
        for i in 0..10 {
            let mut input: Vec<f32> = get_random_number(i);
            let res = unsafe { bubble_sort_f32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_bubble_sort_f64() {
        for i in 0..10 {
            let mut input: Vec<f64> = get_random_number(i);
            let res = unsafe { bubble_sort_f64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_i16() {
        for i in 0..10 {
            let mut input: Vec<i16> = get_random_number(i);
            let res = unsafe { insertion_sort_i16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_i32() {
        for i in 0..10 {
            let mut input: Vec<i32> = get_random_number(i);
            let res = unsafe { insertion_sort_i32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_i64() {
        for i in 0..10 {
            let mut input: Vec<i64> = get_random_number(i);
            let res = unsafe { insertion_sort_i64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_u16() {
        for i in 0..10 {
            let mut input: Vec<u16> = get_random_number(i);
            let res = unsafe { insertion_sort_u16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_u32() {
        for i in 0..10 {
            let mut input: Vec<u32> = get_random_number(i);
            let res = unsafe { insertion_sort_u32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_u64() {
        for i in 0..10 {
            let mut input: Vec<u64> = get_random_number(i);
            let res = unsafe { insertion_sort_u64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_f32() {
        for i in 0..10 {
            let mut input: Vec<f32> = get_random_number(i);
            let res = unsafe { insertion_sort_f32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_insertion_sort_f64() {
        for i in 0..10 {
            let mut input: Vec<f64> = get_random_number(i);
            let res = unsafe { insertion_sort_f64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_i16() {
        for i in 0..10 {
            let mut input: Vec<i16> = get_random_number(i);
            let res = unsafe { selection_sort_i16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_i32() {
        for i in 0..10 {
            let mut input: Vec<i32> = get_random_number(i);
            let res = unsafe { selection_sort_i32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_i64() {
        for i in 0..10 {
            let mut input: Vec<i64> = get_random_number(i);
            let res = unsafe { selection_sort_i64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_u16() {
        for i in 0..10 {
            let mut input: Vec<u16> = get_random_number(i);
            let res = unsafe { selection_sort_u16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_u32() {
        for i in 0..10 {
            let mut input: Vec<u32> = get_random_number(i);
            let res = unsafe { selection_sort_u32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_u64() {
        for i in 0..10 {
            let mut input: Vec<u64> = get_random_number(i);
            let res = unsafe { selection_sort_u64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_f32() {
        for i in 0..10 {
            let mut input: Vec<f32> = get_random_number(i);
            let res = unsafe { selection_sort_f32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_selection_sort_f64() {
        for i in 0..10 {
            let mut input: Vec<f64> = get_random_number(i);
            let res = unsafe { selection_sort_f64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_i16() {
        for i in 0..10 {
            let mut input: Vec<i16> = get_random_number(i);
            let res = unsafe { quick_sort_i16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_i32() {
        for i in 0..10 {
            let mut input: Vec<i32> = get_random_number(i);
            let res = unsafe { quick_sort_i32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_i64() {
        for i in 0..10 {
            let mut input: Vec<i64> = get_random_number(i);
            let res = unsafe { quick_sort_i64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_u16() {
        for i in 0..10 {
            let mut input: Vec<u16> = get_random_number(i);
            let res = unsafe { quick_sort_u16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_u32() {
        for i in 0..10 {
            let mut input: Vec<u32> = get_random_number(i);
            let res = unsafe { quick_sort_u32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_u64() {
        for i in 0..10 {
            let mut input: Vec<u64> = get_random_number(i);
            let res = unsafe { quick_sort_u64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_f32() {
        for i in 0..10 {
            let mut input: Vec<f32> = get_random_number(i);
            let res = unsafe { quick_sort_f32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_quick_sort_f64() {
        for i in 0..10 {
            let mut input: Vec<f64> = get_random_number(i);
            let res = unsafe { quick_sort_f64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_i16() {
        for i in 0..10 {
            let mut input: Vec<i16> = get_random_number(i);
            let res = unsafe { merge_sort_i16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_i32() {
        for i in 0..10 {
            let mut input: Vec<i32> = get_random_number(i);
            let res = unsafe { merge_sort_i32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_i64() {
        for i in 0..10 {
            let mut input: Vec<i64> = get_random_number(i);
            let res = unsafe { merge_sort_i64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_u16() {
        for i in 0..10 {
            let mut input: Vec<u16> = get_random_number(i);
            let res = unsafe { merge_sort_u16(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_u32() {
        for i in 0..10 {
            let mut input: Vec<u32> = get_random_number(i);
            let res = unsafe { merge_sort_u32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_u64() {
        for i in 0..10 {
            let mut input: Vec<u64> = get_random_number(i);
            let res = unsafe { merge_sort_u64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort();
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_f32() {
        for i in 0..10 {
            let mut input: Vec<f32> = get_random_number(i);
            let res = unsafe { merge_sort_f32(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
    #[test]
    fn test_merge_sort_f64() {
        for i in 0..10 {
            let mut input: Vec<f64> = get_random_number(i);
            let res = unsafe { merge_sort_f64(input.as_mut_ptr(), input.len() as u32) };
            let res = unsafe { std::slice::from_raw_parts_mut(res, input.len()) };
            input.sort_by(|a, b| a.partial_cmp(b).unwrap());
            assert_eq!(res.to_vec(), input.to_vec());
        }
    }
}
