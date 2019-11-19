fn dig_pow(n: i64, p: i32) -> i64 {
    let c:i64 = n.to_string().chars().map(|x| x.to_digit(10).unwrap() as i64).enumerate()
                 .map(|x| x.1.pow(x.0 as u32+p as u32))
                 .collect::<Vec<(i64)>>().iter().sum();

    if c%n == 0 {
        return c/n;
    }
    -1i64
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::dig_pow;
   #[test]
    fn test1() {
        assert_eq!(dig_pow(89,1), 1);
    }
    #[test]
    fn test2() {
        assert_eq!(dig_pow(695,2), 2);
    }
    #[test]
    fn test3() {
        assert_eq!(dig_pow(46288,3), 51);
    }
    #[test]
    fn test4() {
        assert_eq!(dig_pow(92,2), -1);
    }
    #[test]
    fn test5() {
        assert_eq!(dig_pow(912,2), -1);
    }
    #[test]
    fn test6() {
        assert_eq!(dig_pow(40,5), -1);
    }
    #[test]
    fn test7() {
        assert_eq!(dig_pow(50,1), -1);
    }
    #[test]
    fn test8() {
        assert_eq!(dig_pow(200,6), -1);
    }
    #[test]
    fn test9() {
        assert_eq!(dig_pow(100,8), -1);
    }
    #[test]
    fn test10() {
        assert_eq!(dig_pow(1000,7), -1);
    }
}
