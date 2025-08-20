use std::cmp::min;

impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut sums = vec![vec![0; cols]; rows];
        let mut res = 0;
        
        sums[0][0] = matrix[0][0];
        for j in 1..cols {
            sums[0][j] = sums[0][j - 1] + matrix[0][j];
        }

        for i in 1..rows {
            sums[i][0] = sums[i - 1][0] + matrix[i][0];
            for j in 1..cols {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i][j];
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                for t in 1..=min(rows - i, cols - j) {
                    let ri = i + t - 1;
                    let rj = j + t - 1;
                    let s1 = sums[ri][rj];
                    let s2 = if j == 0 { 0 } else { sums[ri][j - 1] };
                    let s3 = if i == 0 { 0 } else { sums[i - 1][rj] };
                    let s4 = if i == 0 || j == 0 { 0 } else { sums[i - 1][j - 1] };
                    let st = s1 - s2 - s3 + s4;
                    if st as usize == t * t {
                        res += 1;
                    }
                }
            }
        }

        res
    }
}