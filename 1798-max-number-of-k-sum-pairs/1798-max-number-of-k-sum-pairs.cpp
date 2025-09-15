class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int i=0, j=n-1;
        while(i<j){
            if(nums[i]+nums[j]>k) j--;
            else if(nums[i]+nums[j]<k) i++;
            else {
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
};