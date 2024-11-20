impl Solution {
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut map = [0; 201];
        let mut res = vec![];
        for n in nums {
            let n = n as usize;
            map[n] += 1;
            if map[n] > res.len() {
                res.push(vec![n as i32]);
            } else {
                res[map[n] - 1].push(n as i32);
            }
        }

        res
    }
}