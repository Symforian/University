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
    let mut res:String = string.to_string();
    res.chars().into_iter().map(|x| x = self.ciph[self.ciph.find(x).unwrap()]);
    res
  }
  
  fn decode(&self, string: &str) -> String {
    //your code here
  }
}

fn main()
{

   // println!("{}",number(&[(11,0),(3,5),(5,10)]));
}

#[cfg(test)]
mod tests {
    use super::number;
    #[test]
    fn examples() {
      let map1 = "abcdefghijklmnopqrstuvwxyz";
      let map2 = "etaoinshrdlucmfwypvbgkjqxz";

      let cipher = Cipher::new(map1, map2);
      
      assert_eq!(cipher.encode("abc"), "eta");
      assert_eq!(cipher.encode("xyz"), "qxz");
      assert_eq!(cipher.decode("eirfg"), "aeiou");
      assert_eq!(cipher.decode("erlang"), "aikcfu");
}


}
