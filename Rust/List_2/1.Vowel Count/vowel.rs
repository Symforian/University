fn get_count(string: &str) -> usize {
  
  let mut z: String = string.to_string();
  z.retain(|x| x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
  z.len()
}
fn main()
{
    get_count("1");
}
#[cfg(test)]
mod tests {
    use super::get_count;
    
    #[test]
    fn test1() {
      assert_eq!(get_count("a"), 1);
    }
    #[test]
    fn test2() {
      assert_eq!(get_count("b"), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(get_count("ababab"), 3);
    }
    #[test]
    fn test4() {
      assert_eq!(get_count("aeiou"), 5);
    }
    #[test]
    fn test5() {
      assert_eq!(get_count("abcdefghijklmnoprstuwxyz"), 5);
    }
    #[test]
    fn test6() {
      assert_eq!(get_count("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba"), 1);
    }
    #[test]
    fn test7() {
      assert_eq!(get_count("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"), 0);
    }
    #[test]
    fn test8() {
      assert_eq!(get_count("aebbbbbbae"), 4);
    }
    #[test]
    fn test9() {
      assert_eq!(get_count("aeiouaeiouaeiouaeiou"), 20);
    }
    #[test]
    fn test10() {
      assert_eq!(get_count("bbbbbbbbbbbbbbbabbbbbbbbbbbbbb"), 1);
    }
}
