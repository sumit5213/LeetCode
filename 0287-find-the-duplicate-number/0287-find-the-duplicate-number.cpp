class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                return arr[i];
            }
            else{
                mp[arr[i]]=1;
            }
        }
        return -1;
    }

}
;