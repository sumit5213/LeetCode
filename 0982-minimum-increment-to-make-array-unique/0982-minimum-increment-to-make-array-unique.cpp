class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                count+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return count;
    }
};