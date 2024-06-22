class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int ans=0;
        int n=nums.size();
        int l=0;int r=0;
        while(r<n){
            if(nums[r]%2){
                k--;
                count=0;
            }
            while(k==0){
                k+=(nums[l++]%2);
                count++;
            }
            r++;
            ans+=count;
        }
        return ans;
    }
};