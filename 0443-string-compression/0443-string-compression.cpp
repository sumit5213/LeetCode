class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, res=0;
        while(i<chars.size()){
            int len=1;
            while(i+len<chars.size() && chars[i+len]==chars[i]){
                len++;
            }
            chars[res++] = chars[i];
            if(len>1){
                for(char c: to_string(len)){
                    chars[res++]=c;
                }
            }
            i+=len;
        }
        return res;
    }
};