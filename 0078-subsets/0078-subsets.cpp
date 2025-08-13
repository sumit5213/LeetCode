class Solution {
public:
    void solve(vector<int> arr, vector<int> output, vector<vector<int>>& ans,
               int index) {
        if (index >= arr.size()) {
            ans.push_back(output);
            return;
        }

        solve(arr, output, ans, index + 1);
        int element = arr[index];
        output.push_back(element);
        solve(arr, output, ans, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> output;
        solve(arr, output, ans, index);
        return ans;
    }
};
