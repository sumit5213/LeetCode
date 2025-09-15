class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        // int count
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0){
                bool leftPlot = (i==0) || (flowerbed[i-1]==0);
                bool rightPlot = (i==m-1) || (flowerbed[i+1]==0);
                if(leftPlot && rightPlot){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};