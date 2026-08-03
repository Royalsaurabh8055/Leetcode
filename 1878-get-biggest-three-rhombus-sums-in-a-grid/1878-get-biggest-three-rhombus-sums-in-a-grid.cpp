class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Rhombus of size 0 (single cell)
                st.insert(grid[i][j]);

                int maxLen = min({i, j, m - 1 - i, n - 1 - j});

                for (int len = 1; len <= maxLen; len++) {

                    int sum = 0;

                    // Top -> Right
                    int x = i - len;
                    int y = j;

                    for (int k = 0; k < len; k++) {
                        sum += grid[x + k][y + k];
                    }

                    // Right -> Bottom
                    x = i;
                    y = j + len;

                    for (int k = 0; k < len; k++) {
                        sum += grid[x + k][y - k];
                    }

                    // Bottom -> Left
                    x = i + len;
                    y = j;

                    for (int k = 0; k < len; k++) {
                        sum += grid[x - k][y - k];
                    }

                    // Left -> Top
                    x = i;
                    y = j - len;

                    for (int k = 0; k < len; k++) {
                        sum += grid[x - k][y + k];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

        for (int x : st) {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};