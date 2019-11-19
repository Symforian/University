use std::collections::BTreeMap;

fn letter_frequency(input: &str) -> BTreeMap<char, i32> {
    let mut res = BTreeMap::new();
    for c in input.to_string().chars().
                map(|x| x.to_ascii_lowercase()).
                filter(|x| x.is_alphabetic()).
                collect::<Vec<char>>(){
        match res.clone().get(&c){
            Some(v) => res.insert(c,v+1),
            None => res.insert(c,1),
        };
    
    }
    res
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use std::collections::BTreeMap;
    use super::letter_frequency;
    #[test]
    fn test1() {
        let answer: BTreeMap<char, i32> =
        [('l', 2),
         ('h', 1),
         ('e', 1),
         ('o', 1)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("hello"), answer);
    }
    #[test]
    fn test2() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 1)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("abc"), answer);
    }
    #[test]
    fn test3() {
        let answer: BTreeMap<char, i32> =
         [('d',5), ('a',4), ('b',2), ('c',2), ('h',2)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("aaAabb dddDD hhcc"), answer);
    }
    #[test]
    fn test4() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('c', 2),
         ('d', 1),('e', 1), ('f', 2), ('i', 1), ('j', 1), ('k', 2), ('l', 1), ('m', 1), ('n', 1), ('p', 1), ('s', 2), ('v', 1), ('w', 1), ('x', 1), ('z', 1)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("asdf jsklckz xcvmp wiefn"), answer);
    }
    #[test]
    fn test5() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 1),
         ('d', 1),
         ('e', 1),
         ('f', 1),
         ('g', 1),
         ('h', 1),
         ('i', 1),
         ('j', 1),
         ('k', 1),
         ('l', 1),
         ('m', 1),
         ('n', 1),
         ('o', 1),
         ('p', 1),
         ('r', 1),
         ('s', 1),
         ('t', 1),
         ('u', 1),
         ('w', 1),
         ('x', 1),
         ('y', 1),
         ('z', 1)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("abcdefghijklmnoprstuwxyz"), answer);
    }
    #[test]
    fn test6() {
        let answer: BTreeMap<char, i32> =
        [('a', 3)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("AAA"), answer);
    }
    #[test]
    fn test7() {
        let answer: BTreeMap<char, i32> =
        []
         .iter().cloned().collect();
        assert_eq!(letter_frequency(""), answer);
    }
    #[test]
    fn test8() {
        let answer: BTreeMap<char, i32> =
        [('w', 1),
         ('q', 1),
         ('x', 1),
         ('e', 1)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("12312wqex"), answer);
    }
    #[test]
    fn test9() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 5)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("ABc21334cccC"), answer);
    }
    #[test]
    fn test10() {
        let answer: BTreeMap<char, i32> =
        [('a', 30)]
         .iter().cloned().collect();
        assert_eq!(letter_frequency("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), answer);
    }



}
