fn fcn(n: i32) -> i64 {
    2i64.pow(n as u32)
/*
    let mut v:Vec<i64> = vec![1, 2];
    let mut ptr:usize = 2;
    while v.len()<n as usize{
        println!("ptr:{:?}",v);
        v.push((6*v[ptr-2]*v[ptr-1])/(5*v[ptr-2]-v[ptr-1]));
        println!("{}",v[ptr]);
        ptr+=1;
        
    }
    println!("{:?}",v);
    0i64*/
}
/*
un1 = 1 
un2 = 2

6un u(n+1)-5 un u(n+2) +u(n+1) u(n+2) = 0

6un u(n+1) = u(n+2) (5 un -u(n+1)) 

u(n+2) = 6un*u(n+1) / (5un - u(n+1))

*/
fn main() {
    println!("Hello, world!");
    fcn(10);
}

#[cfg(test)]
mod tests {
    use super::fcn;
   #[test]
    fn test1() {
        assert_eq!(fcn(0), 1);
    }
    #[test]
    fn test2() {
        assert_eq!(fcn(1), 2);
    }
    #[test]
    fn test3() {
        assert_eq!(fcn(2), 4);
    }
    #[test]
    fn test4() {
        assert_eq!(fcn(3), 8);
    }
    #[test]
    fn test5() {
        assert_eq!(fcn(4), 16);
    }
    #[test]
    fn test6() {
        assert_eq!(fcn(5), 32);
    }
    #[test]
    fn test7() {
        assert_eq!(fcn(6), 64);
    }
    #[test]
    fn test8() {
        assert_eq!(fcn(7), 128);
    }
    #[test]
    fn test9() {
        assert_eq!(fcn(8), 256);
    }
    #[test]
    fn test10() {
        assert_eq!(fcn(9), 512);
    }
}
