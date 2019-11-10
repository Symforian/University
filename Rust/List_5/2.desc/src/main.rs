fn descending_order(x: u64) -> u64 {
   let mut v:Vec<u64> = x.to_string().chars().map(|a| a.to_digit(10).unwrap() as u64).collect();
   v.sort_by(|a,b| b.cmp(a));
   v.iter().map(|a| a.to_string()).collect::<String>().parse::<u64>().unwrap()
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::descending_order;
    
    #[test]
    fn one() {
        assert_eq!(descending_order(0), 0);
    }
    #[test]
    fn test2() {
        assert_eq!(descending_order(10), 10);
    }
    #[test]
    fn test3() {
        assert_eq!(descending_order(101), 110);
    }
    #[test]
    fn test4() {
        assert_eq!(descending_order(1032151), 5321110);
    }
    #[test]
    fn test5() {
        assert_eq!(descending_order(123456789), 987654321);
    }
    #[test]
    fn test6() {
        assert_eq!(descending_order(10000000), 10000000);
    }
    #[test]
    fn test7() {
        assert_eq!(descending_order(43211234), 44332211);
    }
    #[test]
    fn test8() {
        assert_eq!(descending_order(123), 321);
    }
    #[test]
    fn test9() {
        assert_eq!(descending_order(123123123), 333222111);
    }
    #[test]
    fn test10() {
        assert_eq!(descending_order(145263), 654321);
    }
}
