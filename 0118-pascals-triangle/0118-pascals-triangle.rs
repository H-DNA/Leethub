impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        if num_rows == 1 {
            return vec![vec![1]];
        } else if num_rows == 2 {
            return vec![vec![1], vec![1, 1]];
        }
        let mut res = vec![vec![1], vec![1,1]];
        for i in 2..num_rows {
            let mut cur_vec = vec![1];
            for j in 1..i {
                cur_vec.push(res[i as usize - 1][j as usize] + res[i as usize - 1][j as usize - 1]);
            }
            cur_vec.push(1);
            res.push(cur_vec);
        }
        res
    }
}