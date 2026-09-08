class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {

        unordered_set<string> st;

        // Store all points
        for (auto p : points) {
            string key = to_string(p[0]) + "#" + to_string(p[1]);
            st.insert(key);
        }

        int n = points.size();
        double ans = 1e18;

        // Choose 3 points
        for (int i = 0; i < n; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = 0; j < n; j++) {

                if (j == i)
                    continue;

                int x2 = points[j][0];
                int y2 = points[j][1];

                for (int k = j + 1; k < n; k++) {

                    if (k == i)
                        continue;

                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    // Fourth point
                    int x4 = x2 - x1 + x3;
                    int y4 = y2 - y1 + y3;

                    string key = to_string(x4) + "#" + to_string(y4);

                    // Fourth point must exist
                    if (st.find(key) == st.end())
                        continue;

                    // Check perpendicular:
                    // (P2-P1) . (P3-P1) == 0
                    int dotProduct =
                        (x2 - x1) * (x3 - x1) +
                        (y2 - y1) * (y3 - y1);

                    if (dotProduct != 0)
                        continue;

                    // Length of two sides squared
                    int side1 =
                        (x2 - x1) * (x2 - x1) +
                        (y2 - y1) * (y2 - y1);

                    int side2 =
                        (x3 - x1) * (x3 - x1) +
                        (y3 - y1) * (y3 - y1);

                    double area = sqrt((double)side1 * side2);

                    ans = min(ans, area);
                }
            }
        }

        if (ans == 1e18)
            return 0;

        return ans;
    }
};