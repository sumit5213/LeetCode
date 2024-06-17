class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0;
        long long j = sqrt(c);
        while (i <= j) {
            long long ans = i * i + j * j;
            if (ans == c) {
                return true;
            } else if (ans < c)
                i++;
            else
                j--;
        }
        return false;
    }
};