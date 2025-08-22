use std::cmp::{min, max};

impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut left = cols - 1;
        let mut right = 0;
        let mut top = rows - 1;
        let mut bottom = 0;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }

        if left > right || top > bottom {
            return 0;
        }

        return ((right - left + 1) * (bottom - top + 1)) as i32;
    }
}