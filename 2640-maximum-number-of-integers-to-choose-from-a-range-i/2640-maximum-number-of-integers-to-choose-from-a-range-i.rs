use std::collections::HashSet;

impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        let range = HashSet::<i32>::from_iter((1..=n)
                            .collect::<Vec<_>>()
                            .into_iter());
        let banned = HashSet::from_iter(banned.into_iter());
        let mut numbers = range.difference(&banned)
                               .into_iter().collect::<Vec<_>>();
        numbers.sort();
        let mut sum = 0;
        for (i, n) in numbers.iter().enumerate() {
            sum += *n;
            if sum > max_sum {
                return i as i32;
            }
        }
        return numbers.len() as i32;
    }
}