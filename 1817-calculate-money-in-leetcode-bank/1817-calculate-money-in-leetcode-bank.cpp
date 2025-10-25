class Solution {
public:
    int totalMoney(int n) {
        int mon = 1;
        int temp = mon;
        int day = 1;
        int ans = 0;
        while (day <= n) {
            if ((day - 1) % 7 == 0 && day > 1) {
                temp++;
                mon = temp;
            }
            ans += mon;
            day++;
            mon++;
        }
        return ans;
    }
};