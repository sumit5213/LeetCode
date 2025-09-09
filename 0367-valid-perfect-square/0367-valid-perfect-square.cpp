class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1;
        int right=num;
        while(left<=right){
            long mid=left+(right-left)%2;
            long long temp = mid*mid;
            if(temp==num) return true;
            else if(temp<num) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};