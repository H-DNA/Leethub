impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut char_count = vec![0; 26];
        let len = tiles.len();
        for c in tiles.into_bytes() {
            char_count[(c as usize) - ('A' as usize)] += 1;
        }
        Solution::num_tile_possibilities_recur(&mut char_count, len)
    }
    pub fn num_tile_possibilities_recur(char_count: &mut Vec<i32>, max_len: usize) -> i32 {
        if max_len == 0 {
            return 0;
        }
        let mut count = 0;
        for i in 0..26 {
            if char_count[i] > 0 {
                count += 1;
                char_count[i] -= 1;
                count += Solution::num_tile_possibilities_recur(char_count, max_len - 1);
                char_count[i] += 1;
            }
        }
        return count;
    }
}