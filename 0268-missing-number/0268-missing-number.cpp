class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int maxx=n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return maxx-sum;
        // int x1 = 0;
        // int n = nums.size();
        // for (int i = 1; i <= n; i++) {
        //     x1 = x1 ^ i;
        // }
        // int x2 = 0;
        // for (int i = 0; i < n; i++) {
        //     x2 = x2 ^ nums[i];
        // }
        // int ans = x1 ^ x2;
        // return ans;
    }
};