class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first, last;
        int degree = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            count[num]++;
            if (count[num] == 1) {
                first[num] = i;
            }
            last[num] = i;
            degree = std::max(degree, count[num]);
        }

        int minLength = INT_MAX;

        for (const auto& kv : count) {
            if (kv.second == degree) {
                int num = kv.first;
                int length = last[num] - first[num] + 1;
                minLength = std::min(minLength, length);
            }
        }
        return minLength;
    }
};