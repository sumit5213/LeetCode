class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long current_value = 0;
        long long power_of_2 = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;
            } else {
                if (current_value + power_of_2 <= k) {
                    current_value += power_of_2;
                    count++;
                }
            }
            if (power_of_2 <= k) {
                power_of_2 *= 2;
            }
        }
        return count;

        // int n = s.size();
        // int zero = count(s.begin(), s.end(), '0');
        // int one = 0;
        // long long curr = 0;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (s[i] == '1') {
        //         if (one >= 31)
        //             continue;
        //         long long bit_value = 1LL << one;
        //         if (bit_value + curr <= k) {
        //             curr += bit_value;
        //             one++;
        //         }
        //     }
        // }
        // return one + zero;
    }
};