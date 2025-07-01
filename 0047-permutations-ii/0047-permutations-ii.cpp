class Solution {
public:
    void func(vector<int>& nums, vector<int> freq, vector<int>& ds,
              vector<vector<int>>& ans) {

        if (nums.size() == ds.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(freq[i]) continue;
            if( i>0 && nums[i]==nums[i-1] && !freq[i-1]) continue;
            // if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                func( nums, freq, ds, ans);
                freq[i] = 0;
                ds.pop_back();
            // }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        vector<int> freq(nums.size(), 0);
        func(nums, freq, ds, ans);
        return ans;
    }
};