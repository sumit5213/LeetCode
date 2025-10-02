class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum =0;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        }
        double  maxx=windowSum;
        for(int i=k;i<nums.size();i++){
            windowSum+=nums[i]-nums[i-k];
            maxx = max(maxx, windowSum);
        }
        return maxx/k;
    }
};