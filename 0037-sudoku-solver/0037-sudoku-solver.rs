impl Solution {
    pub fn next_entry(x: usize, y: usize) -> Option<(usize, usize)> {
        if x == 8 && y == 8 {
            None
        } else if y == 8 {
            Some((x + 1, 0))
        } else {
            Some((x, y + 1))
        }
    }

    pub fn char_to_idx(c: char) -> usize {
        (c as usize) - ('1' as usize)
    }

    pub fn idx_to_char(i: usize) -> char {
        (i + '1' as usize) as u8 as char
    }

    pub fn mask_sudoku_3x3(board: &Vec<Vec<char>>, x: usize, y: usize, mask: &mut [bool]) {
        let x3 = x / 3;
        let y3 = y / 3;

        for i in (x3 * 3)..(x3 * 3 + 3) {
            for j in (y3 * 3)..(y3 * 3 + 3) {
                let entry = board[i][j];
                if entry == '.' {
                    continue;
                }
                let entry = Solution::char_to_idx(entry);
                mask[entry] = false;
            }
        }
    }

    pub fn mask_sudoku_col(board: &Vec<Vec<char>>, x: usize, y: usize, mask: &mut [bool]) {
        for i in 0..9 {
            let entry = board[i][y];
            if entry == '.' {
                continue;
            }
            let entry = Solution::char_to_idx(entry);
            mask[entry] = false;
        }
    }

    pub fn mask_sudoku_row(board: &Vec<Vec<char>>, x: usize, y: usize, mask: &mut [bool]) {
        for i in 0..9 {
            let entry = board[x][i];
            if entry == '.' {
                continue;
            }
            let entry = Solution::char_to_idx(entry);
            mask[entry] = false;
        }
    }

    pub fn solve_sudoku_recur(board: &mut Vec<Vec<char>>, x: usize, y: usize) -> bool {
        let entry = board[x][y];
        let next_entry = Solution::next_entry(x, y);
        
        if entry == '.' {
            let mut mask = [true; 9];
            Solution::mask_sudoku_3x3(board, x, y, &mut mask);
            Solution::mask_sudoku_col(board, x, y, &mut mask);
            Solution::mask_sudoku_row(board, x, y, &mut mask);
            
            for i in 0..9 {
                if mask[i] {
                    board[x][y] = Solution::idx_to_char(i);
                    
                    if next_entry.is_none() {
                        return true;
                    }
                    
                    let (next_x, next_y) = next_entry.unwrap();
                    if Solution::solve_sudoku_recur(board, next_x, next_y) {
                        return true;
                    }
                    
                    board[x][y] = '.';
                }
            }
            false
        } else {
            if next_entry.is_none() {
                return true;
            }
            let (next_x, next_y) = next_entry.unwrap();
            Solution::solve_sudoku_recur(board, next_x, next_y)
        }
    }

    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        Solution::solve_sudoku_recur(board, 0, 0);
    }
}