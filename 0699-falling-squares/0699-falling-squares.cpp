class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<pair<int, int>> intervals;
        vector<int> ans;
        int maxHeight = 0;

        for (auto& square : positions) {
            int left = square[0];
            int side = square[1];
            int right = left + side;

            // Find the height beneath this square
            int baseHeight = 0;

            for (int i = 0; i < intervals.size(); i++) {
                int prevLeft = intervals[i].first;
                int prevRight = positions[i][0] + positions[i][1];
                int prevHeight = intervals[i].second;

                // Check if intervals overlap
                if (left < prevRight && right > prevLeft) {
                    baseHeight = max(baseHeight, prevHeight);
                }
            }

            int currentHeight = baseHeight + side;
            intervals.push_back({left, currentHeight});

            maxHeight = max(maxHeight, currentHeight);
            ans.push_back(maxHeight);
        }

        return ans;
    }
};