class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="";
        for(int i =0;i<number.length(); i++){
            string curr ="";
            if(number[i]==digit){
                curr=number.substr(0,i)+number.substr(i+1);
            }
            ans=max(ans, curr);
        }
        return ans;
    }
};