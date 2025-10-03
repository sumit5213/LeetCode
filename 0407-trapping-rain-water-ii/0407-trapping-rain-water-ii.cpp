class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0,-1},{0,1},{-1, 0},{1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        for (int col = 0; col < n; col++) {
            for (int row : {0, m-1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water =0;

        while(!boundaryCells.empty()){
            PP p=boundaryCells.top();
            boundaryCells.pop();

            int height=p.first;
            int i=p.second.first;
            int j=p.second.second;

            for(auto dir:directions){
                int ii=i+dir[0];
                int jj=j+dir[1];

                if(ii>=0 && ii<m && jj>=0 && jj<n  && !visited[ii][jj]){
                    water+=max(height- heightMap[ii][jj], 0);
                    boundaryCells.push({max(height,heightMap[ii][jj] ), {ii, jj}});
                    visited[ii][jj]=true;
                }
            }
        }
        return water;
    }
};