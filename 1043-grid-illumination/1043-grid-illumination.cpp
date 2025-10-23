class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        if(n==0){
            return ans;
        }

        unordered_map<int, int> x;
        unordered_map<int, int > y;
        unordered_map<int, int > p_diag;
        unordered_map<int, int > s_diag;

        set<pair<int, int>> s;

        for(auto lamp: lamps){
            int r = lamp[0];
            int c = lamp[1];
            
            if(s.find({r, c}) == s.end()){
                x[r]++;
                y[c]++;
                p_diag[r+c]++;
                s_diag[r-c]++;
                s.insert({r, c});
            }
        }

        for(auto q: queries){
            if(x[q[0]]>0 || y[q[1]]>0 || p_diag[q[0]+q[1]]>0 || s_diag[q[0]-q[1]]>0){
                ans.push_back(1);
                for(int i=-1;i<=1;i++){
                    for(int j=-1; j<=1;j++){
                        int qx = q[0]+i;
                        int qy = q[1]+j;
                        if(qx>=0 && qx<n && qy>=0 && qy< n && s.count({qx, qy})){
                            s.erase({qx, qy});
                            x[qx]--;
                            y[qy]--;
                            p_diag[qx+qy]--;
                            s_diag[qx-qy]--;
                        }
                    }
                }
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};