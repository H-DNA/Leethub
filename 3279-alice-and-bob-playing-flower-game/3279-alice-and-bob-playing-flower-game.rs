impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        let even_ns = (n / 2) as i64;
        let odd_ns = ((n + 1) / 2) as i64;
        let even_ms = (m / 2) as i64;
        let odd_ms = ((m + 1) / 2) as i64;
        even_ns * odd_ms + odd_ns * even_ms
    }
}