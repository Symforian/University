struct Sudoku{
    data: Vec<Vec<u32>>,
}


impl Sudoku{
    fn is_valid(&self) -> bool {
      let len = self.data.len();
      let sqr = (len as f64).sqrt() as usize;

      let mut rows = vec![];
      for _i in 0..len{
        rows.push(0u32);
      }
      let mut columns = vec![];
      for _i in 0..len{
        columns.push(rows.clone());
      }

      let mut check_row:Vec<Vec<u32>> = columns.clone();
      let mut check_col:Vec<Vec<u32>>  = columns.clone();
      let mut check_sqr:Vec<Vec<u32>> = columns;

      let mut row_i = 0usize;
      let mut col_i = 0usize;
      let mut sqr_i = 0usize;

      for row in &self.data{

        if row.len()!=len{
            return false;
        }
        let temp = sqr_i;
        for &el in row{
            if el as usize > len || el < 1 {return false;}
            check_col[col_i][(el-1) as usize]+=1;
            check_row[(el-1) as usize][col_i]+=1;
            check_sqr[(el-1) as usize][sqr_i]+=1;
            col_i+=1;
        if col_i%sqr==0 {
            sqr_i+=1;
        }

        }
        sqr_i = temp;
        col_i = 0;
        row_i+=1;
        if row_i%sqr==0 {
            sqr_i+=sqr;
        }
      }
      check_row.iter().
            chain(check_col.iter()).
            chain(check_sqr.iter()).
                    flatten().filter(|&&x| x!=1).collect::<Vec<&u32>>().is_empty()
    }
}
/*
0011
0011
2233
2233
0 0  2 0
0 1  3 0 
1 1  3 1
1 0  2 1

0 3
0 4
1 3
1 4


*/
fn main() {
let bad_sudoku_2 = Sudoku{
        data: vec![
                vec![1,2,3,4],
                vec![2,3,4,1],
                vec![3,4,1,2],
                vec![4,1,2,3],
            ]
    };
    bad_sudoku_2.is_valid();
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::Sudoku;
   #[test]
    fn test1() {
    let sud = Sudoku{
            data: vec![
                    vec![1,2,3,4],
                    vec![2,3,4,1],
                    vec![3,4,1,2],
                    vec![4,1,2,3],
                ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test2() {
    let sud = Sudoku{
            data: vec![
                    vec![1,2,3,4],
                    vec![4,3,2,1],
                    vec![3,4,1,2],
                    vec![2,1,4,3],
                ]
        };
        assert_eq!(sud.is_valid(), true);
    }
    #[test]
    fn test3() {
    let sud = Sudoku{
        data: vec![
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],

                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
            ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test4() {
    let sud = Sudoku{
        data: vec![
                vec![31,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],

                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![1,2,3, 4,5,6, 7,8,9],
            ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test5() {
    let sud = Sudoku{
        data: vec![
                vec![1,2,3, 4,5,6, 7,8,9],
                vec![9,4,5, 7,8,1, 7,8,9],
                vec![6,7,8, 4,5,6, 7,8,9],

                vec![3,9,2, 4,5,6, 7,8,9],
                vec![8,5,1, 4,5,6, 7,8,9],
                vec![4,6,7, 4,5,6, 7,8,9],
                
                vec![2,1,9, 4,5,6, 7,8,9],
                vec![5,3,6, 4,5,6, 7,8,9],
                vec![7,8,4, 4,5,6, 7,8,9],
            ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test6() {
    let sud = Sudoku{
        data: vec![
                vec![1,2,3, 4,9,6, 3,5,1],
                vec![9,4,5, 7,8,1, 7,8,2],
                vec![6,7,8, 5,2,3, 4,6,9],

                vec![3,9,2, 6,4,5, 3,8,5],
                vec![8,5,1, 2,3,7, 7,6,4],
                vec![4,6,7, 8,1,9, 9,2,1],
                
                vec![2,1,9, 3,6,4, 9,5,4],
                vec![5,3,6, 1,7,2, 7,4,3],
                vec![7,8,4, 9,5,8, 8,2,1],
            ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test7() {
    let sud = Sudoku{
        data: vec![
                vec![9,1,5, 7,2,3, 4,6,8],
                vec![7,6,3, 8,9,4, 5,2,1],
                vec![2,4,8, 5,1,6, 7,9,3],

                vec![4,8,2, 6,7,5, 3,1,9],
                vec![1,5,9, 3,8,2, 6,7,4],
                vec![6,3,7, 9,4,1, 2,8,5],
                
                vec![5,9,1, 2,3,7, 8,4,6],
                vec![8,2,6, 4,5,9, 1,3,7],
                vec![3,7,4, 1,6,8, 9,5,2],
            ]
        };
        assert_eq!(sud.is_valid(), true);
    }
    #[test]
    fn test8() {
    let sud = Sudoku{
        data: vec![
                vec![5,3,4, 6,7,8, 9,1,2],
                vec![6,7,2, 1,9,5, 3,4,8],
                vec![1,9,8, 3,4,2, 5,6,7],

                vec![8,5,9, 7,6,1, 4,2,3],
                vec![4,2,6, 8,5,3, 7,9,1],
                vec![7,1,3, 9,2,4, 8,5,6],
                
                vec![9,6,1, 5,3,7, 2,8,4],
                vec![2,8,7, 4,1,9, 6,3,5],
                vec![3,4,5, 2,8,6, 1,7,9],
            ]
        };
        assert_eq!(sud.is_valid(), true);
    }
    #[test]
    fn test9() {
    let sud = Sudoku{
        data: vec![
                vec![5,3,1, 6,7,8, 9,4,2],
                vec![6,7,2, 1,9,5, 3,5,8],
                vec![1,9,8, 3,4,2, 1,6,7],

                vec![8,5,9, 7,6,1, 4,2,3],
                vec![4,2,6, 8,5,3, 7,9,1],
                vec![7,1,3, 9,2,4, 8,5,6],
                
                vec![9,6,7, 5,3,1, 2,8,4],
                vec![2,8,4, 4,1,9, 6,3,5],
                vec![3,4,5, 2,8,6, 1,7,9],
            ]
        };
        assert_eq!(sud.is_valid(), false);
    }
    #[test]
    fn test10() {
    let sud = Sudoku{
            data: vec![
                    vec![1,2,3,4],
                    vec![4,3,2,1],
                    vec![3,4,1,2],
                    vec![2,1,4,1],
                ]
        };
        assert_eq!(sud.is_valid(), false);
    }
}
