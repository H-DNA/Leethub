#[derive(Debug)]
struct Node {
    prev: isize,
    index: usize,
}

impl Solution {
    pub fn largest_divisible_subset(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort();
        
        let mut dp = vec![];

        for (i, n) in nums.iter().enumerate() {
            dp.push(Node { prev: -1, index: 0 });
            for j in 0..i {
                if n % nums[j] == 0 && dp[j].index >= dp[i].index {
                    dp[i].prev = j as isize;
                    dp[i].index = dp[j].index + 1;
                }
            }
        }

        let mut max_node_i = 0; 
        for (i, n) in dp.iter().enumerate() {
            if dp[max_node_i].index < n.index {
                max_node_i = i;
            }
        }

        let mut res = vec![];
        let mut cur_id = max_node_i as isize;
        while cur_id != -1 {
            res.push(nums[cur_id as usize]);
            cur_id = dp[cur_id as usize].prev;
        }

        res
    }
}