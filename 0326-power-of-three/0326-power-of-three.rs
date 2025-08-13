impl Solution {
    pub fn is_power_of_three(mut n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        while n > 1 {
            if n % 3 != 0 {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}