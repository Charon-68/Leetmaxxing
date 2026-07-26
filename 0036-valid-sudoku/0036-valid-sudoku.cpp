class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of seen numbers (0-8)
        // rows[i][num] will be true if 'num' is in row 'i'
        int rows[9][9] = {0}; 
        int cols[9][9] = {0}; 
        int boxes[9][9] = {0};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }
                
                // Convert char '1'-'9' to integer 0-8 for 0-indexed arrays
                int num = board[r][c] - '1';
                
                // Calculate the index of the 3x3 sub-box (0 to 8)
                int boxIndex = (r / 3) * 3 + (c / 3);
                
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }
                
                // Mark the number as seen
                rows[r][num] = 1;
                cols[c][num] = 1;
                boxes[boxIndex][num] = 1;
            }
        }
        
        return true;
    }
};