class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int ch : nums1) {
            mp[ch]++;
        }
        for (int ch : nums2) {
            if (mp[ch] > 0) {
                ans.push_back(ch);
                mp[ch]--;
            }
        }
        return ans;
    }
};