fn print(n: i32) -> Option<String> {
    if n<=0 || n%2==0 {
        return None;
    }
    let n = n as usize;
    let mut res:String="".to_string();
    for i in (0..n/2+1).chain((0..n/2).rev()){
        res.push_str(&" ".repeat((n-(i*2+1))/2));
        res.push_str(&"*".repeat(i*2+1));
        res.push_str("\n");
    }
    Some(res)
}
fn main() {
    println!("Hello, world!");
}
#[cfg(test)]
mod tests {
    use super::print;
   #[test]
    fn test1() {
        assert_eq!(print(0), None);
    }
    #[test]
    fn test2() {
        assert_eq!(print(-1), None);
    }
    #[test]
    fn test3() {
        assert_eq!(print(3), Some(" *\n***\n *\n".to_string()));
    }
    #[test]
    fn test4() {
        assert_eq!(print(2), None);
    }
    #[test]
    fn test5() {
        assert_eq!(print(5), Some("  *\n ***\n*****\n ***\n  *\n".to_string()));
    }
    #[test]
    fn test6() {
        assert_eq!(print(7), Some("   *\n  ***\n *****\n*******\n *****\n  ***\n   *\n".to_string()));
    }
    #[test]
    fn test7() {
        assert_eq!(print(9), Some("    *\n   ***\n  *****\n *******\n*********\n *******\n  *****\n   ***\n    *\n".to_string()));
    }
    #[test]
    fn test8() {
        assert_eq!(print(11), Some("     *\n    ***\n   *****\n  *******\n *********\n***********\n *********\n  *******\n   *****\n    ***\n     *\n".to_string()));
    }
    #[test]
    fn test9() {
        assert_eq!(print(13), Some("      *\n     ***\n    *****\n   *******\n  *********\n ***********\n*************\n ***********\n  *********\n   *******\n    *****\n     ***\n      *\n".to_string()));
    }
    #[test]
    fn test10() {
        assert_eq!(print(15), Some("       *\n      ***\n     *****\n    *******\n   *********\n  ***********\n *************\n***************\n *************\n  ***********\n   *********\n    *******\n     *****\n      ***\n       *\n".to_string()));
    }
}
