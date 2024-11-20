struct Input {
    start_time: i32,
    end_time: i32,
    profit: i32,
}

impl Solution {
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let mut input = vec![];
        let len = start_time.len();

        for i in 0..len {
            input.push(Input { start_time: start_time[i], end_time: end_time[i], profit: profit[i] });
        }

        input.sort_by(|a, b| a.start_time.partial_cmp(&b.start_time).unwrap());

        let mut res = vec![];
        for i in 0..len {
            res.push(0);
        }
        res[len - 1] = input[len - 1].profit;

        for i in (0..len-1).rev() {
            let end = input[i].end_time;

            let mut left_id = i + 1;
            let mut right_id = len - 1;
            while left_id <= right_id {
                let mid_id = (left_id + right_id) / 2;
                if input[mid_id].start_time < end {
                    left_id = mid_id + 1;
                } else {
                    right_id = mid_id - 1;
                }
            }

            res[i] = std::cmp::max(input[i].profit +
                if left_id >= len {
                    0
                } else {
                    res[left_id]
                }, res[i + 1]);
        }

        res[0]
    }
}