use std::cmp::max;

impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut max_diagonal = 0;
        let mut max_area = 0;
        for dimension in dimensions {
            let diagonal = dimension[0] * dimension[0] + dimension[1] * dimension[1];
            if max_diagonal < diagonal {
                max_diagonal = diagonal;
                max_area = dimension[0] * dimension[1];
            } else if max_diagonal == diagonal {
                max_area = max(max_area, dimension[0] * dimension[1]);
            }
        }
        max_area
    }
}