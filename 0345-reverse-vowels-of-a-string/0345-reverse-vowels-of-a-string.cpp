class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < s.size() && i < j) {
                if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' ||
                    s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                    s[i] == 'O' || s[i] == 'U') {
                    break;
                }
                i++;
            }
            while (j >= 0 && i < j) {
                if (s[j] == 'a' || s[j] == 'o' || s[j] == 'e' || s[j] == 'i' ||
                    s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                    s[j] == 'O' || s[j] == 'U') {
                    break;
                }
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
