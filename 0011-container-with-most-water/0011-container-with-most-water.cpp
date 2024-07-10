class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int area = 0, p1 = 0, p2 = height.size() - 1;
        int tmpMax;
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                tmpMax = height[p1] * (p2 - p1);
                if (area < tmpMax)
                    area = tmpMax;
                p1++;
            } else {
                tmpMax = height[p2] * (p2 - p1);
                if (area < tmpMax)
                    area = tmpMax;
                p2--;
            }
        }
        return area;
    }
};