impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        let mut dp = vec![0; n];
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = nums[n - 1].max(nums[n - 2]);
        for i in (0..(n - 2)).rev() {
            dp[i] = (nums[i] + dp[i + 2]).max(dp[i + 1]);
        }
        dp[0]
    }
}