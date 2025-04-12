class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }
        int m=ans.size();
        for(int i=0;i<n-m;i++){
            ans.push_back(0);
        }
        // return ans;
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[i];
        }
    }
};