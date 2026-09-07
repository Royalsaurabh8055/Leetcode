class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {

        int v = destination[0];
        int h = destination[1];

        string ans = "";

        while (v > 0 || h > 0) {

            // If no H left, only V is possible
            if (h == 0) {
                ans += 'V';
                v--;
                continue;
            }

            // Number of strings if we choose H now
            long long ways = 1;

            int total = v + h - 1;

            // C(total, v)
            for (int i = 1; i <= v; i++) {
                ways = ways * (total - i + 1) / i;
            }

            // k lies among strings starting with H
            if (k <= ways) {
                ans += 'H';
                h--;
            }
            else {
                // Skip all strings starting with H
                ans += 'V';
                v--;
                k -= ways;
            }
        }

        return ans;
    }
};