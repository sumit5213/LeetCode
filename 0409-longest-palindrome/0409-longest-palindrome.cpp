class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int count=0;
        for(char ch:s){
            mp[ch]++;
        }
        for(auto ch:mp){
            if(ch.second%2==0){
                count+=ch.second;
            }
            else{
                count+=ch.second-1;
            }
        }
        if(count<s.length())
            return count+1;
        else
            return count;
    }


};