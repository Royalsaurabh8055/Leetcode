class Solution {
public:

    int numPoints(vector<vector<int>>& darts, int r) {

        int n = darts.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                double x1 = darts[i][0];
                double y1 = darts[i][1];

                double x2 = darts[j][0];
                double y2 = darts[j][1];

                double dx = x2 - x1;
                double dy = y2 - y1;

                double d = sqrt(dx * dx + dy * dy);

                // Two points cannot fit inside a circle
                // if their distance is greater than diameter
                if (d > 2.0 * r)
                    continue;

                // Midpoint of the two points
                double midX = (x1 + x2) / 2.0;
                double midY = (y1 + y2) / 2.0;

                // Distance from midpoint to circle center
                double h = sqrt(r * r - (d / 2.0) * (d / 2.0));

                // Two possible circle centers
                double cx1 = midX + h * (-dy) / d;
                double cy1 = midY + h * (dx) / d;

                double cx2 = midX - h * (-dy) / d;
                double cy2 = midY - h * (dx) / d;

                // Check first center
                int count1 = 0;

                for (int k = 0; k < n; k++) {

                    double x = darts[k][0];
                    double y = darts[k][1];

                    double dist = sqrt(
                        (x - cx1) * (x - cx1) +
                        (y - cy1) * (y - cy1)
                    );

                    if (dist <= r + 1e-7)
                        count1++;
                }

                ans = max(ans, count1);

                // Check second center
                int count2 = 0;

                for (int k = 0; k < n; k++) {

                    double x = darts[k][0];
                    double y = darts[k][1];

                    double dist = sqrt(
                        (x - cx2) * (x - cx2) +
                        (y - cy2) * (y - cy2)
                    );

                    if (dist <= r + 1e-7)
                        count2++;
                }

                ans = max(ans, count2);
            }
        }

        return ans;
    }
};