impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let dist1 = (z - x).abs();
        let dist2 = (z - y).abs();
        if dist1 < dist2 {
            1
        } else if dist1 > dist2 {
            2
        } else {
            0
        }
    }
}