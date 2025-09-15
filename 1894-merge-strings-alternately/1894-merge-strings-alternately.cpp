class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0;
        int j = 0;

        // Loop until one of the strings is fully traversed
        while (i < word1.length() && j < word2.length()) {
            result += word1[i];
            result += word2[j];
            i++;
            j++;
        }

        // Append any remaining characters from word1
        while (i < word1.length()) {
            result += word1[i];
            i++;
        }

        // Append any remaining characters from word2
        while (j < word2.length()) {
            result += word2[j];
            j++;
        }

        return result;
    }
};