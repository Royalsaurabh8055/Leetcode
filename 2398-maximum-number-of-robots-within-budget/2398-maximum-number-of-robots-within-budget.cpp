class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {

        int n = chargeTimes.size();

        deque<int> dq;   // stores indices, chargeTimes decreasing
        long long sum = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Add running cost
            sum += runningCosts[right];

            // Maintain decreasing deque of chargeTimes
            while (!dq.empty() &&
                   chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            // Cost of current window
            while (!dq.empty() &&
                   chargeTimes[dq.front()] +
                   (long long)(right - left + 1) * sum > budget) {

                if (dq.front() == left)
                    dq.pop_front();

                sum -= runningCosts[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};