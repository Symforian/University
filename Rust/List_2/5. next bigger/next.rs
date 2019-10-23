fn next_bigger_number(n: i64) -> i64 {
    let strn:String = n.to_string();
    let nlen:usize = strn.len();
    let mut chars:Vec<char> = strn.chars().collect();
    chars.sort_by(|a, b| b.cmp(a));
    if chars.into_iter().collect::<String>() == n.to_string()
        {return -1}
    let mut chars:Vec<char> = strn.chars().collect();
    let mut prev:usize = nlen-1;
    for i in  (0..nlen-1).rev() {
        if chars[prev] > chars[i]{
            for j in prev+1..nlen{
                if chars[prev]>chars[j] && chars[i]<chars[j]
                    {prev = j;}
            }
            chars.swap(prev, i);
            let mut u:Vec<char> = chars.splice(i+1..,vec![].iter().cloned()).collect();
            u.sort();
            chars.splice(i+1..,u.iter().cloned());
            
            break;         
        } 
        prev = i;
    }
    chars.into_iter().collect::<String>().parse::<i64>().unwrap()
}

fn main()
{

    println!("{}",next_bigger_number(8977));
}

#[cfg(test)]
mod tests {
    use super::next_bigger_number;
    
    #[test]
    fn test1() {
      assert_eq!(next_bigger_number(1), -1);
    }
    #[test]
    fn test2() {
      assert_eq!(next_bigger_number(10), -1);
    }
    #[test]
    fn test3() {
      assert_eq!(next_bigger_number(13), 31);
    }
    #[test]
    fn test4() {
      assert_eq!(next_bigger_number(63), -1);
    }
    #[test]
    fn test5() {
      assert_eq!(next_bigger_number(33), -1);
    }
    #[test]
    fn test6() {
      assert_eq!(next_bigger_number(1001), 1010);
    }
    #[test]
    fn test7() {
      assert_eq!(next_bigger_number(2047), 2074);
    }
    #[test]
    fn test8() {
      assert_eq!(next_bigger_number(8977), 9778);
    }
    #[test]
    fn test9() {
      assert_eq!(next_bigger_number(1073741823), 1073741832);
    }
    #[test]
    fn test10() {
      assert_eq!(next_bigger_number(4096), 4609);
    }
    fn test11() {
      assert_eq!(next_bigger_number(1234567890), 1234567908);
    }

}
