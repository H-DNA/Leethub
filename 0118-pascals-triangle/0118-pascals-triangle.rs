impl Solution {
    pub fn generate_next_row(prev_row: &Vec<i32>) -> Vec<i32> {
        let mut res = vec![1];
        for i in 1..prev_row.len() {
            res.push(prev_row[i - 1] + prev_row[i]);
        }
        res.push(1);
        res
    }

    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut v = vec![vec![1]];
        for i in 1..num_rows as usize {
            let next_vec = Solution::generate_next_row(&v[i - 1]);
            v.push(next_vec);
        }
        v
    }
}