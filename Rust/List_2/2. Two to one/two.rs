fn longest(a1: &str, a2: &str) -> String {
    let mut charsa1: Vec<char> = a1.chars().collect();
    let charsa2: Vec<char> = a2.chars().collect();
    charsa1.extend(charsa2);
    charsa1.sort();
    charsa1.dedup();
    charsa1.into_iter().collect()
}
fn main()
{
    longest("1","2");
}
#[cfg(test)]
mod tests {
    use super::longest;
    
    #[test]
    fn test1() {
      assert_eq!(longest("a","a"), "a");
    }
    #[test]
    fn test2() {
      assert_eq!(longest("b","a"), "ab");
    }
    #[test]
    fn test3() {
      assert_eq!(longest("aaaabbb","ccccdddd"), "abcd");
    }
    #[test]
    fn test4() {
      assert_eq!(longest("aeiou","zzzz"), "aeiouz");
    }
    #[test]
    fn test5() {
      assert_eq!(longest("abcdefghijklmnoprstuwxyz","z"), "abcdefghijklmnoprstuwxyz");
    }
    #[test]
    fn test6() {
      assert_eq!(longest("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba","cd"), "abcd");
    }
    #[test]
    fn test7() {
      assert_eq!(longest("xyz","abc"), "abcxyz");
    }
    #[test]
    fn test8() {
      assert_eq!(longest("aebbbbbbae","aebbbbbbae"), "abe");
    }

    #[test]
    fn test9() {
      assert_eq!(longest("aeiouaeiouaeiouaeiou","z"), "aeiouz");
    }
    #[test]
    fn test10() {
      assert_eq!(longest("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb","b"), "b");
    }
}
