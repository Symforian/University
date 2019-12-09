fn dna_strand(dna: &str) -> String {
  fn replace(c:char) -> char{
      return match c{
                      'A' => 'T',
                      'T' => 'A',
                      'G' => 'C',
                      'C' => 'G',
                       _  => '0',
                      }
  }
  dna.to_string().chars().map(|x| replace(x)).collect::<String>()
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::dna_strand;

    #[test]
    fn test1() {
        assert_eq!(dna_strand("AAAA"),"TTTT".to_string());
    }
    #[test]
    fn test2() {
      assert_eq!(dna_strand("ATTGC"),"TAACG".to_string());
    }
    #[test]
    fn test3() {
      assert_eq!(dna_strand("GTAT"),"CATA".to_string());
    }
    #[test]
    fn test4() {
      assert_eq!(dna_strand("CATA"),"GTAT".to_string());
    }
    #[test]
    fn test5() {
      assert_eq!(dna_strand("TAACG"),"ATTGC".to_string());
    }
    #[test]
    fn test6() {
        assert_eq!(dna_strand("TTTT"),"AAAA".to_string());
    }
    #[test]
    fn test7() {
        assert_eq!(dna_strand(""), "".to_string());
    }
    #[test]
    fn test8() {
        assert_eq!(dna_strand("ACGT"), "TGCA".to_string());
    }
    #[test]
    fn test9() {
        assert_eq!(dna_strand("CCC"), "GGG".to_string());
    }
    #[test]
    fn test10() {
        assert_eq!(dna_strand("ACA"), "TGT".to_string());
    }
}
