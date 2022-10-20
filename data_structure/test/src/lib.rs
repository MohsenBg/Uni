mod ffi {
    include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
}

pub use ffi::iteration_fac;
pub use ffi::recursive_fac;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn iteration_factorial() {
        assert_eq!(unsafe { iteration_fac(0) }, 1);
        assert_eq!(unsafe { iteration_fac(1) }, 1);
        assert_eq!(unsafe { iteration_fac(2) }, 2);
        assert_eq!(unsafe { iteration_fac(3) }, 6);
        assert_eq!(unsafe { iteration_fac(4) }, 24);
        assert_eq!(unsafe { iteration_fac(5) }, 120);
        assert_eq!(unsafe { iteration_fac(6) }, 720);
        assert_eq!(unsafe { iteration_fac(7) }, 5040);
        assert_eq!(unsafe { iteration_fac(8) }, 40320);
        assert_eq!(unsafe { iteration_fac(9) }, 362880);
        assert_eq!(unsafe { iteration_fac(10) }, 3628800);
        assert_eq!(unsafe { iteration_fac(11) }, 39916800);
        assert_eq!(unsafe { iteration_fac(12) }, 479001600);
        assert_eq!(unsafe { iteration_fac(13) }, 6227020800);
        assert_eq!(unsafe { iteration_fac(14) }, 87178291200);
        assert_eq!(unsafe { iteration_fac(15) }, 1307674368000);
        assert_eq!(unsafe { iteration_fac(16) }, 20922789888000);
        assert_eq!(unsafe { iteration_fac(17) }, 355687428096000);
        assert_eq!(unsafe { iteration_fac(18) }, 6402373705728000);
        assert_eq!(unsafe { iteration_fac(19) }, 121645100408832000);
        assert_eq!(unsafe { iteration_fac(20) }, 2432902008176640000);
    }

    #[test]
    fn recursive_factorial() {
        assert_eq!(unsafe { recursive_fac(0) }, 1);
        assert_eq!(unsafe { recursive_fac(1) }, 1);
        assert_eq!(unsafe { recursive_fac(2) }, 2);
        assert_eq!(unsafe { recursive_fac(3) }, 6);
        assert_eq!(unsafe { recursive_fac(4) }, 24);
        assert_eq!(unsafe { recursive_fac(5) }, 120);
        assert_eq!(unsafe { recursive_fac(6) }, 720);
        assert_eq!(unsafe { recursive_fac(7) }, 5040);
        assert_eq!(unsafe { recursive_fac(8) }, 40320);
        assert_eq!(unsafe { recursive_fac(9) }, 362880);
        assert_eq!(unsafe { recursive_fac(10) }, 3628800);
        assert_eq!(unsafe { recursive_fac(11) }, 39916800);
        assert_eq!(unsafe { recursive_fac(12) }, 479001600);
        assert_eq!(unsafe { recursive_fac(13) }, 6227020800);
        assert_eq!(unsafe { recursive_fac(14) }, 87178291200);
        assert_eq!(unsafe { recursive_fac(15) }, 1307674368000);
        assert_eq!(unsafe { recursive_fac(16) }, 20922789888000);
        assert_eq!(unsafe { recursive_fac(17) }, 355687428096000);
        assert_eq!(unsafe { recursive_fac(18) }, 6402373705728000);
        assert_eq!(unsafe { recursive_fac(19) }, 121645100408832000);
        assert_eq!(unsafe { recursive_fac(20) }, 2432902008176640000);
    }
}
