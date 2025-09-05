impl Solution {
    pub fn can_fit_bits(num: i64, bits: i32) -> bool {
        if num < 0 {
            return false;
        }
        let mut set_bits = [0; 61];
        let mut mask = 1;
        let mut count = 0;
        for i in 0..61 {
            if num & mask != 0 {
                set_bits[i] = 1;
                count += 1;
            }
            mask <<= 1;
        }
        if count > bits {
            return false;
        }
        if count == bits {
            return true;
        }
        for i in (1..61).rev() {
            if set_bits[i] == 0 {
                continue;
            }
            set_bits[i - 1] += set_bits[i] * 2;
            count += set_bits[i];
            set_bits[i] = 0;
            if count >= bits as i32 {
                return true;
            }
        }
        return false;
    }

    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        let mut num1 = num1 as i64;
        for i in 0..60 {
            if Solution::can_fit_bits(num1, i) {
                return i;
            }
            num1 -= num2 as i64;
        }
        return -1;
    }
}