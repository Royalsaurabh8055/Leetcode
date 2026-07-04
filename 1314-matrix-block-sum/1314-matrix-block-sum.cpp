class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        // Build 2D Prefix Sum
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                prefix[i][j] = mat[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);

                int r2 = min(n - 1, i + k);
                int c2 = min(m - 1, j + k);

                r1++;
                c1++;
                r2++;
                c2++;

                ans[i][j] =
                    prefix[r2][c2]
                  - prefix[r1-1][c2]
                  - prefix[r2][c1-1]
                  + prefix[r1-1][c1-1];
            }
        }

        return ans;
    }
};