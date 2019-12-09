use std::collections::HashMap;
struct MorseDecoder{
    morse_code: HashMap<String, String>,
}
impl MorseDecoder {
    fn new() -> MorseDecoder {
        MorseDecoder{ morse_code :
            [("....-", "4"),("--..--", ","),(".--", "W"),(".-.-.-", "."),("..---", "2"),(".", "E"),("--..", "Z"),(".----", "1"),(".-..", "L"),
            (".--.", "P"),(".-.", "R"),("...", "S"),("-.--", "Y"),("...--", "3"),(".....", "5"),("--.", "G"),("-.--.", "("),("-....", "6"),
            (".-.-.", "+"),("...-..-", "$"),(".--.-.", "@"),("...---...", "SOS"),("..--.-", "_"),("-.", "N"),("-..-", "X"),("-----", "0"),
            ("....", "H"),("-...", "B"),(".---", "J"),("---...", ","),("-", "T"),("---..", "8"),("-..-.", "/"),("--.-", "Q"),("...-", "V"),
            ("----.", "9"),("--", "M"),("-.-.-.", ";"),("-.-.--", "!"),("..-.", "F"),("..--..", "?"),("-...-", "="),("..-", "U"),(".----.", "'"),
            ("---", "O"),("-.--.-", ")"),("..", "I"),("-....-", "-"),(".-..-.", "\""),(".-", "A"),("-.-.", "C"),("-..", "D"),(".-...", "&"),
            ("--...", "7"),("-.-", "K")].iter().map(|(k, v)| (k.to_string(), v.to_string())).collect()
        }
    }
    fn decode_morse(&self, encoded: &str) -> String {
        encoded.split("   ").filter(|&x| x!="").map(|w| w.split(" ").filter(|&x| x!="")
                                                        .map(|l| (&self).morse_code[&l
                                                                                    .chars().filter(|&x| x!=' ')
                                                                                    .collect::<String>()].to_owned())
                                                            .collect::<Vec<String>>().join("")).filter(|x| x!="")
                                                    .collect::<Vec<String>>().join(" ") 
    }
    
}
fn main() {
    println!("Hello, world!");
    let md = MorseDecoder::new();
    md.decode_morse("... --- ...   ... --- ...");
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        let md = MorseDecoder::new();
        assert_eq!(md.decode_morse("...---..."),"SOS".to_string());
    }
    #[test]
    fn test2() {
        let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("...   ---   ..."),"S O S".to_string());
    }
    #[test]
    fn test3() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("... ... ...   ..."),"SSS S".to_string());
    }
    #[test]
    fn test4() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("...  ...  ..."),"SSS".to_string());
    }
    #[test]
    fn test5() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("...-- .- .-    --- .   -- .  -   -     "),"3AA OE MET T".to_string());
    }
    #[test]
    fn test6() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(""),"".to_string());
    }
    #[test]
    fn test7() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("                                  "), "".to_string());
    }
    #[test]
    fn test8() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("   ....   .... .--."), "H HP".to_string());
    }
    #[test]
    fn test9() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("--- - - - -  -"), "OTTTTT".to_string());
    }
    #[test]
    fn test10() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse("... --- ... .. --   ---   ..-.  ..-."), "SOSIM O FF".to_string());
    }
}
