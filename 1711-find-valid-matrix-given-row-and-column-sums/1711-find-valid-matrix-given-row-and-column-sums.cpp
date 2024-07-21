class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        int i=0,j=0;
        while(i<rows and j<cols){
            int val = min(rowSum[i],colSum[j]);
            res[i][j] = val;
            rowSum[i]-=val;
            colSum[j]-=val;
            if(rowSum[i]==0)
                i++;
            if(colSum[j]==0)
                j++;
        }
        return res;
    }
};
