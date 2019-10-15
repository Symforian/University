fn string_to_number(s: &str) -> i32 {
    s.parse::<i32>().unwrap()
     
}
fn main()
{
    string_to_number("1");
}
#[cfg(test)]
mod tests {
    use super::string_to_number;
    
    #[test]
    fn test1() {
      assert_eq!(string_to_number("12345"), 12345);
    }
    #[test]
    fn test2() {
      assert_eq!(string_to_number("0"), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(string_to_number("-12345"), -12345);
    }
    #[test]
    fn test4() {
      assert_eq!(string_to_number("45"), 45);
    }
    #[test]
    fn test5() {
      assert_eq!(string_to_number("9"), 9);
    }
}
