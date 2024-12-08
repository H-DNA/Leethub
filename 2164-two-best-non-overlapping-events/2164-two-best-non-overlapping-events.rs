impl Solution {
    pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
        let mut events_by_start_time = events.clone();
        events_by_start_time.sort_by(|e1, e2| e2[0].cmp(&e1[0]));
        let mut events_by_end_time = events.clone();
        events_by_end_time.sort_by(|e1, e2| e2[1].cmp(&e1[1]));

        let mut max_start = 0;
        let mut max_res = 0;
        let mut start_idx = 0;

        for e_end in events_by_end_time {
            while start_idx < events_by_start_time.len() && events_by_start_time[start_idx][0] > e_end[1] {
                max_start = std::cmp::max(events_by_start_time[start_idx][2], max_start);
                start_idx += 1;
            }
            max_res = std::cmp::max(e_end[2] + max_start, max_res);
        }
        max_res
    }
}