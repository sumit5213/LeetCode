class Solution {
public:
    bool isPalidrome(string s, int start, int end){
        while(start<=end){
           if(s[start++]!=s[end--]){
            return false;
           } 
        }return true;
    }

    void func(int index, string s, vector<vector<string>>&ans, vector<string> &temp){
        if(index==s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(isPalidrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                func(i+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0, s, ans, temp);
        return ans;
    }
};