class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxx=0;
        for(int candy: candies){
            if(candy> maxx) maxx=candy;
        }
        for(int candy: candies){
            ans.push_back(candy+extraCandies>=maxx);
        }
        return ans;
    }
};