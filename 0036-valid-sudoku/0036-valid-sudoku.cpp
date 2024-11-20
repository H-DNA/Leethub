class Solution {
public:
    bool checkRows(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            bool dtbl[9]{};
            for (int c = 0; c < 9; ++c)
                if (board[r][c] != '.') {
                    int ch = board[r][c] - '1';
                    if (dtbl[ch]) return false;
                    dtbl[ch] = true;
                }
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board) {
        for (int c = 0; c < 9; ++c) {
            bool dtbl[9]{};
            for (int r = 0; r < 9; ++r)
                if (board[r][c] != '.') {
                    int ch = board[r][c] - '1';
                    if (dtbl[ch]) return false;
                    dtbl[ch] = true;
                }
        }
        return true;
    }
    
    bool check3x3s(vector<vector<char>>& board) {
        for (int r = 0; r < 3; ++r) 
            for (int c = 0; c < 3; ++c) {
                bool dtbl[9]{};
                for (int ci = 3 * c; ci < 3 * (c + 1); ++ci)
                    for (int ri = 3 * r; ri < 3 * (r + 1); ++ri) {
                        if (board[ri][ci] != '.') {
                            int ch = board[ri][ci] - '1';
                            if (dtbl[ch]) return false;
                            dtbl[ch] = true;
                        }   
                    }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && check3x3s(board);
    }
};