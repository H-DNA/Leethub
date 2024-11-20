use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut res = vec![];
        for (i, n) in nums.iter().enumerate() {
            if let Some(&back_id) = map.get(&(target - n)) {
                res.push(back_id as i32);
                res.push(i as i32);
                return res;
            } 
            map.insert(n, i);
        }

        return res;
    }
}