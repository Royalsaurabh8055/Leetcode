class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

        int n = security.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // Count consecutive non-increasing days before i
        for (int i = 1; i < n; i++) {

            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Count consecutive non-decreasing days after i
        for (int i = n - 2; i >= 0; i--) {

            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        vector<int> ans;

        // Find valid days
        for (int i = 0; i < n; i++) {

            if (left[i] >= time && right[i] >= time) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};