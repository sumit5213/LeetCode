class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int maxx=INT_MIN;
        for(int i=0;i<n-2;i++){
            maxx=max(maxx,nums[i]);
            if(maxx>nums[i+2]) return false;
        }
        return true;
    }
};