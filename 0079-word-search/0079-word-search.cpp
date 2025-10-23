class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int row, int col,
                int initial, int m, int n) {
        if (initial == word.length())
            return true;
        if (row < 0 or col < 0 or row == m or col == n or
            board[row][col] != word[initial] or board[row][col] == '!')
            return false;

        char c = board[row][col];
        board[row][col] = '!';

        bool top = search(board, word, row - 1, col, initial + 1, m, n);
        bool right = search(board, word, row, col + 1, initial + 1, m, n);
        bool bottom = search(board, word, row + 1, col, initial + 1, m, n);
        bool left = search(board, word, row, col - 1, initial + 1, m, n);

        board[row][col] = c;

        return top || right || bottom || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int index = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[index]) {
                    if (search(board, word, i, j, index, m, n))
                        return true;
                }
            }
        }

        return false;
    }
};