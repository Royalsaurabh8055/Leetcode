class Solution {
public:
    int bestRotation(vector<int>& nums) {

        int n = nums.size();

        vector<int> change(n, 0);

        for (int i = 0; i < n; i++) {

            int start = (i + 1) % n;
            int end = (i - nums[i] + n + 1) % n;

            change[start] += 1;
            change[end] -= 1;

            if (start >= end)
                change[0] += 1;
        }

        int bestK = 0;
        int score = 0;
        int maxScore = -1;

        for (int k = 0; k < n; k++) {

            score += change[k];

            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }

        return bestK;
    }
};