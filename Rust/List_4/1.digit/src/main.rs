fn find_digit(num: i32, nth: i32) -> i32 {
    let mut num = num;
    if nth<=0 {return -1;}
    if num == 0 { return 0;}
    if num < 0 {num = -num;}
    for _i in 0..nth-1{
        num /= 10;
    }
    num%10
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::find_digit;
    
    #[test]
    fn test1() {
      assert_eq!(find_digit(1,0), -1);
    }
    #[test]
    fn test2() {
      assert_eq!(find_digit(2,2), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(find_digit(50,1), 0);
    }
    #[test]
    fn test4() {
      assert_eq!(find_digit(445234523,2), 2);
    }
    #[test]
    fn test5() {
      assert_eq!(find_digit(51111111,6), 1);
    }
    #[test]
    fn test6() {
      assert_eq!(find_digit(3123126,100), 0);
    }
    #[test]
    fn test7() {
      assert_eq!(find_digit(7,-1), -1);
    }
    #[test]
    fn test8() {
      assert_eq!(find_digit(-12341238,7), 2);
    }
    #[test]
    fn test9() {
      assert_eq!(find_digit(771345,3), 3);
    }
    #[test]
    fn test10() {
      assert_eq!(find_digit(1200231,3), 2);
    }


}
