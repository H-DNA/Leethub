impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let (mut res, mut prev) = (0, 0);

        for str in &bank {
            let cur = str.chars().filter(|c| *c == '1').count() as i32;

            if cur > 0 {
                res += prev * cur;
                prev = cur;
            }
        } 

        res
    }
}