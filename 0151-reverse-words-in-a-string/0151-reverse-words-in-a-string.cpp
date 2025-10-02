class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        stack<string> st;
        string str="";
        string ans="";
        for(auto ch:s){
            if(ch==' '){
                if(!str.empty()){
                    st.push(str);
                    str="";
                }
            }else str+=ch;
        }
        while(!st.empty()){
            ans+=st.top()+" ";
            st.pop();
        }

        if(ans.size()>0){
            ans=ans.substr(0,ans.size()-1);
        }
        return ans;
    }
};