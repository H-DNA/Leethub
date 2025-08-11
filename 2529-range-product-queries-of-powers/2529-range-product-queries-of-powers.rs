impl Solution {
    pub fn get_powers(mut n: i32) -> Vec<i32> {
        let mut res = vec![];
        let mut exp = 0;
        while n > 0 {
            if (n & 1) == 1 {
                res.push(exp);
            }
            n >>= 1;
            exp += 1;
        }
        res
    }
    pub fn power_2(p: i32) -> i32 {
        let mut res = 1;
        for i in 0..p {
            res = res * 2 % 1000000007;
        }
        res
    }
    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let powers = Solution::get_powers(n);
        let mut sum = 0;
        let mut prefix_sum = vec![0];
        for i in powers {
            sum += i;
            prefix_sum.push(sum);
        }
        queries.iter()
            .map(|q| prefix_sum[1 + q[1] as usize] - prefix_sum[q[0] as usize])
            .map(|q| Solution::power_2(q))
            .collect()
    }
}