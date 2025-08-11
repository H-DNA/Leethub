use std::collections::HashMap;

impl Solution {
    pub fn extract_digits(mut n: usize) -> Vec<i32> {
        let mut res = vec![];
        while n > 0 {
            res.push((n % 10) as i32);
            n /= 10;
        }
        res
    }
    pub fn get_power2_of_known_digits(ndigits: i32) -> Vec<usize> {
        let mut res = vec![];
        let mut cur_ndigits = 1;
        let mut cur_power2: usize = 1;
        let mut cur_power10: usize = 1;
        while cur_ndigits <= ndigits {
            if cur_power2 / cur_power10 >= 10 {
                cur_power10 *= 10;
                cur_ndigits += 1;
            }
            if cur_ndigits == ndigits {
                res.push(cur_power2);
            }
            cur_power2 *= 2;
        }
        res
    }
    pub fn compare_digits(first: &Vec<i32>, second: &Vec<i32>) -> bool {
        let mut m = HashMap::new();
        for i in first {
            *m.entry(i).or_insert(0) += 1;
        }
        for i in second {
            let mut v = m.entry(i).or_insert(0);
            if *v == 0 {
                return false;
            }
            *v -= 1;
        }
        true
    }
    pub fn reordered_power_of2(n: i32) -> bool {
        let digits = Solution::extract_digits(n as usize);
        let power2 = Solution::get_power2_of_known_digits(digits.len() as i32);
        for p in power2 {
            let p_digits = Solution::extract_digits(p);
            if Solution::compare_digits(&digits, &p_digits) {
                return true;
            }
        }
        false
    }
}