impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut max_len = 1;
        let mut cur_len = 1;
        let mut max_num = nums[0];
        for i in 1..nums.len() {
            let old_max_num = max_num;
            max_num = max_num.max(nums[i]);
            if max_num > old_max_num {
                max_len = 1;
            }
            if nums[i] != nums[i - 1] {
                if nums[i-1] == max_num {
                    max_len = max_len.max(cur_len);
                }
                cur_len = 1;
            } else {
                cur_len += 1;
            }
        }
        if nums[nums.len()-1] == max_num {
            max_len = max_len.max(cur_len);
        }
        max_len
    }
}