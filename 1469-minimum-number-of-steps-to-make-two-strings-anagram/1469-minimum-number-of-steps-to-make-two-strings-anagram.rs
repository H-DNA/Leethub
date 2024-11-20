impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut dmap = [0;26];
        
        for c in s.chars() {
            dmap[c as usize - 'a' as usize] += 1;
        }
        
        for c in t.chars() {
            dmap[c as usize - 'a' as usize] -= 1;
        }

        dmap.into_iter().filter(|i| **i > 0).sum()
    }
}