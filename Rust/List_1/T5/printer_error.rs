fn printer_error(s: &str) -> String {
    let slen: &str = &s.len().to_string();
    let mut z:String = s.to_owned(); 
    z.retain(|c| c > 'm');
    let mut z:String = z.len().to_string();
    z.push_str("/");
    z.push_str(slen);
    z   
}
fn main()
{
    printer_error("aaaabbbbvvv");
}

#[cfg(test)]
mod tests {
    use super::printer_error;
    
    #[test]
    fn test1() {
      assert_eq!(printer_error("aaabbbcccdddeeefff"), "0/18");
    }
    #[test]
    fn test2() {
      assert_eq!(printer_error("nnnxxxzzz"), "9/9");
    }
    #[test]
    fn test3() {
      assert_eq!(printer_error("aaabbbcccdddeeefffnnnxxxzzz"), "9/27");
    }
    #[test]
    fn test4() {
      assert_eq!(printer_error("axaxaxbxbxbxcxcxcxdxdxdxexexexfxfxfx"), "18/36");
    }
    #[test]
    fn test5() {
      assert_eq!(printer_error("aaaabbbbccccdddx"), "1/16");
    }
}
