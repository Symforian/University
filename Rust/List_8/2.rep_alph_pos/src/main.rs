fn alphabet_position(text: &str) -> String {
    let ascii_offset = 'a' as u8 - 1;
    text.to_string().chars()
                    .filter(|x| x.is_ascii_alphabetic())
                    .map(|x| (x.to_ascii_lowercase() as u8-ascii_offset).to_string())
                    .collect::<Vec<String>>().join(" ")
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::alphabet_position;

    #[test]
    fn test1() {
        assert_eq!(alphabet_position("The sunset sets at twelve o' clock."), "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11".to_string());
    }
    #[test]
    fn test2() {
        assert_eq!(alphabet_position("The narwhal bacons at midnight."), "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20".to_string());
    }
    #[test]
    fn test3() {
        assert_eq!(alphabet_position("Hello world"), "8 5 12 12 15 23 15 18 12 4");
    }
    #[test]
    fn test4() {
        assert_eq!(alphabet_position("abcde"), "1 2 3 4 5");
    }
    #[test]
    fn test5() {
        assert_eq!(alphabet_position("a b c d e"), "1 2 3 4 5");
    }
    #[test]
    fn test6() {
        assert_eq!(alphabet_position("dDdDdD"), "4 4 4 4 4 4");
    }
    #[test]
    fn test7() {
        assert_eq!(alphabet_position(""), "");
    }
    #[test]
    fn test8() {
        assert_eq!(alphabet_position("123d321"), "4");
    }
    #[test]
    fn test9() {
        assert_eq!(alphabet_position("12313"), "");
    }
    #[test]
    fn test10() {
        assert_eq!(alphabet_position("cxzer"), "3 24 26 5 18");
    }
}
