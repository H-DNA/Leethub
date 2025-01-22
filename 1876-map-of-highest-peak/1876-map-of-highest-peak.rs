use std::collections::VecDeque;

impl Solution {
    pub fn highest_peak(mut is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let r = is_water.len();
        let c = is_water[0].len();
        let mut res = vec![vec![i32::MAX; c]; r];
        
        let mut queue = VecDeque::new();
        for i in 0..r {
            for j in 0..c {
                if is_water[i][j] == 1 {
                    queue.push_back((i, j));
                    res[i][j] = 0;
                }
            }
        }

        while queue.len() > 0 {
            let (i, j) = queue.pop_front().unwrap();
            let h = res[i][j] + 1;
            if i > 0 && res[i - 1][j] > h {
                res[i - 1][j] = h;
                queue.push_back((i - 1, j));
            }
            if i < r - 1 && res[i + 1][j] > h {
                res[i + 1][j] = h;
                queue.push_back((i + 1, j));
            }
            if j > 0 && res[i][j - 1] > h {
                res[i][j - 1] = h;
                queue.push_back((i, j - 1));
            }
            if j < c - 1 && res[i][j + 1] > h {
                res[i][j + 1] = h;
                queue.push_back((i, j + 1));
            }
        }
        res
    }
}