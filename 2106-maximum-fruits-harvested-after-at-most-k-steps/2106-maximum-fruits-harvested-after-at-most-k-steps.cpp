class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();

        vector<int> pos(n);
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        long long ans = 0;
        int l = 0;

        for(int r = 0; r < n; r++) {

            while(l <= r) {

                int left = pos[l];
                int right = pos[r];

                // Minimum steps to collect [left, right]
                int steps;

                if(right <= startPos) {
                    steps = startPos - left;
                }
                else if(left >= startPos) {
                    steps = right - startPos;
                }
                else {
                    int leftDist = startPos - left;
                    int rightDist = right - startPos;

                    steps = min(
                        2 * leftDist + rightDist,
                        leftDist + 2 * rightDist
                    );
                }

                if(steps <= k)
                    break;

                l++;
            }

            if(l <= r) {
                ans = max(ans, prefix[r + 1] - prefix[l]);
            }
        }

        return ans;
    }
};