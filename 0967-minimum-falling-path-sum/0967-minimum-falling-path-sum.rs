use std::cmp::min;

impl Solution {
    pub fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {
        let dim = matrix.len();
        let mut dp = vec![];
        dp.push(matrix[0].clone());
        for i in 1..dim {
            let last_row = &dp[i as usize - 1];
            let mut cur_vec = vec![];
            for j in 0..dim {
                let mut min_v = last_row[j];
                if j as i32 - 1 >= 0 {
                    min_v = min(min_v, last_row[j as usize - 1]);
                }
                if j + 1 < dim {
                    min_v = min(min_v, last_row[j as usize + 1]);
                }
                cur_vec.push(min_v + matrix[i][j]);
            }
            dp.push(cur_vec);
        }
        let mut min_v = dp[dim - 1][0];
        for i in 1..dim {
            min_v = min(min_v, dp[dim - 1][i]);
        }

        min_v
    }
}