class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid, vector<vector<int>>& ans) {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        // ans.push_back({row, col});
        grid[row][col]='1';
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {

                dfs(newRow, newCol, vis, grid, ans);
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans;
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    dfs(row, col, vis, grid, ans);
                }
            }
        }
        return count;
    }
};