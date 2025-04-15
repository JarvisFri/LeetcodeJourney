class Solution {
public:
    // Helper: backtracking function that fills in empty cells.
    bool backtrack(vector<vector<char>>& board, int pos,
                   vector<pair<int, int>>& empties,
                   bool rowUsed[9][10], bool colUsed[9][10], bool boxUsed[9][10]) {
        // Base case: if we have placed numbers in all empty cells, we are done.
        if (pos == empties.size())
            return true;
        
        int i = empties[pos].first;
        int j = empties[pos].second;
        int boxIndex = (i / 3) * 3 + (j / 3);
        
        // Try placing each number 1-9.
        for (int num = 1; num <= 9; num++) {
            if (!rowUsed[i][num] && !colUsed[j][num] && !boxUsed[boxIndex][num]) {
                // Place the number.
                board[i][j] = num + '0';
                rowUsed[i][num] = colUsed[j][num] = boxUsed[boxIndex][num] = true;
                
                // Recursively solve the rest.
                if (backtrack(board, pos + 1, empties, rowUsed, colUsed, boxUsed))
                    return true;  // Found a valid solution.
                
                // Undo the move.
                board[i][j] = '.';
                rowUsed[i][num] = colUsed[j][num] = boxUsed[boxIndex][num] = false;
            }
        }
        return false;  // Trigger backtracking.
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // Trackers for rows, columns, and 3×3 sub-boxes.
        bool rowUsed[9][10] = { false };
        bool colUsed[9][10] = { false };
        bool boxUsed[9][10] = { false };
        vector<pair<int, int>> empties;
        
        // Initialize trackers and record positions of empty cells.
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    empties.push_back({i, j});
                } else {
                    int num = board[i][j] - '0';
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    boxUsed[boxIndex][num] = true;
                }
            }
        }
        
        // Start backtracking from the first empty cell.
        backtrack(board, 0, empties, rowUsed, colUsed, boxUsed);
    }
};
