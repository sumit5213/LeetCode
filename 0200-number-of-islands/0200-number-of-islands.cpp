class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int row, int col) {
            grid[row][col] = '0';
            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols && grid[newRow][newCol] == '1') {
                    dfs(newRow, newCol);
                }
            }
        };

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    count++;
                    dfs(row, col);
                }
            }
        }
        return count;
    }
};