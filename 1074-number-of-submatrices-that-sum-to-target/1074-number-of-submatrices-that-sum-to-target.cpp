class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 0;

        // Fix the top row
        for (int top = 0; top < rows; top++) {

            vector<int> colSum(cols, 0);

            // Expand the bottom row
            for (int bottom = top; bottom < rows; bottom++) {

                // Add current row into column sums
                for (int col = 0; col < cols; col++) {
                    colSum[col] += matrix[bottom][col];
                }

                // Now find number of subarrays
                // in colSum whose sum == target

                unordered_map<int, int> mp;

                mp[0] = 1;

                int prefixSum = 0;

                for (int col = 0; col < cols; col++) {

                    prefixSum += colSum[col];

                    if (mp.find(prefixSum - target) != mp.end()) {
                        ans += mp[prefixSum - target];
                    }

                    mp[prefixSum]++;
                }
            }
        }

        return ans;
    }
};