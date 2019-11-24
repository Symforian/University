fn last_digit(lst: &[u64]) -> u64 {

    fn trim_number(number: u128, base: u128) -> u128{
       return if number < base { number } else { number % base + base }
    }

    if lst.len()==0 {return 1;}

    let first = *(lst.iter().last().unwrap()) as u128;
    let folded = lst.iter().clone().take(lst.len()-1).collect::<Vec<&u64>>().iter().skip(1).rev()
       .fold(first, |first, x| (trim_number(**x as u128, 20)).pow(trim_number(first,4) as u32));
    (((lst[0]%10) as u128).pow(trim_number(folded,4) as u32)%10) as u64

}
fn main() {
    println!("Last of 0^0 is: {:?} should be: 1",last_digit(&[0, 0]));
}
#[cfg(test)]
mod tests {
    use super::last_digit;

    #[test]
    fn test1() {
        assert_eq!(last_digit(&[3,4,2]), 1);
    }
    #[test]
    fn test2() {
        assert_eq!(last_digit(&[1,2,3,4,5,6,7,8,9,10]), 1);
    }
    #[test]
    fn test3() {
        assert_eq!(last_digit(&[0, 0, 0]), 0);
    }
    #[test]
    fn test4() {
        assert_eq!(last_digit(&[7, 6, 21]), 1);
    }
    #[test]
    fn test5() {
        assert_eq!(last_digit(&[12, 30, 21]), 6);
    }
    #[test]
    fn test6() {
        assert_eq!(last_digit(&[937640, 767456, 981242]), 0);
    }
    #[test]
    fn test7() {
        assert_eq!(last_digit(&[123232, 694022, 140249]), 6);
    }
    #[test]
    fn test8() {
        assert_eq!(last_digit(&[2, 2, 101, 2]), 6);
    }
    #[test]
    fn test9() {
        assert_eq!(last_digit(&[2123, 212341, 101, 21231]), 3);
    }
    #[test]
    fn test10() {
        assert_eq!(last_digit(&[]), 1);
    }
}
