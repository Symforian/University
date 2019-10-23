fn number(bus_stops:&[(i32,i32)]) -> i32 {
    bus_stops.into_iter().fold(0, |sum, x| sum+x.0-x.1)
}

fn main()
{

    println!("{}",number(&[(11,0),(3,5),(5,10)]));
}

#[cfg(test)]
mod tests {
    use super::number;
    
    #[test]
    fn test1() {
      assert_eq!(number(&[(11,0),(3,5),(5,10)]), 4);
    }
    #[test]
    fn test2() {
      assert_eq!(number(&[(20,0),(0,5),(0,8)]), 7);
    }
    #[test]
    fn test3() {
      assert_eq!(number(&[(0,0),(0,0),(9,8)]), 1);
    }
    #[test]
    fn test4() {
      assert_eq!(number(&[(20,0),(0,5),(0,8),(20,0),(0,5),(0,8)]), 14);
    }
    #[test]
    fn test5() {
      assert_eq!(number(&[(0,0),(0,0),(0,0),(0,0),(0,0),(0,0)]), 0);
    }
    #[test]
    fn test6() {
      assert_eq!(number(&[(1,0),(1,0),(1,0),(1,0),(1,0),(0,5)]), 0);
    }
    #[test]
    fn test7() {
      assert_eq!(number(&[(1,0),(1,0),(1,0),(1,0),(1,0),(0,5),(100,0),(1,50),(1,50),(18,0),(1,0),(0,10)]), 11);
    }
    #[test]
    fn test8() {
      assert_eq!(number(&[(100,0),(100,0),(100,0),(0,0),(0,0),(0,5),(100,0),(0,95),(200,0),(500,0),(0,500),(0,0)]), 500);
    }
    #[test]
    fn test9() {
      assert_eq!(number(&[(100,0)]), 100);
    }
    #[test]
    fn test10() {
      assert_eq!(number(&[(100,0),(100,200)]), 0);
    }


}
