impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let sqrt = (n as f32).sqrt() as i32;
        n != 0 && ((n - 1) & n) == 0 && sqrt * sqrt == n
    }
}