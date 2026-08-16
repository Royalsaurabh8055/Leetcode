class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> visited(
            deadends.begin(),
            deadends.end()
        );

        // Starting point itself is blocked
        if (visited.count("0000"))
            return -1;

        // Already at target
        if (target == "0000")
            return 0;

        queue<string> q;
        q.push("0000");

        // Mark visited when pushing
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();
            steps++;

            while (size--) {

                string curr = q.front();
                q.pop();

                // Try all 4 wheels
                for (int i = 0; i < 4; i++) {

                    char original = curr[i];

                    // -------------------
                    // Turn UP
                    // -------------------
                    curr[i] = (original == '9')
                              ? '0'
                              : original + 1;

                    if (curr == target)
                        return steps;

                    if (!visited.count(curr)) {
                        visited.insert(curr);
                        q.push(curr);
                    }

                    // -------------------
                    // Turn DOWN
                    // -------------------
                    curr[i] = (original == '0')
                              ? '9'
                              : original - 1;

                    if (curr == target)
                        return steps;

                    if (!visited.count(curr)) {
                        visited.insert(curr);
                        q.push(curr);
                    }

                    // Restore original digit
                    curr[i] = original;
                }
            }
        }

        return -1;
    }
};