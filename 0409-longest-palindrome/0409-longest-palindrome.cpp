class Solution {
public:
    int longestPalindrome(string s) {
        map<char,bool> mp;
        int count=0;
        for(auto ch:s){
            if(mp.find(ch)!=mp.end()){
                mp.erase(ch);
                count+=2;
            }
            else{
                mp.insert({ch,true});
            }
        }
        if(!mp.empty()){
            count++;
        }
        return count;
    }

};