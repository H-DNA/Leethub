impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let mut r = grid.len();
        let mut c = grid[0].len();
        let mut rcs = vec![0; r];
        let mut ccs = vec![0; c];
        for i in 0..r {
            for j in 0..c {
                if grid[i][j] == 1 {
                    rcs[i] += 1;
                    ccs[j] += 1;
                }
            }
        }

        let mut res = 0;
        for i in 0..r {
            for j in 0..c {
                if grid[i][j] == 1 && (rcs[i] > 1 || ccs[j] > 1) {
                    res += 1;
                }
            }
        }
        res
    }
}