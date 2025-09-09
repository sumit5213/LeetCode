class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i = 0, j = 0;
        vector<int> temp;
        while (i < m && j < n) {
            if (num1[i] < num2[j]) {
                temp.push_back(num1[i]);
                i++;
            }
            else{temp.push_back(num2[j]);
            j++;}
        }
        while (i < m) {
            temp.push_back(num1[i]);
            i++;
        }
        while (j < n) {
            temp.push_back(num2[j]);
            j++;
        }
        for (int k = 0; k < m + n; k++) {
            num1[k] = temp[k];
        }
    }
};