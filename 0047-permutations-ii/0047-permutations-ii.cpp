class Solution {
public:
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int i = ind; i < nums.size(); i++) {
            if(seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[i], nums[ind]);
            func(ind + 1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;
    }
};