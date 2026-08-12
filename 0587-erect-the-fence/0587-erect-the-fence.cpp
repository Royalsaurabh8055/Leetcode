class Solution {
public:

    int cross(vector<int>& A, vector<int>& B, vector<int>& C) {
        return (B[0] - A[0]) * (C[1] - B[1])
             - (B[1] - A[1]) * (C[0] - B[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        int n = trees.size();

        if (n <= 1)
            return trees;

        sort(trees.begin(), trees.end());

        vector<bool> used(n, false);
        vector<int> hull;

        // -------------------------
        // LOWER HULL
        // -------------------------

        hull.push_back(0);

        for (int i = 1; i < n; i++) {

            while (hull.size() >= 2 &&
                   cross(trees[hull[hull.size() - 2]],
                         trees[hull[hull.size() - 1]],
                         trees[i]) < 0) {

                used[hull.back()] = false;
                hull.pop_back();
            }

            used[i] = true;
            hull.push_back(i);
        }

        int lowerSize = hull.size();

        // -------------------------
        // UPPER HULL
        // -------------------------

        for (int i = n - 2; i >= 0; i--) {

            // Already present in lower hull
            if (used[i])
                continue;

            while (hull.size() > lowerSize &&
                   cross(trees[hull[hull.size() - 2]],
                         trees[hull[hull.size() - 1]],
                         trees[i]) < 0) {

                hull.pop_back();
            }

            hull.push_back(i);
        }

        // Remove duplicate starting point
        hull.pop_back();

        vector<vector<int>> ans;

        for (int index : hull) {
            ans.push_back(trees[index]);
        }

        return ans;
    }
};