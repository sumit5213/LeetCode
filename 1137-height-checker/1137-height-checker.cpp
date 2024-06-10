class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> dupl(heights);
        sort(dupl.begin(),dupl.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=dupl[i]){
                count++;
            }
        }
        return count;
    }
};