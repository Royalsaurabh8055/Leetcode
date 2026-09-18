class Solution {
public:

    struct Node {
        long long score;
        vector<int> index;

        Node() {
            score = 0;
        }

        Node(long long s, vector<int> v) {
            score = s;
            index = v;
        }
    };

    vector<vector<Node>> dp;

    vector<vector<int>> intervals;

    int n;

    int findNext(int i) {

        int left = i + 1;
        int right = n;

        int end = intervals[i][1];

        while(left < right) {

            int mid = left + (right - left) / 2;

            if(intervals[mid][0] > end)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    Node solve(int i, int remaining) {

        if(i >= n || remaining == 0)
            return Node(0, {});

        if(dp[i][remaining].score != -1)
            return dp[i][remaining];

        // Don't take current interval
        Node skip = solve(i + 1, remaining);

        // Take current interval
        int next = findNext(i);

        Node take = solve(next, remaining - 1);

        take.score += intervals[i][2];

        take.index.push_back(intervals[i][3]);

        // Keep indices sorted
        sort(take.index.begin(), take.index.end());

        // Compare
        if(take.score > skip.score) {

            return dp[i][remaining] = take;
        }

        if(take.score < skip.score) {

            return dp[i][remaining] = skip;
        }

        // Same score -> lexicographically smaller indices
        if(take.index < skip.index)
            return dp[i][remaining] = take;

        return dp[i][remaining] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& input) {

        n = input.size();

        // Store:
        // start, end, weight, original index
        intervals.clear();

        for(int i = 0; i < n; i++) {

            intervals.push_back({
                input[i][0],
                input[i][1],
                input[i][2],
                i
            });
        }

        // Sort by starting point
        sort(intervals.begin(), intervals.end());

        // dp[i][remaining]
        dp.assign(n, vector<Node>(5));

        // -1 means not calculated
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 4; j++) {
                dp[i][j].score = -1;
            }
        }

        return solve(0, 4).index;
    }
};