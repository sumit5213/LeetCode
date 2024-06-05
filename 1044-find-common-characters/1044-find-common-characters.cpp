class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for(char ch='a';ch<='z';ch++){
            int minCount=INT_MAX;
            for(auto word:words){
                int count=0;
                for(auto c:word){
                    if(c==ch){
                        count++;
                    }
                }
                minCount=min(minCount,count);
            }
            for(int i=0;i<minCount;i++){
                ans.push_back({ch});
            }
        }
        return ans;
    }
};