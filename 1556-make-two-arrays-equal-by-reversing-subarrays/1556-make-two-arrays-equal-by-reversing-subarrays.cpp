class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // sort(target.begin(),target.end());
        // map<int,int> mp;
        // for(auto ch:arr){
        //     mp[ch]++;
        // }
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]!=target[i].first)
        //         return false;
        // }
        // return true;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};