fn solution(n: f64) -> f64 {
    let x = n - n.floor();
    return match (x>0.75f64,x>0.5f64, x>0.25f64) {
        (true,_,_) => n.floor()+1f64,
        (false,_,true) => n.floor()+0.5f64,
        _ => n.floor(),
    }
}

fn main() {
    println!("Hello, world!");
}
#[cfg(test)]
mod tests {
    use super::solution;
    #[test]
    fn test1() {
        assert_eq!(solution(0f64), 0f64);
    }
    #[test]
    fn test2() {
        assert_eq!(solution(10.1f64), 10f64);
    }
    #[test]
    fn test3() {
        assert_eq!(solution(10.3f64), 10.5f64);
    }
    #[test]
    fn test4() {
        assert_eq!(solution(10.6f64), 10.5f64);
    }
    #[test]
    fn test5() {
        assert_eq!(solution(10.8f64), 11f64);
    }
    #[test]
    fn test6() {
        assert_eq!(solution(-10.8f64), -11f64);
    }
    #[test]
    fn test7() {
        assert_eq!(solution(-10.2f64), -10f64);
    }
    #[test]
    fn test8() {
        assert_eq!(solution(-10f64), -10f64);
    }
    #[test]
    fn test9() {
        assert_eq!(solution(-5.5f64), -5.5f64);
    }
    #[test]
    fn test10() {
        assert_eq!(solution(-13.9f64), -14f64);
    }



}
