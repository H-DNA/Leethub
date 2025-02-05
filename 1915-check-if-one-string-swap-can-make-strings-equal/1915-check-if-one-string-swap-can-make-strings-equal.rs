impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        let len = s1.len();

        let mut diffs = vec![];
        diffs.reserve(2);

        let s1 = s1.into_bytes();
        let s2 = s2.into_bytes();
        for i in 0..len {
            if s1[i] != s2[i] {
                if diffs.len() == 2 {
                    return false;
                }
                diffs.push((s1[i], s2[i]));
            }
        }
        if diffs.len() == 0 {
            true
        } else if diffs.len() == 1 {
            false
        } else {
            let p1 = diffs[0];
            let p2 = diffs[1];
            p1.0 == p2.1 && p1.1 == p2.0
        }
    }
}