class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        // int row[m]={0};  matirx[...][0]
        // int col[n]={0};  matrix[0][...]

        int col0 = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j] == 0) {
                    nums[i][0] = 0;
                    if (j != 0)
                        nums[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (nums[i][j] != 0) {
                    if (nums[i][0] == 0 || nums[0][j] == 0) {
                        nums[i][j] = 0;
                    }
                }
            }
        }

        if (nums[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                nums[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                nums[i][0] = 0;
            }
        }
    }
};