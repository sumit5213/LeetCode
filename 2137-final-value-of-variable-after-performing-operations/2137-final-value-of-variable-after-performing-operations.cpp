class Solution {
public:
    int finalValueAfterOperations(vector<string>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto num: nums){
            if(num=="++X" || num=="X++"){
                ans++;
            }else ans--;
        }
        return ans;
    }
};