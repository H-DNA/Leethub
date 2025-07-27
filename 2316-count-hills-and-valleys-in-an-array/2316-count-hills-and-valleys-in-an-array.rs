impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut non_dup_nums = vec![];
        non_dup_nums.push(nums[0]);
        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                non_dup_nums.push(nums[i]);
            }
        }

        let nums = non_dup_nums;
        let mut res = 0;
        for i in 1..nums.len() - 1 {
            if nums[i] > nums[i - 1] && nums[i] > nums[i + 1] {
                res += 1;
            } else if nums[i] < nums[i - 1] && nums[i] < nums[i + 1] {
                res += 1;
            }
        }
        res
    }
}