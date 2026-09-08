class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        unordered_set<string> st;

        // Store all points
        for (auto p : points) {
            string key = to_string(p[0]) + "#" + to_string(p[1]);
            st.insert(key);
        }

        int ans = INT_MAX;

        int n = points.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Same x or same y cannot form a diagonal
                if (x1 == x2 || y1 == y2)
                    continue;

                // Other two corners
                string p1 = to_string(x1) + "#" + to_string(y2);
                string p2 = to_string(x2) + "#" + to_string(y1);

                // Check if both corners exist
                if (st.count(p1) && st.count(p2)) {

                    int width = abs(x2 - x1);
                    int height = abs(y2 - y1);

                    int area = width * height;

                    ans = min(ans, area);
                }
            }
        }

        if (ans == INT_MAX)
            return 0;

        return ans;
    }
};