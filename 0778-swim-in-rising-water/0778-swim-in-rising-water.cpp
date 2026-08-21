class Solution {
public:
    int n;

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int i, int j, int t) {

        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;

        if (vis[i][j] || grid[i][j] > t)
            return false;

        if (i == n - 1 && j == n - 1)
            return true;

        vis[i][j] = true;

        return dfs(grid, vis, i + 1, j, t) ||
               dfs(grid, vis, i - 1, j, t) ||
               dfs(grid, vis, i, j + 1, t) ||
               dfs(grid, vis, i, j - 1, t);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int low = grid[0][0];
        int high = n * n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if (dfs(grid, vis, 0, 0, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};