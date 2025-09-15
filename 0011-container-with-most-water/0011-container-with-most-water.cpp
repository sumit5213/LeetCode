class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, tempMax = 0, i=0, j=height.size()-1;
        while(i<j){
            if(height[i]<height[j]){
                tempMax = height[i]*(j-i);
                if(ans<tempMax) ans=tempMax;
                i++;
            }else{
                tempMax = height[j]*(j-i);
                if(ans<tempMax) ans=tempMax;
                j--;
            }
        }
        return ans;
    }
};