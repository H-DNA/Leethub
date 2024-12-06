use std::collections::HashSet;

impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        let banned = HashSet::<i32>::from_iter(banned.into_iter());
        let mut sum = 0;
        let mut count = 0;
        for num in (1..=n).into_iter()
                          .filter(|n| !banned.contains(n)) {
            sum += num;
            if sum > max_sum {
                return count;
            }
            count += 1;
        }
        count
    }
}