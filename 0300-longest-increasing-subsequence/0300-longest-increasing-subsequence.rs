impl Solution {
    pub fn first_greater(vec: &Vec<i32>, num: i32) -> usize {
        if vec.len() == 0 {
            return 0;
        }
    
        let mut left_id = 0 as isize;
        let mut right_id = vec.len() as isize - 1;

        while left_id <= right_id {
            let mid_id = (left_id + right_id) / 2;
            if vec[mid_id as usize] < num {
                left_id = mid_id + 1;
            } else {
                right_id = mid_id - 1;
            }
        }

        left_id as usize
    }

    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut seis = vec![];

        for num in nums {
            let pos = Solution::first_greater(&seis, num);
            if pos == seis.len() {
                seis.push(num);
            } else {
                seis[pos] = num;
            }
        }

        seis.len() as i32
    }
}