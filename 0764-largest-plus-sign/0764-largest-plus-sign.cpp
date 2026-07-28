class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> grid(n, vector<int>(n, 1));

        // Put mines as 0
        for (auto &mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        // Left and Up
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    left[i][j] = 1;
                    up[i][j] = 1;

                    if (j > 0)
                        left[i][j] += left[i][j - 1];

                    if (i > 0)
                        up[i][j] += up[i - 1][j];
                }
            }
        }

        // Right and Down
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (grid[i][j] == 1) {

                    right[i][j] = 1;
                    down[i][j] = 1;

                    if (j < n - 1)
                        right[i][j] += right[i][j + 1];

                    if (i < n - 1)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        // Find minimum of all 4 directions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int order = min({
                    left[i][j],
                    right[i][j],
                    up[i][j],
                    down[i][j]
                });

                ans = max(ans, order);
            }
        }

        return ans;
    }
};