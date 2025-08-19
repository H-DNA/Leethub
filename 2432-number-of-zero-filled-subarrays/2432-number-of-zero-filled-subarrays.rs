impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut zeros = vec![];
        
        let mut cur_len = 0;
        for n in nums {
            if n == 0 {
                cur_len += 1;
            } else {
                if cur_len > 0 {
                    zeros.push(cur_len);
                }
                cur_len = 0;
            }
        }
        if cur_len > 0 {
            zeros.push(cur_len);
        }
        zeros.iter()
             .map(|l| l * (l + 1) / 2).sum()
    }
}