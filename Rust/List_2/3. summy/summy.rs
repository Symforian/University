fn summy(strng: &str) -> i32 {
    strng.split(" ").into_iter().map(|x| x.parse::<i32>().unwrap()).fold(0i32, |a, b| a+b)
}
fn main()
{
    summy("1");
}

#[cfg(test)]
mod tests {
    use super::summy;
    
    #[test]
    fn test1() {
      assert_eq!(summy("1"), 1);
    }
    #[test]
    fn test2() {
      assert_eq!(summy("0 0 0"), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(summy("1 2"), 3);
    }
    #[test]
    fn test4() {
      assert_eq!(summy("3 2 1"), 6);
    }
    #[test]
    fn test5() {
      assert_eq!(summy("10 10 10 10 10 10 10"), 70);
    }
    #[test]
    fn test6() {
      assert_eq!(summy("11 11 11 11 11 11 11 11"), 88);
    }
    #[test]
    fn test7() {
      assert_eq!(summy("11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11"), 176);
    }
    #[test]
    fn test8() {
      assert_eq!(summy("0 0 0 0 0 0 0 0 0 0 0 0 0 0 4"), 4);
    }
    #[test]
    fn test9() {
      assert_eq!(summy("1 2 3 4 5 6 9"), 30);
    }
    #[test]
    fn test10() {
      assert_eq!(summy("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1"), 1);
    }

}
