fn count_bits(n: i64) -> u32 {
  n.count_ones()
}
fn main()
{
    count_bits(1);
}

#[cfg(test)]
mod tests {
    use super::count_bits;
    
    #[test]
    fn test1() {
      assert_eq!(count_bits(1), 1);
    }
    #[test]
    fn test2() {
      assert_eq!(count_bits(0), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(count_bits(3), 2);
    }
    #[test]
    fn test4() {
      assert_eq!(count_bits(63), 6);
    }
    #[test]
    fn test5() {
      assert_eq!(count_bits(8), 1);
    }
    #[test]
    fn test6() {
      assert_eq!(count_bits(11), 3);
    }
    #[test]
    fn test7() {
      assert_eq!(count_bits(2047), 11);
    }
    #[test]
    fn test8() {
      assert_eq!(count_bits(15), 4);
    }
    #[test]
    fn test9() {
      assert_eq!(count_bits(1073741823), 30);
    }
    #[test]
    fn test10() {
      assert_eq!(count_bits(4096), 1);
    }

}
