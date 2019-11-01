pub fn highlight(code: &str) -> String {

    fn get_color(c: char) -> usize{
        match c {
            'F' => return 0,
            'L' => return 1,
            'R' => return 2,
            '('|')' => return 4,
            _   => return 3,
            
        }
    } 
    let colors = [" pink\">"," red\">"," green\">"," orange\">"];
    let open_tag = "<span style=\"color:";
    let close_tag = "</span>";
    let mut ret_val = "".to_string();
    let mut tag = false;
    let mut current_color_id = 4;
    for c in code.to_string().chars(){
        if tag{
            if current_color_id == get_color(c){
                ret_val.push(c);
                tag = true;
                current_color_id = get_color(c);
            }
            else{
                    ret_val.push_str(close_tag);
                    if c != ')' && c != '('{
                        ret_val.push_str(open_tag);
                        ret_val.push_str(colors[get_color(c)]);
                        ret_val.push(c);
                        current_color_id = get_color(c);
                    } 
                    else {
                        ret_val.push(c);
                        tag = false; 
                        current_color_id = 4;
                    }

                 }
        }else
            {
            if c != ')' && c != '('{
                ret_val.push_str(open_tag);
                ret_val.push_str(colors[get_color(c)]);
                ret_val.push(c);
                tag = true;
                current_color_id = get_color(c);
            } 
            else {
                ret_val.push(c);
                tag = false; 
                current_color_id = 4;
            }
          }
    }
    if tag {
        ret_val.push_str(close_tag);    
    }
    ret_val
}

fn main() {
    println!("Hello, world!");
}
#[cfg(test)]
mod tests {
    use super::highlight;
    
    #[test]
    fn single() {
  assert_eq!(highlight("F"), "<span style=\"color: pink\">F</span>");
    }
    #[test]
    fn multiple_singles() {
  assert_eq!(highlight("(FLR0)"),"(<span style=\"color: pink\">F</span><span style=\"color: red\">L</span><span style=\"color: green\">R</span><span style=\"color: orange\">0</span>)");
    }
    #[test]
    fn multiple_multiple() {
  assert_eq!(highlight("(FFFLLLRRR012)"),"(<span style=\"color: pink\">FFF</span><span style=\"color: red\">LLL</span><span style=\"color: green\">RRR</span><span style=\"color: orange\">012</span>)");
    }

    #[test]
    fn someparenth() {
  assert_eq!(highlight("((()))"),"((()))");
    }

    #[test]
    fn someparenth_withsingle() {
  assert_eq!(highlight("(((F)))"),"(((<span style=\"color: pink\">F</span>)))");
    }

    #[test]
    fn someparenth_withmultiple() {
  assert_eq!(highlight("(((FFF)))"),"(((<span style=\"color: pink\">FFF</span>)))");
    }

    #[test]
    fn parenth_mixed_single() {
  assert_eq!(highlight("(L(R(F)R)L)"),"(<span style=\"color: red\">L</span>(<span style=\"color: green\">R</span>(<span style=\"color: pink\">F</span>)<span style=\"color: green\">R</span>)<span style=\"color: red\">L</span>)");
    }

    #[test]
    fn parenth_mixed_multiple() {
  assert_eq!(highlight("(LLL(RRR(FFF)RRR)LLL)"),"(<span style=\"color: red\">LLL</span>(<span style=\"color: green\">RRR</span>(<span style=\"color: pink\">FFF</span>)<span style=\"color: green\">RRR</span>)<span style=\"color: red\">LLL</span>)");
    }

    #[test]
    fn parenth_mixed_multiple_mix() {
  assert_eq!(highlight("(LLRL(RRLR(FFRF)RRR)LLL)"),"(<span style=\"color: red\">LL</span><span style=\"color: green\">R</span><span style=\"color: red\">L</span>(<span style=\"color: green\">RR</span><span style=\"color: red\">L</span><span style=\"color: green\">R</span>(<span style=\"color: pink\">FF</span><span style=\"color: green\">R</span><span style=\"color: pink\">F</span>)<span style=\"color: green\">RRR</span>)<span style=\"color: red\">LLL</span>)");
    }

    #[test]
    fn parenth_tail() {
  assert_eq!(highlight("F))(()()(()()()()()"), "<span style=\"color: pink\">F</span>))(()()(()()()()()");
    }


}
