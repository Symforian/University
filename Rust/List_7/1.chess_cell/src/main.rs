fn chessboard_cell_color(cell1: &str, cell2: &str) -> bool {

    fn cell_to_tuple(cell: &str) -> (u8,u8) {
        let letter_number = vec!['0','A','B','C','D','E','F','G','H'];
        let letter_number = letter_number.iter();
        let xy = cell.clone().to_string().chars(). map(|x| match x.is_alphabetic(){
            true => letter_number.clone().position(|&y| y == x).unwrap() as u8,
            false => x.to_digit(10).unwrap() as u8,
        })
        .collect::<Vec<u8>>();
        (xy[0],xy[1])
    }
    let a = cell_to_tuple(cell1);
    let b = cell_to_tuple(cell2);
    if (a.0 + b.0)%2==1 && (a.1 + b.1)%2==1
        {return true;}
    return if (a.0 + b.0)%2==1 || (a.1 + b.1)%2==1
        { false }
    else 
        { true }
}
fn main() {
    println!("Hello, world!");
chessboard_cell_color("A1","A1");
}

#[cfg(test)]
mod tests {
    use super::chessboard_cell_color;
   #[test]
    fn test1() {
        assert_eq!(chessboard_cell_color("A1", "C3"), true);
    }
    #[test]
    fn test2() {
        assert_eq!(chessboard_cell_color("A1", "H3"), false);
    }
    #[test]
    fn test3() {
        assert_eq!(chessboard_cell_color("A1", "A2"), false);
    }
    #[test]
    fn test4() {
        assert_eq!(chessboard_cell_color("A1", "C1"), true);
    }
    #[test]
    fn test5() {
        assert_eq!(chessboard_cell_color("A1", "A1"), true);
    }
    #[test]
    fn test6() {
        assert_eq!(chessboard_cell_color("A1", "H8"), true);
    }
    #[test]
    fn test7() {
        assert_eq!(chessboard_cell_color("A5", "H5"), false);
    }
    #[test]
    fn test8() {
        assert_eq!(chessboard_cell_color("A7", "B2"), true);
    }
    #[test]
    fn test9() {
        assert_eq!(chessboard_cell_color("H1", "A8"), true);
    }
    #[test]
    fn test10() {
        assert_eq!(chessboard_cell_color("D6", "E6"), false);
    }
}
