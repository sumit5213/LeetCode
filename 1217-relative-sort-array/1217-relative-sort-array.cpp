
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        vector<int> ans;
        vector<int> rest;
        for (int num : arr1) {
            countMap[num]++;
        }
        for (int num : arr2) {
            while (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }
        for (int num : arr1) {
            if (countMap[num] > 0) {
                rest.push_back(num);
                countMap[num]--;
            }
        }
        sort(rest.begin(), rest.end());
        ans.insert(ans.end(), rest.begin(), rest.end());

        return ans;
    }
};
