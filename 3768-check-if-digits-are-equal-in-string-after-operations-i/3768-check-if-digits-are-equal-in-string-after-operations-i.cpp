class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        
        while (s.length() > 2) {
            string next_s = "";
            for (int i = 0; i < s.length() - 1; ++i) {
                int digit1 = s[i] - '0';
                int digit2 = s[i + 1] - '0';
                int temp = (digit1 + digit2) % 10;
                next_s.push_back(temp + '0');
            }
            s = next_s;
        }
        if (s.length() != 2) {
            return false;
        }
        return s[0] == s[1];
    }
};