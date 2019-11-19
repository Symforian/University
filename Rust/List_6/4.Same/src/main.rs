fn comp(a: Vec<i64>, b: Vec<i64>) -> bool {
    if a.is_empty() || b.is_empty() { true }
    else {
    let mut b = b;
    let mut a = a.iter().map(|x| x*x).collect::<Vec<i64>>();
    b.sort();
    a.sort();
    a == b
    }
}
fn main() {
    println!("{}",comp(vec![121, 144, 19, 161, 19, 144, 19, 11],vec![121, 14641, 20736, 36100, 25921, 361, 20736, 361]));
}
#[cfg(test)]
mod tests {
    use super::comp;
   #[test]
    fn test1() {
        assert_eq!(comp(vec![],vec![]), true);
    }
    #[test]
    fn test2() {
        assert_eq!(comp(vec![121, 144, 19, 161, 19, 144, 19, 11],vec![11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]), true);
    }
    #[test]
    fn test3() {
        assert_eq!(comp(vec![121, 144, 19, 161, 19, 144, 19, 11],vec![11*21, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]), false);
    }
    #[test]
    fn test4() {
        assert_eq!(comp(vec![1,2,3],vec![9,4,1]), true);
    }
    #[test]
    fn test5() {
        assert_eq!(comp(vec![121, 144, 19, 161, 19, 144, 19, 11],vec![121, 14641, 20736, 36100, 25921, 361, 20736, 361]), false);
    }
    #[test]
    fn test6() {
        assert_eq!(comp(vec![3, 4, 5, 5, 5, 5],vec![25, 25, 25, 25, 25, 16]), false);
    }
    #[test]
    fn test7() {
        assert_eq!(comp(vec![3, 4, 5, 5, 5, 1],vec![25, 25, 1, 25, 9, 16]), true);
    }
    #[test]
    fn test8() {
        assert_eq!(comp(vec![121, 144, 19, 161, 19, 144, 19, 11],vec![25, 25, 1, 25, 9, 16]), false);
    }
    #[test]
    fn test9() {
        assert_eq!(comp(vec![121, 144, 19, 161, 19, 144, 19, 11, 121, 144, 19, 161, 19, 144, 19, 11, 121, 144, 19, 161, 19, 144, 19, 11],vec![11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19, 11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19, 11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]), true);
    }
    #[test]
    fn test10() {
        assert_eq!(comp(vec![1,2,3,10,100,42],vec![9,4,1,10*10,100*100, 42*42]), true);
    }
}
