class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        auto removeSubstring = [&](string s, char first, char second,
                                   int points) -> pair<string, int> {
            stack<char> st;
            int score = 0;
            for (char ch : s) {
                if (!st.empty() && st.top() == first && ch == second) {
                    st.pop();
                    score += points;
                } else {
                    st.push(ch);
                }
            }
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return {remaining, score};
        };

        if (x > y) {
            auto result1 = removeSubstring(s, 'a', 'b', x);
            ans += result1.second;
            auto result2 = removeSubstring(result1.first, 'b', 'a', y);
            ans += result2.second;
        } else {
            auto result1 = removeSubstring(s, 'b', 'a', y);
            ans += result1.second;
            auto result2 = removeSubstring(result1.first, 'a', 'b', x);
            ans += result2.second;
        }

        return ans;
    }
};