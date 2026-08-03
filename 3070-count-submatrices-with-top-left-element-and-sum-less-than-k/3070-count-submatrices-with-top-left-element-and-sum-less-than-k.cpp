class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));

        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                prefix[i][j] = grid[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];

                if (prefix[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};