class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // vector<
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(i!=nums[i]){
        //         return i;
        //     }
        // }
        // return nums.size();
        int n=nums.size();
        map<int,int> mp;
        for(auto ch:nums) mp[ch]++;
        int i=0;
        for(auto ch:mp){
            if(i!=ch.first){
                return i;
            }
            i++;
        }
        return n;
    }
};