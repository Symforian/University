use std::cmp::Ordering;
fn rank(st: &str, we: Vec<i32>, n: usize) -> &str {

    fn som(s: &str) -> i32{
        let s:String = s.to_string();
        let mut acc:i32 = 0;
        for c in s.chars(){
            let mut m:i32 = 64;
            if c.is_lowercase() { m = 96;}
            acc += (c as i32)%m +1;
        }
        acc 
    }

    if st.is_empty() { return "No participants"}
    if st.len() <= n { return "Not enough participants"}
    
    let vst:Vec<&str> = st.split(",").collect();
    let mut v:Vec<(i32,&str)> = vec![];
    
    for i in 0..we.len(){
        v.push((we[i]*som(vst[i]),vst[i]));
    }
    
    v.sort_by(|a, b| match b.0.cmp(&a.0){
            Ordering::Equal => a.1.cmp(&b.1),
            other => other,
    });

    v[n-1].1
}
fn main()
{

    println!("{}",rank("Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin", vec![4, 2, 1, 4, 3, 1, 2], 4));
}
/*
#[cfg(test)]
mod tests {
    use super::rank;
    
    #[test]
    fn test1() {
      assert_eq!(rank(1), -1);
    }
    #[test]
    fn test2() {
      assert_eq!(rank(10), -1);
    }
    #[test]
    fn test3() {
      assert_eq!(rank(13), 31);
    }
    #[test]
    fn test4() {
      assert_eq!(rank(63), -1);
    }
    #[test]
    fn test5() {
      assert_eq!(rank(33), -1);
    }
    #[test]
    fn test6() {
      assert_eq!(rank(1001), 1010);
    }
    #[test]
    fn test7() {
      assert_eq!(rank(2047), 2074);
    }
    #[test]
    fn test8() {
      assert_eq!(rank(8977), 9778);
    }
    #[test]
    fn test9() {
      assert_eq!(rank(1073741823), 1073741832);
    }
    #[test]
    fn test10() {
      assert_eq!(rank(4096), 4609);
    }

}*/
