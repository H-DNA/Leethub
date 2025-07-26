impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut res: Vec<String> = (0..n).map(|v| (v + 1).to_string()).collect();
        let mut i = 3 as usize;
        while i <= n as usize {
            res[i - 1] = "Fizz".to_string();
            i += 3;
        }
        let mut i = 5 as usize;
        while i <= n as usize {
            res[i - 1] = "Buzz".to_string();
            i += 5;
        }
        let mut i = 15 as usize;
        while i <= n as usize {
            res[i - 1] = "FizzBuzz".to_string();
            i += 15;
        }
        res
    }
}