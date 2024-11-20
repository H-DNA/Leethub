impl Solution {
    pub fn combination_sum4(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        let mut buff: [i32; 1001] = [0; 1001];
        buff[0] = 1;
        for i in 1..=target as usize {
            for j in &nums {
                let j = *j as usize;
                if i < j {
                    break;
                }
                buff[i] += buff[i - j];
            }
        }
        buff[target as usize]
    }
}