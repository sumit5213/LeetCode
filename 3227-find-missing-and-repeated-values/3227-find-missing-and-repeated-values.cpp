class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        long long n = a.size()*a[0].size();
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        long long S = 0, S2 = 0;
        for (auto& vec : a) {
            for (int num : vec) {
                S += num;
                S2 += (long long)num * (long long)num;
            }
        }
        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};