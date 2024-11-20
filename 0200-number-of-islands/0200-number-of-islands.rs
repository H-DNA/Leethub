pub fn sweep(grid: &mut Vec<Vec<char>>, row_id: usize, col_id: usize) {
    let mut queue = vec![];
    grid[row_id][col_id] = '0';
    queue.push((row_id, col_id));
    while !queue.is_empty() {
        let (row_id, col_id) = queue.pop().unwrap();
        if row_id > 0 && grid[row_id - 1][col_id] == '1' {
            queue.push((row_id - 1, col_id));
            grid[row_id - 1][col_id] = '0';
        }
        if row_id < grid.len() - 1 && grid[row_id + 1][col_id] == '1' {
            queue.push((row_id + 1, col_id));
            grid[row_id + 1][col_id] = '0';
        }
        if col_id > 0 && grid[row_id][col_id - 1] == '1' {
            queue.push((row_id, col_id - 1));
            grid[row_id][col_id - 1] = '0';
        }
        if (col_id < grid[row_id].len() - 1 && grid[row_id][col_id + 1] == '1') {
            queue.push((row_id, col_id + 1));
            grid[row_id][col_id + 1] = '0';
        }
    }
}

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut total = 0;
        for row_id in 0..grid.len() {
            for col_id in 0..grid[row_id].len() {
                if grid[row_id][col_id] == '1' {
                    total += 1;
                    sweep(&mut grid, row_id, col_id);
                }
            }
        }
        total
    }
}