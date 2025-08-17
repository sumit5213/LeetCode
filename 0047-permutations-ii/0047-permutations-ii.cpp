class Solution {
public:
    void func(vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size(); i++){
            if(freq[i]) continue;
            if( i>0 && nums[i]==nums[i-1] && !freq[i-1]) continue;
            // if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                func(nums, ds, ans, freq);
                freq[i]=0;
                ds.pop_back();
            // }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> freq(nums.size(), 0);
        vector<int> ds;
        vector<vector<int>> ans;
        func(nums, ds, ans, freq);
        return ans;
    }
};