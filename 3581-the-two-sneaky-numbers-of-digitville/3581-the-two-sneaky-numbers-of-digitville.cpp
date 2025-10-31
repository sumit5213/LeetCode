class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        vector<int> ans;
        for(auto num: mp){
            if(num.second==2){
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};