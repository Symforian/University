fn dec2_fact_string(nb: u64) -> String {
    let char_offset = 'A' as u8 - 10;
    let mut v:String = "".to_string();
    let mut fact = 1u64;
    let mut f = 1u64;
    while nb > fact{
        fact*=f;
        f+=1;
    }
    f-=1;
    fact/=f;
    let mut nb = nb;
    while f > 0{
        let temp = (nb/fact) as u8;
        let mut symbol = temp.to_string();
        if temp >= 10{
            symbol = ((temp+char_offset) as char).to_string();
        }
        v = format!("{}{}",v,symbol);
        nb = nb-(temp as u64*fact);
        f-=1;
        if f == 0
            {break;}
        fact/=f;
    }
    v
}

fn fact_string_2dec(s: String) -> u64 {
    let char_offset = 'A' as u8 - 10;
    let mut f = 1u64;
    let mut fact = 1u64;
    let mut v:Vec<u64> = vec![];
    while s.len() as u64+1 != f{
        v.push(fact);
        fact*=f;
        f+=1;
    }
    s.chars().rev().enumerate().map(|x| match x.1.is_numeric() {
                                            true  => x.1.to_digit(10).unwrap() as u64 *v[x.0] as u64,
                                            false => (x.1 as u8 - char_offset) as u64 *v[x.0] as u64,
                                            }
                                    ).sum::<u64>()

}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::dec2_fact_string;
    use super::fact_string_2dec;
    #[test]
    fn test1() {
        assert_eq!(dec2_fact_string(2982),"4041000".to_string());
    }
    #[test]
    fn test2() {
      assert_eq!(dec2_fact_string(463),"341010".to_string());
    }
    #[test]
    fn test3() {
      assert_eq!(dec2_fact_string(39916800),"B0000000000".to_string());
    }
    #[test]
    fn test4() {
      assert_eq!(dec2_fact_string(399168321),"A00000231110".to_string());
    }
    #[test]
    fn test5() {
      assert_eq!(dec2_fact_string(431321312312),"4D3555813111100".to_string());
    }
    #[test]
    fn test6() {
        assert_eq!(fact_string_2dec("4041000".to_string()),2982);
    }
    #[test]
    fn test7() {
        assert_eq!(fact_string_2dec("341010".to_string()), 463);
    }
    #[test]
    fn test8() {
        assert_eq!(fact_string_2dec("4D3555813111100".to_string()), 431321312312);
    }
    #[test]
    fn test9() {
        assert_eq!(fact_string_2dec("A00000231110".to_string()), 399168321);
    }
    #[test]
    fn test10() {
        assert_eq!(fact_string_2dec("B0000000000".to_string()), 39916800);
    }
}
