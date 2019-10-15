fn count_red_beads(n: u32) -> u32 {
    
    if n<2 {return 0;}
    (n-1)*2
    
}
fn main()
{
    count_red_beads(5);
}

#[cfg(test)]
mod tests {
    use super::count_red_beads;
    
    #[test]
    fn test1() {
      assert_eq!(count_red_beads(0), 0);
    }
    #[test]
    fn test2() {
      assert_eq!(count_red_beads(1), 0);
    }
    #[test]
    fn test3() {
      assert_eq!(count_red_beads(2), 2);
    }
    #[test]
    fn test4() {
      assert_eq!(count_red_beads(4), 6);
    }
    #[test]
    fn test5() {
      assert_eq!(count_red_beads(50), 98);
    }
}
