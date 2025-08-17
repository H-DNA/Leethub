impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let mut dp = vec![0.0; (k + max_pts) as usize];
        let mut window = 0.0;
        for i in k..(k + max_pts) {
            dp[i as usize] = if i > n { 0.0 } else { 1.0 };
            window += dp[i as usize];
        }
        for i in (0..k).rev() {
            dp[i as usize] = window / max_pts as f64;
            window = window + dp[i as usize] - dp[(i + max_pts) as usize];
        }
        dp[0]
    }
}