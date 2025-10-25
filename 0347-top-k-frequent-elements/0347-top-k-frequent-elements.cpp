class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        vector<pair<int, int>> sorted_elements;
        for (const auto& pair : counts) {
            sorted_elements.push_back({pair.first, pair.second});
        }
        sort(
            sorted_elements.begin(), sorted_elements.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first < b.first;
        });
        vector<int> ans;
        
            for(int i=0; i<k;i++){
                ans.push_back(sorted_elements[i].first);
            }
        

        return ans;
    }
};