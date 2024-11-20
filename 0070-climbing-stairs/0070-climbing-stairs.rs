impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut dp = vec![];
        dp.push(1);
        dp.push(1);
        for i in 2..=n {
            dp.push(dp[i as usize - 1] + dp[i as usize - 2]);
        }
        
        dp[n as usize]
    }
}