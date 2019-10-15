fn square_area_to_circle(size:f64) -> f64 {
    let r = size.sqrt()/2f64;
    std::f64::consts::PI*r*r
}
fn main()
{
    square_area_to_circle(5.0);
}

#[cfg(test)]
mod tests {
    use super::square_area_to_circle;
    
    #[test]
    fn test1() {
      assert_eq!(square_area_to_circle(0.0), 0.0);
    }
    #[test]
    fn test2() {
      assert_eq!(square_area_to_circle(11.0), 8.63937979737193);
    }
    #[test]
    fn test3() {
      assert_eq!(square_area_to_circle(22.0), 17.278759594743864);
    }
    #[test]
    fn test4() {
      assert_eq!(square_area_to_circle(45.0), 35.34291735288517);
    }
    #[test]
    fn test5() {
      assert_eq!(square_area_to_circle(30.0), 23.56194490192345);
    }
}
