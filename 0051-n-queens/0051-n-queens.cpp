class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        solve(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> & board, int n, vector<int> &leftRow, 
        vector<int> &upperDiagonal, vector<int> &lowerDiagonal){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }

    
};