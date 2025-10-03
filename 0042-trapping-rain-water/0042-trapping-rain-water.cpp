class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixMax(n);
        vector<int>suffixMax(n);

        prefixMax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1], nums[i]);
        }

        suffixMax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1], nums[i]);
        }

        int total=0;

        for(int i=0;i<n;i++){
            int leftMax=prefixMax[i];
            int rightMax=suffixMax[i];
            if(nums[i]<leftMax && nums[i]<rightMax){
                total+=min(leftMax, rightMax)-nums[i];
            }
        }
        return total;
    }
};