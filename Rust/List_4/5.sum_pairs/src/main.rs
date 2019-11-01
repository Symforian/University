use std::collections::HashSet;
fn sum_pairs(ints: &[i8], s: i8) -> Option<(i8, i8)> {
    let mut h = HashSet::new();
    for i in ints.iter(){
        match h.get(&(s-*i)){
            Some(v) => return Some((*v,*i)),
            _ => h.insert(*i),
        };
    }
    None

}


fn main() {
    println!("Hello, world!");
println!("{:?}",sum_pairs(&[1,1,1],2));
}

#[test]
fn test1(){
    assert_eq!(sum_pairs(&[1,1,1],2), Some((1,1)));
}
#[test]
fn test2(){
    assert_eq!(sum_pairs(&[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,59],60), Some((1,59)));
}
#[test]
fn test3(){
    assert_eq!(sum_pairs(&[],60), None);
}
#[test]
fn test4(){
    assert_eq!(sum_pairs(&[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,59],63), None);
}
#[test]
fn test5(){
    assert_eq!(sum_pairs(&[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,59],60), Some((1,59)));
}
#[test]
fn test6(){
    assert_eq!(sum_pairs(&[1,2,3,4,5,6,77,8,9],10), Some((4,6)));
}
#[test]
fn test7(){
    assert_eq!(sum_pairs(&[1,2,3,4,5,6,77,8,9],11), Some((5,6)));
}
#[test]
fn test8(){
    assert_eq!(sum_pairs(&[1],2), None);
}
#[test]
fn test9(){
    assert_eq!(sum_pairs(&[-1,0,-31],2), None);
}
#[test]
fn test10(){
    assert_eq!(sum_pairs(&[1,23,23,-23,65,-24,78,23,5,23,42,34,54,-23,4,2,34,53,34,2,42,3,42,3,42,34,23,-23,42,34,114,1,4,-41,101,11,1,1,1,1,6,7,8,9,55,71,1,1,1,1,1,58,58,22,32,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,58,58,22,32,59],60), Some((-41,101)));
}
