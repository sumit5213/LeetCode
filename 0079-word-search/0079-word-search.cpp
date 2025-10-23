class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        int index=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[index]){
                    if(search(board, word, i, j, index, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int row, int col, int initial, int m, int n){
        if(initial==word.length()) return true;
        if(row<0 or row==m or col<0 or col==n or board[row][col]!=word[initial] or board[row][col] == '!') 
            return false;
        int roww[4] = {-1, 0, 1, 0};
        int coll[4] = {0, 1, 0, -1};
        char c = board[row][col];
        board[row][col] = '!';
        bool found=false;
        for(int i=0;i<4;i++){
            int newRow = row + roww[i];
            int newCol = col + coll[i];
                if(search(board, word, newRow, newCol, initial+1, m, n)){
                    found=true;
                    break;
                }
        }
        board[row][col] = c;
        return found;
    }
};