fn gen_sequence(n: i32) -> (Vec<i32>,Vec<i32>){
    if n<1 {return (vec![],vec![])}
    let mut john_vec:Vec<i32> = vec![0];
    let mut ann_vec:Vec<i32> = vec![1];
    let mut it_john:usize = 0;
    let mut it_ann:usize = 0;
    while john_vec.len() < n as usize{
        john_vec.push(it_john as i32 + 1 - ann_vec[john_vec[it_john] as usize]);
        it_john+=1;
        ann_vec.push(it_ann as i32 + 1 - john_vec[ann_vec[it_ann] as usize]);
        it_ann+=1;
    }
    (john_vec, ann_vec)
}
fn john(n: i32) -> Vec<i32> {
    gen_sequence(n).0
}
fn ann(n: i32) -> Vec<i32> {
    gen_sequence(n).1
}
fn sum_john(n: i32) -> i32 {
    john(n).iter().sum()
}
fn sum_ann(n: i32) -> i32 {
    ann(n).iter().sum()
}
fn main() {
    println!("{:?}",john(11));
    println!("{:?}",ann(6));
    println!("{:?}",sum_john(75));
    println!("{:?}",sum_ann(150));
}

#[cfg(test)]
mod tests {
    use super::john;
    use super::ann;
    use super::sum_john;
    use super::sum_ann;
   #[test]
    fn test1() {
        assert_eq!(john(10), vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6]);
    }
    #[test]
    fn test2() {
        assert_eq!(john(1), vec![0]);
    }
    #[test]
    fn test3() {
        assert_eq!(john(0), vec![]);
    }
    #[test]
    fn test4() {
        assert_eq!(ann(10), vec![1, 1, 2, 2, 3, 3, 4, 5, 5, 6]);
    }
    #[test]
    fn test5() {
        assert_eq!(ann(1), vec![1]);
    }
    #[test]
    fn test6() {
        assert_eq!(ann(0), vec![]);
    }
    #[test]
    fn test7() {
        assert_eq!(sum_john(75), 1720);
    }
    #[test]
    fn test8() {
        assert_eq!(sum_john(100), 3066);
    }
    #[test]
    fn test9() {
        assert_eq!(sum_ann(150), 6930);
    }
    #[test]
    fn test10() {
        assert_eq!(sum_ann(240), 17760);
    }
}
