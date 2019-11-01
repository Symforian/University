fn last_digit(str1: &str, str2: &str) -> i32 {
    if str2 == "0" { return 1;}
    let number = str1.get(str1.len()-1..str1.len()).unwrap();
    if number == "0"|| number ==  "1"|| number ==  "5"|| number ==  "6" { return number.parse::<i32>().unwrap();} 
    else if number == "9"{
        if str2.get(str2.len()-1..str2.len()).unwrap().parse::<u8>().unwrap() % 2 == 0 { return 1;}
        else {return 9;}
    } else if number == "4"{
        if str2.get(str2.len()-1..str2.len()).unwrap().parse::<u8>().unwrap() % 2 == 0 { return 6;}
        else {return 4;}
    }
    let perms:Vec<Vec<i32>>= vec![vec![],vec![],vec![2,4,8,6],vec![3,9,7,1],vec![],vec![],vec![],vec![7,9,3,1],vec![8,4,2,6],vec![]];
    return perms[number.parse::<usize>().unwrap()][(str2.get(str2.len()-2..str2.len()).unwrap().parse::<usize>().unwrap()-1)%4];

    
    
}
// 1 1
// 2 2 4 8 6 
// 3 3 9 7 1
// 4 4 6 
// 5 5
// 6 6
// 7 7 9 3 1
// 8 8 4 2 6
// 9 9 1
// 0 0
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::last_digit;
    
    #[test]
    fn test1() {
      assert_eq!(last_digit("1231253213412341241346","23412413421341234"), 6);
    }
    #[test]
    fn test2() {
      assert_eq!(last_digit("1231253213412341241349","334124132222222224"), 1);
    }
    #[test]
    fn test3() {
      assert_eq!(last_digit("1231253213412341241349","23412413421341333"), 9);
    }
    #[test]
    fn test4() {
      assert_eq!(last_digit("1231253213412341241340","23412413421341233"), 0);
    }
    #[test]
    fn test5() {
      assert_eq!(last_digit("1231253213412341241341","234124222222223"), 1);
    }
    #[test]
    fn test6() {
      assert_eq!(last_digit("1231253213412341241345","23412413421341233"), 5);
    }
    #[test]
    fn test7() {
  assert_eq!(last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"), 7);
    }
    #[test]
    fn test8() {
      assert_eq!(last_digit("1231253213412341241341","234124223"), 1);
    }
    #[test]
    fn test9() {
      assert_eq!(last_digit("1231253213412341241340","234124212323"), 0);
    }
    #[test]
    fn test10() {
      assert_eq!(last_digit("1231253213412341241349","234124212323"), 9);
    }


}
