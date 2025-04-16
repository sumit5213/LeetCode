class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> newArr;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (num1[i] <= num2[j]) {
                newArr.push_back(num1[i]);
                i++;
            } else {
                newArr.push_back(num2[j]);
                j++;
            }
        }
        while (i < m) {
            newArr.push_back(num1[i]);
            i++;
        }
        while (j < n) {
            newArr.push_back(num2[j]);
            j++;
        }
        for(int i=0;i<m+n;i++){
           num1[i]=newArr[i]; 
        }
    }
};
