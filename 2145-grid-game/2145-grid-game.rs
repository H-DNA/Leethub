impl Solution {
    pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
        let mut low: i64 = 0;
        let mut high: i64 = 0;
        for i in 1..grid[0].len() {
            high += grid[0][i] as i64;
        }
        let mut score = high;
        for i in 1..grid[0].len() {
            low += grid[1][i-1] as i64;
            high -= grid[0][i] as i64;
            score = std::cmp::min(score, std::cmp::max(low, high));
        }
        score
    }
}