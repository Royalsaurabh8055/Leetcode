class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Compute heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        int ans = 0;

        // Step 2: Sort each row and calculate max area
        for (int i = 0; i < m; i++) {

            vector<int> height = matrix[i];

            sort(height.begin(), height.end(), greater<int>());

            for (int j = 0; j < n; j++) {

                ans = max(ans, height[j] * (j + 1));
            }
        }

        return ans;
    }
};