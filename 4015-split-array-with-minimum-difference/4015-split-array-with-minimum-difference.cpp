class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return -1;

        vector<bool> isLeftInc(n);
        vector<bool> isRightDec(n);

        vector<long long> leftArrSum(n);

        isLeftInc[0] = true;
        leftArrSum[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            isLeftInc[i] = isLeftInc[i - 1] && (nums[i] > nums[i - 1]);
            leftArrSum[i] = leftArrSum[i - 1] + nums[i];
        }

        isRightDec[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            isRightDec[i] = isRightDec[i + 1] && (nums[i] > nums[i + 1]);
        }

        long long minDiff = -1;
        long long totalSum = leftArrSum[n - 1];

        for (int i = 0; i < n - 1; ++i) {
            if (isLeftInc[i] && isRightDec[i + 1]) {
                long long leftSum = leftArrSum[i];
                long long rightSum = totalSum - leftSum;
                long long currDiff = abs(leftSum - rightSum);

                if (minDiff == -1 || currDiff < minDiff) {
                    minDiff = currDiff;
                }
            }
        }
        return minDiff;
    }
};