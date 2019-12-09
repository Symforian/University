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
    fn decode_bits(&self, encoded: &str) -> String {
        fn bits_to_chars(n_type:usize,n:u32,unit:u32) -> String{
            return match n_type {
                1 => {
                        if n == unit{
                            ".".to_string()
                            }
                        else{
                            "-".to_string()
                        }
                    },
                0 => {
                        if n == unit{
                            "".to_string()
                            }
                        else if n == unit*3{
                            " ".to_string()
                        }
                        else{
                            "   ".to_string()
                        }
                    },
                _ => panic!(),
            }
        }
        if encoded == "" {return "".to_string();}
        let mut vec:Vec<u32> = vec![];
        let mut current = encoded.chars().next().unwrap();
        let mut counter = 0u32;
        for s in encoded.chars(){

            if s!=current{
                vec.push(counter);
                counter= 0;
                current = s;
            }
            counter+=1;
        }
        vec.push(counter);
        if vec.len()==1{
            return "".to_string();
        }
        if encoded.chars().next().unwrap() == '0'{
            vec.remove(0);        
        }
        if vec.len()==0{
            return "".to_string();
        }
        if encoded.chars().last().unwrap() == '0'{
            vec.remove(vec.len()-1);
        }
        let unit_size = *vec.iter().min().unwrap();
        vec
                    .iter()
                    .enumerate()
                    .map(|x| bits_to_chars((x.0+1)%2,*x.1,unit_size)
        ).collect::<Vec<String>>().join("")

    }
    
}
fn main() {
    println!("Hello, world!");
    let md = MorseDecoder::new();
    md.decode_morse("... --- ...   ... --- ...");
    md.decode_bits("0011001100110000001111001100110011000");
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        let md = MorseDecoder::new();
        assert_eq!(md.decode_morse(&md.decode_bits("101010111011101110101010")),"SOS".to_string());
    }
    #[test]
    fn test2() {
        let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("0011001100110000001111001100110011000")),"SB".to_string());
    }
    #[test]
    fn test3() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("110011001100000011001100110000001100110011000000000000001100110011")),"SSS S".to_string());
    }
    #[test]
    fn test4() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("0000000000000000000000000011001100110000001100110011000000110011001100000000000000110011001100000000000000000000000000")),"SSS S".to_string());
    }
    #[test]
    fn test5() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("1100110011001100000011000000111111001100111111001111110000000000000011001111110011111100111111000000110011001111110000001111110011001100000011")), "HEY JUDE".to_string());
    }
    #[test]
    fn test6() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("")),"".to_string());
    }
    #[test]
    fn test7() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("0000000000000000000001000000000000000000")), "E".to_string());
    }
    #[test]
    fn test8() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("0000000000000000000")), "".to_string());
    }
    #[test]
    fn test9() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("00011110000111100001111000000000000111111111111000000")), "ST".to_string());
    }
    #[test]
    fn test10() {
      let md = MorseDecoder::new();
      assert_eq!(md.decode_morse(&md.decode_bits("101000111011100000001011100011101000111000")), "IM ANT".to_string());
    }
}
