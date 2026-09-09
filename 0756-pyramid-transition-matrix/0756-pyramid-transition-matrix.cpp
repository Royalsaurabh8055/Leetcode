class Solution {
public:

    int possible[7][7];

    unordered_map<string, bool> dp;

    bool solve(string row, string nextRow) {

        // Pyramid completed
        if (row.length() == 1)
            return true;

        // Current next row is complete
        if (nextRow.length() == row.length() - 1) {
            return solve(nextRow, "");
        }

        // Create unique state
        string key = row + "|" + nextRow;

        if (dp.find(key) != dp.end())
            return dp[key];

        int index = nextRow.length();

        int left = row[index] - 'A';
        int right = row[index + 1] - 'A';

        int mask = possible[left][right];

        // Try every possible block
        for (int k = 0; k < 7; k++) {

            if ((mask & (1 << k)) == 0)
                continue;

            char ch = 'A' + k;

            nextRow.push_back(ch);

            if (solve(row, nextRow)) {
                dp[key] = true;
                return true;
            }

            nextRow.pop_back();
        }

        dp[key] = false;
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        memset(possible, 0, sizeof(possible));

        // Store possible top blocks using bitmask
        for (string s : allowed) {

            int left = s[0] - 'A';
            int right = s[1] - 'A';
            int top = s[2] - 'A';

            possible[left][right] |= (1 << top);
        }

        return solve(bottom, "");
    }
};