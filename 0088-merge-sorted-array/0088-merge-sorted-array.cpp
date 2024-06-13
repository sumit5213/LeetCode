class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> num3(m + n);
        int left = 0;
        int right = 0;
        int index = 0;
        while (left < m && right < n) {
            if (num1[left] < num2[right]) {
                num3[index] = num1[left];
                index++;
                left++;
            } else {
                num3[index] = num2[right];
                index++;
                right++;
            }
        }
        while (left < m) {
            num3[index] = num1[left];
            index++;
            left++;
        }
        while (right < n) {
            num3[index] = num2[right];
            index++;
            right++;
        }
        for(int i=0;i<m+n;i++){
            // if(i<m){
                num1[i]=num3[i];
            // }
            // else{
            //     num2[i-m]=num3[i];
            // }
        }
    }
};
