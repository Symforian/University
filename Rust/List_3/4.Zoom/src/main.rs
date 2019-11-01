fn zoom(n: i32) -> String {
    // Base case
    if n == 1 {return "■".to_string();}
    // Setting proper color
    let mut current_color = "■";
    if (n-1)/2%2 == 1 {
        current_color = "□";
    };
    let mut rows:Vec<String> = vec![]; //Remembered rows
    let mut res:String = "".to_string(); //Result
    let mut constrow:String = current_color.clone().to_string(); //Const part of row
    // First half of pattern
    for r in 0..(n-1)/2{
        // First part of row pattern
        let mut row:String = constrow.clone();
        // Middle part of row pattern
        for _c in 0..n-(2*(r+1)){
            row.push_str(&current_color);
        }
        // Last part of row pattern
        let constrowflip:String = constrow.clone().chars().rev().collect();
        row = format!("{}{}",row,constrowflip);
        res = format!("{}{}",res,row);
        rows.push(row);
        res.push_str("\n");
        if current_color == "■" {
            current_color = "□";
        } else {
            current_color = "■";
        }
        constrow.push_str(&current_color);
    }
    // Color of middle row's first tile
    if (n-1)/2%2 == 1 {
        current_color = "□";
    } else {
        current_color = "■";
    }
    // Middle row
    for _c in 0..n{
        if current_color == "□" {res.push_str("□"); current_color = "■";} 
        else {res.push_str("■"); current_color = "□";}
    };
    res.push_str("\n");
    // Second half of pattern
    for i in (0..rows.len()).rev(){
        res = format!("{}{}",res,rows[i]);
        if i != 0 {res.push_str("\n");}
    }
    res
        
}

fn main() {
    println!("{}",zoom(5));
}

#[cfg(test)]
mod tests {
    use super::zoom;
  #[test]
    fn test_1() {
      assert_eq!(zoom(1), "■");
    }

    #[test]
    fn test_2() {
      assert_eq!(zoom(3), "\
□□□
□■□
□□□"
      );
    }

    #[test]
    fn test_3() {
      assert_eq!(zoom(5), "\
■■■■■
■□□□■
■□■□■
■□□□■
■■■■■"
      );
    }

    #[test]
    fn test_4() {
      assert_eq!(zoom(7), "\
□□□□□□□
□■■■■■□
□■□□□■□
□■□■□■□
□■□□□■□
□■■■■■□
□□□□□□□"
      );
    }

    #[test]
    fn test_5() {
      assert_eq!(zoom(9), "\
■■■■■■■■■
■□□□□□□□■
■□■■■■■□■
■□■□□□■□■
■□■□■□■□■
■□■□□□■□■
■□■■■■■□■
■□□□□□□□■
■■■■■■■■■"
    );
    }
    #[test]
    fn test_6() {
      assert_eq!(zoom(11), "\
□□□□□□□□□□□
□■■■■■■■■■□
□■□□□□□□□■□
□■□■■■■■□■□
□■□■□□□■□■□
□■□■□■□■□■□
□■□■□□□■□■□
□■□■■■■■□■□
□■□□□□□□□■□
□■■■■■■■■■□
□□□□□□□□□□□"
    );
    }
    #[test]
    fn test_7() {
      assert_eq!(zoom(13), "\
■■■■■■■■■■■■■
■□□□□□□□□□□□■
■□■■■■■■■■■□■
■□■□□□□□□□■□■
■□■□■■■■■□■□■
■□■□■□□□■□■□■
■□■□■□■□■□■□■
■□■□■□□□■□■□■
■□■□■■■■■□■□■
■□■□□□□□□□■□■
■□■■■■■■■■■□■
■□□□□□□□□□□□■
■■■■■■■■■■■■■"
    );
    }
    #[test]
    fn test_8() {
      assert_eq!(zoom(15), "\
□□□□□□□□□□□□□□□
□■■■■■■■■■■■■■□
□■□□□□□□□□□□□■□
□■□■■■■■■■■■□■□
□■□■□□□□□□□■□■□
□■□■□■■■■■□■□■□
□■□■□■□□□■□■□■□
□■□■□■□■□■□■□■□
□■□■□■□□□■□■□■□
□■□■□■■■■■□■□■□
□■□■□□□□□□□■□■□
□■□■■■■■■■■■□■□
□■□□□□□□□□□□□■□
□■■■■■■■■■■■■■□
□□□□□□□□□□□□□□□"
    );
    }
    #[test]
    fn test_9() {
      assert_eq!(zoom(17), "\
■■■■■■■■■■■■■■■■■
■□□□□□□□□□□□□□□□■
■□■■■■■■■■■■■■■□■
■□■□□□□□□□□□□□■□■
■□■□■■■■■■■■■□■□■
■□■□■□□□□□□□■□■□■
■□■□■□■■■■■□■□■□■
■□■□■□■□□□■□■□■□■
■□■□■□■□■□■□■□■□■
■□■□■□■□□□■□■□■□■
■□■□■□■■■■■□■□■□■
■□■□■□□□□□□□■□■□■
■□■□■■■■■■■■■□■□■
■□■□□□□□□□□□□□■□■
■□■■■■■■■■■■■■■□■
■□□□□□□□□□□□□□□□■
■■■■■■■■■■■■■■■■■"
    );
    }
    #[test]
    fn test_10() {
      assert_eq!(zoom(19), "\
□□□□□□□□□□□□□□□□□□□
□■■■■■■■■■■■■■■■■■□
□■□□□□□□□□□□□□□□□■□
□■□■■■■■■■■■■■■■□■□
□■□■□□□□□□□□□□□■□■□
□■□■□■■■■■■■■■□■□■□
□■□■□■□□□□□□□■□■□■□
□■□■□■□■■■■■□■□■□■□
□■□■□■□■□□□■□■□■□■□
□■□■□■□■□■□■□■□■□■□
□■□■□■□■□□□■□■□■□■□
□■□■□■□■■■■■□■□■□■□
□■□■□■□□□□□□□■□■□■□
□■□■□■■■■■■■■■□■□■□
□■□■□□□□□□□□□□□■□■□
□■□■■■■■■■■■■■■■□■□
□■□□□□□□□□□□□□□□□■□
□■■■■■■■■■■■■■■■■■□
□□□□□□□□□□□□□□□□□□□"
    );
    }


}
