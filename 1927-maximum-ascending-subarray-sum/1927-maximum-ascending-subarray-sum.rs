impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut cur_res = nums[0];
        for i in 1..nums.len() {
            let cur = nums[i];
            let prev = nums[i - 1];
            if cur > prev {
                cur_res += cur;
            } else {
                res = std::cmp::max(res, cur_res);
                cur_res = cur;
            }
        }
        std::cmp::max(res, cur_res)
    }
}