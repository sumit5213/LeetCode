class Solution {
public:
    int minimumDeletions(string s) {
        int ans=0,curr =0;
        for(char ch:s){
            if(ch=='b')
                curr++;
            else if(curr){
                curr--;
                ans++;
            }
        }
        return ans;
    }
};