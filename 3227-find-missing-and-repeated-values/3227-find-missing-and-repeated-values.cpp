class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> result(2,-1);
        unordered_map<int, int> mp;
        for (auto& vec : grid) {
            for (int num : vec) {
                mp[num]++;
            }
        }

        int maxNum = grid.size() * grid[0].size();
        for (int i = 1; i <= maxNum; ++i) {
            if (mp[i] == 0) {
                result[1] = i; 
            } else if (mp[i] == 2) {
                result[0] = i; 
            }
        }

        return result;
    }
};