class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9+7;
        vector<int> dp(r+1, 1);
        for(int i=1;i<n;i++){
            vector<int> next_dp(r+1);
            if(i%2==1){
                int prefix=0;
                for(int x=l;x<=r;x++){
                    next_dp[x]=prefix;
                    prefix=(prefix+dp[x])%mod;
                }
            }else{
                int suffix = 0;
                for(int x=r;x>=l;x--){
                    next_dp[x]=suffix;
                    suffix=(suffix+dp[x])%mod;
                }
            }
            dp=next_dp;
        }
        int count =0;
        for(int i=l;i<=r;i++){
            count = (count+dp[i])%mod;
        }
        return (count*2)%mod;
    }
};