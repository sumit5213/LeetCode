class Solution {
public:
    vector<int> ans;

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        ans.resize(n, -1);
        return solve(books, shelfWidth, 0);
    }

    int solve(vector<vector<int>>& books, int shelfWidth, int ind) {
        if (ind == books.size())
            return 0;
        if (ans[ind] != -1)
            return ans[ind];

        int res = INT_MAX, maxH = 0, width = 0;
        for (int i = ind; i < books.size(); ++i) {
            width += books[i][0];
            if (width > shelfWidth)
                break;
            maxH = max(maxH, books[i][1]);
            res = min(res, maxH + solve(books, shelfWidth, i + 1));
        }

        return ans[ind] = res;
    }
};
