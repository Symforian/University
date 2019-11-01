fn even_numbers(array: &Vec<i32>, number: usize) -> Vec<i32> {
  let mut ret :Vec<i32> = array.clone().into_iter().filter(|x| x%2==0).rev().collect::<Vec<i32>>();
  ret.drain(0..number).rev().collect()
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::even_numbers;
    
    #[test]
    fn test1() {
  assert_eq!(even_numbers(&vec!(1, 2, 3, 4, 5, 6, 7, 8, 9), 3), vec!(4, 6, 8));
    }
    #[test]
    fn test2() {
  assert_eq!(even_numbers(&vec!(-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26), 2), vec!(-8, 26));
    }
    #[test]
    fn test3() {
  assert_eq!(even_numbers(&vec!(8, -25, 3, 7, 5, 5, 7, -3, 23), 1), vec!(8));
    }
    #[test]
    fn test4() {
  assert_eq!(even_numbers(&vec!(8, -25, 4, 7, 5, 5, 7, -3, 23), 2), vec!(8,4));
    }
 /*   #[test]
    fn test5() {
      assert_eq!(find_digit(51111111,6), 1);
    }
    #[test]
    fn test6() {
      assert_eq!(find_digit(3123126,100), 0);
    }
    #[test]
    fn test7() {
      assert_eq!(find_digit(7,-1), -1);
    }
    #[test]
    fn test8() {
      assert_eq!(find_digit(-12341238,7), 2);
    }
    #[test]
    fn test9() {
      assert_eq!(find_digit(771345,3), 3);
    }
    #[test]
    fn test10() {
      assert_eq!(find_digit(1200231,3), 2);
    }

*/
}
