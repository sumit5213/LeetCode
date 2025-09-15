class Solution {
public:
    int gcd(int a, int b){
        int ans=min(a,b);
        while(ans>1){
            if(a%ans==0 && b%ans==0) break;
            ans--;
        }
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int GCD = gcd(str1.size(), str2.size());
        return str1.substr(0,GCD);
    }
};