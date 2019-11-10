fn xo(string: &'static str) -> bool {
  string.chars().into_iter().fold(0i32, |acc,x| match x{
      'x'| 'X' => acc+1,
      'o'| 'O' => acc-1,
      _ => acc,
  }) == 0
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::xo;
    
    #[test]
    fn empty() {
        assert_eq!(xo(""), true);
    }
    #[test]
    fn oneone() {
        assert_eq!(xo("xo"), true);
    }
    #[test]
    fn onezero() {
        assert_eq!(xo("x"), false);
    }
    #[test]
    fn zeroone() {
        assert_eq!(xo("o"), false);
    }
    #[test]
    fn with_other() {
        assert_eq!(xo("asdfxcvzooxasdzxcasdoasdfasdfxcvoasdf"), true);
    }
    #[test]
    fn with_other_and_case() {
        assert_eq!(xo("asdfXxcvzooxasdzaDFSxcaOsdoascxvvdfaOOsdfxcvoasXdf"), true);
    }
    #[test]
    fn test7() {
        assert_eq!(xo("qwerrtyyuiiopljhgfsaZXXVBVDSFASDQWGCCXAS VBZZXASCZX"), false);
    }
    #[test]
    fn test8() {
        assert_eq!(xo("cweofndkvnoawnfcklasfjhasplckizshjfhnkldfhqoaFOSDHFFOAIDPDjapfPFJSDPKVNA"), false);
    }
    #[test]
    fn test9() {
        assert_eq!(xo("vnsoakdnvosknzl"), false);
    }
    #[test]
    fn test10() {
        assert_eq!(xo("qwdjgpiahsfpoacruwervuiqofisdpofjnakoaklfnmapiwfjmpsrjrpqiarujpasidkvcpjiapsjfckzadpjiwjcfksahfiowhcoajs"), false);
    }
}
