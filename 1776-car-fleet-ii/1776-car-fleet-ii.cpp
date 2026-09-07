class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();

        vector<double> ans(n, -1.0);

        stack<int> st;

        // Start from the last car
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty()) {

                int j = st.top();

                // Current car is not faster
                // so it can never catch car j
                if (cars[i][1] <= cars[j][1]) {
                    st.pop();
                    continue;
                }

                // Time needed to catch car j
                double time =
                    (double)(cars[j][0] - cars[i][0]) /
                    (cars[i][1] - cars[j][1]);

                // If car j doesn't collide with anyone,
                // or i reaches j before j's collision
                if (ans[j] == -1 || time <= ans[j]) {
                    ans[i] = time;
                    break;
                }

                // j will collide before i can reach it
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};