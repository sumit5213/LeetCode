class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        for(int i=0,j=m;i<n;i++){
            num1[j]=num2[i];
            j++;
        }
        sort(num1.begin(),num1.end());
    }
};