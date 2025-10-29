class Solution {
public:
    int smallestNumber(int n) {
        vector<int> temp = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
        for (int i = 0; i < temp.size(); i++) {
            if (n == temp[i])
                return n;
            if (n < temp[i])
                return temp[i];
        }
        return 1;
    }
};