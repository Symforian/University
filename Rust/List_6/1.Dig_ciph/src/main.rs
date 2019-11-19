fn encode(msg: String, n: i32) -> Vec<i32> {
    let ascii_offset = 'a' as i32 -1;
    let mut n = n.to_string().chars().map(|x| x as u8).collect::<Vec<u8>>().into_iter().cycle();
    msg.chars().map(|x| ((x as u8 + n.next().unwrap() -ascii_offset)%48)as i32).collect()
}

fn main() {
    println!("{:?}",encode("abc".to_string(),1));
}
#[cfg(test)]
mod tests {
    use super::encode;
    #[test]
    fn test1() {
        assert_eq!(encode("".to_string(), 0), []);
    }
    #[test]
    fn test2() {
        assert_eq!(encode("abc".to_string(),1 ), [2, 3, 4]);
    }
    #[test]
    fn test3() {
        assert_eq!(encode("helloworld".to_string(),4), [12, 9, 16, 16, 19, 27, 19, 22, 16, 8]);
    }
    #[test]
    fn test4() {
        assert_eq!(encode("aaaaa".to_string(),123), [2, 3, 4, 2, 3]);
    }
    #[test]
    fn test5() {
        assert_eq!(encode("asnfoanisfask".to_string(),123123), [2, 21, 17, 7, 17, 4, 15, 11, 22, 7, 3, 22, 12]);
    }
    #[test]
    fn test6() {
        assert_eq!(encode("sapjidjvsdkvja".to_string(),123111), [20, 3, 19, 11, 10, 5, 11, 24, 22, 5, 12, 23, 11, 3]);
    }
    #[test]
    fn test7() {
        assert_eq!(encode("aczxcsdf".to_string(),8645234), [9, 9, 30, 29, 5, 22, 8, 14]);
    }
    #[test]
    fn test8() {
        assert_eq!(encode("zxcasfvxzxcasfdasv".to_string(),121111), [27, 26, 4, 2, 20, 7, 23, 26, 27, 25, 4, 2, 20, 8, 5, 2, 20, 23]);
    }
    #[test]
    fn test9() {
        assert_eq!(encode("xcasefdfsvcx".to_string(),111111), [25, 4, 2, 20, 6, 7, 5, 7, 20, 23, 4, 25]);
    }
    #[test]
    fn test10() {
        assert_eq!(encode("xzcxzefjryoui".to_string(),10088542), [25, 26, 3, 32, 34, 10, 10, 12, 19, 25, 15, 29, 17]);
    }



}
