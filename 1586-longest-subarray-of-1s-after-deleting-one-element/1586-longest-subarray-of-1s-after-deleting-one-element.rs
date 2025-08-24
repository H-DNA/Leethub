impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut left_ones = vec![0; n];
        let mut right_ones = vec![0; n];

        for i in 0..n - 1 {
            if nums[i] == 0 {
                left_ones[i + 1] = 0;
            } else {
                left_ones[i + 1] = left_ones[i] + 1;
            }
        }

        for i in (1..n).rev() {
            if nums[i] == 0 {
                right_ones[i - 1] = 0;
            } else {
                right_ones[i - 1] = right_ones[i] + 1;
            }
        }

        let mut res = 0;
        for i in 0..n {
            res = std::cmp::max(res, left_ones[i] + right_ones[i]);
        }
        res
    }
}