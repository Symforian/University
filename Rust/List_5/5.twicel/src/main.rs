fn dbl_linear(n: u32) -> u32{
    let mut u = vec![1u32];
    let mut lastx = 0usize;
    let mut lasty = 0usize;
    while u.len() <=n as usize{
        let x:u32 = 2*u[lastx]+1;
        let y:u32 = 3*u[lasty]+1; 
        if  x <= y{
            u.push(x);
            lastx+=1;
            if x  == y{
                lasty+=1;
            }
        } 
        else{
            u.push(y);
            lasty+=1;
        }
    }
    u[n as usize]
}
fn main() {
    dbl_linear(20);
}
#[cfg(test)]
mod tests {
    use super::dbl_linear;
    #[test]
    fn test1() {
        assert_eq!(dbl_linear(0), 1);
    }
    #[test]
    fn test2() {
        assert_eq!(dbl_linear(10), 22);
    }
    #[test]
    fn test3() {
        assert_eq!(dbl_linear(15), 40);
    }
    #[test]
    fn test4() {
        assert_eq!(dbl_linear(20), 57);
    }
    #[test]
    fn test5() {
        assert_eq!(dbl_linear(30), 91);
    }
    #[test]
    fn test6() {
        assert_eq!(dbl_linear(40), 130);
    }
    #[test]
    fn test7() {
        assert_eq!(dbl_linear(50), 175);
    }
    #[test]
    fn test8() {
        assert_eq!(dbl_linear(200), 1051);
    }
    #[test]
    fn test9() {
        assert_eq!(dbl_linear(100), 447);
    }
    #[test]
    fn test10() {
        assert_eq!(dbl_linear(1000), 8488);
    }



}
