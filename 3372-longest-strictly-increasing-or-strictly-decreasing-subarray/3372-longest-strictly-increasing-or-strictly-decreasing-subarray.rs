enum State {
    UNDETERMINED = 0,
    INCREASING = 1,
    DECREASING = 2,
}

impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let mut state = State::UNDETERMINED;
        let mut cur_res = 1;
        let mut res = 1;
        for i in 1..nums.len() {
            let cur = nums[i];
            let prev = nums[i - 1];
            match state {
                State::UNDETERMINED => {
                    if cur > prev {
                        cur_res += 1;
                        state = State::INCREASING;
                    } else if cur < prev {
                        cur_res += 1;
                        state = State::DECREASING;
                    } else {
                        cur_res = 1;
                        state = State::UNDETERMINED;
                        res = std::cmp::max(res, cur_res);
                    }
                }
                State::INCREASING => {
                    if cur > prev {
                        cur_res += 1;
                    } else if cur == prev {
                        res = std::cmp::max(res, cur_res);
                        cur_res = 1;
                        state = State::UNDETERMINED;
                    } else {
                        res = std::cmp::max(res, cur_res);
                        cur_res = 2;
                        state = State::DECREASING;
                    }
                }
                State::DECREASING => {
                    if cur < prev {
                        cur_res += 1;
                    } else if cur == prev {
                        res = std::cmp::max(res, cur_res);
                        cur_res = 1;
                        state = State::UNDETERMINED;
                    } else {
                        res = std::cmp::max(res, cur_res);
                        cur_res = 2;
                        state = State::INCREASING;
                    }
                }
            }
        }
        res = std::cmp::max(cur_res, res);
        res
    }
}