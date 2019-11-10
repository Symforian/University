pub fn execute(code: &str) -> String {

    enum Dir{
        North,
        South,
        West,
        East,
    }
    fn rot_r(direction: Dir) -> Dir {
        match direction{
            Dir::North => Dir::East,
            Dir::East => Dir::South,
            Dir::South => Dir::West,
            Dir::West => Dir::North,
        }
    }
    fn rot_l(direction: Dir) -> Dir {
        match direction{
            Dir::North =>  Dir::West,
            Dir::East =>  Dir::North,
            Dir::South =>  Dir::East,
            Dir::West =>  Dir::South,
        }
    }
    let mut code:String = code.to_string();
    code.push('-');

    let mut max_n = 0i32;
    let mut min_s = 0i32;
    let mut min_w = 0i32;
    let mut max_e = 0i32;

    let mut pos = (0,0);  
    let mut positions = vec![(0i32,0i32)];
    let mut direction = Dir::East;

    let mut command:char = ' ';
    let mut number = 0;
    let mut power = 1;

    for i in code.chars(){
        if !i.is_ascii_digit(){
            if command == 'F' {
                if number == 0 {
                    number = 1;
                }
                match direction{
                    Dir::North => {
                            for _j in 0..number{
                                pos.1+=1;
                                positions.push(pos);
                            }
                            if max_n<pos.1{
                                max_n=pos.1;
                            }
                           },
                    Dir::South => {
                            for _j in 0..number{
                                pos.1-=1;
                                positions.push(pos);
                            }
                            if min_s>pos.1{
                                min_s=pos.1;
                            }
                           },
                    Dir::East => {
                            for _j in 0..number{
                                pos.0+=1;
                                positions.push(pos);
                            }
                            if max_e<pos.0{
                                max_e=pos.0;
                            }
                           },
                    Dir::West => {
                            for _j in 0..number{
                                pos.0-=1;
                                positions.push(pos);
                            }
                            if min_w>pos.0{
                                min_w=pos.0;
                            }
                           },
                }
                number = 0;
                power = 1;
            }
            else if command == 'R'{
                if number == 0 {
                    number = 1;
                }
                for _j in 0..number{
                    direction = rot_r(direction);
                }
                number = 0;
                power = 1;

            }
            else if command == 'L'{
                if number == 0 {
                    number = 1;
                }
                for _j in 0..number{
                    direction = rot_l(direction);
                }
                number = 0;
                power = 1;
                }
            command = i;
        }
        else if i.is_ascii_digit(){
            number= number * power + i.to_digit(10).unwrap() as i32;
            power*=10;
        } 
    }
    let mut row:Vec<char> = vec![];
    let mut map:Vec<Vec<char>> = vec![];
    for _i in 0..1+max_e-min_w{
        row.push(' ');
    }
    for _i in 0..1+max_n-min_s{
        map.push(row.clone());
    }
    if min_s < 0 || min_w < 0{
        let mut xmod = 0i32;
        let mut ymod = 0i32;
        if min_w < 0{
            xmod = -min_w;
        }
        if min_s < 0{
            ymod = -min_s;
        }
        positions = positions.iter().map(|x| (x.0+xmod,x.1+ymod)).collect();
    }
    for i in positions{
        map[i.1 as usize][i.0 as usize]='*';
    }
    map.iter().rev().map(|x| x.into_iter().collect()).collect::<Vec<String>>().join("\r\n").to_string()
}
fn main() {
        println!("{}",execute("F"));
        println!("{}",execute("FRRRLLL"));
        println!("{}",execute("FFFFF"));
        println!("{}",execute("F5"));
        println!("{}",execute("FR4FL4F"));
        println!("{}",execute("FFFFFLFFFFFLFFFFFLFFFFFL"));
        println!("{}",execute("LFFFFFRFFFRFFFRFFFFFFF"));
        execute("LF10LF10LF10");
}


#[cfg(test)]
mod tests {
    use super::execute;
    #[test]
    fn test1() {
        assert_eq!(execute(""), "*");
    }
    #[test]
    fn test2() {
        assert_eq!(execute("F"), "**");
    }
    #[test]
    fn test3() {
        assert_eq!(execute("RRRLLL"), "*");
    }
    #[test]
    fn test4() {
        assert_eq!(execute("FFFFF"), "******");
    }
    #[test]
    fn test5() {
        assert_eq!(execute("F5"), "******");
    }
    #[test]
    fn test6() {
        assert_eq!(execute("FR4FL4F"), "****");
    }
    #[test]
    fn test7() {
        assert_eq!(execute("LF5RF3RF3RF7"), 
    "    ****\r\n    *  *\r\n    *  *\r\n********\r\n    *   \r\n    *   ");
    }
    #[test]
    fn test8() {
        assert_eq!(execute("FFFFFLFFFFFLFFFFFLFFFFFL"), "******\r\n*    *\r\n*    *\r\n*    *\r\n*    *\r\n******");
    }
    #[test]
    fn test9() {
        assert_eq!(execute("F10LF10LF10LF10"), "***********\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n*         *\r\n***********");
    }
/*
***********
*         *
*         *
*         *
*         *
*         *
*         *
*         *
*         *
*         *
***********

*/
    #[test]
    fn test10() {
        assert_eq!(execute("R3FF4RF3"), "****\r\n*   \r\n*   \r\n*   \r\n*   \r\n*   ");
    }
/*
****
*   
*   
*   
*   
*   

*/
}
