struct Cipher {
  alph :Vec<char>,
  ciph :Vec<char>,
}

impl Cipher {
  fn new(map1: &str, map2: &str) -> Cipher {
    Cipher{
    alph : map1.chars().collect(),
    ciph : map2.chars().collect(), 
    }
  }
  
  fn encode(&self, string: &str) -> String {
    let mut res:String = "".to_string();
    for c in string.chars(){
        let symb = self.alph.iter().position(|&e| e == c);
        match symb{
        Some(v) => res.push(self.ciph[v]),
        None => res.push(c),
        }
    }
    res
  }
  
  fn decode(&self, string: &str) -> String {
    let mut res:String = "".to_string();
    for c in string.chars(){
        let symb = self.ciph.iter().position(|&e| e == c);
        match symb{
        Some(v) => res.push(self.alph[v]),
        None => res.push(c),
        }
    }
    res
  }
}

fn main()
{
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "etaoinshrdlucmfwypvbgkjqxz";
      let cipher = Cipher::new(map1, map2);
      
      assert_eq!(cipher.encode("abc"), "eta");
      assert_eq!(cipher.encode("xyz"), "qxz");
      assert_eq!(cipher.decode("eirfg"), "aeiou");
      assert_eq!(cipher.decode("erlang"), "aikcfu");

   // println!("{}",number(&[(11,0),(3,5),(5,10)]));
}

#[cfg(test)]
mod tests {
    use super::Cipher;
    #[test]
    fn cipher1_semirand() {
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "bcagdzxyqwermpnotuilkvsfhj";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "bca");
      assert_eq!(ciph.encode("xyz"), "fhj");
      assert_eq!(ciph.decode("bdqnk"), "aeiou");
      assert_eq!(ciph.decode("brbmbenlb"), "alamakota");
      assert_eq!(ciph.encode(&ciph.decode("brbmbenlb")), "brbmbenlb");   
    }

    #[test]
    fn cipher2_samealph() {
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "abcdefghijklmnopqrstuvwxyz";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "abc");
      assert_eq!(ciph.encode("xyz"), "xyz");
      assert_eq!(ciph.decode("bdqnk"), "bdqnk");
      assert_eq!(ciph.decode("brbmbenlb"), "brbmbenlb");
      assert_eq!(ciph.encode(&ciph.decode("brbmbenlb")), "brbmbenlb");   
    }

    #[test]
    fn cipher3_alph_invert() {
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "zyxwvutsrqponmlkjihgfedcba";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "zyx");
      assert_eq!(ciph.encode("xyz"), "cba");
      assert_eq!(ciph.decode("bdqnk"), "ywjmp");
      assert_eq!(ciph.decode("brbmbenlb"), "yiynyvmoy");
      assert_eq!(ciph.encode(&ciph.decode("brbmbenlb")), "brbmbenlb");   
    }

    #[test]
    fn cipher4_3inverted() {
      let map1 = "zyxwvutsrqponmlkjihgfedcba";
      let map2 = "abcdefghijklmnopqrstuvwxyz";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("zyx"), "abc");
      assert_eq!(ciph.encode("cba"), "xyz");
      assert_eq!(ciph.decode("ywjmp"), "bdqnk");
      assert_eq!(ciph.decode("yiynyvmoy"), "brbmbenlb");
      assert_eq!(ciph.encode(&ciph.decode("brbmbenlb")), "brbmbenlb");   
    }

    #[test]
    fn cipher5mini_qwerty() {
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "qwertyuiopasdfghjklzxcvbnm";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "qwe");
      assert_eq!(ciph.decode("qsqdqagzq"), "alamakota");
      assert_eq!(ciph.encode(&ciph.decode("brbmbenlb")), "brbmbenlb");   
    }

    #[test]
    fn ciph6minimini() {
      let map1 = "abcdefgh";
      let map2 = "zxcvbnaf";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "zxc");
      assert_eq!(ciph.decode("vbcz"), "deca");
      assert_eq!(ciph.encode(&ciph.decode("c")), "c");   
    }
    #[test]
    fn ciph7minimini() {
      let map1 = "abcdefgh";
      let map2 = "abfedcgh";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abc"), "abf");
      assert_eq!(ciph.decode("abcdefgh"), "abfedcgh");
      assert_eq!(ciph.encode(&ciph.decode("cde")), "cde");   
    }
    #[test]
    fn ciph8minimini_special() {
      let map1 = "abcdefgh";
      let map2 = "abfedcgh";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abzxc"), "abzxf");
      assert_eq!(ciph.decode("zzz"), "zzz");
      assert_eq!(ciph.encode(&ciph.decode("x")), "x");   
    }
    #[test]
    fn ciph9minimini_badcipher() {
      let map1 = "abcdefghijklmnoprstuvwxyz";
      let map2 = "aaaaaaaaaaaaaaaaaaaaaaaaa";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("abcd"), "aaaa");
      assert_eq!(ciph.decode("aaaa"), "aaaa");
      assert_eq!(ciph.encode(&ciph.decode("x")), "a");   
    }
    #[test]
    fn ciph10badcipher() {
      let map1 = "noprstuvwxyz";
      let map2 = "abcdefghijkl";

      let ciph = Cipher::new(map1, map2);
      assert_eq!(ciph.encode("nopr"), "abcd");
      assert_eq!(ciph.decode("nope"), "nops");
      assert_eq!(ciph.encode(&ciph.decode("x")), "j");   
    }


}
