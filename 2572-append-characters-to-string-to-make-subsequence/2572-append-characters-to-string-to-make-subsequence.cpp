class Solution {
public:
    int appendCharacters(string s, string t) {
        int ss=0;
        int tt=0;
        while(ss<s.length() && tt<t.length()){
            if(s[ss]==t[tt]){
                tt++;
            }
            ss++;
        }
        return t.length()-tt;
    }
};