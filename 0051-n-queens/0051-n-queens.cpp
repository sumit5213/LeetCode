class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, ans, board);
        return ans;
    }

    void solve(int col, int n, vector<vector<string>>& ans,
               vector<string>& board) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(col + 1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int n) {
        int roww = row;
        int coll = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = roww;
        col = coll;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = roww;
        col = coll;
        while (col >= 0 && row < n) {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
};